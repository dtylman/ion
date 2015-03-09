/*
 * File:   Injector.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 10:33 AM
 */

#include "Injector.h"
#include "LibnetException.h"
#include "IPData.h"
#include <Poco/Buffer.h>
#include <Poco/Format.h>
#include <Poco/Bugcheck.h>
#include <vector>
#include <net/ethernet.h>

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

void Injector::buildEhernet(const MAC& targetMAC, uint16_t type)
{
    libnet_ptag_t tag = libnet_autobuild_ethernet(targetMAC.data(), type, _libnet);
    if (tag == -1) {
        throw LibnetException("Failed to build arp eth header", _libnet);
    }
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
    buildEhernet(targetMAC, ETHERTYPE_ARP);
    write();
    _logger.trace("Sent ARP request to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::buildIP(const Poco::Net::IPAddress& targetIP, unsigned len, u_int8_t protocol)
{
    if (_srcIP.family() == Poco::Net::IPAddress::IPv4) {
        buildIPv4(targetIP, len, protocol);
    }
    else {
        buildIPv6(targetIP, len, protocol);
    }
}

void Injector::buildIPv4(const Poco::Net::IPAddress& targetIP, unsigned len, u_int8_t protocol)
{
    if (_srcIP.family() != Poco::Net::IPAddress::Family::IPv4) {
        throw Poco::InvalidArgumentException("Cannot build ipv4 packet for address %s", _srcIP.toString());
    }
    if (targetIP.family() != Poco::Net::IPAddress::Family::IPv4) {
        throw Poco::InvalidArgumentException("Cannot build ipv4 packet for address %s", targetIP.toString());
    }
    /* * @param ip_len total length of the IP packet including all subsequent data (subsequent
     *   data includes any IP options and IP options padding)
     * @param tos type of service bits
     * @param id IP identification number
     * @param frag fragmentation bits and offset
     * @param ttl time to live in the network
     * @param prot upper layer protocol
     * @param sum checksum (0 for libnet to autofill)
     * @param src source IPv4 address (little endian)
     * @param dst destination IPv4 address (little endian)
     * @param payload optional payload or NULL
     * @param payload_s payload length or 0
     * @param l pointer to a libnet context
     * @param ptag protocol tag to modify an existing header, 0 to build a new one
     * @return protocol tag value on success, -1 on error*/
    uint32_t src_ip = *((uint32_t*) _srcIP.addr());
    uint32_t tgt_ip = *((uint32_t*) targetIP.addr());
    libnet_ptag_t tag = libnet_build_ipv4(LIBNET_IPV4_H + len, 0, 242, 0, 64, protocol, 0, src_ip, tgt_ip, NULL, 0, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build ipv4 header", _libnet);
    }
}

void Injector::buildIPv6(const Poco::Net::IPAddress& targetIP, unsigned len, u_int8_t protocol)
{
    if (_srcIP.family() != Poco::Net::IPAddress::Family::IPv6) {
        throw Poco::InvalidArgumentException("Cannot build ipv6 packet for address %s", _srcIP.toString());
    }
    if (targetIP.family() != Poco::Net::IPAddress::Family::IPv6) {
        throw Poco::InvalidArgumentException("Cannot build ipv6 packet for address %s", targetIP.toString());
    }
    /**
     * Builds a version 6 RFC 2460 Internet Protocol (IP) header.
     * @param tc traffic class
     * @param fl flow label
     * @param len total length of the IP packet
     * @param nh next header
     * @param hl hop limit
     * @param src source IPv6 address
     * @param dst destination IPv6 address
     * @param payload optional payload or NULL
     * @param payload_s payload length or 0
     * @param l pointer to a libnet context
     * @param ptag protocol tag to modify an existing header, 0 to build a new one
     * @return protocol tag value on success, -1 on error
     */
    struct libnet_in6_addr src_ip = *((struct libnet_in6_addr*) _srcIP.addr());
    struct libnet_in6_addr tgt_ip = *((struct libnet_in6_addr*) targetIP.addr());
    libnet_ptag_t tag = libnet_build_ipv6(0, 0, LIBNET_ICMPV6_H + len, protocol, 64, src_ip, tgt_ip, NULL, 0, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build ipv6 header", _libnet);
    }
}

void Injector::icmpNSR(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    /**
     * Builds an IP version 6 RFC 2461 Internet Control Message Protocol (ICMP)
     * NDP neighbour solicitation header. Could be used with
     * libnet_build_icmpv6_ndp_opt() and ICMPV6_NDP_OPT_SLLA.
     * @param type type of ICMP packet (should be ND_NEIGHBOR_SOLICIT)
     * @param code code of ICMP packet (should be zero)
     * @param sum checksum (0 for libnet to autofill)
     * @param target target ipv6 address
     * @param payload optional payload or NULL
     * @param payload_s payload length or 0
     * @param l pointer to a libnet context
     * @param ptag protocol tag to modify an existing header, 0 to build a new one
     * @return protocol tag value on success, -1 on error
     */
    struct libnet_in6_addr tgt_ip = *((struct libnet_in6_addr*) targetIP.addr());
    libnet_ptag_t tag = libnet_build_icmpv6_ndp_nsol(ND_NEIGHBOR_SOLICIT, 0, 0, tgt_ip, nullptr, 0, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build neighbour solicitation request", _libnet);
    }
    buildIPv6(targetIP, LIBNET_ICMPV6_NDP_NSOL_H, IPPROTO_ICMPV6);
    buildEhernet(targetMAC, ETHERTYPE_IPV6);
    write();
    _logger.trace("Sent neighbour solicitation request to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::icmpTimestamp(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    /**
     * Builds an IP version 4 RFC 792 Internet Control Message Protocol (ICMP)
     * timestamp request/reply header.
     * @param type type of ICMP packet (should be ICMP_TSTAMP or ICMP_TSTAMPREPLY)
     * @param code code of ICMP packet (should be 0)
     * @param sum checksum (0 for libnet to autofill)
     * @param id identification number
     * @param seq sequence number
     * @param otime originate timestamp
     * @param rtime receive timestamp
     * @param ttime transmit timestamp
     * @param payload optional payload or NULL
     * @param payload_s payload length or 0
     * @param l pointer to a libnet context
     * @param ptag protocol tag to modify an existing header, 0 to build a new one
     * @return protocol tag value on success, -1 on error
     */
    uint16_t id = (uint16_t) libnet_get_prand(LIBNET_PR16);
    uint32_t otime = 0;
    uint32_t rtime = 0;
    uint32_t ttime = 0;
    libnet_ptag_t tag = libnet_build_icmpv4_timestamp(ICMP_TSTAMP, 0, 0, id, 1, otime, rtime, ttime, nullptr, 0, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build icmp timestamp request", _libnet);
    }
    buildIPv4(targetIP, LIBNET_ICMPV4_TS_H, IPPROTO_ICMP);
    buildEhernet(targetMAC, ETHERTYPE_IP);
    write();
    _logger.trace("Sent timestamp request to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::icmpMask(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    /**
     * Builds an IP version 4 RFC 792 Internet Control Message Protocol (ICMP)
     * IP netmask request/reply header.
     * @param type type of ICMP packet (should be ICMP_MASKREQ or ICMP_MASKREPLY)
     * @param code code of ICMP packet (should be 0)
     * @param sum checksum (0 for libnet to autofill)
     * @param id identification number
     * @param seq packet sequence number
     * @param mask subnet mask
     * @param payload optional payload or NULL
     * @param payload_s payload length or 0
     * @param l pointer to a libnet context
     * @param ptag protocol tag to modify an existing header, 0 to build a new one
     * @return protocol tag value on success, -1 on error
     */
    uint32_t mask = 0xFF00;
    uint16_t id = (uint16_t) libnet_get_prand(LIBNET_PR16);
    libnet_ptag_t tag = libnet_build_icmpv4_mask(ICMP_MASKREQ, 0, 0, id, 1, mask, nullptr, 0, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build icmp mask request", _libnet);
    }
    buildIPv4(targetIP, LIBNET_ICMPV4_MASK_H, IPPROTO_ICMP);
    buildEhernet(targetMAC, ETHERTYPE_IP);
    write();
    _logger.trace("Sent mask request to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::icmpEcho(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    uint16_t id = (uint16_t) libnet_get_prand(LIBNET_PR16);
    libnet_ptag_t tag = libnet_build_icmpv4_echo(ICMP_ECHO, 0, 0, id, 1, nullptr, 0, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build icmp echo request", _libnet);
    }
    buildIPv4(targetIP, LIBNET_ICMPV4_ECHO_H, IPPROTO_ICMP);
    buildEhernet(targetMAC, ETHERTYPE_IP);
    write();
    _logger.trace("Sent echo request to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::icmpEcho6(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    char payload[56];
    int i;
    for (i = 0; i < 56; i++) payload[i] = 'A' + ((char) (i % 26));
    libnet_ptag_t tag = libnet_build_icmpv6_echo(ICMP6_ECHO_REQUEST, 0, 0, 1, 0, (uint8_t*) payload, sizeof (payload), _libnet, 0);
    if (tag == 11) {
        throw LibnetException("Failed to build icmpv6 echo request", _libnet);
    }
    buildIPv6(targetIP, LIBNET_ICMPV6_ECHO_H, IPPROTO_ICMP6);
    buildEhernet(targetMAC, ETHERTYPE_IPV6);
    if (tag == -1) {
        throw LibnetException("Failed to build eth header", _libnet);
    }
    write();
    _logger.trace("Sent ipv6 echo request to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::udp(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC, uint16_t port, const std::string& payload)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    buildUDP(44222, port, payload);
    buildIP(targetIP, LIBNET_UDP_H, IPPROTO_UDP);
    if (_srcIP.family() == Poco::Net::IPAddress::IPv4) {
        buildEhernet(targetMAC, ETHERTYPE_IP);
    }
    else {
        buildEhernet(targetMAC, ETHERTYPE_IPV6);
    }
    write();
    _logger.trace("Sent udp to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::tcpSyn(const Poco::Net::IPAddress& targetIP, const MAC& targetMAC, uint16_t port)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    libnet_clear_packet(_libnet);
    buildTCP(44222, port, TH_SYN);
    buildIP(targetIP, LIBNET_TCP_H, IPPROTO_TCP);
    if (_srcIP.family() == Poco::Net::IPAddress::IPv4) {
        buildEhernet(targetMAC, ETHERTYPE_IP);
    }
    else {
        buildEhernet(targetMAC, ETHERTYPE_IPV6);
    }
    write();
    _logger.trace("Sent tcp syn to %s %s", targetMAC.toString(), targetIP.toString());
}

void Injector::buildTCP(uint16_t srcPort, uint16_t destPort, uint8_t flags, const std::string& payload)
{
    /**
     * Builds an RFC 793 Transmission Control Protocol (TCP) header.
     * @param sp source port
     * @param dp destination port
     * @param seq sequence number
     * @param ack acknowledgement number
     * @param control control flags
     * @param win window size
     * @param sum checksum (0 for libnet to autofill)
     * @param urg urgent pointer
     * @param len total length of the TCP packet (for checksum calculation)
     * @param payload
     * @param payload_s payload length or 0
     * @param l pointer to a libnet context
     * @param ptag protocol tag to modify an existing header, 0 to build a new one
     * @return protocol tag value on success, -1 on error
     */
    uint8_t* payloadPtr = nullptr;
    uint16_t payloadLen = 0;
    if (!payload.empty()) {
        payloadPtr = (uint8_t*) payload.c_str();
        payloadLen = payload.length();
    }
    libnet_ptag_t tag = libnet_build_tcp(srcPort, destPort, 0x01010101, 0x02020202, flags, 32767, 0, 10, LIBNET_TCP_H + 20 + payloadLen, payloadPtr, payloadLen, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build tcp header", _libnet);
    }
}

void Injector::buildUDP(uint16_t srcPort, uint16_t destPort, const std::string& payload)
{

    /**
     * Builds an RFC 768 User Datagram Protocol (UDP) header.
     * @param sp source port
     * @param dp destination port
     * @param len total length of the UDP packet
     * @param sum checksum (0 for libnet to autofill)
     * @param payload optional payload or NULL
     * @param payload_s payload length or 0
     * @param l pointer to a libnet context
     * @param ptag protocol tag to modify an existing header, 0 to build a new one
     * @return protocol tag value on success, -1 on error
     */
    uint8_t* payloadPtr = nullptr;
    uint16_t payloadLen = 0;
    if (!payload.empty()) {
        payloadPtr = (uint8_t*) payload.c_str();
        payloadLen = payload.length();
    }
    libnet_ptag_t tag = libnet_build_udp(srcPort, destPort, LIBNET_UDP_H + payloadLen, 0, payloadPtr, payloadLen, _libnet, 0);
    if (tag == -1) {
        throw LibnetException("Failed to build udp header", _libnet);
    }
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
