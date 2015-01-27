/*
 * File:   IPCache.h
 * Author: danny
 *
 * Created on January 25, 2015, 11:46 AM
 */

#ifndef IPCACHE_H
#define	IPCACHE_H

#include "MAC.h"
#include <Poco/Net/IPAddress.h>
#include <Poco/ExpireCache.h>
#include <Poco/Timestamp.h>

class IPCache
{
public:
    IPCache();
    virtual ~IPCache();
    bool exists(const MAC& mac, const Poco::Net::IPAddress& ip, const std::string& iface);
private:
    Poco::ExpireCache<std::string, Poco::Timestamp> _cache;
};

#endif	/* IPCACHE_H */

