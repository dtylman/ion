/*
 * File:   Selfy.cpp
 * Author: danny
 *
 * Created on February 4, 2015, 10:26 AM
 */

#include "Selfy.h"
#include "DataSubsystem.h"
#include "IPDataObject.h"
#include "ThingDataObject.h"
#include "PcapSubsystem.h"
#include "Routing.h"
#include "Injector.h"
#include "Arping.h"
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
    for (auto device : devices) {
        Poco::Net::IPAddress ip = device.getIPAddress(Poco::Net::IPAddress::IPv4);
        reportIPConfig(ip, device.pcapName());
        ip = device.getIPAddress(Poco::Net::IPAddress::IPv6);
        reportIPConfig(ip, device.pcapName());
    }

}

void Selfy::reportIPConfig(const Poco::Net::IPAddress& ip, const std::string& pcapName)
{
    if (ip.isUnicast()) {
        try {
            MAC mac = Poco::Net::NetworkInterface::forAddress(ip).macAddress();
            DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
            IPDataObject ipDAO(data.createSession());
            ipDAO.addIP(ip, mac, pcapName);
            ThingDataObject thing(data.createSession());
            if (!thing.exists(mac)) {
                Poco::Util::AbstractConfiguration& config = Poco::Util::Application::instance().config();
                thing.setName(mac, config.getString("system.nodeName"));
                thing.setOS(mac, config.getString("system.osName"));
                thing.setType(mac, "Computer");
            }
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
    IPDataObject ipDAO(data.createSession());
    ThingDataObject thingDAO(data.createSession());
    for (auto gateway : gateways) {
        try {
            PcapDevice pcapDevice = pcap.getDevice(gateway.second);
            const Poco::Net::IPAddress& gwIP = gateway.first;
            Poco::Net::IPAddress src = pcapDevice.getIPAddress(Poco::Net::IPAddress::IPv4);
            Injector injector(pcapDevice.pcapName(), src);
            //move from here
            ipDAO.addIP(src, injector.deviceMACAddress(), pcapDevice.pcapName());
            _logger.information("Adding address %s %s %s", src.toString(), injector.deviceMACAddress().toString(), pcapDevice.pcapName());
            //move from here -- end
            Arping arping(injector, gwIP);
            if (arping.ping()) {
                const MAC& gwMAC = arping.targetMAC();
                _logger.information("Adding router %s %s Gw IP %s mac %s", pcapDevice.pcapName(), src.toString(), gwIP.toString(), gwMAC.toString());
                ipDAO.addRouter(gwIP, gwMAC, pcapDevice.pcapName());
                thingDAO.setType(gwMAC, "Router");
            }
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
    }
}

