/*
 * File:   PcapDevice.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 2:44 PM
 */

#include "PcapDevice.h"
#include <Poco/Format.h>

PcapDevice::PcapDevice()
{

}

PcapDevice::~PcapDevice()
{
}

void PcapDevice::addAddress(const PcapIfaceAddress& address)
{
    _addresses.push_back(address);
}

void PcapDevice::setName(const std::string& pcapName, const std::string& name)
{
    _pcapName = pcapName;
    _name = name;
}

Poco::Net::IPAddress PcapDevice::getIPAddress(Poco::Net::IPAddress::Family family) const
{
    for (auto address : _addresses) {
        const Poco::Net::IPAddress& ip = address.ip();
        if ((ip.family() == family) && (ip.isUnicast())) {
            return address.ip();
        }
    }
    return Poco::Net::IPAddress(family);
}

const std::string& PcapDevice::systemName() const
{

    return _name;
}

const std::string& PcapDevice::pcapName() const
{
    return _pcapName;
}

std::string PcapDevice::toString() const
{
    return Poco::format("%s pcapName: %s. IPv4: %s IPv6: %s", _name, _pcapName,
                        getIPAddress(Poco::Net::IPAddress::Family::IPv4).toString(),
                        getIPAddress(Poco::Net::IPAddress::Family::IPv6).toString());
}
