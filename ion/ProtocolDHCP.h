/*
 * File:   ProtocolDHCP.h
 * Author: danny
 *
 * Created on January 28, 2015, 2:29 PM
 */

#ifndef PROTOCOLDHCP_H
#define	PROTOCOLDHCP_H

#include "Protocol.h"
#include "MAC.h"
#include <map>

class ProtocolDHCP : public Protocol
{
public:
    ProtocolDHCP();
    static const std::string Name;
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next);
    virtual const std::string& name() const;
    virtual std::string toString() const;
    std::string getOption(Poco::UInt8 option) const;
    bool isRequest() const;
    const MAC& clientMAC() const;
protected:
    virtual ~ProtocolDHCP();
private:
    bool parseOption(const FrameBuffer& buffer, size_t& offset);
    Poco::UInt8 _type;
    MAC _clientMAC;
    Poco::Net::IPAddress _assignedIP;
    typedef std::map<Poco::UInt8, std::string> Options;
    Options _options;
};

#endif	/* PROTOCOLDHCP_H */

