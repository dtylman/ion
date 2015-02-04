/*
 * File:   EventsSubsystem.cpp
 * Author: danny
 *
 * Created on February 4, 2015, 9:04 AM
 */

#include "EventsSubsystem.h"
#include "EventDataObject.h"
#include "DataSubsystem.h"
#include <Poco/NObserver.h>
#include <Poco/NotificationCenter.h>
#include <Poco/Util/Application.h>

EventsSubsystem::EventsSubsystem() : _activity(this, &EventsSubsystem::runActivity),
_logger(Poco::Logger::get("EventsSubsystem"))
{

}

EventsSubsystem::~EventsSubsystem()
{

}

void EventsSubsystem::initialize(Poco::Util::Application& app)
{
    _logger.debug("EventsSubsystem::initialize");
    _activity.start();
}

const char* EventsSubsystem::name() const
{
    return "EventsSubsystem";
}

void EventsSubsystem::uninitialize()
{
    _logger.debug("EventsSubsystem::uninitialize");
    _activity.stop();
    _queue.wakeUpAll();
    _activity.wait(2500);
}

void EventsSubsystem::notify(EventNotification::Ptr notif)
{
    _queue.enqueueNotification(notif);
}

void EventsSubsystem::persistEvent(const EventData& eventData)
{
    DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
    EventDataObject edo(data.createSession());
    edo.insert(eventData);
}

void EventsSubsystem::processEvent(const EventData& eventData)
{
    if (_logger.debug()) {
        _logger.debug("Event: %s", eventData.toString());
    }
    persistEvent(eventData);
}

void EventsSubsystem::runActivity()
{
    _logger.information("Activity Started");
    while (!_activity.isStopped()) {
        try {
            Poco::Notification::Ptr notif(_queue.waitDequeueNotification(2500), true);
            EventNotification::Ptr event = notif.cast<EventNotification>();
            if (!event.isNull()) {
                processEvent(event->event());
            }
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
        catch (std::exception& ex) {
            _logger.error(std::string(ex.what()));
        }
        catch (...) {
            _logger.error("Unknown exception in EventsSubsystem::runActivity");
        }
    }
    _logger.information("Activity Ended");
}
