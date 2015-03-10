/*
 * File:   EventDataObject.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 10:20 PM
 */

#include "EventDataObject.h"
#include <Poco/Util/Application.h>

using namespace Poco::Data::Keywords;

EventDataObject::EventDataObject(const Poco::Data::Session& session) : DataObject(session)
{

}

EventDataObject::~EventDataObject()
{
}

void EventDataObject::insert(const EventData& data)
{
    EventData event = data;
	_session << "INSERT INTO event (time,name,details) VALUES (?,?,?)", use(event), now;
    deleteOld();
}

void EventDataObject::deleteOld()
{
    Poco::Timestamp achshav;
    Poco::Timespan days = Poco::Timespan::DAYS * Poco::Util::Application::instance().config().getUInt("ion.eventsage", 7);
    achshav -= days;
    std::time_t age = achshav.epochTime();
    _session << "DELETE FROM event WHERE time<?", use(age), now;
}
