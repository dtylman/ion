/*
 * File:   Routing.h
 * Author: danny
 *
 * Created on January 27, 2015, 3:25 PM
 */

#ifndef ROUTING_H
#define	ROUTING_H

#include <string>
#include <map>
#include <Poco/Net/IPAddress.h>

class Routing
{
public:
    Routing();
    virtual ~Routing();
    typedef std::map<Poco::Net::IPAddress, std::string> Gateways;
    const Gateways& gateways() const;
private:
    void load4();
    void load6();
    Gateways _gateways;
};

#endif	/* ROUTING_H */

