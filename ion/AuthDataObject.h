/*
 * File:   AuthDataObject.h
 * Author: danny
 *
 * Created on February 16, 2015, 2:51 PM
 */

#ifndef AUTHDATAOBJECT_H
#define	AUTHDATAOBJECT_H

#include "DataObject.h"
#include "MAC.h"
#include <Poco/Logger.h>

class AuthDataObject : public DataObject
{
public:
    AuthDataObject(const Poco::Data::Session& session);
    virtual ~AuthDataObject();

    bool isAuthorized(const MAC& mac);
    void authorize(const MAC& mac);
    void unAuthorize(const MAC& mac);

    void authorizeAll();
    void unAuthorizeAll();


private:
    Poco::Logger& _logger;
};

#endif	/* AUTHDATAOBJECT_H */

