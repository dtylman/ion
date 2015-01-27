/*
 * File:   IPModel.h
 * Author: danny
 *
 * Created on January 24, 2015, 8:50 PM
 */

#ifndef IPMODEL_H
#define	IPMODEL_H

#include "Model.h"
#include "Frame.h"
#include "MAC.h"
#include "IPCache.h"
#include <Poco/Net/IPAddress.h>
#include <Poco/ExpireCache.h>

//mac-ip

class IPModel : public Model
{
public:
    IPModel();
    virtual void initialize();
    void link(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void linkRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
protected:
    void onFrameEvent(Frame::Ptr& frame);
    virtual ~IPModel();
private:
    IPCache _cache;
};

#endif	/* IPMODEL_H */

