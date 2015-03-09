/*
 * File:   EventDataObject.h
 * Author: danny
 *
 * Created on February 3, 2015, 10:20 PM
 */

#ifndef EVENTDATAOBJECT_H
#define	EVENTDATAOBJECT_H

#include "DataObject.h"
#include "EventData.h"

class EventDataObject : public DataObject
{
public:
    EventDataObject(const Poco::Data::Session& session);
    virtual ~EventDataObject();

    void insert(const EventData& data);

    void deleteOld();

};

#endif	/* EVENTDATAOBJECT_H */

