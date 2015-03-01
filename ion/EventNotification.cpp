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
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTimeFormat.h>
#include <Poco/Format.h>
#include <Poco/String.h>

const std::string EventNotification::IP_OFFLINE("ip_offline");
const std::string EventNotification::IP_ONLINE("ip_online");
const std::string EventNotification::THING_ONLINE("thing_online");
const std::string EventNotification::THING_OFFLINE("thing_offline");
const std::string EventNotification::NOT_AUTHORIZED("not_authorized");

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

void EventNotification::notify(const std::string& name, const ThingData& thing)
{
    std::string key = Poco::format("ion.events.%s.text", name);
    std::string text = Poco::Util::Application::instance().config().getString(key);
    Poco::replaceInPlace(text, std::string("[type]"), thing.type());
    Poco::replaceInPlace(text, std::string("[name]"), thing.name());
    Poco::replaceInPlace(text, std::string("[os]"), thing.os());
    Poco::replaceInPlace(text, std::string("[vendor]"), thing.vendor());
    Poco::replaceInPlace(text, std::string("[desc]"), thing.desc());
    EventNotification::Ptr notif = new EventNotification();
    notif->_data.setName(name);
    notif->_data.setDetails(text);
    Poco::Util::Application::instance().getSubsystem<EventsSubsystem>().notify(notif);
}

/*    MAC _mac;
    Poco::Net::IPAddress _ip;
    Poco::Timestamp _lastSeen;
    std::string _iface;*/

void EventNotification::notify(const std::string& name, const IPData& ip)
{
    std::string key = Poco::format("ion.events.%s.text", name);
    std::string text = Poco::Util::Application::instance().config().getString(key);
    Poco::replaceInPlace(text, std::string("[mac]"), ip.mac().toString());
    Poco::replaceInPlace(text, std::string("[ip]"), ip.ip().toString());
    std::string lastSeen = Poco::DateTimeFormatter::format(ip.lastSeen(), Poco::DateTimeFormat::HTTP_FORMAT, 0);
    Poco::replaceInPlace(text, std::string("[timestamp]"), lastSeen);
    Poco::replaceInPlace(text, std::string("[interface]"), ip.iface());
    EventNotification::Ptr notif = new EventNotification();
    notif->_data.setName(name);
    notif->_data.setDetails(text);
    Poco::Util::Application::instance().getSubsystem<EventsSubsystem>().notify(notif);
}
