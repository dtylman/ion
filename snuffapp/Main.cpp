/*
 * File:   ZakifApp.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */


#include "Main.h"
#include "PcapSubsystem.h"
#include "DissectSubsystem.h"
#include "DataSubsystem.h"
#include "MAC.h"
#include "Arper.h"
#include "Injector.h"
#include "Arping.h"
#include "Routing.h"
#include "IPDataObserver.h"
#include <iostream>

Main::Main()
{
    addSubsystem(new DataSubsystem());
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
    addRouters();
    arpAll();
    waitForTerminationRequest();
    return EXIT_OK;
}

void Main::addRouters()
{
    Routing routing;
    const Routing::Gateways& gateways = routing.gateways();
    PcapSubsystem& pcap = getSubsystem<PcapSubsystem>();
    DataSubsystem& data = getSubsystem<DataSubsystem>();
    IPDataObject ipDao(data.createSession());
    for (auto gateway : gateways) {
        try {
            PcapDevice pcapDevice = pcap.getDevice(gateway.second);
            const Poco::Net::IPAddress& gwIP = gateway.first;
            Poco::Net::IPAddress src = pcapDevice.getIPAddress(Poco::Net::IPAddress::IPv4);
            Injector injector(pcapDevice.pcapName(), src);
            ipDao.addAddress(src, injector.deviceMACAddress(), pcapDevice.pcapName());
            logger().notice("Adding address %s %s %s", src.toString(), injector.deviceMACAddress().toString(), pcapDevice.pcapName());
            Arping arping(injector, gwIP);
            if (arping.ping()) {
                const MAC& gwMAC = arping.targetMAC();
                logger().notice("Adding router %s %s Gw IP %s mac %s", pcapDevice.pcapName(), src.toString(), gwIP.toString(), gwMAC.toString());
                ipDao.addRouter(gwIP, gwMAC, pcapDevice.pcapName());
            }
        }
        catch (Poco::Exception& ex) {
            logger().error(ex.displayText());
        }
    }
}

void Main::arpAll()
{
    PcapSubsystem& pcap = getSubsystem<PcapSubsystem>();
    PcapSubsystem::Devices pcapDevices;
    pcap.getAllDevices(pcapDevices);
    for (auto pcapDevice : pcapDevices) {
        for (auto address : pcapDevice.addresses()) {
            const Poco::Net::IPAddress& ip = address.ip();
            if ((ip.family() == Poco::Net::IPAddress::IPv4) && (ip.isUnicast()) && (!ip.isLinkLocal())) {
                Injector injector(pcapDevice.pcapName(), ip);
                PcapIfaceAddress::IPContainer ips;
                address.fillAllIPs(ips);
                for (auto ip : ips) {
                    injector.arpRequest(ip);
                    Poco::Thread::sleep(50); //throttle this a bit
                }
            }
        }
    }
}

POCO_SERVER_MAIN(Main)