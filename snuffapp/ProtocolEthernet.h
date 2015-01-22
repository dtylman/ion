/*
 * File:   ProtocolEthernet.h
 * Author: danny
 *
 * Created on January 22, 2015, 11:17 AM
 */

#ifndef PROTOCOLETHERNET_H
#define	PROTOCOLETHERNET_H

#include "Frame.h"
#include <string>

class ProtocolEthernet : public Protocol
{
public:
    ProtocolEthernet();
    static std::string Name;
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;
protected:
    virtual ~ProtocolEthernet();
private:
    MAC _sourceMAC;
    MAC _destMAC;
	Poco::UInt16 _ethType = 0;

};

#endif	/* PROTOCOLETHERNET_H */

