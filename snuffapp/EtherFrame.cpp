/*
 * File:   EtherFrame.cpp
 * Author: danny
 *
 * Created on January 21, 2015, 4:30 PM
 */

#include "EtherFrame.h"
#include "IPFrame.h"
#include "ARPFrame.h"
#include <arpa/inet.h>

struct EtherHeader
{
    Poco::UInt8 dest[6];
    Poco::UInt8 src[6];
    Poco::UInt16 type;
};

EtherFrame::EtherFrame(const char* data, int len) : Frame(data, len)
{
    _reader>> _destMAC;
    _reader>> _sourceMAC;
    _reader>>_type;
}

EtherFrame::~EtherFrame()
{
}

Frame* EtherFrame::createFrame(const char* data, int len)
{
    if (len<sizeof (EtherHeader)) {
        return nullptr;
    }
    const EtherHeader* eth = (const EtherHeader*) data;
    Poco::UInt16 type = ntohs(eth->type);
    switch (type) {
    case 0x0800:
        return new IPFrame(data, len);
        break;
    case 0x0806:
        return new ARPFrame(data, len);
        break;
        //case 0x86DD:
    default:
        return nullptr;
        break; // do nothing;
    };
}
