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
#include <Poco/Util/Application.h>

SaveThingPage::SaveThingPage()
{
}

SaveThingPage::~SaveThingPage()
{
}

bool SaveThingPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    if (!form.empty()) {
        std::string mac = form.get("mac");
        std::string type = form.get("type");
        std::string vendor = form.get("vendor");
        std::string os = form.get("os");
        std::string desc = form.get("desc");
        ThingDataObject thing(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
        thing.update(MAC(mac), type, vendor, os, desc);
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
