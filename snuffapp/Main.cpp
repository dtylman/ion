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
#include "Injector.h"
#include "Arping.h"
#include "Routing.h"
#include "IPDataObserver.h"
#include "AutoJSONConfiguration.h"
#include <iostream>
#include <Poco/Util/TimerTaskAdapter.h>

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
    _solicitator.arpAll();
    waitForTerminationRequest();
    return EXIT_OK;
}

void Main::addRouters()
{
    Routing routing;
    const Routing::Gateways& gateways = routing.gateways();
    PcapSubsystem& pcap = getSubsystem<PcapSubsystem>();
    DataSubsystem& data = getSubsystem<DataSubsystem>();
    IPDataObject ipDAO(data.createSession());
    for (auto gateway : gateways) {
        try {
            PcapDevice pcapDevice = pcap.getDevice(gateway.second);
            const Poco::Net::IPAddress& gwIP = gateway.first;
            Poco::Net::IPAddress src = pcapDevice.getIPAddress(Poco::Net::IPAddress::IPv4);
            Injector injector(pcapDevice.pcapName(), src);
            ipDAO.addIP(src, injector.deviceMACAddress(), pcapDevice.pcapName());
            logger().information("Adding address %s %s %s", src.toString(), injector.deviceMACAddress().toString(), pcapDevice.pcapName());
            Arping arping(injector, gwIP);
            if (arping.ping()) {
                const MAC& gwMAC = arping.targetMAC();
                logger().information("Adding router %s %s Gw IP %s mac %s", pcapDevice.pcapName(), src.toString(), gwIP.toString(), gwMAC.toString());
                ipDAO.addRouter(gwIP, gwMAC, pcapDevice.pcapName());
            }
        }
        catch (Poco::Exception& ex) {
            logger().error(ex.displayText());
        }
    }
}

void Main::initialize(Poco::Util::Application& self)
{
    loadConfiguration();
    Poco::Util::ServerApplication::initialize(self);
    unsigned interval = config().getUInt("ion.offline-interval", 10) * 60 * 1000;
    _timer.scheduleAtFixedRate(new Poco::Util::TimerTaskAdapter<Main>(*this, &Main::onOnlineScan), interval, interval);
}

void Main::onOnlineScan(Poco::Util::TimerTask& timerTask)
{
    _solicitator.arpOnline();
}

int Main::loadConfiguration(int priority)
{
    Poco::Path path = config().getString("application.configDir");
    path.pushDirectory("config");
    Poco::File file(path);
    file.createDirectories();
    config().setString("application.configDir", path.toString());
    config().add(new AutoJSONConfiguration(path, "ion.config.json"), priority);
    return 1;
}

POCO_SERVER_MAIN(Main)
