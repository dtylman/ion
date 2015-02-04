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

class EventNotification : public Poco::Notification
{
public:
    static const std::string IP_ONLINE;
    static const std::string IP_OFFLINE;
    static const std::string THING_ONLINE;
    static const std::string THING_OFFLINE;

    EventNotification();

    typedef Poco::AutoPtr<EventNotification> Ptr;

    const EventData& event() const;

    void setDetails(const std::string& details);

    static void notify(const std::string& name, const MAC& mac, const std::string& details = "");
    static void notify(const std::string& name, const MAC& mac, const Poco::Net::IPAddress& ip, const std::string& details = "");
protected:
    virtual ~EventNotification();
private:
    EventData _data;
};

#endif	/* DATANOTIFICAATION_H */

