/*
 * File:   ProtocolNBDatagram.h
 * Author: danny
 *
 * Created on January 22, 2015, 3:40 PM
 */

#ifndef PROTOCOLNBDATAGRAM_H
#define	PROTOCOLNBDATAGRAM_H

#include "Protocol.h"

class ProtocolNBDatagram : public Protocol
{
public:
    ProtocolNBDatagram();
    const static std::string Name;

    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;
protected:
    virtual ~ProtocolNBDatagram();
private:
    std::string decodeName(const Poco::UInt8* nbName, size_t len);
    std::string _destName;
    std::string _srcName;
};

#endif	/* PROTOCOLNBDATAGRAM_H */

