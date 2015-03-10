/*
 * File:   TrafficObserver.h
 * Author: danny
 *
 * Created on March 10, 2015, 5:55 PM
 */

#ifndef TRAFFICOBSERVER_H
#define	TRAFFICOBSERVER_H

#include "DataObserver.h"
#include "Frame.h"
#include <Poco/Logger.h>

class TrafficObserver : public DataObserver
{
public:
    TrafficObserver();
protected:
    void onFrameEvent(Frame::Ptr& frame);
    virtual ~TrafficObserver();
private:
    Poco::Logger& _logger;
};

#endif	/* TRAFFICOBSERVER_H */

