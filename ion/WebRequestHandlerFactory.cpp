/*
 * File:   IONRequestHandlerFactory.cpp
 * Author: danny
 *
 * Created on February 10, 2015, 8:46 AM
 */

#include "WebRequestHandlerFactory.h"
#include "FileRequestHandler.h"
#include "DevicesRequestHandler.h"
#include "EventsRequestsHandler.h"
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
    std::string path = uri.getPath();
    if (path == "/devices.bin") {
        return new DevicesRequestHandler();
    }
    else if (path == "/events.bin") {
        return new EventsRequestsHandler();
    }
    return new FileRequestHandler();
}
