/*
 * File:   Protocol.h
 * Author: danny
 *
 * Created on January 22, 2015, 11:21 AM
 */

#ifndef PROTOCOL_H
#define	PROTOCOL_H

#include <Poco/Buffer.h>
#include <Poco/Types.h>
#include <Poco/RefCountedObject.h>
#include <Poco/AutoPtr.h>
#include <map>
#include <string>

typedef Poco::Buffer<Poco::UInt8> FrameBuffer;

class Protocol : public Poco::RefCountedObject
{
public:
    Protocol();
    typedef Poco::AutoPtr<Protocol> Ptr;
    typedef std::map<std::string, Protocol::Ptr> Container;
    virtual bool dissect(const FrameBuffer& buffer, size_t& offset, Protocol::Ptr& next) = 0;
    virtual const std::string& name() const = 0;
    virtual std::string toString() const = 0;
protected:
    bool enoughFor(const FrameBuffer& buffer, size_t& offset, size_t length);
    virtual ~Protocol();
};

#endif	/* PROTOCOL_H */

