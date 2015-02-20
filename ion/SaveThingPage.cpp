/*
 * File:   SaveThingPage.cpp
 * Author: danny
 *
 * Created on February 15, 2015, 12:55 PM
 */

#include "SaveThingPage.h"
#include "WebMenu.h"
#include "DataSubsystem.h"
#include "AuthDataObject.h"
#include "IONDataObject.h"
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
    IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    std::string id = form.get("id");
    ThingData thing;
    if (!ion.getThing(Poco::UUID(id), thing)) {
        throw Poco::NotFoundException("Thing not found!");
    }
    thing.setType(form.get("type"));
    thing.setVendor(form.get("vendor"));
    thing.setOS(form.get("os"));
    thing.setDesc(form.get("desc"));
    ion.setThing(thing, true);
}

void SaveThingPage::handleAuthThing(Poco::Net::HTTPServerRequest& request)
{
    std::string thingid = getQueryParam("id", request);
    std::string auth = getQueryParam("auth", request);
    IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    ion.authorizeThing(Poco::UUID(thingid), (auth == "no"));
}
