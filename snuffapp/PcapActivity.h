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
#include <pcap.h>

class PcapActivity : public Poco::RefCountedObject
{
public:
    PcapActivity(pcap_t* pcap);
    void runActivity();

    typedef Poco::AutoPtr<PcapActivity> Ptr;
protected:
    virtual ~PcapActivity();
private:
    pcap_t* _pcap;
    Poco::Activity<PcapActivity> _activity;
    Poco::Logger& _logger;
};

#endif	/* PCAPACTIVITY_H */

