/*
 * File:   IPDataObject.h
 * Author: danny
 *
 * Created on January 28, 2015, 8:51 AM
 */

#ifndef IPDATAOBJECT_H
#define	IPDATAOBJECT_H

#include "MAC.h"
#include "DataObject.h"
#include <Poco/Net/IPAddress.h>

class IPDataObject : public DataObject
{
public:
    IPDataObject(const Poco::Data::Session& session);
    virtual ~IPDataObject();
    void createTable();
    void addAddress(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void addRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void routerSuspected(const Poco::Net::IPAddress& ip, const MAC& mac);
    bool isRouter(const MAC& mac, int af);
private:

};

#endif	/* IPDATAOBJECT_H */

