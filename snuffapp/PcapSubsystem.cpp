/*
 * File:   PcapSubsystem.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:35 PM
 */

#include "PcapSubsystem.h"
#include "PcapActivityFactory.h"
#include <Poco/Logger.h>
#include <Poco/Buffer.h>
#include <Poco/Exception.h>
#include <Poco/Format.h>
#include <string>

PcapSubsystem::PcapSubsystem() : _logger(Poco::Logger::get("PcapSubsystem"))
{
}

PcapSubsystem::~PcapSubsystem()
{
}

void PcapSubsystem::initialize(Poco::Util::Application& app)
{
    Poco::Buffer<char> errBuff(PCAP_ERRBUF_SIZE);
    pcap_if_t *iface = nullptr;
    if (pcap_findalldevs(&iface, errBuff.begin()) < 0) {
        throw Poco::ApplicationException(Poco::format("pcap_findalldevs failed. Error: %s", std::string(errBuff.begin())));
    }
    while (iface != nullptr) {
        _logger.information(iface->name);
        PcapActivity::Ptr activity = PcapActivityFactory::createActivity(iface);
        if (!activity.isNull()) {
            _activities.push_back(activity);
        }
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
    _activities.clear();
}
