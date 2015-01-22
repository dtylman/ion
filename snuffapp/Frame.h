/*
 * File:   FrameNotification.h
 * Author: danny
 *
 * Created on January 21, 2015, 9:12 PM
 */

#ifndef FRAMENOTIFICATION_H
#define	FRAMENOTIFICATION_H

#include "MAC.h"
#include "Protocol.h"
#include <Poco/Notification.h>
#include <Poco/Buffer.h>
#include <Poco/Types.h>
#include <string>

class Frame : public Poco::Notification
{
public:
    Frame(const std::string& device, const Poco::UInt8* data, int len);
    typedef Poco::AutoPtr<Frame> Ptr;
    void dissect();
    std::string toString() const;
private:
    virtual ~Frame();

    FrameBuffer _buffer;
    std::string _device;
    Protocol::Container _protocols;
};

#endif	/* FRAMENOTIFICATION_H */

