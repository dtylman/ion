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

void Selfy::reportNetworkConfig()
{
    updateMyAddresses();
    updateMyThing();
}

void Selfy::findRouters()
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
            Poco::Net::IPAddress deviceIP = pcapDevice.getIPAddress(Poco::Net::IPAddress::IPv4);
            Injector injector(pcapDevice.pcapName(), deviceIP);
            Arping arping(injector, gwIP);
            if (arping.ping()) {
                const MAC& gwMAC = arping.targetMAC();
                _logger.information("Adding router %s %s Gw IP %s mac %s", pcapDevice.pcapName(), deviceIP.toString(), gwIP.toString(), gwMAC.toString());
                ion.setRouter(gwIP, gwMAC, pcapDevice.pcapName());
            }
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
    }
}

void Selfy::updateMyThing()
{
    ThingData mything;
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    PcapSubsystem::Devices devices;
    pcap.getAllDevices(devices);
    DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
    IONDataObject ion(data.createSession());
    for (auto device : devices) {
        try {
            MAC mac = device.getMACAddress();
            if (ion.getThingByMAC(mac, mything)) {
                break;
            }
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
    }
    Poco::Util::AbstractConfiguration& config = Poco::Util::Application::instance().config();
    mything.setName(config.getString("system.nodeName"));
    mything.setOS(config.getString("system.osName"));
    mything.setType("Computer");
    mything.setDesc("ION machine");
    ion.setThing(mything, true);
}

void Selfy::updateMyAddresses()
{
    DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    PcapSubsystem::Devices devices;
    pcap.getAllDevices(devices);
    IONDataObject ion(data.createSession());
    IPData ipData;
    for (auto device : devices) {
        try {
            ipData.setMAC(device.getMACAddress());
            ipData.setIface(device.pcapName());
            ipData.setIP(device.getIPAddress(Poco::Net::IPAddress::IPv4));
            ion.setOnline(ipData);
            ipData.setIP(device.getIPAddress(Poco::Net::IPAddress::IPv6));
            ion.setOnline(ipData);
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
    }
}
