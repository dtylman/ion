/*
 * File:   ProtocolDHCP.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 2:29 PM
 */

#include "ProtocolDHCP.h"
#include <Poco/Format.h>

const std::string ProtocolDHCP::Name("DCHP");

ProtocolDHCP::ProtocolDHCP()
{
}

ProtocolDHCP::~ProtocolDHCP()
{
}

#pragma pack(push, 1)

struct DHCPHeader
{
    Poco::UInt8 type;
    Poco::UInt8 hwType;
    Poco::UInt8 hwLen;
    Poco::UInt8 hops;
    Poco::UInt32 id;
    Poco::UInt16 secs;
    Poco::UInt16 flags;
    Poco::UInt32 ipClient;
    Poco::UInt32 ipYour;
    Poco::UInt32 ipServer;
    Poco::UInt32 rpRelay;
    Poco::UInt8 macAddress[6];
    Poco::UInt8 macPadding[10];
    Poco::UInt8 server[64];
    Poco::UInt8 file[128];
    Poco::UInt8 magic[4];
};
#pragma pack(pop)

bool ProtocolDHCP::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    if (!enoughFor(buffer, offset, sizeof (DHCPHeader))) {
        return false;
    }
    struct DHCPHeader * dhcp = (struct DHCPHeader*) (buffer.begin() + offset);
    _type = dhcp->type;
    _clientMAC = MAC(dhcp->macAddress);
    Poco::UInt32 ipAddress = ntohl(dhcp->ipYour);
    _assignedIP = Poco::Net::IPAddress(&ipAddress, sizeof (Poco::UInt32));
    offset += sizeof (struct DHCPHeader);
    bool more = parseOption(buffer, offset);
    while (more) {
        more = parseOption(buffer, offset);
    };
    next = nullptr;
    return true;
}

bool ProtocolDHCP::parseOption(const FrameBuffer& buffer, size_t& offset)
{
    if (buffer.sizeBytes() <= offset + 1) {
        return false;
    }
    Poco::UInt8 type = buffer[offset];
    Poco::UInt8 length = buffer[offset];
    offset += 2;
    if (!enoughFor(buffer, offset, length)) {
        return false;
    }
    std::string data(buffer[offset], length);
    offset += length;
    _options[type] = data;
    return true;
}

const std::string& ProtocolDHCP::name() const
{
    return ProtocolDHCP::Name;
}

std::string ProtocolDHCP::toString() const
{
    return Poco::format("type: %c Client MAC: %s Assigned IP: %s", _type, _clientMAC.toString(), _assignedIP.toString());
}

std::string ProtocolDHCP::getOption(Poco::UInt8 type) const
{
    auto option = _options.find(type);
    if (option != _options.end()) {
        return option->second;
    }
    else {
        return std::string();
    }
}

const MAC& ProtocolDHCP::clientMAC() const
{
    return _clientMAC;
}

bool ProtocolDHCP::isRequest() const
{
    return _type == 0x01;
}
