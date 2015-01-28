/*
 * File:   ModelSubsystem.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 6:42 PM
 */

#include "DataSubsystem.h"
#include "DissectSubsystem.h"
#include "IPDataObserver.h"
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

    IPDataObject(createSession()).createTable();

    addObserver(new IPDataObserver(createSession()));


    //addModel(new HostnameModel());
    //   app.getSubsystem<DissectSubsystem>().onFrame += Poco::Delegate()
}

const char* DataSubsystem::name() const
{
    return "ModelSubsystem";
}

void DataSubsystem::uninitialize()
{
    Poco::Data::SQLite::Connector::unregisterConnector();
}

void DataSubsystem::addObserver(DataObserver* model)
{
    poco_check_ptr(model);
    model->initialize();
}

Poco::Data::Session DataSubsystem::createSession()
{
    Poco::Data::Session session(Poco::Data::SQLite::Connector::KEY, "zakif.db");
    session.setConnectionTimeout(30000); // 30 seconds
    session << "PRAGMA synchronous = OFF", now;
    session << "PRAGMA journal_mode = MEMORY", now;
    return session;
}
