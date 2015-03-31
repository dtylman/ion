/*
 * File:   ProtocolIP.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 11:51 AM
 */

#include "ProtocolIP.h"
#include "ProtocolUDP.h"
#include "ProtocolTCP.h"
#include <Poco/Format.h>

const std::string ProtocolIP::Name("IP");

ProtocolIP::ProtocolIP()
{
}

ProtocolIP::~ProtocolIP()
{
}

#pragma pack(push, 1)

struct IPHeader
{
    Poco::UInt8 len : 4;
    Poco::UInt8 version : 4;
    Poco::UInt8 tos;
    Poco::UInt16 totalLen;
    Poco::UInt16 id;
    Poco::UInt16 fragOffset;
    Poco::UInt8 ttl;
    Poco::UInt8 protocol;
    Poco::UInt16 checksum;
    Poco::UInt32 srcaddr;
    Poco::UInt32 destaddr;
};
#pragma pack(pop)

bool ProtocolIP::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (IPHeader))) {
        return false;
    }
    struct IPHeader* header = (struct IPHeader*) (buffer.begin() + offset);
    _ttl = header->ttl;
    _protocol = header->protocol;
    if (_protocol == 0x11) // UDP
    {
        next = new ProtocolUDP();
    }
    else if (_protocol == 0x6) //TCP
    {
        next = new ProtocolTCP();
    }
    else {
        next = nullptr;
    }
    _source = Poco::Net::IPAddress(&header->srcaddr, sizeof (header->srcaddr));
    _dest = Poco::Net::IPAddress(&header->destaddr, sizeof (header->destaddr));
    offset += sizeof (IPHeader);
    return true;
}

const std::string& ProtocolIP::name() const
{
    return ProtocolIP::Name;
}

std::string ProtocolIP::toString() const
{
    return Poco::format("Src: %s, Dest: %s, Protocol: %d, TTL: %d", _source.toString(), _dest.toString(), (int) _protocol, (int) _ttl);
}

bool ProtocolIP::isDefaultTTL() const
{
    return ((_ttl % 32) == 0);
}

const Poco::Net::IPAddress& ProtocolIP::dest() const
{
    return _dest;
}

const Poco::Net::IPAddress& ProtocolIP::source() const
{
    return _source;
}
