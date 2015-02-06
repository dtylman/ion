/*
 * File:   DataObject.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 9:02 AM
 */

#include "DataObject.h"

DataObject::DataObject(const Poco::Data::Session& session) : _session(session)
{

}

DataObject::~DataObject()
{
}

