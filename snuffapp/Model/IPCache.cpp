/*
 * File:   IPCache.cpp
 * Author: danny
 *
 * Created on January 25, 2015, 11:46 AM
 */

#include "IPCache.h"
#include <Poco/Timespan.h>
#include <Poco/Hash.h>

IPCache::IPCache() : _cache(Poco::Timespan::MINUTES * 3)
{
}

IPCache::~IPCache()
{
}

bool IPCache::exists(const MAC& mac, const Poco::Net::IPAddress& ip, const std::string& iface)
{
    std::string key = mac.toString() + ip.toString() + iface;
    if (_cache.has(key)) {
        return true;
    }
    _cache.add(key, Poco::Timestamp());
}
