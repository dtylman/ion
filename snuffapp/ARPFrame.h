/*
 * File:   ARPFrame.h
 * Author: danny
 *
 * Created on January 21, 2015, 12:40 PM
 */

#ifndef ARPFRAME_H
#define	ARPFRAME_H

#include "Frame.h"

class ARPFrame : public Frame
{
public:
    ARPFrame(const char* data, int len);
protected:
    virtual ~ARPFrame();
private:

};

#endif	/* ARPFRAME_H */

