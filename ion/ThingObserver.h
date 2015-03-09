/*
 * File:   HostObserver.h
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#ifndef HOSTOBSERVER_H
#define	HOSTOBSERVER_H

#include "DataObserver.h"
#include "Frame.h"
#include "DHCPOSDataObject.h"
#include "IONDataObject.h"

class ThingObserver : public DataObserver
{
public:
    ThingObserver(const Poco::Data::Session& session);
protected:
    virtual ~ThingObserver();
    void onFrameEvent(Frame::Ptr& frame);
private:
    IONDataObject _ion;
    DHCPOSDataObject _dhcp;
};

#endif	/* HOSTOBSERVER_H */

