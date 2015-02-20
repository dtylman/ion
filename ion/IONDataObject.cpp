/*
 * File:   IONDataObject.cpp
 * Author: danny
 *
 * Created on February 18, 2015, 3:47 PM
 */

#include "IONDataObject.h"
#include "ScopedTransaciton.h"
#include "EventNotification.h"
#include "AuthDataObject.h"
#include <Poco/Data/Statement.h>
#include <Poco/Timespan.h>
#include <Poco/Timestamp.h>
#include <Poco/Util/Application.h>

using namespace Poco::Data::Keywords;

IONDataObject::IONDataObject(const Poco::Data::Session& session) : DataObject(session),
_logger(Poco::Logger::get("IONDataObject"))
{

}

IONDataObject::~IONDataObject()
{
}

void IONDataObject::setThing(const ThingData& thing, bool overwrite)
{
    std::string uuid = thing.uuid().toString();
    std::string type = thing.type();
    std::string name = thing.name();
    std::string vendor = thing.vendor();
    std::string os = thing.os();
    std::string desc = thing.desc();
    ScopedTransaciton transaction(_session);
    bool hasThing = thingExists(thing);
    if (hasThing && (!overwrite)) {
        _session << "UPDATE thing SET type=? WHERE type IS NOT NULL AND id=?", use(type), use(uuid), now;
        _session << "UPDATE thing SET name=? WHERE name IS NOT NULL AND id=?", use(name), use(uuid), now;
        _session << "UPDATE thing SET vendor=? WHERE vendor IS NOT NULL AND id=?", use(vendor), use(uuid), now;
        _session << "UPDATE thing SET os=? WHERE os IS NOT NULL AND id=?", use(os), use(uuid), now;
        _session << "UPDATE thing SET desc=? WHERE desc IS NOT NULL AND id=?", use(desc), use(uuid), now;
    }
    else {
        _session << "INSERT OR REPLACE INTO thing (id, type , name , vendor , os , desc) VALUES(?,?,?,?,?,?)",
                use(uuid), use(type), use(name), use(vendor), use(os), use(desc), now;
        if (!hasThing) {
            onThingAdded(thing);
        }
    };
}

bool IONDataObject::ipExists(const Poco::Net::IPAddress& ip, const MAC& mac)
{
    std::string ipstr(ip.toString());
    std::string macstr(mac.toString());
    int exists = 0;
    _session << "SELECT 1 FROM ip WHERE ip=? AND mac=?", use(ipstr), use(macstr), into(exists), now;
    return (exists == 1);
}

bool IONDataObject::macExists(const MAC& mac)
{
    std::string macstr(mac.toString());
    int exists = 0;
    _session << "SELECT 1 FROM ip WHERE  mac=?", use(macstr), into(exists), now;
    return (exists == 1);
}

bool IONDataObject::thingExists(const ThingData& thing)
{
    std::string uuid = thing.uuid().toString();
    int exists = 0;
    _session << "SELECT 1 FROM thing WHERE id=?", use(uuid), into(exists), now;
    return (exists == 1);
}

bool IONDataObject::thingIDExists(const Poco::UUID& thingID)
{
    std::string uuid = thingID.toString();
    int exists = 0;
    _session << "SELECT 1 FROM thing WHERE id=?", use(uuid), into(exists), now;
    return (exists == 1);
}

void IONDataObject::removeThing(const ThingData& thing)
{
    std::string uuid = thing.uuid().toString();
    _session << "DELETE FROM thing WHERE id=?", use(uuid), now;
    onThingRemoved(thing);
}

bool IONDataObject::getThing(const MAC& mac, ThingData& thing)
{
    ScopedTransaciton transaction(_session);
    if (macExists(mac)) {
        std::string uuid;
        std::string macstr(mac.toString());
        _session << "SELECT thingid FROM ip WHERE mac=?", use(macstr), into(uuid), now;
        return getThing(Poco::UUID(uuid), thing);
    }
    return false;
}

bool IONDataObject::getThing(const Poco::UUID& thingID, ThingData & data)
{
    ScopedTransaciton transaction(_session);
    if (!thingIDExists(thingID)) {
        return false;
    }
    std::string uuid = thingID.toString();
    _session << "SELECT id, type, name, vendor, os, desc FROM thing WHERE id=?", use(uuid), into(data), now;
    return true;
}

void IONDataObject::findIPs(IPData::Container & container)
{
    _session << "SELECT mac, ip, last_seen,iface FROM ip", into(container), now;
}

void IONDataObject::findOnlineIPs(IPData::Container & container)
{
    Poco::Timespan interval = Poco::Timespan::MINUTES * Poco::Util::Application::instance().config().getUInt("ion.offline-interval", 10);
    Poco::Timestamp ts;
    ts -= interval;
    std::time_t last = ts.epochTime();
    _session << "SELECT mac, ip, last_seen,iface FROM ip WHERE last_seen>?", use(last), into(container), now;
}

bool IONDataObject::isRouter(const MAC& mac, const Poco::Net::IPAddress::Family & family)
{
    std::string macstr = mac.toString();
    int famnum = getFamNum(family);
    bool router = false;
    _session << "SELECT 1 FROM router WHERE mac=? AND family=?", use(macstr), use(famnum), into(router), now;
    return router;
}

