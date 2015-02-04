/*
 * File:   Solicitator.h
 * Author: danny
 *
 * Created on February 3, 2015, 11:13 AM
 */

#ifndef SOLICITATOR_H
#define	SOLICITATOR_H

#include <Poco/Logger.h>

#include "IPData.h"

class Solicitator
{
public:
    Solicitator();
    virtual ~Solicitator();
    void solicitateAl();
    void solicitateOnline();
private:
    bool arpPing(const IPData& ip);
    Poco::Logger& _logger;
};

#endif	/* SOLICITATOR_H */

