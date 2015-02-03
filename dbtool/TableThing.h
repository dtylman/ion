/*
 * File:   TableDevice.h
 * Author: danny
 *
 * Created on February 3, 2015, 9:55 AM
 */

#ifndef TABLEDEVICE_H
#define	TABLEDEVICE_H

#include <Poco/Data/Session.h>

class TableThing
{
public:
    TableThing(Poco::Data::Session& session);
    virtual ~TableThing();
    void create();
private:
    Poco::Data::Session& _session;

};

#endif	/* TABLEDEVICE_H */

