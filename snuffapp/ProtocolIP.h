/*
 * File:   ProtocolIP.h
 * Author: danny
 *
 * Created on January 22, 2015, 11:51 AM
 */

#ifndef PROTOCOLIP_H
#define	PROTOCOLIP_H

#include "Protocol.h"
#include <Poco/Net/IPAddress.h>

class ProtocolIP : public Protocol
{
public:
    ProtocolIP();
    static std::string Name;
    virtual const std::string& name() const;
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual std::string toString() const;
protected:
    virtual ~ProtocolIP();
private:
    Poco::UInt8 _protocol;
    Poco::UInt8 _ttl;
    Poco::Net::IPAddress _source;
    Poco::Net::IPAddress _dest;
};

#endif	/* PROTOCOLIP_H */

