/*
 * File:   Injector.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 10:33 AM
 */

#include "Injector.h"
#include "LibnetException.h"
#include <Poco/Buffer.h>
#include <Poco/Format.h>
#include <Poco/Bugcheck.h>
#include <vector>

Injector::Injector(const std::string& device, const Poco::Net::IPAddress& sourceIP) :
_device(device), _srcIP(sourceIP), _logger(Poco::Logger::get("Injector"))
{
    Poco::Buffer<char> errBuff(LIBNET_ERRBUF_SIZE);
    _libnet = libnet_init(LIBNET_LINK, device.c_str(), errBuff.begin());
    if (_libnet == nullptr) {
        throw Poco::ApplicationException(Poco::format("Cannot init libnet with %s %s", device, std::string(errBuff.begin())));
    }
    libnet_seed_prand(_libnet);
    _srcMAC = libnet_get_hwaddr(_libnet);
    _logger.debug("Created inject for %s: source: %s ", device, sourceIP.toString());
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
        throw LibnetException("Failed to build arp request", _libnet);
    }
    tag = libnet_autobuild_ethernet(targetMAC.data(), ETHERTYPE_ARP, _libnet);
    if (tag == -1) {
        throw LibnetException("Failed to build arp eth header", _libnet);
    }
    write();
    _logger.trace("Sent ARP request to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::icmpEcho(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);

    uint16_t id = (uint16_t) libnet_get_prand(LIBNET_PR16);
    std::string payload = "hello world";
    libnet_ptag_t tag = libnet_build_icmpv4_echo(ICMP_ECHO, 0, 0, id, 1, (const uint8_t*) payload.c_str(), payload.length(), _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build icmp echo request", _libnet);
    }
    uint32_t* dest = (uint32_t*) targetIP.addr();
    tag = libnet_autobuild_ipv4(LIBNET_IPV4_H + LIBNET_ICMPV4_ECHO_H, IPPROTO_ICMP, *dest, _libnet);
    if (tag == -1) {
        throw LibnetException("Failed to build ipv4 header", _libnet);
    }
    tag = libnet_autobuild_ethernet(targetMAC.data(), ETHERTYPE_IP, _libnet);
    if (tag == -1) {
        throw LibnetException("Failed to build eth header", _libnet);
    }
    write();
    _logger.trace("Sent echo request to %s %s", targetMAC.toString(), targetIP.toString());
}

const std::string& Injector::device() const
{
    return _device;
}

MAC Injector::deviceMACAddress() const
{
    return MAC(_srcMAC->ether_addr_octet);
}

void Injector::write()
{
    int ret = libnet_write(_libnet);
    if (ret == -1) {
        throw LibnetException("Failed to write packet", _libnet);
    }
    libnet_clear_packet(_libnet);
}
