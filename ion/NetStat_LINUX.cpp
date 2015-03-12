#include "NetStat.h"

NetStat::NetStat() : _logger(Poco::Logger::get("NetStat"))
{

}

NetStat::~NetStat()
{

}

std::string NetStat::getProcess(const std::string& transport, const Poco::Net::IPAddress& ip, Poco::UInt16 port) const
{
    return "";
}

std::string NetStat::pid2Name(const std::string& pid)
{

}

void NetStat::populate()
{

}

void NetStat::populateProcesses()
{

}

void NetStat::write_tcp4()
{

}

void NetStat::write_udp4()
{

}
