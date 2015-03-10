/*
 * File:   EventData.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 10:10 PM
 */

#include "EventData.h"
#include <Poco/Format.h>
#include <Poco/DateTimeFormatter.h>

EventData::EventData()
{
}

EventData::~EventData()
{
}

const std::string& EventData::details() const
{
    return _details;
}

const std::string& EventData::name() const
{
    return _name;
}

void EventData::setDetails(const std::string& details)
{
    _details = details;
}

void EventData::setName(const std::string& name)
{
    _name = name;
}

void EventData::setTime(const Poco::Timestamp& time)
{
    _time = time;
}

const Poco::Timestamp& EventData::time() const
{
    return _time;
}

std::string EventData::toString() const
{
    return Poco::format("%s %s '%s'", Poco::DateTimeFormatter::format(_time, Poco::DateTimeFormat::HTTP_FORMAT, 0),
                        _name, _details);
}
