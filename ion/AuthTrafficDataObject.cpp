/*
 * File:   AuthTrafficDataObject.cpp
 * Author: danny
 *
 * Created on March 18, 2015, 4:54 PM
 */

#include "AuthTrafficDataObject.h"
#include <Poco/Data/Session.h>
using namespace Poco::Data::Keywords;

AuthTrafficDataObject::AuthTrafficDataObject(const Poco::Data::Session& session) : DataObject(session), _logger(Poco::Logger::get("AuthTrafficDataObject"))
{

}

AuthTrafficDataObject::~AuthTrafficDataObject()
{
}

void AuthTrafficDataObject::authorize(const std::string& type, const std::string& value)
{
    std::string typestr(type);
    std::string valuestr(value);
    _session << "INSERT OR REPLACE INTO authorized_traffic (type, value) VALUES (?,?)", use(typestr), use(valuestr), now;
    _logger.notice("traffic from %s '%s' is now authorized", type, value);
}

void AuthTrafficDataObject::unauthorize(const std::string& type, const std::string& value)
{
    std::string typestr(type);
    std::string valuestr(value);
    _session << "DELETE FROM authorized_traffic WHERE type=? AND value=?", use(typestr), use(valuestr), now;
    _logger.notice("traffic from %s '%s' is no longer authorized", type, value);
}
