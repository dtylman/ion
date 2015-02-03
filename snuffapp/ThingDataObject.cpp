/*
 * File:   HostDataObject.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#include "ThingDataObject.h"

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
    _session << "INSERT OR REPLACE INTO thing (mac,name) VALUES (?,?)", use(macstr), use(namestr), now;
    _logger.information("Thing %s name set to %s", macstr, namestr);
}

void ThingDataObject::setOS(const MAC& mac, const std::string& os, bool overwrite)
{
    std::string macstr(mac.toString());
    std::string osstr(os);
    if (!overwrite) {
        bool hasOS = false;
        _session << "SELECT 1 FROM thing WHERE mac=? AND os is not null", use(macstr), into(hasOS), now;
        if (hasOS) {
            return;
        }
    }
    _session << "INSERT OR REPLACE INTO thing (mac,os) VALUES (?,?)", use(macstr), use(osstr), now;
    _logger.information("Thing %s os set to %s", macstr, osstr);
}

