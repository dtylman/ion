/*
 * File:   EventConfigPage.cpp
 * Author: danny
 *
 * Created on February 15, 2015, 4:25 PM
 */

#include "EventConfigPage.h"
#include "EventNotification.h"
#include "WebMenu.h"
#include "ThingsPage.h"
#include <Poco/Format.h>
#include <Poco/Util/Application.h>

const std::string EventConfigPage::Link("eventconf.bin");
const std::string EventConfigPage::Title("Events Setup");

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
    output << "<form>";
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

    output << "<div class='panel-footer clearfix'>";
    output << "<input class='btn btn-success' type='submit' value='Save' >";
    output << Poco::format(" <a href='%s' class='btn btn-primary'>Cancel</a>", ThingsPage::Link);
    output << "</div>";
    output << "</div>";

    output << "</form>";
}

std::string EventConfigPage::title() const
{
    return Title;
}

void EventConfigPage::renderPanel(std::ostream& output, const std::string& eventName)
{
    std::string keyName = Poco::format("ion.events.%s.text", eventName);
    std::string text = Poco::Util::Application::instance().config().getString(keyName);

    output << "<div class='row form-group'>";
    output << Poco::format("<label class='col-xs-2'>When %s:</label>", eventName);
    output << "<label class='control-label col-xs-1' >Message Text:</label>";
    output << "<div class='col-xs-6'>";
    output << Poco::format("<input class='form-control' name='txt%s' value='%s'>", eventName, text);
    output << "</div>";
    output << "</div>";
    output << "<div class='row form-group'>";
    renderCheckbox(output, eventName, "save", "Save to local database");
    renderCheckbox(output, eventName, "mail", "Send Mail");
    renderCheckbox(output, eventName, "syslog", "Write to system logger");
    output << "</div>";

}

void EventConfigPage::renderCheckbox(std::ostream& output, const std::string& eventName, const std::string& eventType, const std::string& desc)
{
    std::string keyName = Poco::format("ion.events.%s.%s", eventName, eventType);
    std::string checeked;
    if (Poco::Util::Application::instance().config().getBool(keyName)) {
        checeked = "checked";
    }
    output << "<div class='col-xs-3'>";
    output << Poco::format("<input type='checkbox' name='chk%s_%s' %s value='%s'>", eventType, eventName, checeked, desc);
    output << "</div>";

}

