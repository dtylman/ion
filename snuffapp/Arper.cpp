/*
 * File:   Arper.cpp
 * Author: danny
 *
 * Created on January 26, 2015, 10:21 PM
 */

#include "Arper.h"
#include "PcapSubsystem.h"
#include <Poco/Util/Application.h>
#include <libnet.h>
#include <Poco/Buffer.h>
#include "MAC.h"

Arper::Arper() : _logger(Poco::Logger::get("Arper"))
{
}

Arper::~Arper()
{
}

void Arper::arp()
{
    //    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    //    PcapSubsystem::Devices devices;
    //    pcap.getDevices(devices);
    //    for (auto device : devices) {
    //
    //    }
    Poco::Buffer<char> errBuff(LIBNET_ERRBUF_SIZE);
    std::string device = "wlan0";
    libnet_t* libnet = libnet_init(LIBNET_LINK, device.c_str(), errBuff.begin());
    poco_check_ptr(libnet);
    //    MAC sender;
    //    MAC recevier;
    const libnet_ether_addr* src = libnet_get_hwaddr(libnet);
    //parameters are: sender mac, sender ip, target mac (if unicast or fffffff if unknown), target ip
    Poco::Net::IPAddress srcIP("192.168.10.4");
    MAC srcMAC("00:00:00:00:00:01");
    Poco::Net::IPAddress targetIP("192.168.10.8");
    libnet_ptag_t tag = libnet_autobuild_arp(ARPOP_REQUEST, srcMAC.data(), (const uint8_t*) srcIP.addr(), MAC::Broadcast.data(), (uint8_t*) targetIP.addr(), libnet);
    if (tag == -1) {
        _logger.error(libnet_geterror(libnet));
    }
    tag = libnet_autobuild_ethernet(MAC::Broadcast.data(), ETHERTYPE_ARP, libnet);
    if (tag == -1) {
        _logger.error(libnet_geterror(libnet));
    }
    int ret = libnet_write(libnet);
    if (ret == -1) {
        _logger.error(libnet_geterror(libnet));
        //error
    }
    libnet_destroy(libnet);
}
