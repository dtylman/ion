/*
 * File:   TrafficData.cpp
 * Author: danny
 *
 * Created on March 11, 2015, 4:59 PM
 */

#include "TrafficData.h"
#include <Poco/Format.h>
#include <Poco/Hash.h>

TrafficData::TrafficData()
{

}

TrafficData::TrafficData(const MAC& mac, const Poco::Net::IPAddress& ip, Poco::UInt16 port, const std::string& transport) :
_mac(mac), _ip(ip), _port(port), _transport(transport)
{

}

TrafficData::~TrafficData()
{
}

const Poco::UInt32 TrafficData::count() const
{
    return _count;
}

void TrafficData::setCount(Poco::UInt32 count)
{
    _count = count;
}

const std::string& TrafficData::process() const
{
    return _process;
}

void TrafficData::setHost(const std::string& host)
{
    _host = host;
}

void TrafficData::setProcess(const std::string& process)
{
    _process = process;
}

void TrafficData::setTime(const Poco::Timestamp& timestamp)
{
    _time = timestamp;
}

void TrafficData::setIP(const Poco::Net::IPAddress& toIP)
{
    _ip = toIP;
}

void TrafficData::setMAC(const MAC& mac)
{
    _mac = mac;
}

const Poco::Timestamp& TrafficData::time() const
{
    return _time;
}

const std::string& TrafficData::host() const
{
    return _host;
}

const Poco::Net::IPAddress& TrafficData::ip() const
{
    return _ip;
}

const MAC& TrafficData::mac() const
{
    return _mac;
}

const Poco::UInt16 TrafficData::port() const
{
    return _port;
}

const std::string& TrafficData::transport() const
{
    return _transport;
}

void TrafficData::setPort(Poco::UInt16 port)
{
    _port = port;
}

void TrafficData::setTransport(const std::string& transport)
{
    _transport = transport;
}

std::string TrafficData::toString() const
{
    return Poco::format("%s %s:%hu (%s)", _transport, _ip.toString(), _port, _host);
}

std::size_t TrafficData::hash() const
{
    return Poco::hash(Poco::format("%s %s %s %hu", _mac.toString(), _ip.toString(), _transport, _port));
}

void TrafficData::update()
{
    _count++;
}

const std::string& TrafficData::domain() const
{
    return _domain;
}

void TrafficData::setDomain(const std::string& domain)
{
    _domain = domain;
}
