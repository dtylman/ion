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
#include <Poco/Logger.h>
#include "MAC.h"

class Injector
{
public:
    Injector(const std::string& device, const Poco::Net::IPAddress& sourceIP);
    virtual ~Injector();

    void arpRequest(const Poco::Net::IPAddress& targetIP);
    void arpRequest(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);

    void icmpEcho(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);
    void icmpEcho6(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);

    void icmpMask(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);
    void icmpTimestamp(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);

    void icmpNSR(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC);

    void tcpSyn(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC, uint16_t port);
    void udp(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC, uint16_t port, const std::string& payload = "");
    const std::string& device() const;
    MAC deviceMACAddress() const;
private:
    void buildEhernet(const MAC& targetMAC, uint16_t type);
    void buildIP(const Poco::Net::IPAddress& targetIP, unsigned len, u_int8_t protocol);
    void buildIPv4(const Poco::Net::IPAddress& targetIP, unsigned len, u_int8_t protocol);
    void buildIPv6(const Poco::Net::IPAddress& targetIP, unsigned len, u_int8_t protocol);
    void buildUDP(uint16_t srcPort, uint16_t destPort, const std::string& payload = "");
    void buildTCP(uint16_t srcPort, uint16_t destPort, uint8_t flags, const std::string& payload = "");
    void write();
    std::string _device;
    Poco::FastMutex _mutex;
    libnet_t* _libnet = nullptr;
    libnet_ether_addr* _srcMAC = nullptr;
    Poco::Net::IPAddress _srcIP;
    Poco::Logger& _logger;
};

#endif	/* INJECTOR_H */

