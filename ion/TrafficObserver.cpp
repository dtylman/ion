/*
 * File:   TrafficObserver.cpp
 * Author: danny
 *
 * Created on March 10, 2015, 5:55 PM
 */

#include "TrafficObserver.h"
#include "DissectSubsystem.h"
#include "ProtocolTCP.h"
#include <Poco/Util/Application.h>
#include <Poco/Delegate.h>

TrafficObserver::TrafficObserver() : _logger(Poco::Logger::get("TrafficObserver"))
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame += Poco::delegate(this, &TrafficObserver::onFrameEvent);
}

TrafficObserver::~TrafficObserver()
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame -= Poco::delegate(this, &TrafficObserver::onFrameEvent);
}

void TrafficObserver::onFrameEvent(Frame::Ptr& frame)
{
    if (frame.isNull()) {
        return;
    }
    const ProtocolTCP* tcp = frame->getProtocol<ProtocolTCP>();
    if (tcp == nullptr) {
        return;
    }
    if (tcp->isSynAck()) {
        _logger.debug(frame->toString());
    }
}


