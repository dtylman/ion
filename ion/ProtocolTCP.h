/*
 * File:   ProtocolTCP.h
 * Author: danny
 *
 * Created on March 10, 2015, 4:32 PM
 */

#ifndef PROTOCOLTCP_H
#define	PROTOCOLTCP_H

#include "Protocol.h"

class ProtocolTCP : public Protocol
{
public:
    ProtocolTCP();
    static const std::string Name;

    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;

    bool isSynAck() const;
protected:
    virtual ~ProtocolTCP();
private:
    Poco::UInt16 _source;
    Poco::UInt16 _dest;
    bool _ack = false;
    bool _syn = false;
    Poco::UInt8* _options = nullptr;
};

#endif	/* PROTOCOLTCP_H */

