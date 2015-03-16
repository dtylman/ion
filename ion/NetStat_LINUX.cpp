#include "NetStat.h"
#include <Poco/StringTokenizer.h>
#include <Poco/Buffer.h>
#include <Poco/String.h>
#include <stdio.h>
#include <errno.h>

NetStat::NetStat() : _logger(Poco::Logger::get("NetStat"))
{

}

NetStat::~NetStat()
{

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

void NetStat::populate()
{
    FILE *stream = popen("netstat -np --inet --inet6", "r");
    if (stream == nullptr) {
        _logger.error("Failed to run netstat, error: %s", std::string(strerror(errno)));
    }
    Poco::Buffer<char> buff(512);
    while (fgets(buff.begin(), buff.size(), stream) != NULL) {
        std::string line(buff.begin());
        Poco::StringTokenizer tokens(line, "\t", Poco::StringTokenizer::TOK_TRIM);
        const std::string& transport = Poco::toLower(Poco::translate(tokens[0], "6", ""));
        const std::string& address = tokens[4];
        const std::string& process = tokens[6];
        _processes[Poco::format("%s:%s", transport, process)] = process;

    }
    pclose(stream);
}

