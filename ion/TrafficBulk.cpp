/*
 * File:   TrafficBulk.cpp
 * Author: danny
 *
 * Created on March 11, 2015, 3:41 PM
 */

#include "TrafficBulk.h"
#include "PcapSubsystem.h"
#include "ScopedTransaciton.h"
#include "NetStat.h"
#include <Poco/Util/Application.h>
#include <Poco/Net/DNS.h>

using namespace Poco::Data::Keywords;

TrafficBulk::TrafficBulk(const Poco::Data::Session& session) : _activity(this, &TrafficBulk::bulkUpdate), DataObject(session),
_logger(Poco::Logger::get("TrafficBulk"))
{
    PcapSubsystem::Devices devices;
    Poco::Util::Application::instance().getSubsystem<PcapSubsystem>().getAllDevices(devices);
    for (auto device : devices) {
        try {
            _selfMACs.insert(device.getMACAddress());
            _logger.debug("Adding self mac: %s", device.getMACAddress().toString());
        }
        catch (Poco::Exception& ex) {
            _logger.warning("Cannot find mac address for %s", device.systemName());
        }
    }

}

TrafficBulk::~TrafficBulk()
{
}

void TrafficBulk::add(const MAC& sourceMAC, const MAC& destMAC, const Poco::Net::IPAddress& sourceIP, const Poco::Net::IPAddress& destIP, Poco::UInt16 srcPort, Poco::UInt16 destPort, const std::string& transport)
{
    if (_selfMACs.find(sourceMAC) != _selfMACs.end()) {
        set(destMAC, destIP, destPort, transport);
    }
    else if (_selfMACs.find(destMAC) != _selfMACs.end()) {
        set(sourceMAC, sourceIP, srcPort, transport);
    }
}

void TrafficBulk::set(const MAC& mac, const Poco::Net::IPAddress& ip, Poco::UInt16 port, const std::string& transport)
{
    TrafficData trafficData(mac, ip, port, transport);
    size_t hash = trafficData.hash();
    _logger.debug("Traffic: %s", trafficData.toString());
    Poco::FastMutex::ScopedLock lock(_mutex);
    auto existingItem = _data.find(hash);
    if (existingItem != _data.end()) {
        existingItem->second.update();
    }
    else {
        _data[hash] = trafficData;
    }
    if (_lastUpdate.isElapsed(Poco::Timespan::MINUTES * 3)) {
        _lastUpdate.update();
        _activity.start();
    }
}

void TrafficBulk::bulkUpdate()
{
    _logger.debug("TrafficBulk::bulkInsert started");
    TrafficContainer container;
    {
        Poco::FastMutex::ScopedLock lock(_mutex);
        container = _data;
        _data.clear();
    }
    NetStat ns;
    for (auto data : container) {
        update(data.second, ns);
    }
    _logger.debug("TrafficBulk::bulkInsert ended");
}

void TrafficBulk::update(TrafficData& trafficData, const NetStat& netstat)
{
    try {
        Poco::Net::HostEntry host = Poco::Net::DNS::hostByAddress(trafficData.ip());
        trafficData.setHost(host.name());
        trafficData.setProcess(netstat.getProcess(trafficData.transport(), trafficData.ip(), trafficData.port()));
        _session << "INSERT INTO traffic (time ,count ,mac ,ip, port, host, transport , process) VALUES (?,?,?,?,?,?,?,?)", use(trafficData), now;
    }
    catch (Poco::Exception& ex) {
        _logger.error(ex.displayText());
    }
}
