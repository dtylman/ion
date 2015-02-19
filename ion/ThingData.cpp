/*
 * File:   ThingData.cpp
 * Author: danny
 *
 * Created on February 18, 2015, 4:01 PM
 */

#include "ThingData.h"
#include <Poco/UUIDGenerator.h>

ThingData::ThingData()
{
    _uuid = Poco::UUIDGenerator::defaultGenerator().create();
}

ThingData::~ThingData()
{
}

const std::string& ThingData::desc() const
{
    return _desc;
}

const std::string& ThingData::name() const
{
    return _name;
}

const std::string& ThingData::os() const
{
    return _os;
}

void ThingData::setDesc(const std::string& desc)
{
    _desc = desc;
}

void ThingData::setName(const std::string& name)
{
    _name = name;
}

void ThingData::setOS(const std::string& os)
{
    _os = os;
}

void ThingData::setType(const std::string& type)
{
    _type = type;
}

void ThingData::setUUID(const Poco::UUID& uuid)
{
    _uuid = uuid;
}

const std::string& ThingData::type() const
{
    return _type;
}

const Poco::UUID& ThingData::uuid() const
{
    return _uuid;
}

const std::string& ThingData::vendor() const
{
    return _vendor;
}

void ThingData::setVendor(const std::string& vendor)
{
    _vendor = vendor;
}

