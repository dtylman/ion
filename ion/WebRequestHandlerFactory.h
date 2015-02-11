/*
 * File:   IONRequestHandlerFactory.h
 * Author: danny
 *
 * Created on February 10, 2015, 8:46 AM
 */

#ifndef WEBREQUESTHANDLERFACTORY_H
#define	WEBREQUESTHANDLERFACTORY_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Logger.h>

class WebRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    WebRequestHandlerFactory();
    virtual ~WebRequestHandlerFactory();

    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

private:
    Poco::Logger& _logger;
};

#endif	/* IONREQUESTHANDLERFACTORY_H */

