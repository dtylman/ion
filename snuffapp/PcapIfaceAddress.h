/*
 * File:   PcapIfaceAddress.h
 * Author: danny
 *
 * Created on January 24, 2015, 6:55 PM
 */

#ifndef PCAPIFACEADDRESS_H
#define	PCAPIFACEADDRESS_H

#include <Poco/Net/IPAddress.h>
#include <list>
#include <string>
#include <pcap.h>

class PcapIfaceAddress
{
public:
    PcapIfaceAddress(const pcap_addr* address);
    virtual ~PcapIfaceAddress();
    typedef std::list<PcapIfaceAddress> Container;

private:
    Poco::Net::IPAddress _ip;
    Poco::Net::IPAddress _bcast;
    Poco::Net::IPAddress _netmask;
    Poco::Net::IPAddress _dest; //p2p
};

#endif	/* PCAPIFACEADDRESS_H */

