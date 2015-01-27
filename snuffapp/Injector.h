/*
 * File:   Injector.h
 * Author: danny
 *
 * Created on January 27, 2015, 10:33 AM
 */

#ifndef INJECTOR_H
#define	INJECTOR_H

#include <string>
#include <libnet.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Mutex.h>
#include "MAC.h"

class Injector
{
public:
    Injector(const std::string& device);
    virtual ~Injector();

    void arpRequest(const Poco::Net::IPAddress& targetIP);
    void arpRequest(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);

    const std::string& device() const;
private:
    std::string _device;
    Poco::FastMutex _mutex;
    libnet_t* _libnet = nullptr;
    libnet_ether_addr* _srcMAC = nullptr;
    uint32_t _srcIP;
    libnet_in6_addr _srcIPv6;
};

#endif	/* INJECTOR_H */

