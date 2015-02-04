/*
 * File:   IPData.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 11:33 AM
 */

#include "IPData.h"
#include <Poco/Format.h>

IPData::IPData()
{
}

IPData::~IPData()
{
}

const std::string& IPData::iface() const
{
    return _iface;
}

const Poco::Net::IPAddress& IPData::ip() const
{
    return _ip;
}

const Poco::Timestamp& IPData::lastSeen() const
{
    return _lastSeen;
}

const MAC& IPData::mac() const
{
    return _mac;
}

void IPData::setIP(const Poco::Net::IPAddress& ip)
{
    _ip = ip;
}

void IPData::setIface(const std::string& iface)
{
    _iface = iface;
}

void IPData::setLastSeen(const Poco::Timestamp& lastSeen)
{
    _lastSeen = lastSeen;
}

void IPData::setMAC(const MAC& mac)
{
    _mac = mac;
}

std::string IPData::toString() const
{
    return Poco::format("%s %s %s", _mac.toString(), _ip.toString(), _iface);
}
