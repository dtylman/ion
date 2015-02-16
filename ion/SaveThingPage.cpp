/*
 * File:   SaveThingPage.cpp
 * Author: danny
 *
 * Created on February 15, 2015, 12:55 PM
 */

#include "SaveThingPage.h"
#include "WebMenu.h"
#include "ThingDataObject.h"
#include "DataSubsystem.h"
#include "AuthDataObject.h"
#include <Poco/Util/Application.h>
#include <Poco/Exception.h>

SaveThingPage::SaveThingPage()
{
}

SaveThingPage::~SaveThingPage()
{
}

bool SaveThingPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    std::string action = getQueryParam("action", request);
    if (action == "update") {
        handleUpdateThing(form);
    }
    else if (action == "auth") {
        handleAuthThing(request);
    }
    else {
        throw Poco::InvalidArgumentException("Invalid form action");
    }
    response.redirect(WebMenu::PAGE_THINGS);
    return true;
}

void SaveThingPage::renderBody(std::ostream&, Poco::Net::HTTPServerRequest& request)
{

}

std::string SaveThingPage::title() const
{
    return "Save Thing";
}

void SaveThingPage::handleUpdateThing(const Poco::Net::HTMLForm& form)
{
    std::string mac = form.get("mac");
    std::string type = form.get("type");
    std::string vendor = form.get("vendor");
    std::string os = form.get("os");
    std::string desc = form.get("desc");
    ThingDataObject thing(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    thing.update(MAC(mac), type, vendor, os, desc);
}

void SaveThingPage::handleAuthThing(Poco::Net::HTTPServerRequest& request)
{
    MAC mac = getQueryParam("mac", request);
    std::string auth = getQueryParam("auth", request);
    AuthDataObject ado(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    if (auth == "toggle") {
        if (ado.isAuthorized(mac)) {
            ado.unAuthorize(mac);
        }
        else {
            ado.authorize(mac);
        }
    }
}
