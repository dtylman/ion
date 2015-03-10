/*
 * File:   PcapSubsystem.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:35 PM
 */

#include "PcapSubsystem.h"
#include "PcapIfaceAddress.h"
#include <Poco/Logger.h>
#include <Poco/Buffer.h>
#include <Poco/Exception.h>
#include <Poco/Format.h>
#include <Poco/Net/IPAddress.h>
#include <string>

PcapSubsystem::PcapSubsystem() : _logger(Poco::Logger::get("PcapSubsystem"))
{
}

PcapSubsystem::~PcapSubsystem()
{
}

void PcapSubsystem::start()
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    for (auto activity : _activities) {
        activity.second->start();
    }
}

void PcapSubsystem::initialize(Poco::Util::Application& app)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    Poco::Buffer<char> errBuff(PCAP_ERRBUF_SIZE);
    pcap_if_t *iface = nullptr;
    if (pcap_findalldevs(&iface, errBuff.begin()) < 0) {
        throw Poco::ApplicationException(Poco::format("pcap_findalldevs failed. Error: %s", std::string(errBuff.begin())));
    }
    while (iface != nullptr) {
        if (iface->flags & PCAP_IF_LOOPBACK) {
            iface = iface->next;
            continue;
        }
        if (iface->name == nullptr) {
            iface = iface->next;
            continue;
        }
        PcapDevice pcapDevice;
        if (iface->description == nullptr) {
            pcapDevice.setName(iface->name, iface->name);
        }
        else {
            pcapDevice.setName(iface->name, iface->description);
        }
        if (pcapDevice.pcapName() == "any") {
            iface = iface->next;
            continue;
        }
        pcap_addr* address = iface->addresses;
        while (address != nullptr) {
            pcapDevice.addAddress(PcapIfaceAddress(address));
            address = address->next;
        }
        _logger.information("Adding device: %s ", pcapDevice.toString());
        _activities[pcapDevice.pcapName()] = new PcapActivity(pcapDevice.pcapName());
        _devices.push_back(pcapDevice);
        iface = iface->next;
    }
    pcap_freealldevs(iface);
}

const char* PcapSubsystem::name() const
{
    return "PcapSubsystem";
}

void PcapSubsystem::uninitialize()
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    _logger.notice("PcapSubsystem::uninitialize");
    for (auto activity : _activities) {
        activity.second->stop();
    }
}

PcapDevice PcapSubsystem::getDevice(const std::string& name) const
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    for (auto device : _devices) {
        if ((device.pcapName() == name) || (device.systemName() == name)) {
            return device;
        }
    }
    throw Poco::NotFoundException(Poco::format("Device %s not found", name));
}

void PcapSubsystem::getAllDevices(Devices& devices)
{
    devices.clear();
    Poco::FastMutex::ScopedLock lock(_mutex);
    devices.insert(devices.begin(), _devices.begin(), _devices.end());
}
