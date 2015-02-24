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
#include "Main.h"
#include "WebForm.h"
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
    if (request.getMethod() == Poco::Net::HTTPServerRequest::HTTP_POST) {
        updateConfig(form, EventNotification::IP_OFFLINE);
        updateConfig(form, EventNotification::IP_ONLINE);
        updateConfig(form, EventNotification::NOT_AUTHORIZED);
        updateConfig(form, EventNotification::THING_OFFLINE);
        updateConfig(form, EventNotification::THING_ONLINE);
        Main& main = dynamic_cast<Main&> (Poco::Util::Application::instance());
        main.saveConfig();
    }
    return false;
}

void EventConfigPage::updateConfig(Poco::Net::HTMLForm& form, const std::string& eventName)
{
    updateConfig(form, eventName, "save");
    updateConfig(form, eventName, "mail");
    updateConfig(form, eventName, "syslog");
    std::string name = Poco::format("txt_%s", eventName);
    if (form.has(name)) {
        std::string keyName = Poco::format("ion.events.%s.text", eventName);
        Poco::Util::Application::instance().config().setString(keyName, form.get(name));
    }
}

void EventConfigPage::updateConfig(Poco::Net::HTMLForm& form, const std::string& eventName, const std::string& eventType)
{
    std::string name = Poco::format("chk_%s_%s", eventName, eventType);
    std::string keyName = Poco::format("ion.events.%s.%s", eventName, eventType);
    if (form.has(name)) {
        Poco::Util::Application::instance().config().setBool(keyName, true);
    }
    else {
        Poco::Util::Application::instance().config().setBool(keyName, false);
    }
}

void EventConfigPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    renderPanel(output, EventNotification::IP_OFFLINE);
    renderPanel(output, EventNotification::IP_ONLINE);
    renderPanel(output, EventNotification::NOT_AUTHORIZED);
    renderPanel(output, EventNotification::THING_OFFLINE);
    renderPanel(output, EventNotification::THING_ONLINE);
}

bool EventConfigPage::renderFormStart(std::ostream& output)
{
    output << Poco::format("<form method='POST' action='%s'>", Link);
    return true;
}

std::string EventConfigPage::title() const
{
    return Title;
}

std::string EventConfigPage::subtitle() const
{
    return "subtitle";
}

void EventConfigPage::renderButtons(std::ostream& output)
{
    output << "<input class='btn btn-success' type='submit' value='Save' >";
    output << Poco::format(" <a href='%s' class='btn btn-primary'>Cancel</a>", ThingsPage::Link);
}

void EventConfigPage::renderPanel(std::ostream& output, const std::string& eventName)
{
    const Poco::Util::AbstractConfiguration* config = Poco::Util::Application::instance().config().createView(Poco::format("ion.events.%s", eventName));
    WebForm wf(output);
    wf.startRow();
    wf.renderInput("txt_" + eventName, eventName + " Message Text:", "Enter Text", config->getString("text"), true, "text", 5);
    wf.renderChkbox("chk_" + eventName + "_save", "Save", config->getBool("save"), 1);
    wf.renderChkbox("chk_" + eventName + "_mail", "Send mail", config->getBool("mail"), 1);
    wf.renderChkbox("chk_" + eventName + "_syslog", "Write to System Logger", config->getBool("syslog"), 1);
    wf.endRow();
}

void EventConfigPage::renderCheckbox(std::ostream& output, const std::string& eventName, const std::string& eventType, const std::string& desc)
{
    std::string keyName = Poco::format("ion.events.%s.%s", eventName, eventType);
    std::string checeked;
    if (Poco::Util::Application::instance().config().getBool(keyName)) {
        checeked = "checked";
    }
    output << "<div class='col-xs-2'><label class='checkbox'>";
    output << Poco::format("<input type='checkbox' name='chk_%s_%s' %s>%s", eventName, eventType, checeked, desc);
    output << "</label></div>";

}

