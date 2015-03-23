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

void IONDataObject::removeThing(const Poco::UUID& thingid)
{
    ScopedTransaciton transaction(_session);
    IPData::Container ips;
    findThingIPs(thingid, ips);
    for (auto ip : ips) {
        removeIP(ip);
    }
}

bool IONDataObject::macExists(const MAC& mac)
{
    std::string macstr(mac.toString());
    int exists = 0;
    _session << "SELECT 1 FROM ip WHERE  mac=?", use(macstr), into(exists), limit(1), now;
    return (exists == 1);
}

bool IONDataObject::thingExists(const ThingData& thing)
{
    std::string uuid = thing.uuid().toString();
    int exists = 0;
    _session << "SELECT 1 FROM thing WHERE id=?", use(uuid), into(exists), limit(1), now;
    return (exists == 1);
}

bool IONDataObject::thingIDExists(const Poco::UUID& thingID)
{
    std::string uuid = thingID.toString();
    int exists = 0;
    _session << "SELECT 1 FROM thing WHERE id=?", use(uuid), into(exists), limit(1), now;
    return (exists == 1);
}

void IONDataObject::removeThingData(const ThingData& thing)
{
    std::string uuid = thing.uuid().toString();
    _session << "DELETE FROM thing WHERE id=?", use(uuid), now;
    onThingRemoved(thing);
}

bool IONDataObject::getThingByMAC(const MAC& mac, ThingData& thing)
{
    ScopedTransaciton transaction(_session);
    if (macExists(mac)) {
        std::string uuid;
        std::string macstr(mac.toString());
        _session << "SELECT thingid FROM ip WHERE mac=?", use(macstr), into(uuid), limit(1), now;
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
    _session << "SELECT id, type, name, vendor, os, desc FROM thing WHERE id=?", use(uuid), into(data), limit(1), now;
    return true;
}

bool IONDataObject::getThing(const IPData& ip, ThingData& thing)
{	
	if (!getThing(ip.thingID(), thing))
	{
		return getThingByMAC(ip.mac(), thing);
	}
	return true;
}

void IONDataObject::findIPs(IPData::Container & container)
{
    _session << "SELECT mac, ip, last_seen,iface FROM ip", into(container), now;
}

void IONDataObject::findThingIPs(const Poco::UUID& thingid, IPData::Container & container)
{
    std::string thingidstr(thingid.toString());
    _session << "SELECT mac, ip, last_seen,iface FROM ip where thingid=?", use(thingidstr), into(container), now;
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
    _session << "SELECT 1 FROM router WHERE mac=? AND family=?", use(macstr), use(famnum), into(router), limit(1), now;
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
	_session << "DELETE FROM thing WHERE id NOT IN (SELECT thingid FROM ip)", now;
    int famnum = getFamNum(ip.family());
    _session << "INSERT INTO router (mac, family) VALUES (?,?)", use(macstr), use(famnum), now;        	
	ThingData routerThing;
	getThingByMAC(mac, routerThing);
	routerThing.setType("Router");	
    IPData address(mac, ip, device);
	address.setThingID(routerThing.uuid());    
    setThing(routerThing, true);
	setOnline(address, true); 
}

void IONDataObject::setOnline(IPData & data, bool ignoreRouterMAC)
{
    if (data.ignore()) {
        return;
    }
    ScopedTransaciton transaction(_session);
	if ( (!ignoreRouterMAC) && (isRouter(data.mac(), data.ip().family()))) {
        return;
    }
    ThingData thing;

    if (!getThing(data, thing)) {        
        thing.setDesc(Poco::format("First seen with IP %s", data.ip().toString()));
        setThing(thing, true);
    }
	data.setThingID(thing.uuid());
    bool exists = ipExists(data);
    bool online = false;
    if (exists) {
        online = ipOnline(data);
    }
    _session << "INSERT OR REPLACE INTO ip (mac ,ip ,last_seen , iface , thingid) VALUES (?,?,?,?,?)", use(data), now;
    if (!exists) {
        onIPAdded(data);
    }
    if (!online) {
        onIPOnline(data);
    }
}

bool IONDataObject::ipExists(const IPData& data)
{
    bool exists = false;
    std::string ipstr = data.ip().toString();
    std::string macstr = data.mac().toString();
    std::string thingid = data.thingID().toString();
    _session << "SELECT 1 FROM ip WHERE mac=? AND ip=? AND thingid=?", use(macstr), use(ipstr), use(thingid), into(exists), now;
    return exists;
}

bool IONDataObject::ipOnline(const IPData& data)
{
    bool online = false;
    std::string ipstr = data.ip().toString();
    std::string macstr = data.mac().toString();
    std::string thingid = data.thingID().toString();
    Poco::Timespan interval = Poco::Timespan::MINUTES * Poco::Util::Application::instance().config().getUInt("ion.offline-interval", 10);
    Poco::Timestamp achshav;
    achshav -= interval;
    std::time_t offlineTime = achshav.epochTime();
	_session << "SELECT 1 FROM ip WHERE mac=? AND ip=? AND thingid=? AND last_seen>?", use(macstr), use(ipstr), use(thingid), use(offlineTime), into(online), now;
    return online;
}

void IONDataObject::ipOffline(const IPData& data)
{
    onIPOffline(data);
}

void IONDataObject::removeIP(const IPData& ipData)
{
    ScopedTransaciton transaction(_session);
    if (!ipExists(ipData)) {
        return;
    }
    std::string ipstr = ipData.ip(). toString();
    std::string macstr = ipData.mac().toString();
    std::string thingid = ipData.thingID().toString();
    _session << "DELETE FROM ip WHERE ip=? AND mac=? AND thingid=?", use(ipstr), use(macstr), use(thingid), now;
    _logger.debug("IP deleted: %s ", ipData.toString());
    bool exists = false;
    _session << "SELECT 1 FROM ip WHERE thingid=?", use(thingid), into(exists), limit(1), now;
    if (!exists) {
        ThingData thing;
        removeThingData(thing);
    }
    onIPOffline(ipData);
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
    EventNotification::notifyThing(EventNotification::THING_ONLINE, thing);
}

void IONDataObject::onThingRemoved(const ThingData & thing)
{
    _logger.notice("Thing removed: %s", thing.toString());
    EventNotification::notifyThing(EventNotification::THING_OFFLINE, thing);
}

void IONDataObject::onIPAdded(const IPData & ip)
{
    _logger.notice("IP added: %s", ip.toString());
    AuthDataObject auth(_session);
    if (!auth.isAuthorized(ip.mac())) {
        EventNotification::notifyIP(EventNotification::NOT_AUTHORIZED, ip);
    }
}

void IONDataObject::onIPOnline(const IPData& ip)
{
    _logger.notice("IP online: %s", ip.toString());
    EventNotification::notifyIP(EventNotification::IP_ONLINE, ip);
}

void IONDataObject::onIPOffline(const IPData & ip)
{
    _logger.notice("IP offline: %s", ip.toString());
    EventNotification::notifyIP(EventNotification::IP_OFFLINE, ip);
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

/** return true if at least one mac address is not authorized*/
bool IONDataObject::thingAuthorized(const Poco::UUID & thingID)
{
    std::string thingidstr(thingID.toString());
    bool notAuth = 0;
    _session << "SELECT DISTINCT 1 FROM ip WHERE ip.mac NOT IN authorized AND ip.thingid=?", use(thingidstr), into(notAuth), now;
    return !(notAuth);
}
