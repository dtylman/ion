/*
 * File:   Arping.h
 * Author: danny
 *
 * Created on January 27, 2015, 10:54 AM
 */

#ifndef ARPING_H
#define	ARPING_H

#include "Frame.h"
#include <Poco/Net/IPAddress.h>
#include <Poco/Timespan.h>
#include <Poco/AtomicCounter.h>
#include "MAC.h"
#include "Injector.h"
#include <string>

class Arping
{
public:
    Arping(Injector& injector, const Poco::Net::IPAddress& targetIP, const MAC& targetMAC = MAC::Broadcast);
    virtual ~Arping();

    bool ping(int retries = 3, const Poco::Timespan& interval = Poco::Timespan::SECONDS);
    const MAC& targetMAC() const;
protected:
    void onFrameEvent(Frame::Ptr& frame);
private:
    Injector& _injector;
    Poco::Net::IPAddress _targetIP;
    MAC _targetMAC;
    Poco::AtomicCounter _counter;
};

#endif	/* ARPING_H */

