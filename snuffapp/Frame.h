/*
 * File:   Frame.h
 * Author: danny
 *
 * Created on January 21, 2015, 12:43 PM
 */

#ifndef FRAME_H
#define	FRAME_H

#include <Poco/BinaryReader.h>
#include <Poco/RefCountedObject.h>
#include <Poco/AutoPtr.h>
#include <Poco/Buffer.h>

class Frame : public Poco::RefCountedObject
{
public:
    Frame(const char* data, int len);
    typedef Poco::AutoPtr<Frame> Ptr;
protected:
    virtual ~Frame();
    Poco::Buffer<char> _buffer;
    Poco::MemoryBinaryReader _reader;
};

#endif	/* FRAME_H */

