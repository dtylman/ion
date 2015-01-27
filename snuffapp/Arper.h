/*
 * File:   Arper.h
 * Author: danny
 *
 * Created on January 26, 2015, 10:21 PM
 */

#ifndef ARPER_H
#define	ARPER_H

#include <Poco/Logger.h>

class Arper
{
public:
    Arper();
    virtual ~Arper();
    void arp();
private:
    Poco::Logger& _logger;
};

#endif	/* ARPER_H */

