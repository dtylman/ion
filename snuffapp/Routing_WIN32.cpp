/*
 * File:   Routing.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 3:25 PM
 */

#include "Routing.h"
#include <iphlpapi.h>
#include <Poco/Net/NetworkInterface.h>
#pragma comment(lib, "iphlpapi.lib")

void Routing::load4()
{
	PMIB_IPFORWARD_TABLE2 table = NULL;
	DWORD r = NO_ERROR;
	if ((r = GetIpForwardTable2(AF_UNSPEC, &table)) != NO_ERROR) {
		throw Poco::ApplicationException("GetIpForwardTable2 failed", r);
	}
	if (table != NULL) {
		for (int i = 0; i < (int)table->NumEntries; i++) {
			const MIB_IPFORWARD_ROW2& row = table->Table[i];
			if (row.DestinationPrefix.Prefix.si_family == AF_INET) {
				Poco::Net::IPAddress address(&row.DestinationPrefix.Prefix.Ipv4.sin_addr, sizeof(IN_ADDR));
				Poco::Net::IPAddress hop(&row.NextHop.Ipv4.sin_addr, sizeof(IN_ADDR));
				if (!hop.isWildcard()) {
					std::string deviceName = Poco::Net::NetworkInterface::forIndex(row.InterfaceIndex).displayName();
					_gateways[hop] = deviceName;
				}
			}
			else if (row.DestinationPrefix.Prefix.si_family == AF_INET6) {
				Poco::Net::IPAddress address(&row.DestinationPrefix.Prefix.Ipv6.sin6_addr, sizeof(IN6_ADDR));
				Poco::Net::IPAddress hop(&row.NextHop.Ipv6.sin6_addr, sizeof(IN6_ADDR));
				if (!hop.isWildcard()) {
					std::string deviceName = Poco::Net::NetworkInterface::forIndex(row.InterfaceIndex).displayName();
					_gateways[hop] = deviceName;
				}
			}
			else {
				continue;
			}
		}
		FreeMibTable(table);
	}
}

void Routing::load6()
{

}
