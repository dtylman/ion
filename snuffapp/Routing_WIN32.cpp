/*
 * File:   Routing.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 3:25 PM
 */

#include "Routing.h"

Routing::Routing()
{
    load4();
    load6();
}

Routing::~Routing()
{
}

void Routing::load4()
{

}

void Routing::load6()
{

}

/*
 * RoutingTable.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: danny
 */

#include "RoutingTable.h"
#include <Poco/SharedLibrary.h>
#include <Poco/Buffer.h>
#include <iphlpapi.h>

#pragma comment(lib, "iphlpapi.lib")

using Infra::Objects::IPRoute;
using Infra::Objects::RoutingTable;
using Infra::Objects::Subnet;

typedef DWORD(WINAPI *GETIPFORWARDTABLE2)(ADDRESS_FAMILY, PMIB_IPFORWARD_TABLE2 *);
typedef DWORD(WINAPI *FREEMIBTABLE)(PVOID);

bool interfaceSupported(IFTYPE ifaceType)
{
    switch (ifaceType) {
    case IF_TYPE_ETHERNET_CSMACD:
    case IF_TYPE_TUNNEL:
    case IF_TYPE_IEEE80211:
        return true;
    }
    return false;
}

void init_vista(Poco::SharedLibrary& dll, Infra::Objects::RoutingTable::Table& table4,
                Infra::Objects::RoutingTable::Table& table6, Poco::Logger& logger)
{
    PMIB_IPFORWARD_TABLE2 table = NULL;
    GETIPFORWARDTABLE2 GetIpForwardTable2 = (GETIPFORWARDTABLE2) dll.getSymbol("GetIpForwardTable2");
    FREEMIBTABLE FreeMibTable = (FREEMIBTABLE) dll.getSymbol("FreeMibTable");
    DWORD r = NO_ERROR;
    if ((r = GetIpForwardTable2(AF_UNSPEC, &table)) != NO_ERROR) {
        throw Poco::ApplicationException("GetIpForwardTable2 failed", r);
    }
    if (table != NULL) {
        for (int i = 0; i < (int) table->NumEntries; i++) {
            const MIB_IPFORWARD_ROW2& row = table->Table[i];
            Poco::Net::NetworkInterface nic = Poco::Net::NetworkInterface::forIndex(row.InterfaceIndex);
            if (!nic.macAddress().empty()) {
                if (interfaceSupported(row.InterfaceLuid.Info.IfType)) {
                    if (row.DestinationPrefix.Prefix.si_family == AF_INET) {
                        Poco::Net::IPAddress address(&row.DestinationPrefix.Prefix.Ipv4.sin_addr, sizeof (IN_ADDR));
                        Subnet subnet(address, row.DestinationPrefix.PrefixLength);
                        IPRoute route(subnet, nic);
                        Poco::Net::IPAddress hop(&row.NextHop.Ipv4.sin_addr, sizeof (IN_ADDR));
                        if (!hop.isWildcard()) {
                            route.setNextHop(hop);
                        }
                        logger.debug(Poco::format("Adding route %s", route.toString()));
                        table4.push_front(route);
                    }
                    else if (row.DestinationPrefix.Prefix.si_family == AF_INET6) {
                        Poco::Net::IPAddress address(&row.DestinationPrefix.Prefix.Ipv6.sin6_addr, sizeof (IN6_ADDR));
                        Subnet subnet(address, row.DestinationPrefix.PrefixLength);

                        IPRoute route(subnet, Poco::Net::NetworkInterface::forIndex(row.InterfaceIndex));
                        Poco::Net::IPAddress hop(&row.NextHop.Ipv6.sin6_addr, sizeof (IN6_ADDR));
                        if (!hop.isWildcard()) {
                            route.setNextHop(hop);
                        }
                        logger.debug(Poco::format("Adding route %s", route.toString()));
                        table6.push_front(route);
                    }
                    else {
                        //log.warning - stupid family here.
                        continue;
                    }
                }
                else {
                    logger.debug("Not adding route destination: Interface '%s' is not supported (type=%d)", nic.displayName(), (int) row.InterfaceLuid.Info.IfType);
                }
            }
            else {
                logger.debug("Not adding route destination: Interface '%s' does not have a mac address ", nic.displayName());
            }
        }
        FreeMibTable(table);
    }
}

void init_xp(Infra::Objects::RoutingTable::Table& table4, Poco::Logger& logger)
{
    Poco::Buffer<MIB_IPFORWARDTABLE> buffForwardTable(1);
    DWORD dwSize = 0;
    if (GetIpForwardTable(buffForwardTable.begin(), &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER) {
        buffForwardTable.resize(dwSize);
    }
    DWORD dwRetVal = NO_ERROR;
    if ((dwRetVal = GetIpForwardTable(buffForwardTable.begin(), &dwSize, 0)) != NO_ERROR) {
        throw Poco::ApplicationException("GetIpForwardTable failed", dwRetVal);
    }
    PMIB_IPFORWARDTABLE pIpForwardTable = buffForwardTable.begin();
    for (DWORD i = 0; i < pIpForwardTable->dwNumEntries; i++) {
        const MIB_IPFORWARDROW& row = pIpForwardTable->table[i];
        Poco::Net::NetworkInterface nic = Poco::Net::NetworkInterface::forIndex(row.dwForwardIfIndex);
        if (!nic.macAddress().empty()) {
            Poco::Net::IPAddress address(&row.dwForwardDest, sizeof (DWORD));
            Poco::Net::IPAddress mask(&row.dwForwardMask, sizeof (DWORD));
            Subnet subnet(address, mask.prefixLength());
            IPRoute route(subnet, nic);
            if (!route.getIfaceMac().empty()) {
                Poco::Net::IPAddress hop(&row.dwForwardNextHop, sizeof (DWORD));
                if (!hop.isWildcard()) {
                    route.setNextHop(hop);
                }
                logger.debug(Poco::format("Adding route %s", route.toString()));
                table4.push_front(route);
            }
        }
    }
}

void RoutingTable::init()
{
    mTable4.clear();
    mTable6.clear();
    Poco::SharedLibrary dll("iphlpapi.dll");
    if (dll.hasSymbol("GetIpForwardTable2") && (dll.hasSymbol("FreeMibTable"))) {
        init_vista(dll, mTable4, mTable6, mLogger);
    }
    else {
        init_xp(mTable4, mLogger);
    }
}
