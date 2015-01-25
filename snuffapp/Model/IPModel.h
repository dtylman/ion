/*
 * File:   IPModel.h
 * Author: danny
 *
 * Created on January 24, 2015, 8:50 PM
 */

#ifndef IPMODEL_H
#define	IPMODEL_H

#include "Model.h"
#include "../Dissect/Frame.h"
#include "../Dissect/MAC.h"
#include "IPCache.h"
#include <Poco/Net/IPAddress.h>
#include <Poco/ExpireCache.h>

//mac-ip

class IPModel : public Model
{
public:
    IPModel();
    virtual void initialize();
    void onFrameEvent(Frame::Ptr& frame);
protected:
    virtual ~IPModel();
private:
    void link(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    void linkRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device);
    IPCache _cache;
};

#endif	/* IPMODEL_H */

