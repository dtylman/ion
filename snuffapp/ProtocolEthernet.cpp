/*
 * File:   ProtocolEthernet.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 11:17 AM
 */

#include "ProtocolEthernet.h"
#include "ProtocolARP.h"
#include "ProtocolIP.h"
#include <Poco/Format.h>
#ifdef POCO_OS_FAMILY_WINDOWS
#include <WinSock2.h>
#else
#include <netinet/in.h>
#endif

std::string ProtocolEthernet::Name("ETH");

ProtocolEthernet::ProtocolEthernet()
{
}

ProtocolEthernet::~ProtocolEthernet()
{
}

#pragma pack(push, 1)

struct EtherHeader
{
    Poco::UInt8 dest[6];
    Poco::UInt8 src[6];
    Poco::UInt16 type;
};
#pragma pack(pop)

bool ProtocolEthernet::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (EtherHeader))) {
        return false;
    }
    struct EtherHeader * header = (struct EtherHeader*) (buffer.begin() + offset);
    _destMAC.assign(header->dest, header->dest + 6);
    _sourceMAC.assign(header->src, header->src + 6);
    _ethType = ntohs(header->type);
    if (_ethType == 0x0800) { //IPv4
        next = new ProtocolIP();
    }
    else if (_ethType == 0x0806) { //ARP
        next = new ProtocolARP();
    }
    else if (_ethType == 0x8035) { //RARP

    }
    else if (_ethType == 0x86DD) { //IPv6

    }
    offset += sizeof (EtherHeader);
    return true;

}

const std::string& ProtocolEthernet::name() const
{
    return ProtocolEthernet::Name;
}

std::string ProtocolEthernet::toString() const
{
    return Poco::format("SRC: %s, DEST: %s, TYPE: %hX", _sourceMAC.toString(), _destMAC.toString(), _ethType);
}
