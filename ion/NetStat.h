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
#include <map>

class NetStat
{
public:
    NetStat();
    virtual ~NetStat();

    std::string getProcess(const std::string& transport, const Poco::Net::IPAddress& ip, Poco::UInt16 port) const;
private:
    void populate();
    typedef std::map<std::string, std::string> Processes;
    Processes _processes;
    Poco::Logger& _logger;
};


#endif