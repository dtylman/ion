/*
 * File:   ProtocolIP.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 11:51 AM
 */

#include "ProtocolIP.h"

std::string ProtocolIP::Name("IP");

ProtocolIP::ProtocolIP()
{
}

ProtocolIP::~ProtocolIP()
{
}

bool ProtocolIP::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    return false;
}

const std::string& ProtocolIP::name() const
{
    return ProtocolIP::Name;
}

std::string ProtocolIP::toString() const
{
    return "IP DATA";
}
