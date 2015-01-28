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

class HostDataObject : public DataObject
{
public:
    HostDataObject(const Poco::Data::Session& session);
    void createTable();
    void addHostInfo(const MAC& mac, const std::string& hostName, const std::string& dhcpVendor, const std::string& iface);
    virtual ~HostDataObject();
private:

};

#endif	/* HOSTDATAOBJECT_H */

