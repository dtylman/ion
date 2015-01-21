/*
 * File:   IPFrame.h
 * Author: danny
 *
 * Created on January 21, 2015, 12:41 PM
 */

#ifndef IPFRAME_H
#define	IPFRAME_H

#include <Poco/Net/IPAddress.h>
#include "EtherFrame.h"

class IPFrame : public EtherFrame
{
public:
    IPFrame(const char* data, int len);

    std::string toString() const;
protected:
    virtual ~IPFrame();
    Poco::UInt8 _version;
    Poco::UInt8 _headerLen;
    Poco::UInt8 _tos;
    Poco::UInt16 _totalLen;
    Poco::UInt16 _id;
    Poco::UInt16 _fragOffset;
    Poco::UInt8 _ttl;
    Poco::UInt8 _protocol;
    Poco::UInt16 _checksum;
    Poco::Net::IPAddress _sourceIP;
    Poco::Net::IPAddress _destinationIP;
};

#endif	/* IPFRAME_H */

