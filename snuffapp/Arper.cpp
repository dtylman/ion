/*
 * File:   Arper.cpp
 * Author: danny
 *
 * Created on January 26, 2015, 10:21 PM
 */

#include "Arper.h"
#include "Sniff/PcapSubsystem.h"
#include <Poco/Util/Application.h>
#include <libnet.h>

Arper::Arper()
{
}

Arper::~Arper()
{
}

void Arper::arp()
{
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    PcapSubsystem::Devices devices;
    pcap.getDevices(devices);
    for (auto device : devices) {
    }
}
