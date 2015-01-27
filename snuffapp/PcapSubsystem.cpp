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
        std::string device(iface->name);
        if (device == "any") {
            iface = iface->next;
            continue;
        }

        PcapIfaceAddress::Container addresses;
        pcap_addr* address = iface->addresses;
        while (address != nullptr) {
            addresses.push_back(PcapIfaceAddress(address));
            address = address->next;
        }
        _logger.information("Adding device: %s ", device);
        _activities[device] = new PcapActivity(device, addresses);
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

bool PcapSubsystem::inject(const std::string& iface, const Poco::UInt8* data, int len)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    ActivityContainer::iterator activity = _activities.find(iface);
    if (activity == _activities.end()) {
        return false;
    }
    return activity->second->inject(data, len);
}

void PcapSubsystem::injectAll(const Poco::UInt8* data, int len)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    for (auto activity : _activities) {
        activity.second->inject(data, len);
    }
}

void PcapSubsystem::getDevices(Devices& devices)
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    for (auto activity : _activities) {
        devices[activity.first] = activity.second->addresses();
    }
}
