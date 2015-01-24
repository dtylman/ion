/*
 * File:   Model.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 8:53 PM
 */

#include "Model.h"
#include <Poco/Data/SQLite/Connector.h>
using namespace Poco::Data::Keywords;

Model::Model() : _session(Poco::Data::SQLite::Connector::KEY, "zakif.db")
{
    _session << "PRAGMA synchronous = OFF", now;
    _session << "PRAGMA journal_mode = MEMORY", now;
}

Model::~Model()
{
}

