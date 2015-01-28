/*
 * File:   HostObserver.h
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#ifndef HOSTOBSERVER_H
#define	HOSTOBSERVER_H

#include "DataObserver.h"
#include "HostDataObject.h"
#include "Frame.h"

class HostObserver : public DataObserver
{
public:
    HostObserver(const Poco::Data::Session& session);
protected:
    virtual ~HostObserver();
    void onFrameEvent(Frame::Ptr& frame);
private:
    HostDataObject _dao;
};

#endif	/* HOSTOBSERVER_H */

