/*
 * File:   EventsSubsystem.h
 * Author: danny
 *
 * Created on February 4, 2015, 9:04 AM
 */

#ifndef EVENTSSUBSYSTEM_H
#define	EVENTSSUBSYSTEM_H

#include "EventNotification.h"
#include "Syslog.h"
#include <Poco/Util/Subsystem.h>
#include <Poco/NotificationQueue.h>
#include <Poco/Activity.h>
#include <Poco/Logger.h>

class EventsSubsystem : public Poco::Util::Subsystem
{
public:
    EventsSubsystem();
    void notify(EventNotification::Ptr notif);
protected:
    virtual ~EventsSubsystem();
    virtual const char* name() const;
    virtual void initialize(Poco::Util::Application& app);
    virtual void uninitialize();
private:
    void runActivity();
    void processEvent(const EventData& eventData);
    void persistEvent(const EventData& eventData);
    void mailEvent(const EventData& eventData);
    void syslogEvent(const EventData& eventData);
    Poco::NotificationQueue _queue;
    Poco::Activity<EventsSubsystem> _activity;
    Poco::Logger& _logger;
    Syslog _syslog;
};

#endif	/* EVENTSSUBSYSTEM_H */

