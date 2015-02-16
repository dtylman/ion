/*
 * File:   EventConfigPage.cpp
 * Author: danny
 *
 * Created on February 15, 2015, 4:25 PM
 */

#include "EventConfigPage.h"
#include "EventNotification.h"
#include "WebMenu.h"
#include <Poco/Format.h>
#include <Poco/Util/Application.h>

EventConfigPage::EventConfigPage()
{
}

EventConfigPage::~EventConfigPage()
{
}

bool EventConfigPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void EventConfigPage::renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << "<form class='form-group'>";
    output << "<div class='panel panel-default'>";
    output << "<div class='panel-heading'>";
    output << "<h3 class='panel-title'>This should explain what this page is for</h3>";
    output << "</div>";
    output << "<div class='panel-body'>";
    renderPanel(output, EventNotification::IP_OFFLINE);
    renderPanel(output, EventNotification::IP_ONLINE);
    renderPanel(output, EventNotification::NOT_AUTHORIZED);
    renderPanel(output, EventNotification::THING_OFFLINE);
    renderPanel(output, EventNotification::THING_ONLINE);
    output << "</div>";
    output << "</div>";
    output << "<input class='btn btn-success' type='submit' value='Save' >";
    output << Poco::format(" <a href='%s' class='btn btn-primary'>Cancel</a>", WebMenu::PAGE_THINGS);

    output << "</div>";

    output << "</form>";
}

std::string EventConfigPage::title() const
{
    return "Events Setup";
}

void EventConfigPage::renderPanel(std::ostream& output, const std::string& eventName)
{

    output << "<div class='row'>";
    output << "<div class='col-lg-6'>";
    output << "When " << eventName << ": ";
    output << "<div class='input-group'>";
    renderCheckbox(output, eventName, "save", "Save to local database");
    renderCheckbox(output, eventName, "mail", "Send Mail");
    renderCheckbox(output, eventName, "syslog", "Write to system logger");
    output << "</div>";
    output << "</div>";
    output << "</div>";

}

void EventConfigPage::renderCheckbox(std::ostream& output, const std::string& eventName, const std::string& eventType, const std::string& desc)
{
    std::string keyName = Poco::format("ion.events.%s.%s", eventName, eventType);
    std::string checeked;
    if (Poco::Util::Application::instance().config().getBool(keyName, false)) {
        checeked = "checked";
    }
    output << "<span class='input-group-addon'>";
    output << Poco::format("<input type='checkbox' name='chk%s_%s' %s>", eventType, eventName, checeked);
    output << "</span>";
    output << Poco::format("<label class='form-control'>%s</label>", desc);
}
