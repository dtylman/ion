/*
 * File:   TableDevice.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 9:55 AM
 */

#include "TableThing.h"

using namespace Poco::Data::Keywords;

TableThing::TableThing(Poco::Data::Session& session) : _session(session)
{

}

TableThing::~TableThing()
{
}

void TableThing::create()
{
    _session << "CREATE TABLE IF NOT EXISTS thing (mac TEXT NOT NULL,type TEXT, name TEXT, vendor TEXT, os TEXT, desc TEXT)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_thing on thing (mac ASC)", now;
}
