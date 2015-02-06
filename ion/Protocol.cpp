/*
 * File:   Protocol.cpp
 * Author: danny
 *
 * Created on January 22, 2015, 11:21 AM
 */

#include "Protocol.h"

Protocol::Protocol()
{

}

Protocol::~Protocol()
{

}

bool Protocol::enoughFor(const FrameBuffer& buffer, size_t& offset, size_t length)
{
    return (buffer.sizeBytes() >= (offset + length));
}


