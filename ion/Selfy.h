/*
 * File:   Selfy.h
 * Author: danny
 *
 * Created on February 4, 2015, 10:26 AM
 */

#ifndef SELFY_H
#define	SELFY_H

#include <Poco/Logger.h>
#include <Poco/Net/IPAddress.h>

#include "ThingData.h"

class Selfy
{
public:
    Selfy();
    virtual ~Selfy();
    void reportNetworkConfig();
    void findRouters();
private:
    void updateMyThing();
    void updateMyAddresses();
    Poco::Logger& _logger;
};

#endif	/* SELFY_H */

