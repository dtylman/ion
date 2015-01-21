/*
 * File:   EtherFrame.h
 * Author: danny
 *
 * Created on January 21, 2015, 4:30 PM
 */

#ifndef ETHERFRAME_H
#define	ETHERFRAME_H

#include "Frame.h"
#include "MAC.h"

class EtherFrame : public Frame
{
public:
    EtherFrame(const char* data, int len);

    static Frame* createFrame(const char* data, int len);
protected:
    virtual ~EtherFrame();
    MAC _sourceMAC;
    MAC _destMAC;
    Poco::UInt16 _type;

};

#endif	/* ETHERFRAME_H */

