/*
 * File:   IPModel.h
 * Author: danny
 *
 * Created on January 24, 2015, 8:50 PM
 */

#ifndef IPMODEL_H
#define	IPMODEL_H

#include "DataObserver.h"
#include "Frame.h"
#include "IPCache.h"
#include "IPDataObject.h"
#include <Poco/ExpireCache.h>

//mac-ip

class IPDataObserver : public DataObserver
{
public:
    IPDataObserver(const Poco::Data::Session& session);
    virtual void initialize();

protected:
    void onFrameEvent(Frame::Ptr& frame);
    virtual ~IPDataObserver();
private:
    bool handleIP(Frame::Ptr& frame);
    bool handleARP(Frame::Ptr& frame);
    void link(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void routerSuspected(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);

    IPCache _cache;
    IPDataObject _dao;
};

#endif	/* IPMODEL_H */

