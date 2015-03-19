/*
 * File:   ProtocolTCP.cpp
 * Author: danny
 *
 * Created on March 10, 2015, 4:32 PM
 */

#include "ProtocolTCP.h"
#include <Poco/Format.h>
#ifdef POCO_OS_FAMILY_WINDOWS
#include <WinSock2.h>
#else
#include <netinet/in.h>
#endif

const std::string ProtocolTCP::Name("TCP");

ProtocolTCP::ProtocolTCP()
{
}

ProtocolTCP::~ProtocolTCP()
{
    if (_options != nullptr) {
        delete _options;
        _options = nullptr;
    }
}

#pragma pack(push,1)

struct TCPHeader
{
    Poco::UInt16 srcport;
    Poco::UInt16 dstport;
    Poco::UInt32 seq;
    Poco::UInt32 seqack;
    Poco::UInt8 ns : 1;
    Poco::UInt8 reserved_part1 : 3;
    Poco::UInt8 header_len : 4;
    Poco::UInt8 fin : 1;
    Poco::UInt8 syn : 1;
    Poco::UInt8 rst : 1;
    Poco::UInt8 psh : 1;
    Poco::UInt8 ack : 1;
    Poco::UInt8 urg : 1;
    Poco::UInt8 ecn : 1;
    Poco::UInt8 cwr : 1;
    Poco::UInt16 window;
    Poco::UInt16 checksum;
    Poco::UInt16 urgent_pointer;
};
#pragma pack(pop)

bool ProtocolTCP::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (TCPHeader))) {
        return false;
    }
    struct TCPHeader* header = (struct TCPHeader*) (buffer.begin() + offset);
    _source = ntohs(header->srcport);
    _dest = ntohs(header->dstport);
    _ack = header->ack;
    _syn = header->syn;

    offset += sizeof (TCPHeader);
    size_t optionLen = (header->header_len * 4) - (sizeof (TCPHeader));
    _options = new Poco::UInt8[optionLen];
    memcpy(_options, (buffer.begin() + offset), optionLen);

    offset += optionLen;
    next = nullptr;
    return true;
}

const std::string& ProtocolTCP::name() const
{
    return ProtocolTCP::Name;
}

std::string ProtocolTCP::toString() const
{
    return Poco::format("Source: %hu Dest: %hu Syn: %b Ack: %b", _source, _dest, _syn, _ack);
}

bool ProtocolTCP::isSynAck() const
{
    return (_syn && _ack);
}

const Poco::UInt16 ProtocolTCP::destPort() const
{
    return _dest;
}

const Poco::UInt16 ProtocolTCP::srcPort() const
{
    return _source;
}
