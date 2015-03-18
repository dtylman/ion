/*
 * File:   AuthTrafficDataObject.h
 * Author: danny
 *
 * Created on March 18, 2015, 4:54 PM
 */

#ifndef AUTHTRAFFICDATAOBJECT_H
#define	AUTHTRAFFICDATAOBJECT_H

#include "DataObject.h"
#include <Poco/Logger.h>

class AuthTrafficDataObject : public DataObject
{
public:
    AuthTrafficDataObject(const Poco::Data::Session& session);
    virtual ~AuthTrafficDataObject();
    void authorize(const std::string& type, const std::string& value);
    void unauthorize(const std::string& type, const std::string& value);
private:
    Poco::Logger& _logger;
};

#endif	/* AUTHTRAFFICDATAOBJECT_H */

