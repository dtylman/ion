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
#include <Poco/JSON/Object.h>
#include "MAC.h"
#include <Poco/Net/IPAddress.h>

class DataNotificaation : public Poco::Notification
{
public:
    DataNotificaation(const std::string& name);
    DataNotificaation(const std::string& name, const MAC& mac);
    DataNotificaation(const std::string& name, const MAC& mac, const Poco::Net::IPAddress& ip);
    typedef Poco::AutoPtr<DataNotificaation> Ptr;

    Poco::JSON::Object& json();
protected:
    virtual ~DataNotificaation();
private:
    std::string _name;
    Poco::JSON::Object _json;
};

#endif	/* DATANOTIFICAATION_H */

