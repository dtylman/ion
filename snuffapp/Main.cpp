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
#include "Routing.h"
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
    Routing routing;
    const Routing::Gateways& gateways = routing.gateways();
    for (auto gateway : gateways) {
		PcapDevice pcapDevice = pcap.getDevice(gateway.second);
        const Poco::Net::IPAddress& gw = gateway.first;
        Poco::Net::IPAddress src = pcapDevice.getIPAddress(Poco::Net::IPAddress::IPv4);
		Injector injector(pcapDevice.pcapName(), src);
        Arping arping(injector, gw);
        if (arping.ping()) {
            logger().notice("Device %s %s Gw IP %s mac %s", pcapDevice.pcapName(), src.toString(), gw.toString(), arping.targetMAC().toString());
        }
    }
    waitForTerminationRequest();
    return EXIT_OK;
}

POCO_SERVER_MAIN(Main)