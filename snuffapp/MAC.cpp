/*
 * File:   MAC.cpp
 * Author: danny
 *
 * Created on January 20, 2015, 6:01 PM
 */

#include "MAC.h"
#include <Poco/Format.h>
#include <Poco/HexBinaryDecoder.h>
#include <Poco/MemoryStream.h>

#define MAC_ADDRESS_SIZE 6

const MAC MAC::Broadcast("FF:FF:FF:FF:FF:FF");

MAC::MAC()
{
    assign(MAC_ADDRESS_SIZE, 0);
}

MAC::MAC(const Poco::UInt8* address)
{
    assign(address, address + MAC_ADDRESS_SIZE);
}

MAC::MAC(const std::string& address)
{
    if (address.size() < 17) {
        throw Poco::InvalidArgumentException(Poco::format("Invalid mac address %s", address));
    }
    Poco::MemoryInputStream mis(address.c_str(), address.size());
    Poco::HexBinaryDecoder decoder(mis);
    Poco::UInt8 byte;
    for (int i = 0; i < MAC_ADDRESS_SIZE; i++) {
        decoder>>byte;
        push_back(byte);
        mis.get(); // the delimiter
    }
}

MAC::~MAC()
{
}

std::string MAC::toString(const std::string & byteFormat) const
{
    return toString(byteFormat, size());
}

std::string MAC::toString(const std::string & byteFormat, size_t size) const
{
    std::string res;
    size_t bytes = size;
    if (size > this->size()) {
        bytes = this->size();
    }
    for (unsigned int i = 0; i < bytes; i++) {
        unsigned int num = at(i);
        res.append(Poco::format(byteFormat, num));
        if (i != (bytes - 1)) {
            res.push_back(':');
        }
    }
    return res;
}

std::string MAC::vendorPrefix() const
{
    return toString("%02x", 3);
}

bool MAC::isUnicast() const
{
    return (!isBroadcast() && !isMulticast() && (!isWildcard()));
}

bool MAC::isWildcard() const
{
    for (unsigned char c : * this) {
        if (c != 0x00) {
            return false;
        }
    }
    return true;
}

bool MAC::isBroadcast() const
{
    for (unsigned char c : * this) {
        if (c != 0xFF) {
            return false;
        }
    }
    return true;
}

bool MAC::isMulticast() const
{
    if ((at(0) == 0x5e) && (at(1) == 0x00) && (at(2) == 0x01)) {
        return true; // IPv4 ;
    }
    if ((at(0) == 0x33) && (at(1) == 0x33)) {
        return true; // IPv6
    }
    return false;
}