void IONDataObject::setRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string & device)
{
    if (!mac.isUnicast()) {
        return;
    }

    ScopedTransaciton transaction(_session);
    if (isRouter(mac, ip.family())) {
        return;
    }
    std::string macstr = mac.toString();
    std::string ipstr = ip.toString();
    _session << "DELETE FROM ip WHERE mac=? and ip!=?", use(macstr), use(ipstr), now;
    int famnum = getFamNum(ip.family());
    _session << "INSERT INTO router (mac, family) VALUES (?,?)", use(macstr), use(famnum), now;
    //onRouterAdded(mac, ip.family());
    std::time_t ts = Poco::Timestamp().epochTime();
    IPData address(mac, ip, device);
    setIP(address);
    ThingData routerThing;
    getThing(mac, routerThing);
    routerThing.setType("Router");
    setThing(routerThing, false);
}

void IONDataObject::setIP(const IPData & data)
{
    if (data.ignore()) {
        return;
    }
    ScopedTransaciton transaction(_session);
    bool exists = ipExists(data.ip(), data.mac());
    std::string macstr = data.mac().toString();
    std::string ipstr = data.ip().toString();
    std::time_t time = Poco::Timestamp().epochTime();
    if (exists) {
        _session << "UPDATE ip SET last_seen=? WHERE mac=? AND ip=?", use(time), use(macstr), use(ipstr), now;
    }
    else {
        ThingData newThing;
        newThing.setDesc(Poco::format("First seen with IP %s", ipstr));
        setThing(newThing, false);
        std::string thingid = newThing.uuid().toString();
        std::string ifacestr = data.iface();
        _session << "INSERT INTO ip (mac ,ip ,last_seen , iface , thingid) VALUES (?,?,?,?,?)",
                use(macstr), use(ipstr), use(time), use(ifacestr), use(thingid), now;
        onIPAdded(data);
    }
}

void IONDataObject::removeIP(const Poco::Net::IPAddress& ip, const MAC & mac)
{
    ScopedTransaciton transaction(_session);
    if (!ipExists(ip, mac)) {
        return;
    }
    IPData data;
    std::string ipstr = ip.toString();
    std::string macstr = mac.toString();
    _session << "SELECT (mac,ip,last_seen,iface,thingid) FROM ip WHERE ip=? AND mac=?", into(data), use(ipstr), use(macstr), now;
    _session << "DELETE FROM ip WHERE ip=? AND mac=?", use(ipstr), use(macstr), now;
    bool exists = 0;
    std::string thingid = data.thingID().toString();
    _session << "SELECT 1 FROM ip WHERE thingid=?", use(thingid), now;
    if (exists == 0) {
        ThingData thing;
        getThing(thingid, thing);
        removeThing(thing);
    }
    onIPRemoved(data);
}

void IONDataObject::setSuspectedRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string & device)
{
    if (!mac.isUnicast()) {
        return;
    }
    ScopedTransaciton transaction(_session);
    if (isRouter(mac, ip.family())) {
        return;
    }
    int count = 0;
    std::string macstr = mac.toString();
    _session << "SELECT count(ip) FROM ip WHERE mac=?", use(macstr), into(count), now;
    if (count > 3) {
        setRouter(ip, mac, device);
    }
}

void IONDataObject::onThingAdded(const ThingData & thing)
{
    _logger.notice("Thing added: %s", thing.toString());
    EventNotification::notify(EventNotification::THING_ONLINE, thing);
}

void IONDataObject::onThingRemoved(const ThingData & thing)
{
    _logger.notice("Thing removed: %s", thing.toString());
    EventNotification::notify(EventNotification::THING_OFFLINE, thing);
}

void IONDataObject::onIPAdded(const IPData & ip)
{
    _logger.notice("IP added: %s", ip.toString());
    AuthDataObject auth(_session);
    if (!auth.isAuthorized(ip.mac())) {
        EventNotification::notify(EventNotification::NOT_AUTHORIZED, ip);
    }
    EventNotification::notify(EventNotification::IP_ONLINE, ip);
}

void IONDataObject::onIPRemoved(const IPData & ip)
{
    _logger.notice("IP removed: %s", ip.toString());
    EventNotification::notify(EventNotification::IP_OFFLINE, ip);
}

int IONDataObject::getFamNum(const Poco::Net::IPAddress::Family fam) const
{
    if (fam == Poco::Net::IPAddress::IPv4) {
        return 4;
    }
    return 6;
}

void IONDataObject::authorizeThing(const Poco::UUID& thingID, bool authorize)
{
    ScopedTransaciton transaction(_session);
    std::list<std::string> macs;
    std::string thingidstr = thingID.toString();
    _session << "SELECT mac FROM ip WHERE thingid=?", use(thingidstr), into(macs), now;
    AuthDataObject ado(_session);
    for (auto mac : macs) {
        if (authorize) {
            ado.authorize(MAC(mac));
        }
        else {
            ado.unAuthorize(MAC(mac));
        }
    }
}
