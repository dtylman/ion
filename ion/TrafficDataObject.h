/*
 * File:   TrafficDataObject.h
 * Author: danny
 *
 * Created on March 11, 2015, 5:22 PM
 */

#ifndef TRAFFICDATAOBJECT_H
#define	TRAFFICDATAOBJECT_H

#include "DataObject.h"
#include "TrafficData.h"
#include <Poco/Logger.h>

class TrafficDataObject : public DataObject
{
public:
    TrafficDataObject(const Poco::Data::Session& session);
    virtual ~TrafficDataObject();

    void insert(TrafficData& trafficData);
    void deleteOld();
    void checkAuthStatus();
    void authorizeTraffic();
    void authorizeDomain(const std::string& name);
private:
    Poco::Logger& _logger;
};

#endif	/* TRAFFICDATAOBJECT_H */

