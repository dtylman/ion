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
#include "TrafficBulk.h"
#include <Poco/Logger.h>

class TrafficObserver : public DataObserver
{
public:
    TrafficObserver(const Poco::Data::Session& session);
protected:
    void onFrameEvent(Frame::Ptr& frame);
    virtual ~TrafficObserver();
private:
    bool handleTCP(Frame::Ptr& frame);
    bool handleUDP(Frame::Ptr& frame);
    void handleIP(const std::string& transport, const Poco::UInt16 srcPort, const Poco::UInt16 destPort, Frame::Ptr& frame);
    TrafficBulk _bulk;
    Poco::Logger& _logger;
};

#endif	/* TRAFFICOBSERVER_H */

