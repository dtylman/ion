/*
 * File:   ZakifApp.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */


#include "Main.h"
#include "PcapSubsystem.h"
#include "DissectSubsystem.h"
#include "ModelSubsystem.h"
#include "MAC.h"
#include "Arper.h"
#include "Injector.h"
#include "Arping.h"
#include <iostream>

Main::Main()
{
    addSubsystem(new ModelSubsystem());
    addSubsystem(new DissectSubsystem());
    addSubsystem(new PcapSubsystem());
}

Main::~Main()
{
}

int Main::main(const std::vector<std::string>& args)
{
    PcapSubsystem& pcap = getSubsystem<PcapSubsystem>();
    pcap.start();
    PcapSubsystem::Devices devices;
    pcap.getDevices(devices);
    for (auto device : devices) {
        logger().notice("Looking for routers on %s", device.first);
        for (auto pcapAddr : device.second) {
            const Poco::Net::IPAddress& broadcastAddr = pcapAddr.broadcast();
            if (broadcastAddr.isUnicast()) {
                if (broadcastAddr.af() == Poco::Net::IPAddress::IPv4) {
                    Injector injector(device.first, pcapAddr.ip());
                    Arping arping(injector, broadcastAddr);
                    if (arping.ping()) {
                        logger().notice("Device %s broadcast ip %s mac %s", device.first, broadcastAddr.toString(), arping.targetMAC().toString());
                    }
                }
            }
        }
    }
    waitForTerminationRequest();
    return EXIT_OK;
}

POCO_SERVER_MAIN(Main)