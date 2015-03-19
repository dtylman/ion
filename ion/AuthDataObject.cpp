/*
 * File:   AuthDataObject.cpp
 * Author: danny
 *
 * Created on February 16, 2015, 2:51 PM
 */

#include "AuthDataObject.h"

using namespace Poco::Data::Keywords;

AuthDataObject::AuthDataObject(const Poco::Data::Session& session) : DataObject(session),
_logger(Poco::Logger::get("AuthDataObject"))
{

}

AuthDataObject::~AuthDataObject()
{

}

void AuthDataObject::authorize(const MAC& mac)
{
    std::string macstr(mac.toString());
    _session << "INSERT OR REPLACE INTO authorized (mac) VALUES (?)", use(macstr), now;
    _logger.information("%s authorized", macstr);
}

bool AuthDataObject::isAuthorized(const MAC& mac)
{
    std::string macstr(mac.toString());
    bool authorized = false;
    _session << "SELECT DISTINCT 1 FROM authorized WHERE mac=?", use(macstr), into(authorized), now;
    return authorized;
}

void AuthDataObject::unAuthorize(const MAC& mac)
{
    std::string macstr(mac.toString());
    _session << "DELETE FROM authorized WHERE mac=?", use(macstr), now;
    _logger.information("%s un-authorized", macstr);
}

void AuthDataObject::authorizeAll()
{
    _session << "INSERT OR REPLACE INTO authorized (mac) SELECT DISTINCT mac FROM ip", now;
    _logger.notice("All devices authorized");
}

void AuthDataObject::unAuthorizeAll()
{
    _session << "DELETE FROM authorized", now;
    _logger.notice("All devices unauthorized");
}
