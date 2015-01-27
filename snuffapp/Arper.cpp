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

Arper::Arper()
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

    Poco::Net::IPAddress targetIP("192.168.10.8");
    uint8_t bcast[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    //    libnet_ptag_t tag = libnet_autobuild_arp(ARPOP_REQUEST, bcast, (uint8_t*) srcIP.addr(), bcast, libnet);
}
