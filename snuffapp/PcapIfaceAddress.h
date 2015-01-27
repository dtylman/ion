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

    const Poco::Net::IPAddress& ip() const;
    const Poco::Net::IPAddress& broadcast() const;
    const Poco::Net::IPAddress& netmask() const;
    const Poco::Net::IPAddress& p2pdest() const;
private:
    void setAddress(Poco::Net::IPAddress& poco, const sockaddr* address);
    Poco::Net::IPAddress _ip;
    Poco::Net::IPAddress _bcast;
    Poco::Net::IPAddress _netmask;
    Poco::Net::IPAddress _dest; //p2p
};

#endif	/* PCAPIFACEADDRESS_H */

