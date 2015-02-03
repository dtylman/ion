/*
 * File:   ModelSubsystem.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 6:42 PM
 */

#include "DataSubsystem.h"
#include "DissectSubsystem.h"
#include "IPDataObserver.h"
#include "ThingDataObject.h"
#include "ThingObserver.h"
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Delegate.h>
#include <Poco/Util/Application.h>
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
    _observers.push_back(new IPDataObserver(createSession()));
    _observers.push_back(new ThingObserver(createSession()));
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
	Poco::Path dbFile(Poco::Util::Application::instance().config().getString("application.dir"));
	dbFile.setFileName("ion.db");
    Poco::Data::Session session(Poco::Data::SQLite::Connector::KEY, dbFile.absolute().toString());
    session.setConnectionTimeout(30000); // 30 seconds
    session << "PRAGMA synchronous = OFF", now;
    session << "PRAGMA journal_mode = MEMORY", now;
    return session;
}
