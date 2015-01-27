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

class Model : public Poco::RefCountedObject
{
public:
    Model();
    typedef Poco::AutoPtr<Model> Ptr;
    typedef std::list<Ptr> Container;
    virtual void initialize() = 0;
protected:
    virtual ~Model();
    Poco::Data::Session _session;
};

#endif	/* MODEL_H */

