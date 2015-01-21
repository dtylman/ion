/*
 * File:   IPFrame.cpp
 * Author: danny
 *
 * Created on January 21, 2015, 12:41 PM
 */

#include "IPFrame.h"
#include "EtherFrame.h"
#include <Poco/Format.h>

struct IPHeader
{
    Poco::UInt8 header_len : 4;
    Poco::UInt8 version : 4;
};

IPFrame::IPFrame(const char* data, int len) : EtherFrame(data, len)
{
    Poco::UInt8 header;
    _reader >> header;
    struct IPHeader* ipheader = (IPHeader*) & header;
    _headerLen = ipheader->header_len;
    _version = ipheader->version;
    _reader >> _tos;
    _reader >> _totalLen;
    _reader >> _id;
    _reader >> _fragOffset;
    _reader >> _ttl;
    _reader >> _protocol;
    _reader >> _checksum;
    _reader >> _sourceIP;
    _reader >> _destinationIP;
}

IPFrame::~IPFrame()
{
}

std::string IPFrame::toString() const
{
    return Poco::format("%s -> %s", _sourceIP.toString(), _destinationIP.toString());
}
