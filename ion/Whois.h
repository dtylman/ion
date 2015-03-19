/*
 * File:   Whois.h
 * Author: danny
 *
 * Created on March 16, 2015, 9:39 PM
 */

#ifndef WHOIS_H
#define	WHOIS_H

#include <Poco/Net/IPAddress.h>
#include <string>
#include <sstream>
#include <Poco/Logger.h>

class Whois
{
public:
    Whois();
    virtual ~Whois();
    void query(const std::string& hostName);
    void query(const Poco::Net::IPAddress& ip);

    std::stringstream& record();
private:
    std::string getServer(const std::string& domain);
    std::stringstream _record;
    Poco::Logger& _logger;
};

#endif	/* WHOIS_H */

