/*
 * File:   ProtocolUDP.h
 * Author: danny
 *
 * Created on January 22, 2015, 3:18 PM
 */

#ifndef PROTOCOLUDP_H
#define	PROTOCOLUDP_H

#include "Protocol.h"

class ProtocolUDP : public Protocol
{
public:
    ProtocolUDP();
    static const std::string Name;
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;
protected:
    virtual ~ProtocolUDP();
private:
    Poco::UInt16 _source;
    Poco::UInt16 _dest;
    Poco::UInt16 _length;
    Poco::UInt16 _checksum;
};

#endif	/* PROTOCOLUDP_H */

