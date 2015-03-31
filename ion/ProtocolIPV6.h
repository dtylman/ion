/*
 * File:   ProtocolIPV6.h
 * Author: danny
 *
 * Created on February 24, 2015, 5:50 PM
 */

#ifndef PROTOCOLIPV6_H
#define	PROTOCOLIPV6_H

#include "Protocol.h"

class ProtocolIPV6 : public Protocol
{
public:
    static const std::string Name;
    ProtocolIPV6();
    virtual ~ProtocolIPV6();
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;
};

#endif	/* PROTOCOLIPV6_H */

