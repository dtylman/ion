/*
 * File:   PcapDevice.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 2:44 PM
 */

#include "PcapDevice.h"

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
        if (address.ip().family() == family) {
            return address.ip();
        }
    }
}

const std::string& PcapDevice::systemName() const
{
	return _name;
}
const std::string& PcapDevice::pcapName() const
{
	return _pcapName;
}