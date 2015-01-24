/*
 * File:   ProtocolARP.h
 * Author: danny
 *
 * Created on January 22, 2015, 11:51 AM
 */

#ifndef PROTOCOLARP_H
#define	PROTOCOLARP_H

#include "Protocol.h"
#include "MAC.h"
#include <Poco/Net/IPAddress.h>

class ProtocolARP : public Protocol
{
public:
    ProtocolARP();
    static const std::string Name;
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;
protected:
    virtual ~ProtocolARP();
private:
    Poco::UInt16 _opCode;
    MAC _senderMAC;
    Poco::Net::IPAddress _senderIP;
    MAC _targetMAC;
    Poco::Net::IPAddress _targetIP;

};

#endif	/* PROTOCOLARP_H */

