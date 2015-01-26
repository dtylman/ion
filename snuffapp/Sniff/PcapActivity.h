/*
 * File:   PcapActivity.h
 * Author: danny
 *
 * Created on January 19, 2015, 10:41 PM
 */

#ifndef PCAPACTIVITY_H
#define	PCAPACTIVITY_H

#include <Poco/RefCountedObject.h>
#include <Poco/Activity.h>
#include <Poco/Logger.h>
#include <Poco/AutoPtr.h>
#include <pcap.h>

#include "PcapIfaceAddress.h"

class PcapActivity : public Poco::RefCountedObject
{
public:
    PcapActivity(const std::string& device, const PcapIfaceAddress::Container& addresses);
    typedef Poco::AutoPtr<PcapActivity> Ptr;
    void start();
    void stop();
    bool inject(const Poco::UInt8* data, int len);
    const PcapIfaceAddress::Container& addresses() const;
protected:
    void runActivity();
    virtual ~PcapActivity();
private:
    bool openLive();
    std::string _device;
    PcapIfaceAddress::Container _addresses;
    pcap_t* _pcap = nullptr;
    Poco::Activity<PcapActivity> _activity;
    Poco::Logger& _logger;
};

#endif	/* PCAPACTIVITY_H */

