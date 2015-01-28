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
    Injector(const std::string& device, const Poco::Net::IPAddress& sourceIP);
    virtual ~Injector();

    void arpRequest(const Poco::Net::IPAddress& targetIP);
    void arpRequest(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);

    const std::string& device() const;
    MAC deviceMACAddress() const;
private:
    std::string _device;
    Poco::FastMutex _mutex;
    libnet_t* _libnet = nullptr;
    libnet_ether_addr* _srcMAC = nullptr;
    Poco::Net::IPAddress _srcIP;
};

#endif	/* INJECTOR_H */

