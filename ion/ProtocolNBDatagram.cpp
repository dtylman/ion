/*
 * File:   ProtocolNBDatagram.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 3:40 PM
 */

#include "ProtocolNBDatagram.h"
#include <Poco/Format.h>
#include <Poco/MemoryStream.h>

const std::string ProtocolNBDatagram::Name = "NBDGS";

ProtocolNBDatagram::ProtocolNBDatagram()
{
}

ProtocolNBDatagram::~ProtocolNBDatagram()
{
}

#pragma pack(push,1)

struct NBDatagram
{
    Poco::UInt8 msgType;
    Poco::UInt8 flags;
    Poco::UInt16 id;
    Poco::UInt32 srcIP;
    Poco::UInt16 srcPort;
    Poco::UInt16 length;
    Poco::UInt16 offset;
    Poco::UInt8 srcName[34];
    Poco::UInt8 destName[34];
};
#pragma pack(pop)

bool ProtocolNBDatagram::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (NBDatagram))) {
        return false;
    }
    struct NBDatagram * datagram = (struct NBDatagram*) (buffer.begin() + offset);

    _destName = decodeName(datagram->destName, 34);
    _srcName = decodeName(datagram->srcName, 34);
    offset += sizeof (struct NBDatagram);
    next = nullptr;
    return true;
}

const std::string& ProtocolNBDatagram::name() const
{
    return ProtocolNBDatagram::Name;
}

std::string ProtocolNBDatagram::toString() const
{
    return Poco::format("DestName: %s, SrcName: %s", _destName, _srcName);
}


//http://support.microsoft.com/kb/194203

std::string ProtocolNBDatagram::decodeName(const Poco::UInt8* nbName, size_t len)
{
    std::string output;
    Poco::MemoryInputStream mis((const char*) nbName, len);
    return output;
}
