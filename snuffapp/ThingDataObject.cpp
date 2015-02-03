/*
 * File:   HostDataObject.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#include "ThingDataObject.h"
#include "ScopedTransaciton.h"

using namespace Poco::Data::Keywords;

//seen, host-name, guessed os, mac-vendor, current_ip, given: given type, given manufaturer, given os, given description

ThingDataObject::ThingDataObject(const Poco::Data::Session& session) : DataObject(session),
_logger(Poco::Logger::get("ThingDataObject"))
{
}

ThingDataObject::~ThingDataObject()
{
}

void ThingDataObject::setName(const MAC& mac, const std::string& name)
{
    std::string macstr(mac.toString());
    std::string namestr(name);
    ScopedTransaciton transaction(_session);
    if (!exists(mac)) {
        _session << "INSERT INTO thing (mac, name) VALUES (?,?)", use(macstr), use(namestr), now;
    }
    else {
        _session << "UPDATE thing SET name=? WHERE mac=?", use(namestr), use(macstr), now;
    }

    _logger.information("Thing %s name set to %s", macstr, namestr);
}

void ThingDataObject::setOS(const MAC& mac, const std::string& os)
{
    std::string macstr(mac.toString());
    std::string osstr(os);
    ScopedTransaciton transaction(_session);
    if (!exists(mac)) {
        _session << "INSERT INTO thing (mac,os) VALUES (?,?)", use(macstr), use(osstr), now;
        _logger.information("Thing %s os set to %s", macstr, osstr);
    }
    else {
        _session << "UPDATE thing SET os=? WHERE mac=? AND os IS NULL", use(osstr), use(macstr), now;
    }
}

void ThingDataObject::setType(const MAC& mac, const std::string& type)
{
    std::string macstr(mac.toString());
    std::string typestr(type);
    ScopedTransaciton transaction(_session);
    if (!exists(mac)) {
        _session << "INSERT INTO thing (mac,type) VALUES (?,?)", use(macstr), use(typestr), now;
        _logger.information("Thing %s type set to %s", macstr, typestr);
    }
    else {
        _session << "UPDATE thing SET type=? WHERE mac=? AND type IS NULL", use(typestr), use(macstr), now;
    }
}

bool ThingDataObject::exists(const MAC& mac)
{
    std::string macstr(mac.toString());
    bool exists = false;
    _session << "SELECT 1 FROM thing WHERE mac=?", use(macstr), into(exists), now;
    return exists;
}
