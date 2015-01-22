/*
 * File:   FrameNotification.cpp
 * Author: danny
 *
 * Created on January 21, 2015, 9:12 PM
 */

#include "Frame.h"
#include "MAC.h"
#include "ProtocolEthernet.h"
#include <netinet/in.h>

Frame::Frame(const std::string& device, const Poco::UInt8* data, int len) :
_device(device),
_buffer(data, len)
{

}

Frame::~Frame()
{
}

void Frame::dissect()
{
    Protocol::Ptr protocol = new ProtocolEthernet();
    size_t offset = 0;
    while (!protocol.isNull()) {
        Protocol::Ptr next;
        if (protocol->dissect(_buffer, offset, next)) {
            _protocols[protocol->name()] = protocol;
            protocol = next;
        }
    }
}

std::string Frame::toString() const
{
    std::string output = _device + "\n";
    for (auto protocol : _protocols) {
        output += protocol.first + "\n";
        output += protocol.second->toString();
    }
    return output;
}
