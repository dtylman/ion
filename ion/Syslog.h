/*
 * File:   Syslog.h
 * Author: danny
 *
 * Created on March 9, 2015, 8:41 PM
 */

#ifndef SYSLOG_H
#define	SYSLOG_H

#include "EventData.h"

class Syslog
{
public:
    Syslog();
    virtual ~Syslog();
    void log(const EventData& eventData);
private:

};

#endif	/* SYSLOG_H */

