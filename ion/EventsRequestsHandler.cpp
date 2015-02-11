/*
 * File:   EventsRequestsHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 11:08 PM
 */

#include "EventsRequestsHandler.h"

EventsRequestsHandler::EventsRequestsHandler()
{
}

EventsRequestsHandler::~EventsRequestsHandler()
{
}

void EventsRequestsHandler::renderBody(std::ostream& output)
{
    output << "Events will go here ";
}

std::string EventsRequestsHandler::title() const
{
    return "Events";
}
