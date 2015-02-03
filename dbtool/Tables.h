/*
 * File:   TableIP.h
 * Author: danny
 *
 * Created on February 3, 2015, 9:55 AM
 */

#ifndef TABLEIP_H
#define	TABLEIP_H

#include <Poco/Data/Session.h>

class Tables
{
public:
    Tables(Poco::Data::Session& session);
    virtual ~Tables();
    void create();
private:
    Poco::Data::Session& _session;

};

#endif	/* TABLEIP_H */

