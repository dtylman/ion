/*
 * File:   PcapIfaceAddress.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 6:55 PM
 */

#include "PcapIfaceAddress.h"

PcapIfaceAddress::PcapIfaceAddress(const pcap_addr* address)
{
    //    if (address->addr != nullptr) {
    //        _ip = Poco::Net::IPAddress(address->addr->sa_data, sizeof (address->addr->sa_data));
    //    }
    //    if (address->broadaddr != nullptr) {
    //        printf(" %d \n", (int) address->broadaddr->sa_family);
    //        _bcast = Poco::Net::IPAddress(*address->broadaddr);
    //    }
    //    if (address->netmask != nullptr) {
    //        printf(" %d \n", (int) address->netmask->sa_family);
    //        _netmask = Poco::Net::IPAddress(*address->netmask);
    //    }
    //    if (address->dstaddr != nullptr) {
    //        printf(" %d \n", (int) address->dstaddr->sa_family);
    //        _dest = Poco::Net::IPAddress(*address->dstaddr);
    //    }
}

PcapIfaceAddress::~PcapIfaceAddress()
{
}

