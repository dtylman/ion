/*
 * File:   DataNotificaation.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 5:34 PM
 */

#include "DataNotificaation.h"
#include "MAC.h"

DataNotificaation::DataNotificaation(const std::string& name) : _name(name)
{
    _json.set("name", _name);
}

DataNotificaation::DataNotificaation(const std::string& name, const MAC& mac) : _name(name)
{
    _json.set("name", _name);
    _json.set("mac", mac.toString());
}

DataNotificaation::DataNotificaation(const std::string& name, const MAC& mac, const Poco::Net::IPAddress& ip) : _name(name)
{
    _json.set("name", _name);
    _json.set("mac", mac.toString());
    _json.set("ip", ip.toString());
}

DataNotificaation::~DataNotificaation()
{
}

Poco::JSON::Object& DataNotificaation::json()
{
    return _json;
}
