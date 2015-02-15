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
#include "SaveThingPage.h"
#include "EventConfigPage.h"
#include <Poco/URI.h>

WebRequestHandlerFactory::WebRequestHandlerFactory() : _logger(Poco::Logger::get("IONRequestHandlerFactory"))
{
    _pages.registerClass<ThingsPage>(WebMenu::PAGE_THINGS);
    _pages.registerClass<EventsPage>(WebMenu::PAGE_EVENTS);
    _pages.registerClass<EditThingPage>(WebMenu::PAGE_EDIT_THING);
    _pages.registerClass<SaveThingPage>(WebMenu::PAGE_SAVE_THING);
    _pages.registerClass<EventConfigPage>(WebMenu::PAGE_EVENTS_CONFIG);
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
    if (_pages.isClass(path)) {
        return _pages.createInstance(path);
    }
    return new FileRequestHandler();
}
