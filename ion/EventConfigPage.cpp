/*
 * File:   EventConfigPage.cpp
 * Author: danny
 *
 * Created on February 15, 2015, 4:25 PM
 */

#include "EventConfigPage.h"
#include "EventNotification.h"
#include <Poco/Format.h>

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
    output << "<span class='input-group-addon'>";

    output << Poco::format("<input type='checkbox' name='chkSyslog_%s'>", eventName);
    output << "</span>";
    output << "<label class='form-control' >Write to system log</label>";
    output << "<span class='input-group-addon'>";
    output << Poco::format("<input type='checkbox' name='chkMail_%s'>", eventName);
    output << "</span>";
    output << "<label class='form-control' >Send Mail</label>";

    output << "</div>";
    output << "</div>";
    output << "</div>";
}
