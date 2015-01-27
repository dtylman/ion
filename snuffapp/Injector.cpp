/*
 * File:   Injector.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 10:33 AM
 */

#include "Injector.h"
#include <Poco/Buffer.h>
#include <Poco/Format.h>
#include <Poco/Bugcheck.h>
#include <vector>

Injector::Injector(const std::string& device, const Poco::Net::IPAddress& sourceIP) :
_device(device), _srcIP(sourceIP)
{
    Poco::Buffer<char> errBuff(LIBNET_ERRBUF_SIZE);
    _libnet = libnet_init(LIBNET_LINK, device.c_str(), errBuff.begin());
    if (_libnet == nullptr) {
        throw Poco::ApplicationException(Poco::format("Cannot init libnet with %s %s", device, std::string(errBuff.begin())));
    }
    _srcMAC = libnet_get_hwaddr(_libnet);
}

Injector::~Injector()
{
    libnet_destroy(_libnet);
}

void Injector::arpRequest(const Poco::Net::IPAddress& targetIP)
{
    arpRequest(targetIP, MAC::Broadcast);
}

void Injector::arpRequest(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    libnet_ptag_t tag = libnet_autobuild_arp(ARPOP_REQUEST, _srcMAC->ether_addr_octet, (const uint8_t *) _srcIP.addr(), targetMAC.data(), (uint8_t*) targetIP.addr(), _libnet);
    if (tag == -1) {
        throw Poco::ApplicationException(Poco::format("Failed to build arp request: %s", libnet_geterror(_libnet)));

    }
    tag = libnet_autobuild_ethernet(targetMAC.data(), ETHERTYPE_ARP, _libnet);
    if (tag == -1) {
        throw Poco::ApplicationException(Poco::format("Failed to build arp eth header: %s", libnet_geterror(_libnet)));
    }
    int ret = libnet_write(_libnet);
    if (ret == -1) {
        throw Poco::ApplicationException(Poco::format("Failed to write arp request: %s", libnet_geterror(_libnet)));
    }
}

const std::string& Injector::device() const
{
    return _device;
}
