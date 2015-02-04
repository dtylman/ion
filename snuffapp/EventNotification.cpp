/*
 * File:   DataNotificaation.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 5:34 PM
 */

#include "EventNotification.h"
#include "MAC.h"
#include "EventsSubsystem.h"
#include <Poco/Util/Application.h>

const std::string EventNotification::IP_OFFLINE("IPOFFLINE");
const std::string EventNotification::IP_ONLINE("IPONLINE");
const std::string EventNotification::THING_ONLINE("THINGONLINE");
const std::string EventNotification::THING_OFFLINE("THINGOFFLINE");

EventNotification::EventNotification()
{

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

void EventNotification::notify(const std::string& name, const MAC& mac, const std::string& details)
{
    EventNotification::Ptr notif = new EventNotification();
    notif->_data.setName(name);
    notif->_data.setMAC(mac);
    notif->_data.setDetails(details);
    Poco::Util::Application::instance().getSubsystem<EventsSubsystem>().notify(notif);
}

void EventNotification::notify(const std::string& name, const MAC& mac, const Poco::Net::IPAddress& ip, const std::string& details)
{
    EventNotification::Ptr notif = new EventNotification();
    notif->_data.setName(name);
    notif->_data.setMAC(mac);
    notif->_data.setIP(ip);
    Poco::Util::Application::instance().getSubsystem<EventsSubsystem>().notify(notif);
}
