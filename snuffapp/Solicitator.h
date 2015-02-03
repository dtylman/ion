/*
 * File:   Solicitator.h
 * Author: danny
 *
 * Created on February 3, 2015, 11:13 AM
 */

#ifndef SOLICITATOR_H
#define	SOLICITATOR_H

#include <Poco/Logger.h>

class Solicitator
{
public:
    Solicitator();
    virtual ~Solicitator();
    void arpAll();
    void arpOnline();
private:
    Poco::Logger& _logger;
};

#endif	/* SOLICITATOR_H */

