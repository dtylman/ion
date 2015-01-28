/*
 * File:   IPDataObject.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 8:51 AM
 */

#include "IPDataObject.h"
#include <Poco/Timestamp.h>

using namespace Poco::Data::Keywords;

IPDataObject::IPDataObject(const Poco::Data::Session& session) : DataObject(session)
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
    std::string ipStr = ip.toString();
    std::string macSTR = mac.toString();
    std::string ifaceStr = iface;
    Poco::UInt64 ts = Poco::Timestamp().epochMicroseconds();
    _session << "INSERT OR REPLACE INTO ip (mac,ip,last_seen,iface) VALUES (?,?,?,?)",
            use(macSTR), use(ipStr), use(ts), use(ifaceStr), now;
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
        std::string macStr = mac.toString();
        int family = ip.af();
        _session << "SELECT count(ip) FROM ip WHERE mac=?", use(macStr), into(count), now;
        if (count > 3) {
            _session << "INSERT OR REPLACE INTO router (mac, family) VALUES (?,?)", use(macStr), use(family), now;
            _session << "DELETE FROM ip WHERE mac=?", use(macStr), now;
        }
    }
}

void IPDataObject::addRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device)
{
    if ((!ip.isUnicast()) || (!mac.isUnicast())) {
        return;
    }
    std::string macStr = mac.toString();
    std::string ipStr = ip.toString();
    _session << "DELETE FROM ip WHERE mac=? and ip!=?", use(macStr), use(ipStr), now;
    Poco::UInt64 ts = Poco::Timestamp().epochMicroseconds();
    std::string deviceStr = device;
    _session << "INSERT OR REPLACE INTO ip (mac,ip,last_seen,iface) VALUES (?,?,?,?)",
            use(macStr), use(ipStr), use(ts), use(deviceStr), now;
    int family = ip.af();
    _session << "INSERT OR REPLACE INTO router (mac, family) VALUES (?,?)",
            use(macStr), use(family), now;

}

void IPDataObject::createTable()
{
    _session << "CREATE TABLE IF NOT EXISTS ip (mac TEXT NOT NULL,ip TEXT NOT NULL,last_seen INTEGER NOT NULL, iface TEXT)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_ip on ip (mac ASC, ip ASC, iface ASC)", now;
    _session << "CREATE TABLE IF NOT EXISTS router (mac TEXT NOT NULL, family INTEGER NOT NULL)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_router on router (mac ASC, family ASC)", now;
}

bool IPDataObject::isRouter(const MAC& mac, int af)
{
    std::string macStr = mac.toString();
    bool router = false;
    _session << "SELECT 1 FROM router WHERE mac=? AND family=?", use(macStr), use(af), into(router), now;
    return router;
}
