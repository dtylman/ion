/*
 * File:   TrafficDataObject.cpp
 * Author: danny
 *
 * Created on March 11, 2015, 5:22 PM
 */

#include "TrafficDataObject.h"
#include "EventNotification.h"
#include <Poco/Util/Application.h>

using namespace Poco::Data::Keywords;

TrafficDataObject::TrafficDataObject(const Poco::Data::Session& session) : DataObject(session), _logger(Poco::Logger::get("TrafficDataObject"))
{

}

TrafficDataObject::~TrafficDataObject()
{
}

void TrafficDataObject::insert(TrafficData& trafficData)
{
    _session << "INSERT INTO traffic (time ,count ,mac ,ip, port, host, domain, transport , process) VALUES (?,?,?,?,?,?,?,?,?)", use(trafficData), now;
}

void TrafficDataObject::deleteOld()
{
    Poco::Timestamp achshav;
    Poco::Timespan days = Poco::Timespan::DAYS * Poco::Util::Application::instance().config().getUInt("ion.trafficage", 1);
    achshav -= days;
    std::time_t age = achshav.epochTime();
    _session << "DELETE FROM traffic WHERE time<?", use(age), now;
}

void TrafficDataObject::checkAuthStatus()
{
    unsigned count = 0;
    _session << "SELECT sum(count) AS count FROM traffic WHERE "
            "traffic.domain NOT IN (SELECT value FROM authorized_traffic WHERE  type='domain') AND "
            "traffic.ip NOT IN (SELECT value FROM authorized_traffic WHERE  type='ip') AND "
            "traffic.port NOT IN (SELECT value FROM authorized_traffic WHERE  type='port') AND "
            "traffic.process NOT IN (SELECT value FROM authorized_traffic WHERE  type='process')", into(count), now;
    if (count > 0) {
        _logger.notice("Non authorized traffic count %u", count);
        EventNotification::notifyTraffic(count);
    }
}
