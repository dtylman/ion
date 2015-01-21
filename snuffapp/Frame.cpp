/*
 * File:   Frame.cpp
 * Author: danny
 *
 * Created on January 21, 2015, 12:43 PM
 */

#include "Frame.h"
#include <Poco/BinaryReader.h>

Frame::Frame(const char* data, int len) : _buffer(data, len), _reader(_buffer, Poco::BinaryReader::NETWORK_BYTE_ORDER)
{

}

Frame::~Frame()
{

}
