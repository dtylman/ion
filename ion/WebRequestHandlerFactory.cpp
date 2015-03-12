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
#include "EventConfigPage.h"
#include "AddressesPage.h"
#include "MailConfigPage.h"
#include "MailSendPage.h"
#include "ServerSettingsPage.h"
#include "TrafficPage.h"
#include <Poco/URI.h>

WebRequestHandlerFactory::WebRequestHandlerFactory() : _logger(Poco::Logger::get("IONRequestHandlerFactory"))
{
    _pages.registerClass<ThingsPage>(ThingsPage::Link);
    _pages.registerClass<AddressesPage>(AddressesPage::Link);
    _pages.registerClass<EventsPage>(EventsPage::Link);
    _pages.registerClass<EditThingPage>(EditThingPage::Link);
    _pages.registerClass<EventConfigPage>(EventConfigPage::Link);
    _pages.registerClass<MailConfigPage>(MailConfigPage::Link);
    _pages.registerClass<MailSendPage>(MailSendPage::Link);
    _pages.registerClass<ServerSettingsPage>(ServerSettingsPage::Link);
    _pages.registerClass<TrafficPage>(TrafficPage::Link);
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
