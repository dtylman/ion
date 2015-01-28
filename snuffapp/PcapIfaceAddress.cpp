/*
 * File:   PcapIfaceAddress.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 6:55 PM
 */

#include "PcapIfaceAddress.h"

PcapIfaceAddress::PcapIfaceAddress(const pcap_addr* address) : _logger(Poco::Logger::get("PcapIfaceAddress"))
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
        _logger.notice("Setting address %s", poco.toString());
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

void PcapIfaceAddress::fillAllIPs(IPContainer& container, unsigned max) const
{
    container.clear();
    if (_ip.family() != Poco::Net::IPAddress::IPv4) {
        return;
    }
    Poco::Net::IPAddress ip = _ip;
    ip.mask(_netmask);
    Poco::UInt32 baseAddress;
    memcpy(&baseAddress, ip.addr(), sizeof (Poco::UInt32));
    baseAddress = ntohl(baseAddress);
    unsigned count = pow(2, (32 - _netmask.prefixLength()));
    if (count > max) {
        count = max;
    }
    for (unsigned i = 0; i < count; ++i) {
        Poco::UInt32 address = ntohl(baseAddress);
        container.push_back(Poco::Net::IPAddress(&address, sizeof (Poco::UInt32)));
        baseAddress++;
    }
}