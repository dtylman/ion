/*
 * File:   IPDataObject.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 8:51 AM
 */

#include "IPDataObject.h"
#include "EventNotification.h"
#include "AuthDataObject.h"
#include "ThingDataObject.h"
#include <Poco/Timestamp.h>
#include <Poco/Util/Application.h>
#include <Poco/Timespan.h>

using namespace Poco::Data::Keywords;

IPDataObject::IPDataObject(const Poco::Data::Session& session) : DataObject(session),
_logger(Poco::Logger::get("IPDataObject"))
{

}

IPDataObject::~IPDataObject()
{
}

void IPDataObject::addIP(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& iface)
{
    if ((!ip.isUnicast()) || (!mac.isUnicast())) {
        return;
    }
    if (isRouter(mac, ip.af())) {
        return;
    }
    std::string ipstr = ip.toString();
    std::string macstr = mac.toString();
    std::string ifacestr = iface;
    std::time_t ts = Poco::Timestamp().epochTime();
    bool macExists = exists(mac);
    bool ipExists = exists(ip, mac);
    _session << "INSERT OR REPLACE INTO ip (mac,ip,last_seen,iface) VALUES (?,?,?,?)",
            use(macstr), use(ipstr), use(ts), use(ifacestr), now;
    if (!ipExists) {
        _logger.notice("IP online %s %s %s", macstr, ipstr, ifacestr);
        EventNotification::notify(EventNotification::IP_ONLINE, mac, ip);
        AuthDataObject auth(_session);
        if (!auth.isAuthorized(mac)) {
            EventNotification::notify(EventNotification::NOT_AUTHORIZED, mac);
        }
    }
    else {
        _logger.information("IP updated %s %s %s", macstr, ipstr, ifacestr);
    }
    if (!macExists) {
        _logger.notice("Device added %s %s %s", macstr, ipstr, ifacestr);
        EventNotification::notify(EventNotification::THING_ONLINE, mac, ip);
    }
}

void IPDataObject::removeIP(const Poco::Net::IPAddress& ip, const MAC& mac)
{
    std::string ipstr = ip.toString();
    std::string macstr = mac.toString();
    bool ipExists = exists(ip, mac);
    _session << "DELETE FROM ip WHERE mac=? AND ip=?", use(macstr), use(ipstr), now;
    if (ipExists) {
        _logger.notice("IP offline %s %s", macstr, ipstr);
        EventNotification::notify(EventNotification::IP_OFFLINE, mac, ip);
        if (!exists(ip, mac)) {
            _logger.notice("Device offline: %s", macstr);
            EventNotification::notify(EventNotification::THING_OFFLINE, mac, ip);
        }
    }
}

void IPDataObject::routerSuspected(const Poco::Net::IPAddress& ip, const MAC& mac)
{
    if ((!mac.isUnicast())) {
        return;
    }
    if (isRouter(mac, ip.af())) {
        return;
    }
    else {
        int count = 0;
        std::string macstr = mac.toString();
        int family = ip.af();
        _session << "SELECT count(ip) FROM ip WHERE mac=?", use(macstr), into(count), now;
        if (count > 3) {
            _session << "INSERT OR REPLACE INTO router (mac, family) VALUES (?,?)", use(macstr), use(family), now;
            _session << "DELETE FROM ip WHERE mac=?", use(macstr), now;
            _logger.notice("Router added: %s", macstr);

            if (ip.family() == Poco::Net::IPAddress::IPv4) {
                EventNotification::notify(EventNotification::THING_ONLINE, mac, "Router for IPv4");
            }
            else {
                EventNotification::notify(EventNotification::THING_ONLINE, mac, "Router for IPv6");
            }
        }
    }
}

void IPDataObject::addRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device)
{
    if ((!ip.isUnicast()) || (!mac.isUnicast())) {

        return;
    }
    std::string macstr = mac.toString();
    std::string ipstr = ip.toString();
    _session << "DELETE FROM ip WHERE mac=? and ip!=?", use(macstr), use(ipstr), now;
    std::time_t ts = Poco::Timestamp().epochTime();
    std::string deviceStr = device;
    _session << "INSERT OR REPLACE INTO ip (mac,ip,last_seen,iface) VALUES (?,?,?,?)",
            use(macstr), use(ipstr), use(ts), use(deviceStr), now;
    int family = ip.af();
    _session << "INSERT OR REPLACE INTO router (mac, family) VALUES (?,?)",
            use(macstr), use(family), now;
    _logger.notice("Router address added: %s %s", macstr, ipstr);
    EventNotification::notify(EventNotification::THING_ONLINE, mac, ip, "Router");
}

bool IPDataObject::isRouter(const MAC& mac, int af)
{
    std::string macStr = mac.toString();
    bool router = false;
    _session << "SELECT 1 FROM router WHERE mac=? AND family=?", use(macStr), use(af), into(router), now;
    return router;
}

void IPDataObject::findAll(IPData::Container& container)
{
    _session << "SELECT mac, ip, last_seen,iface FROM ip", into(container), now;
}

void IPDataObject::findOnline(IPData::Container& container)
{
    Poco::Timespan interval = Poco::Timespan::MINUTES * Poco::Util::Application::instance().config().getUInt("ion.offline-interval", 10);
    Poco::Timestamp ts;
    ts -= interval;
    std::time_t last = ts.epochTime();
    _session << "SELECT mac, ip, last_seen,iface FROM ip WHERE last_seen>?", use(last), into(container), now;
}

bool IPDataObject::exists(const Poco::Net::IPAddress& ip, const MAC& mac)
{
    std::string ipstr = ip.toString();
    std::string macstr = mac.toString();
    bool exists = false;
    _session << "SELECT DISTINCT 1 FROM ip WHERE mac=? AND ip=?", use(macstr), use(ipstr), into(exists), now;
    return exists;
}

bool IPDataObject::exists(const MAC& mac)
{
    std::string macstr(mac.toString());
    bool exists = false;
    _session << "SELECT DISTINCT 1 FROM ip WHERE mac=?", use(macstr), into(exists), now;
    return exists;

}

