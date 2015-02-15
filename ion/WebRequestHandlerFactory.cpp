/*
 * File:   IONRequestHandlerFactory.cpp
 * Author: danny
 *
 * Created on February 10, 2015, 8:46 AM
 */

#include "WebRequestHandlerFactory.h"
#include "FileRequestHandler.h"
#include "ThingsPage.h"
#include "EventsPage.h"
#include "EditThingPage.h"
#include "WebMenu.h"
#include "ErrorPage.h"
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
    if (!path.empty()) {
        path.erase(0, 1);
    }
    if (path.empty() || path == WebMenu::PAGE_THINGS) {
        return new ThingsPage();
    }
    if (path == WebMenu::PAGE_EVENTS) {
        return new EventsPage();
    }
    if (path == WebMenu::PAGE_EDIT_THING) {
        return new EditThingPage(uri.getQueryParameters());
    }
    return new FileRequestHandler();
}
