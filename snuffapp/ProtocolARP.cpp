/*
 * File:   ProtocolARP.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 11:51 AM
 */

#include "ProtocolARP.h"
#include <Poco/Format.h>

#ifdef POCO_OS_FAMILY_WINDOWS
#include <WinSock2.h>
#else
#include <netinet/in.h>
#endif

const std::string ProtocolARP::Name("ARP");

ProtocolARP::ProtocolARP()
{
}

ProtocolARP::~ProtocolARP()
{
}
#pragma pack(push, 1)

struct ARPHeader
{
    Poco::UInt16 hwType;
    Poco::UInt16 protocol;
    Poco::UInt8 hwSize;
    Poco::UInt8 protocolSize;
    Poco::UInt16 opcode;
    Poco::UInt8 senderMAC[6];
    Poco::UInt32 senderIP;
    Poco::UInt8 targetMAC[6];
    Poco::UInt32 targetIP;
};
#pragma pack(pop)

bool ProtocolARP::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (ARPHeader))) {
        return false;
    }
    struct ARPHeader* header = (struct ARPHeader*) (buffer.begin() + offset);
    if (htons(header->protocol) != 0x0800) {
        //protocol is not IP
        return false;
    }
    if ((header->hwSize != 6) || (header->protocolSize != 4)) {
        //hw is not mac or ip is not ipv4
        return false;
    }
    _opCode = ntohs(header->opcode);
    _senderMAC.assign(header->senderMAC, header->senderMAC + 6);
    _senderIP = Poco::Net::IPAddress(&header->senderIP, sizeof (header->senderIP));
    _targetMAC.assign(header->targetMAC, header->targetMAC + 6);
    _targetIP = Poco::Net::IPAddress(&header->targetIP, sizeof (header->targetIP));
    offset += sizeof (ARPHeader);
    next = nullptr;
    return true;
}

const std::string& ProtocolARP::name() const
{
    return ProtocolARP::Name;
}

std::string ProtocolARP::toString() const
{
    return Poco::format("Opcode: %hu Sender: %s %s Target: %s %s", _opCode, _senderMAC.toString(), _senderIP.toString(),
                        _targetMAC.toString(), _targetIP.toString());
}

Poco::UInt16 ProtocolARP::opCode() const
{
    return _opCode;
}

const Poco::Net::IPAddress& ProtocolARP::senderIP() const
{
    return _senderIP;
}

const MAC& ProtocolARP::senderMAC() const
{
    return _senderMAC;
}

const Poco::Net::IPAddress& ProtocolARP::targetIP() const
{
    return _targetIP;
}

const MAC& ProtocolARP::targetMAC() const
{
    return _targetMAC;
}

bool ProtocolARP::isReply() const
{
    return _opCode == 2;
}

bool ProtocolARP::isRequest() const
{
    return _opCode == 1;
}
