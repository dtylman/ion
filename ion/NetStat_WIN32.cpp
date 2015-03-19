#include "NetStat.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <Psapi.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Exception.h>
#include <Poco/NumberFormatter.h>
#include <Poco/Format.h>
#include <Poco/Buffer.h>
#include <Poco/String.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

NetStat::NetStat(void) : _logger(Poco::Logger::get("NetStat"))
{
	populate();
}

NetStat::~NetStat(void)
{
}

void NetStat::populate()
{
	popTCP4();	
}

void NetStat::popTCP4()
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
		unsigned pid = module.dwOwningPid;
		Poco::Net::IPAddress ipAddress(&module.dwRemoteAddr, sizeof(DWORD));
		if (ipAddress.isUnicast())
		{
			unsigned port = module.dwRemotePort;
			std::string xfer = Poco::format("tcp:%s:%u", ipAddress.toString(), port);
			std::string name = processName(pid);
			_logger.debug("Adding process %s=%s", xfer, name);
			_processes[xfer] = name;
		}
    }
    free(pTCPTable);
}

/*
void NetStat::popUDP4()
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
        MIB_UDPROW_OWNER_MODULE module = pUDPTable->table[i];
		unsigned pid = module.dwOwningPid;
		Poco::Net::IPAddress ipAddress(&module.dwLocalAddr, sizeof(DWORD));
		unsigned port = module.dwLocalPort;
		std::string xfer = Poco::format("tcp:%s:%u", ipAddress.toString(), port);
		_processes[xfer] = processName(pid);
    }
    free(pUDPTable);
    return;
}
*/

std::string NetStat::processName(unsigned pid)
{
	HANDLE handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
	if (handle != 0)
	{		
		Poco::Buffer<char> basename(MAX_PATH);
		DWORD len = GetModuleBaseName(handle, nullptr, basename.begin(), MAX_PATH);
		if (len>0)
		{
			return std::string(basename.begin(), len);
		}
	}
	return "";
}

std::string NetStat::getProcess(const std::string& transport, const Poco::Net::IPAddress& ip, Poco::UInt16 port) const
{
	std::string address = Poco::format("%s:%s:%hu", Poco::toLower(transport), ip.toString(), port);
	auto process = _processes.find(address);
	if (process == _processes.end()) {
		return "";
	}
	return process->second;
}