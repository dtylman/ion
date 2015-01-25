/*
 * File:   MAC.h
 * Author: danny
 *
 * Created on January 20, 2015, 6:01 PM
 */

#ifndef MAC_H
#define	MAC_H

#include <Poco/Net/NetworkInterface.h>
#include <Poco/Types.h>
#include <string>

class MAC : public Poco::Net::NetworkInterface::MACAddress
{
public:
    MAC();
    MAC(const Poco::UInt8* address);
    virtual ~MAC();
    std::string toString(const std::string& byteFormat = "%02x") const;
    std::string toString(const std::string& byteFormat, size_t size) const;
    std::string vendorPrefix() const;
    bool isUnicast() const;
    bool isWildcard() const;
    bool isMulticast() const;
    bool isBroadcast() const;
};

#endif	/* MAC_H */

