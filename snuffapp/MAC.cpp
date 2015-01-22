/*
 * File:   MAC.cpp
 * Author: danny
 *
 * Created on January 20, 2015, 6:01 PM
 */

#include "MAC.h"
#include <Poco/Format.h>

#define MAC_ADDRESS_SIZE 6

MAC::MAC()
{
    assign(MAC_ADDRESS_SIZE, 0);
}

MAC::MAC(const Poco::UInt8* address)
{
    assign(address, address + MAC_ADDRESS_SIZE);
}

MAC::~MAC()
{
}

std::string MAC::toString(const std::string& byteFormat) const
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

