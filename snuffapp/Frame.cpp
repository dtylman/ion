/*
 * File:   FrameNotification.cpp
 * Author: danny
 *
 * Created on January 21, 2015, 9:12 PM
 */

#include "Frame.h"
#include "MAC.h"
#include "ProtocolEthernet.h"
#include <Poco/Format.h>

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
        else {
            return;
        }
    }
}

std::string Frame::toString() const
{
    std::string output = Poco::format("Device %s\nProtocols:\n", _device);
    for (auto protocol : _protocols) {
        output += Poco::format("\t%s: %s\n", protocol.first, protocol.second->toString());
    }
    return output;
}
