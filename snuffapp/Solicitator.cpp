/*
 * File:   Solicitator.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 11:13 AM
 */

#include "Solicitator.h"
#include "PcapSubsystem.h"
#include "Injector.h"
#include "DataSubsystem.h"
#include "IPDataObject.h"
#include "Arping.h"
#include <Poco/Util/Application.h>

Solicitator::Solicitator() : _logger(Poco::Logger::get("Solicitator"))
{
}

Solicitator::~Solicitator()
{
}

void Solicitator::arpAll()
{
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    PcapSubsystem::Devices pcapDevices;
    pcap.getAllDevices(pcapDevices);
    for (auto pcapDevice : pcapDevices) {
        for (auto address : pcapDevice.addresses()) {
            const Poco::Net::IPAddress& ip = address.ip();
            if ((ip.family() == Poco::Net::IPAddress::IPv4) && (ip.isUnicast()) && (!ip.isLinkLocal())) {
                try {
                    Injector injector(pcapDevice.pcapName(), ip);
                    PcapIfaceAddress::IPContainer ips;
                    address.fillAllIPs(ips);
                    for (auto ip : ips) {
                        injector.arpRequest(ip);
                        Poco::Thread::sleep(50); //throttle this a bit
                    }
                }
                catch (Poco::Exception&ex) {
                    _logger.error("Failed to send ARP for device %s: %s", pcapDevice.toString(), ex.displayText());
                }
            }
        }
    }
}

void Solicitator::arpOnline()
{
    DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
    IPDataObject dao(data.createSession());
    IPData::Container ipContainer;
    dao.findOnline(ipContainer);
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    for (auto data : ipContainer) {
        if (data.ip().family() == Poco::Net::IPAddress::IPv4) {
            PcapDevice device = pcap.getDevice(data.iface());
            Poco::Net::IPAddress srcIP = device.getIPAddress(data.ip().family());
            Injector injector(device.pcapName(), srcIP);
            Arping arping(injector, data.ip(), data.mac());
            if (!arping.ping()) {
                //device offline!
                _logger.notice("IP %s offline", data.ip().toString());
            }
            else {
                _logger.debug("IP %s online", data.ip().toString());
            }
        }
    }

}
