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
#include "Arping.h"
#include "IONDataObject.h"
#include <Poco/Util/Application.h>

Solicitator::Solicitator() : _logger(Poco::Logger::get("Solicitator"))
{
}

Solicitator::~Solicitator()
{
}

void Solicitator::solicitateAll()
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

void Solicitator::solicitateOnline()
{
    DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
    IONDataObject ion(data.createSession());
    IPData::Container ipContainer;
    ion.findOnlineIPs(ipContainer);
    for (auto data : ipContainer) {
        bool pong = false;
        if (data.ip().family() == Poco::Net::IPAddress::IPv4) {
            _logger.debug("Arping %s", data.toString());
            pong = arpPing(data);
        }
        else {
            //nsr(data); //neighbour solicitation request?
        }
        if (!pong) {
            _logger.debug("No reply from %s", data.toString());
            ion.setOffline(data);
        }
        else {
            _logger.debug("Pong from %s", data.toString());
        }
    }
}

bool Solicitator::arpPing(const IPData& data)
{
    PcapSubsystem& pcap = Poco::Util::Application::instance().getSubsystem<PcapSubsystem>();
    PcapDevice device = pcap.getDevice(data.iface());
    Poco::Net::IPAddress srcIP = device.getIPAddress(data.ip().family());
    Injector injector(device.pcapName(), srcIP);
    Arping arping(injector, data.ip(), data.mac());
    return arping.ping();
}
