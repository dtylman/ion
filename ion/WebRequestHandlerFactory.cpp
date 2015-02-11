/*
 * File:   IONRequestHandlerFactory.cpp
 * Author: danny
 *
 * Created on February 10, 2015, 8:46 AM
 */

#include "WebRequestHandlerFactory.h"
#include "PageRequestHandler.h"
#include "RestRequestHandler.h"
#include <Poco/URI.h>

WebRequestHandlerFactory::WebRequestHandlerFactory() : _logger(Poco::Logger::get("IONRequestHandlerFactory"))
{
}

WebRequestHandlerFactory::~WebRequestHandlerFactory()
{
}

Poco::Net::HTTPRequestHandler* WebRequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request)
{
    _logger.debug("Handling request from %s: %s (%s)", request.getHost(), request.getURI(), request.getMethod());

    Poco::URI uri(request.getURI());
    if (uri.getPath() == "/bin/devices") {
        return new RestRequestHandler();
    }
    return new PageRequestHandler();
}
