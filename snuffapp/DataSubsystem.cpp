/*
 * File:   ModelSubsystem.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 6:42 PM
 */

#include "DataSubsystem.h"
#include "DissectSubsystem.h"
#include "IPDataObserver.h"
#include "HostDataObject.h"
#include "HostObserver.h"
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Delegate.h>
#include <list>

using namespace Poco::Data::Keywords;

DataSubsystem::DataSubsystem()
{
}

DataSubsystem::~DataSubsystem()
{
}

void DataSubsystem::initialize(Poco::Util::Application& app)
{
    Poco::Data::SQLite::Connector::registerConnector();

    Poco::Data::Session session = createSession();
    IPDataObject(session).createTable();
    HostDataObject(session).createTable();

    _observers.push_back(new IPDataObserver(createSession()));
    _observers.push_back(new HostObserver(createSession()));
}

const char* DataSubsystem::name() const
{
    return "DataSubsystem";
}

void DataSubsystem::uninitialize()
{
    _observers.clear();
    Poco::Data::SQLite::Connector::unregisterConnector();
}

Poco::Data::Session DataSubsystem::createSession()
{
    Poco::Data::Session session(Poco::Data::SQLite::Connector::KEY, "zakif.db");
    session.setConnectionTimeout(30000); // 30 seconds
    session << "PRAGMA synchronous = OFF", now;
    session << "PRAGMA journal_mode = MEMORY", now;
    return session;
}
