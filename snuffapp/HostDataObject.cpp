/*
 * File:   HostDataObject.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#include "HostDataObject.h"

using namespace Poco::Data::Keywords;

//seen, host-name, guessed os, mac-vendor, current_ip, given: given type, given manufaturer, given os, given description

HostDataObject::HostDataObject(const Poco::Data::Session& session) : DataObject(session)
{
}

HostDataObject::~HostDataObject()
{
}

void HostDataObject::createTable()
{
    _session << "CREATE TABLE IF NOT EXISTS host (mac TEXT NOT NULL,hostname TEXT, os TEXT,last_seen INTEGER NOT NULL, iface TEXT)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_host on host (mac ASC)", now;
}

void HostDataObject::addHostInfo(const MAC& mac, const std::string& hostName, const std::string& dhcpVendor, const std::string& iface)
{
    std::string macStr = mac.toString();
    std::string hostStr = hostName;
    std::string osStr = dhcpVendor;
    Poco::UInt64 ts = Poco::Timestamp().epochMicroseconds();
    std::string ifaceStr = iface;
    _session << "INSERT OF REPLACE INTO host (mac,hostname,os,last_seen,iface VALUES (?,?,?,?,?)",
            use(macStr), use(hostStr), use(osStr), use(ts), use(ifaceStr), now;
}

