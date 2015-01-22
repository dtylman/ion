/*
 * File:   ProtocolARP.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 11:51 AM
 */

#include "ProtocolARP.h"

std::string ProtocolARP::Name("ARP");

ProtocolARP::ProtocolARP()
{
}

ProtocolARP::~ProtocolARP()
{
}

bool ProtocolARP::dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next)
{
    return false;
}

const std::string& ProtocolARP::name() const
{
    return ProtocolARP::Name;
}

std::string ProtocolARP::toString() const
{
    return "ARP DATA";
}
