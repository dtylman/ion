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
#include <Poco/Net/IPAddress.h>

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
    void link(const Poco::Net::IPAddress& ip, const MAC& mac);
};

#endif	/* IPMODEL_H */

