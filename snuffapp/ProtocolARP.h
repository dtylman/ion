/*
 * File:   ProtocolARP.h
 * Author: danny
 *
 * Created on January 22, 2015, 11:51 AM
 */

#ifndef PROTOCOLARP_H
#define	PROTOCOLARP_H

#include "Protocol.h"

class ProtocolARP : public Protocol
{
public:
    ProtocolARP();
    static std::string Name;
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;
protected:
    virtual ~ProtocolARP();

};

#endif	/* PROTOCOLARP_H */

