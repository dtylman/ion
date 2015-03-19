/*
 * File:   ProtocolIPV6.cpp
 * Author: danny
 *
 * Created on February 24, 2015, 5:50 PM
 */

#include "ProtocolIPV6.h"

const std::string ProtocolIPV6::Name("IPv6");

ProtocolIPV6::ProtocolIPV6()
{
}

ProtocolIPV6::~ProtocolIPV6()
{
}
#pragma pack(push, 1)

struct IPV6Header
{
    Poco::UInt32 version : 4,
    traffic_class : 8,
    flow_label : 20;
    Poco::UInt32 length;
    Poco::UInt8 next_header;
    Poco::UInt8 hop_limit;
    Poco::UInt8 src[16];
    Poco::UInt8 dest[16];
};
#pragma pack(pop)

bool ProtocolIPV6::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (IPV6Header))) {
        return false;
    }
    struct IPV6Header* header = (struct IPV6Header*) (buffer.begin() + offset);
    //    _ttl = header->ttl;
    //    _protocol = header->protocol;
    //    if (_protocol == 0x11) // UDP
    //    {
    //        next = new ProtocolUDP();
    //    }
    //    else {
    //        next = nullptr;
    //    }
    //    _source = Poco::Net::IPAddress(&header->srcaddr, sizeof (header->srcaddr));
    //    _dest = Poco::Net::IPAddress(&header->destaddr, sizeof (header->destaddr));
    offset += sizeof (IPV6Header);
    return true;
}

const std::string& ProtocolIPV6::name() const
{
    return Name;
}

std::string ProtocolIPV6::toString() const
{
    return "No data yet";
}
