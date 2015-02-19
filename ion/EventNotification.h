/*
 * File:   DataNotificaation.h
 * Author: danny
 *
 * Created on February 3, 2015, 5:34 PM
 */

#ifndef DATANOTIFICAATION_H
#define	DATANOTIFICAATION_H

#include <Poco/Notification.h>
#include <Poco/AutoPtr.h>
#include "EventData.h"
#include "ThingData.h"
#include "IPData.h"

class EventNotification : public Poco::Notification
{
public:
    static const std::string IP_ONLINE;
    static const std::string IP_OFFLINE;
    static const std::string THING_ONLINE;
    static const std::string THING_OFFLINE;
    static const std::string NOT_AUTHORIZED;

    EventNotification();

    typedef Poco::AutoPtr<EventNotification> Ptr;

    const EventData& event() const;

    void setDetails(const std::string& details);

    static void notify(const std::string& name, const ThingData& thing);
    static void notify(const std::string& name, const IPData& ip);
protected:
    virtual ~EventNotification();
private:
    EventData _data;
};

#endif	/* DATANOTIFICAATION_H */

