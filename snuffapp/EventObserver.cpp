/*
 * File:   EventObserver.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 10:17 PM
 */

#include "EventObserver.h"
#include "EventNotification.h"
#include <Poco/NotificationCenter.h>
#include <Poco/NObserver.h>

EventObserver::EventObserver(const Poco::Data::Session& session) : _event(session)
{
    Poco::NObserver<EventObserver, EventNotification> observer(*this, &EventObserver::handleEventNotification);
    Poco::NotificationCenter::defaultCenter().addObserver(observer);
}

EventObserver::~EventObserver()
{
    Poco::NObserver<EventObserver, EventNotification> observer(*this, &EventObserver::handleEventNotification);
    Poco::NotificationCenter::defaultCenter().removeObserver(observer);
}

void EventObserver::handleEventNotification(const EventNotification::Ptr& notif)
{
    _event.insert(notif->event());
}
