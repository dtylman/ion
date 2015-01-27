/*
 * File:   PcapIfaceAddress.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 6:55 PM
 */

#include "PcapIfaceAddress.h"

PcapIfaceAddress::PcapIfaceAddress(const pcap_addr* address)
{
    setAddress(_ip, address->addr);
    setAddress(_bcast, address->broadaddr);
    setAddress(_netmask, address->netmask);
    setAddress(_dest, address->dstaddr);
}

PcapIfaceAddress::~PcapIfaceAddress()
{
}

void PcapIfaceAddress::setAddress(Poco::Net::IPAddress& poco, const sockaddr* address)
{
    if (address == nullptr) {
        return;
    }
    if ((address->sa_family == AF_INET) || (address->sa_family == AF_INET6)) {
        poco = Poco::Net::IPAddress(*address);
    }
}

const Poco::Net::IPAddress& PcapIfaceAddress::broadcast() const
{
    return _bcast;
}

const Poco::Net::IPAddress& PcapIfaceAddress::ip() const
{
    return _ip;
}

const Poco::Net::IPAddress& PcapIfaceAddress::netmask() const
{
    return _netmask;
}

const Poco::Net::IPAddress& PcapIfaceAddress::p2pdest() const
{
    return _dest;
}
