/*
 * File:   PcapDevice.h
 * Author: danny
 *
 * Created on January 27, 2015, 2:44 PM
 */

#ifndef PCAPDEVICE_H
#define	PCAPDEVICE_H

#include "PcapIfaceAddress.h"

class PcapDevice
{
public:
    PcapDevice();
    virtual ~PcapDevice();

    void setName(const std::string& pcapName, const std::string& name);
    void addAddress(const PcapIfaceAddress& address);
    Poco::Net::IPAddress getIPAddress(Poco::Net::IPAddress::Family family) const;
private:
    PcapIfaceAddress::Container _addresses;
    std::string _name;
    std::string _pcapName;
};

#endif	/* PCAPDEVICE_H */

