/*
 * File:   DataObject.h
 * Author: danny
 *
 * Created on January 28, 2015, 9:02 AM
 */

#ifndef DATAOBJECT_H
#define	DATAOBJECT_H

#include <Poco/Data/Session.h>

class DataObject
{
public:
    DataObject(const Poco::Data::Session& session);
    virtual ~DataObject();
protected:
    Poco::Data::Session _session;

};

#endif	/* DATAOBJECT_H */

