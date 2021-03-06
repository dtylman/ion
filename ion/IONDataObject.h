/*
 * File:   IONDataObject.h
 * Author: danny
 *
 * Created on February 18, 2015, 3:47 PM
 */

#ifndef IONDATAOBJECT_H
#define	IONDATAOBJECT_H

#include "IPData.h"
#include "DataObject.h"
#include "MAC.h"
#include "ThingData.h"
#include <Poco/Net/IPAddress.h>
#include <Poco/UUID.h>
#include <Poco/Logger.h>

class IONDataObject : public DataObject
{
public:
    IONDataObject(const Poco::Data::Session& session);
    virtual ~IONDataObject();

    void setThing(const ThingData& thing, bool overwrite);
    void removeThing(const Poco::UUID& thingid);
    bool getThingByMAC(const MAC& mac, ThingData& thing);
    bool getThing(const Poco::UUID& thingID, ThingData& thing);
    bool getThing(const IPData& ip, ThingData& thing);
    void removeIP(const IPData& ip);
    void setRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void setSuspectedRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void setOnline(IPData& data, bool ignoreRouterMAC = false);
    bool ipExists(const IPData& data);
    bool isOnline(const IPData& data);
    void setOffline(const IPData& data);
    bool isRouter(const MAC& mac, const Poco::Net::IPAddress::Family& family);
    void findIPs(IPData::Container& container);
    void findThingIPs(const Poco::UUID& thingid, IPData::Container & container);
    void findOnlineIPs(IPData::Container& container);
    bool macExists(const MAC& mac);
    bool thingExists(const ThingData& thing);
    bool thingIDExists(const Poco::UUID& thingID);
    void authorizeThing(const Poco::UUID& thingID, bool authorize);
    bool thingAuthorized(const Poco::UUID& thingID);
private:
    void removeThingData(const ThingData& thing);

    void onThingAdded(const ThingData& thing);
    void onThingRemoved(const ThingData& thing);
    void onIPAdded(const IPData& ip);
    void onIPOnline(const IPData& ip);
    void onIPOffline(const IPData& ip);
    int getFamNum(const Poco::Net::IPAddress::Family fam) const;
    Poco::Logger& _logger;
};

#endif	/* IONDATAOBJECT_H */

