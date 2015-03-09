/*
 * File:   Selfy.cpp
 * Author: danny
 *
 * Created on February 4, 2015, 10:26 AM
 */

#include "Selfy.h"
#include "DataSubsystem.h"
#include "PcapSubsystem.h"
#include "Routing.h"
#include "Injector.h"
#include "Arping.h"
#include "IONDataObject.h"
#include <Poco/Util/Application.h>

Selfy::Selfy() : _logger(Poco::Logger::get("Selfy"))
{
}

Selfy::~Selfy()
{
}

void Selfy::report()
{
    reportNetworkConfig();
    reportRouters();
}

void Selfy::reportNetworkConfig()
{
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    PcapSubsystem::Devices devices;
    pcap.getAllDevices(devices);
    ThingData thingData;
    Poco::Util::AbstractConfiguration& config = Poco::Util::Application::instance().config();
    thingData.setName(config.getString("system.nodeName"));
    thingData.setOS(config.getString("system.osName"));
    thingData.setType("Computer");	
	for (auto device : devices) {
        Poco::Net::IPAddress ip = device.getIPAddress(Poco::Net::IPAddress::IPv4);
        reportIPConfig(ip, device.pcapName(), thingData);
        ip = device.getIPAddress(Poco::Net::IPAddress::IPv6);
        reportIPConfig(ip, device.pcapName(), thingData);
    }

}

void Selfy::reportIPConfig(const Poco::Net::IPAddress& ip, const std::string& pcapName, ThingData& myThing)
{
    if (ip.isUnicast()) {
        try {
            MAC mac = Poco::Net::NetworkInterface::forAddress(ip).macAddress();
            DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
            IONDataObject ion(data.createSession());
			ion.getThingByMAC(mac, myThing);
            IPData ipData(mac, ip, pcapName);
            ion.setIP(ipData);
        }
        catch (Poco::NotFoundException&) {
            _logger.notice("No MAC for %s %s", ip.toString(), pcapName);
        }
    }
}

void Selfy::reportRouters()
{
    Routing routing;
    const Routing::Gateways& gateways = routing.gateways();
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
    IONDataObject ion(data.createSession());
    for (auto gateway : gateways) {
        try {
            PcapDevice pcapDevice = pcap.getDevice(gateway.second);
            const Poco::Net::IPAddress& gwIP = gateway.first;
            Poco::Net::IPAddress src = pcapDevice.getIPAddress(Poco::Net::IPAddress::IPv4);
            Injector injector(pcapDevice.pcapName(), src);
            //move from here
            ion.setIP(IPData(injector.deviceMACAddress(), src, pcapDevice.pcapName()));
            _logger.information("Adding address %s %s %s", src.toString(), injector.deviceMACAddress().toString(), pcapDevice.pcapName());
            //move from here -- end
            Arping arping(injector, gwIP);
            if (arping.ping()) {
                const MAC& gwMAC = arping.targetMAC();
                _logger.information("Adding router %s %s Gw IP %s mac %s", pcapDevice.pcapName(), src.toString(), gwIP.toString(), gwMAC.toString());
                ion.setRouter(gwIP, gwMAC, pcapDevice.pcapName());
            }
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
    }
}

