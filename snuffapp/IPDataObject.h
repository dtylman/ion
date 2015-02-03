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
#include "IPData.h"
#include <Poco/Net/IPAddress.h>
#include <Poco/Logger.h>

class IPDataObject : public DataObject
{
public:
    IPDataObject(const Poco::Data::Session& session);
    virtual ~IPDataObject();
    void addIP(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void removeIP(const Poco::Net::IPAddress& ip, const MAC& mac);
    void addRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void routerSuspected(const Poco::Net::IPAddress& ip, const MAC& mac);
    bool isRouter(const MAC& mac, int af);
    void findAll(IPData::Container& container);
    void findOnline(IPData::Container& container);
    bool exists(const Poco::Net::IPAddress& ip, const MAC& mac);
    bool exists(const MAC& mac);
private:
    Poco::Logger& _logger;
};

#endif	/* IPDATAOBJECT_H */

