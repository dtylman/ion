#include "NetStat.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Exception.h>
#include <Poco/NumberFormatter.h>
#include <Poco/Format.h>
#include "WMI/WMIProvider.h"

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

NetStat::NetStat(void) : _logger(Poco::Logger::get("NetStat"))
{
}

NetStat::~NetStat(void)
{
}

void NetStat::populate()
{

}

void NetStat::populate(ContextWriter& writer)
{
    WMIProvider wmi;
    wmi.connect();
    WMIProvider::WMIResults res;
    wmi.query("SELECT Name, ProcessId from Win32_Process", res);
    WMIProvider::WMIResults::iterator iter = res.begin();
    for (; iter != res.end(); ++iter) {
        std::string& name = iter->second["Name"];
        std::string& id = iter->second["ProcessId"];
        _processes[id] = name;
    }
    write_tcp4(writer);
    write_udp4(writer);
}

void NetStat::write_tcp4(ContextWriter& writer)
{
    DWORD size = 0;
    DWORD result = 0;
    result = GetExtendedTcpTable(NULL, &size, true, AF_INET, TCP_TABLE_OWNER_MODULE_ALL, 0);
    if ((result != ERROR_INSUFFICIENT_BUFFER) && (result != NO_ERROR)) {
        _logger.error(Poco::format("Failed to get size estimation. Error: %u.", (Poco::UInt32)GetLastError()));
        return;
    }
    PMIB_TCPTABLE_OWNER_MODULE pTCPTable = (PMIB_TCPTABLE_OWNER_MODULE) malloc(size);
    if (pTCPTable == NULL) {
        return;
    }
    result = GetExtendedTcpTable(pTCPTable, &size, true, AF_INET, TCP_TABLE_OWNER_MODULE_ALL, 0);
    if (result != NO_ERROR) {
        _logger.error(Poco::format("Failed to get TCP Table. Error: %u", (Poco::UInt32)GetLastError()));
        free(pTCPTable);
        return;
    }
    for (DWORD i = 0; i < pTCPTable->dwNumEntries; i++) {
        MIB_TCPROW_OWNER_MODULE module = pTCPTable->table[i];
        if (module.dwState == MIB_TCP_STATE_LISTEN) {
            writer.startObject("socket");
            Poco::Net::IPAddress local(&module.dwLocalAddr, sizeof (DWORD));
            writer.write("localaddress", local.toString());
            std::string pid = Poco::NumberFormatter::format(module.dwOwningPid);
            writer.write("pid", pid);
            writer.write("pname", pid2Name(pid));
            writer.write("localport", Poco::NumberFormatter::format(htons((short) module.dwLocalPort)));
            writer.write("protocol", "TCP");
            writer.endObject();
        }

    }
    free(pTCPTable);
}

void NetStat::write_udp4(ContextWriter& writer)
{
    DWORD size = 0;
    DWORD result = 0;
    result = GetExtendedUdpTable(NULL, &size, true, AF_INET, UDP_TABLE_OWNER_MODULE, 0);
    if ((result != ERROR_INSUFFICIENT_BUFFER) && (result != NO_ERROR)) {
        _logger.error(Poco::format("Failed to get size estimation. Error: %u.", (Poco::UInt32)GetLastError()));
        return;
    }
    PMIB_UDPTABLE_OWNER_MODULE pUDPTable = (PMIB_UDPTABLE_OWNER_MODULE) malloc(size);
    if (pUDPTable == NULL) {
        return;
    }
    result = GetExtendedUdpTable(pUDPTable, &size, true, AF_INET, UDP_TABLE_OWNER_MODULE, 0);
    if (result != NO_ERROR) {
        _logger.error(Poco::format("Failed to get TCP Table. Error: %u", (Poco::UInt32)GetLastError()));
        free(pUDPTable);
        return;
    }
    for (DWORD i = 0; i < pUDPTable->dwNumEntries; i++) {
        writer.startObject("socket");
        MIB_UDPROW_OWNER_MODULE module = pUDPTable->table[i];
        Poco::Net::IPAddress local(&module.dwLocalAddr, sizeof (DWORD));
        writer.write("localaddress", local.toString());
        std::string pid = Poco::NumberFormatter::format(module.dwOwningPid);
        writer.write("pid", pid);
        writer.write("pname", pid2Name(pid));
        writer.write("localport", Poco::NumberFormatter::format(htons((short) module.dwLocalPort)));
        writer.write("protocol", "UDP");
        writer.endObject();
    }
    free(pUDPTable);
    return;
}

std::string NetStat::pid2Name(const std::string& pid)
{
    std::map<std::string, std::string>::const_iterator iter = _processes.find(pid);
    if (iter != _processes.end()) {
        return iter->second;
    }
    return "";
}