/*
 * File:   DHCPOSDataObject.h
 * Author: danny
 *
 * Created on February 3, 2015, 10:05 AM
 */

#ifndef DHCPOSDATAOBJECT_H
#define	DHCPOSDATAOBJECT_H

#include "DataObject.h"
#include <Poco/Logger.h>

class DHCPOSDataObject : public DataObject
{
public:
    DHCPOSDataObject(const Poco::Data::Session& session);
    virtual ~DHCPOSDataObject();

    std::string findOS(const std::string& vendor, const std::string& hostname);
private:
    Poco::Logger& _logger;
};

#endif	/* DHCPOSDATAOBJECT_H */

