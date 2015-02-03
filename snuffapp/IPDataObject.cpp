/*
 * File:   IPDataObject.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 8:51 AM
 */

#include "IPDataObject.h"
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

void IPDataObject::addAddress(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& iface)
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
    bool alreadyExists = false;
    _session << "SELECT 1 FROM ip WHERE mac=?", use(macstr), into(alreadyExists), now;
    _session << "INSERT OR REPLACE INTO ip (mac,ip,last_seen,iface) VALUES (?,?,?,?)",
            use(macstr), use(ipstr), use(ts), use(ifacestr), now;
    _logger.information("Address updated %s %s %s", macstr, ipstr, ifacestr);
    if (!alreadyExists) {
        _logger.notice("New address updated %s %s %s", macstr, ipstr, ifacestr);
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
            _logger.information("Router added: %s", macstr);
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
    _logger.information("Router address added: %s %s", macstr, ipstr);
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
    Poco::Timestamp now;
    now -= interval;
	std::time_t last = now.epochTime();
    _session << "SELECT mac, ip, last_seen,iface FROM ip WHERE last_seen>?", use(last), into(container), now;
}
