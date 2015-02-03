/*
 * File:   TableIP.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 9:55 AM
 */

#include "TableIP.h"
using namespace Poco::Data::Keywords;

TableIP::TableIP(Poco::Data::Session& session) : _session(session)
{

}

TableIP::~TableIP()
{
}

void TableIP::create()
{
    _session << "CREATE TABLE IF NOT EXISTS ip (mac TEXT NOT NULL,ip TEXT NOT NULL,last_seen INTEGER NOT NULL, iface TEXT)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_ip on ip (mac ASC, ip ASC, iface ASC)", now;
    _session << "CREATE TABLE IF NOT EXISTS router (mac TEXT NOT NULL, family INTEGER NOT NULL)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_router on router (mac ASC, family ASC)", now;
}
