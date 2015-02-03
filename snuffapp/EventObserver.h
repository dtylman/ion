/*
 * File:   EventObserver.h
 * Author: danny
 *
 * Created on February 3, 2015, 10:17 PM
 */

#ifndef EVENTOBSERVER_H
#define	EVENTOBSERVER_H

#include "DataObserver.h"
#include "EventDataObject.h"
#include "EventNotification.h"

class EventObserver : public DataObserver
{
public:
    EventObserver(const Poco::Data::Session& session);
protected:
    virtual ~EventObserver();
private:
    void handleEventNotification(const EventNotification::Ptr& notif);
    EventDataObject _event;
};

#endif	/* EVENTOBSERVER_H */

