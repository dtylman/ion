/*
 * File:   TrafficBulk.h
 * Author: danny
 *
 * Created on March 11, 2015, 3:41 PM
 */

#ifndef TRAFFICBULK_H
#define	TRAFFICBULK_H

#include "MAC.h"
#include "PcapSubsystem.h"
#include "TrafficData.h"
#include "TrafficDataObject.h"
#include "NetStat.h"
#include <Poco/Logger.h>
#include <Poco/Mutex.h>
#include <set>
#include <map>

class TrafficBulk : public DataObject
{
public:
    TrafficBulk(const Poco::Data::Session& session);
    virtual ~TrafficBulk();
    void add(const MAC& sourceMAC, const MAC& destMAC, const Poco::Net::IPAddress& sourceIP, const Poco::Net::IPAddress& destIP,
             Poco::UInt16 srcPort, Poco::UInt16 destPort, const std::string& transport);
private:
    void set(const MAC& mac, const Poco::Net::IPAddress& ip, Poco::UInt16 port, const std::string& transport);
    void bulkUpdate();
    void update(TrafficData& trafficData, const NetStat& netstat);
    void setHostName(TrafficData& trafficData, const std::string& fqdn);
    typedef std::set<MAC> MACSContainer;
    MACSContainer _selfMACs;
    typedef std::map<std::size_t, TrafficData> TrafficContainer;
    TrafficContainer _data;
    Poco::Timestamp _lastUpdate;
    Poco::FastMutex _mutex;
    Poco::Activity<TrafficBulk> _activity;
    Poco::Logger& _logger;
};

#endif	/* TRAFFICBULK_H */

