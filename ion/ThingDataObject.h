/*
 * File:   HostDataObject.h
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#ifndef HOSTDATAOBJECT_H
#define	HOSTDATAOBJECT_H

#include "DataObject.h"
#include "MAC.h"
#include <Poco/Logger.h>

class ThingDataObject : public DataObject
{
public:
    ThingDataObject(const Poco::Data::Session& session);
    virtual ~ThingDataObject();

    void setType(const MAC& mac, const std::string& type);
    void setName(const MAC& mac, const std::string& name);
    void setOS(const MAC& mac, const std::string& os);
    bool exists(const MAC& mac);
private:
    Poco::Logger& _logger;
};

#endif	/* HOSTDATAOBJECT_H */

