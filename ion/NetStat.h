/*
 * File:   NetStat.h
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */

#ifndef NETSTAT_H
#define	NETSTAT_H

#include <Poco/Logger.h>
#include <Poco/Net/IPAddress.h>
#include <string>
#include <map>

class NetStat
{
public:
    NetStat();
    virtual ~NetStat();

    std::string getProcess(const std::string& transport, const Poco::Net::IPAddress& ip, Poco::UInt16 port) const;
protected:
    void populateProcesses();
    void populate();
    void write_tcp4();
    void write_udp4();
    std::string pid2Name(const std::string& pid);

    std::map<std::string, std::string> _processes;
    Poco::Logger& _logger;
};


#endif