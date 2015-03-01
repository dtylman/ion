/*
 * File:   ServerSettingsPage.cpp
 * Author: danny
 *
 * Created on February 24, 2015, 4:15 PM
 */

#include "ServerSettingsPage.h"
#include "WebMenu.h"
#include "WebForm.h"
#include "Main.h"
#include <Poco/Util/LayeredConfiguration.h>
#include <Poco/Util/Application.h>

const std::string ServerSettingsPage::Link("settings.bin");
const std::string ServerSettingsPage::Title("Server Settings");

ServerSettingsPage::ServerSettingsPage()
{
}

ServerSettingsPage::~ServerSettingsPage()
{
}

std::string ServerSettingsPage::title() const
{
    return Title;
}

std::string ServerSettingsPage::subtitle() const
{
    return "Some wisdom";
}

bool ServerSettingsPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    updateSettings(form, "offline", "ion.offline-interval");
    updateSettings(form, "eventsage", "ion.eventsage");
    if (form.has("linklocal")) {
        Poco::Util::Application::instance().config().setBool("ion.ignoreLinkLocal", true);
    }
    else {
        Poco::Util::Application::instance().config().setBool("ion.ignoreLinkLocal", false);
    }

    Main& main = dynamic_cast<Main&> (Poco::Util::Application::instance());
    main.saveConfig();

    return false;
}

bool ServerSettingsPage::renderFormStart(std::ostream& output)
{
    output << Poco::format("<form method='POST' action='%s' >", Link);
    return true;
}

void ServerSettingsPage::renderButtons(std::ostream& output)
{
    output << "<input class='btn btn-success' type='submit' value='Save'> ";
    WebMenu::renderHomeButton(output, "Close");
}

void ServerSettingsPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    Poco::Util::LayeredConfiguration& config = Poco::Util::Application::instance().config();
    WebForm wf(output);
    wf.startRow();
    wf.renderInput("offline", "Offline interval (minutes):", "minutes", config.getString("ion.offline-interval"), true, "number", 3);
    wf.endRow();
    wf.startRow();
    wf.renderInput("eventsage", "Events age (days):", "days", config.getString("ion.eventsage"), true, "number", 3);
    wf.endRow();
    wf.startRow();
    wf.renderChkbox("linklocal", "Ignore link local addresses:", config.getBool("ion.ignoreLinkLocal"), 3);
    wf.endRow();
}

bool ServerSettingsPage::updateSettings(Poco::Net::HTMLForm& form, const std::string& name, const std::string& confKey)
{
    if (form.has(name)) {
        Poco::Util::Application::instance().config().setString(confKey, form.get(name));
        return true;
    }
    return false;
}
