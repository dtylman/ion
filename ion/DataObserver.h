/*
 * File:   Model.h
 * Author: danny
 *
 * Created on January 24, 2015, 8:53 PM
 */

#ifndef MODEL_H
#define	MODEL_H

#include <Poco/RefCountedObject.h>
#include <Poco/AutoPtr.h>
#include <Poco/Data/Session.h>
#include <list>

class DataObserver : public Poco::RefCountedObject
{
public:
    DataObserver();
    typedef Poco::AutoPtr<DataObserver> Ptr;
    typedef std::list<Ptr> Container;
protected:
    virtual ~DataObserver();
};

#endif	/* MODEL_H */

