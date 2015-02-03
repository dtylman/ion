/*
 * File:   TableIP.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 9:55 AM
 */

#include "Tables.h"
using namespace Poco::Data::Keywords;

Tables::Tables(Poco::Data::Session& session) : _session(session)
{

}

Tables::~Tables()
{
}

void Tables::create()
{
    _session << "CREATE TABLE ip (mac TEXT NOT NULL,ip TEXT NOT NULL,last_seen INTEGER NOT NULL, iface TEXT)", now;
    _session << "CREATE UNIQUE INDEX pk_ip on ip (mac ASC, ip ASC, iface ASC)", now;

    _session << "CREATE TABLE router (mac TEXT NOT NULL, family INTEGER NOT NULL)", now;
    _session << "CREATE UNIQUE INDEX pk_router on router (mac ASC, family ASC)", now;

    _session << "CREATE TABLE thing (mac TEXT NOT NULL,type TEXT, name TEXT, vendor TEXT, os TEXT, desc TEXT)", now;
    _session << "CREATE UNIQUE INDEX pk_thing on thing (mac ASC)", now;

    _session << "CREATE TABLE event (time INTEGER NOT NULL, name TEXT NOT NULL, mac TEXT ,ip TEXT, details TEXT)", now;
    _session << "CREATE INDEX pk_event on event (time ASC, name ASC)", now;

}
