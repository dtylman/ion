/*
 * File:   DataNotificaation.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 5:34 PM
 */

#include "EventNotification.h"
#include "MAC.h"

const std::string EventNotification::IP_OFFLINE("IPOFFLINE");
const std::string EventNotification::IP_ONLINE("IPONLINE");
const std::string EventNotification::THING_ONLINE("THINGONLINE");
const std::string EventNotification::THING_OFFLINE("THINGOFFLINE");

EventNotification::EventNotification(const std::string& name, const MAC& mac)
{
    _data.setName(name);
    _data.setMAC(mac);
}

EventNotification::EventNotification(const std::string& name, const MAC& mac, const Poco::Net::IPAddress& ip)
{
    _data.setName(name);
    _data.setMAC(mac);
    _data.setIP(ip);
}

EventNotification::~EventNotification()
{
}

const EventData& EventNotification::event() const
{
    return _data;
}

void EventNotification::setDetails(const std::string& details)
{
    _data.setDetails(details);
}
