/*
 * File:   Whois.h
 * Author: danny
 *
 * Created on March 16, 2015, 9:39 PM
 */

#ifndef WHOIS_H
#define	WHOIS_H

#include <string>
#include <sstream>
#include <Poco/Logger.h>

class Whois
{
public:
    Whois();
    virtual ~Whois();
    void query(const std::string& host);
    std::stringstream& record();
private:
    std::string query(const std::string& query, const std::string& server);
    std::stringstream _record;
    Poco::Logger& _logger;
};

#endif	/* WHOIS_H */

