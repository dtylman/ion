/*
 * File:   ProtocolUDP.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 3:18 PM
 */

#include "ProtocolUDP.h"
#include "ProtocolNBDatagram.h"
#include "ProtocolDHCP.h"
#include <Poco/Format.h>

#ifdef POCO_OS_FAMILY_WINDOWS
#include <WinSock2.h>
#else
#include <netinet/in.h>
#endif

const std::string ProtocolUDP::Name("UDP");

ProtocolUDP::ProtocolUDP()
{
}

ProtocolUDP::~ProtocolUDP()
{
}

#pragma pack(push,1)

struct UDPHeader
{
    Poco::UInt16 source;
    Poco::UInt16 dest;
    Poco::UInt16 len;
    Poco::UInt16 checksum;
};
#pragma pack(pop)

bool ProtocolUDP::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (UDPHeader))) {
        return false;
    }
    struct UDPHeader * header = (struct UDPHeader*) (buffer.begin() + offset);
    _source = ntohs(header->source);
    _dest = ntohs(header->dest);
    _length = ntohs(header->len);
    _checksum = ntohs(header->checksum);
    offset += sizeof (UDPHeader);
    if (_source == 68) //boop-client
    {
        next = new ProtocolDHCP();
        return true;
    }
    next = nullptr;
    return true;
}

const std::string& ProtocolUDP::name() const
{
    return ProtocolUDP::Name;
}

std::string ProtocolUDP::toString() const
{
    return Poco::format("Source: %hu Dest: %hu Len: %hu Chksum: %hu", _source, _dest, _length, _checksum);
}
