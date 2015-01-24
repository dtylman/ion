/*
 * File:   ModelSubsystem.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 6:42 PM
 */

#include "ModelSubsystem.h"
#include "DissectSubsystem.h"

#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Delegate.h>

ModelSubsystem::ModelSubsystem()
{
}

ModelSubsystem::~ModelSubsystem()
{
}

void ModelSubsystem::initialize(Poco::Util::Application& app)
{
    Poco::Data::SQLite::Connector::registerConnector();
    //   app.getSubsystem<DissectSubsystem>().onFrame += Poco::Delegate()
}

const char* ModelSubsystem::name() const
{
    return "ModelSubsystem";
}

void ModelSubsystem::uninitialize()
{
    Poco::Data::SQLite::Connector::unregisterConnector();
}

