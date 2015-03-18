/*
 * File:   MainMenu.cpp
 * Author: danny
 *
 * Created on February 12, 2015, 12:44 PM
 */

#include "WebMenu.h"
#include "ThingsPage.h"
#include "AddressesPage.h"
#include "EventsPage.h"
#include "EventConfigPage.h"
#include "MailConfigPage.h"
#include "ServerSettingsPage.h"
#include "TrafficPage.h"
#include "AuthorizationPage.h"
#include <Poco/Format.h>

WebMenu::WebMenu()
{
    _navbarItems.push_back(MenuItem(ThingsPage::Title, ThingsPage::Link));
    _navbarItems.push_back(MenuItem(AddressesPage::Title, AddressesPage::Link));
    _navbarItems.push_back(MenuItem(EventsPage::Title, EventsPage::Link));
    _navbarItems.push_back(MenuItem(TrafficPage::Title, TrafficPage::Link));
    _navbarItems.push_back(MenuItem(AuthorizationPage::Title, AuthorizationPage::Link));
    _navbarItems.push_back(MenuItem(EventConfigPage::Title, EventConfigPage::Link));
    _navbarItems.push_back(MenuItem(MailConfigPage::Title, MailConfigPage::Link));
    _navbarItems.push_back(MenuItem(ServerSettingsPage::Title, ServerSettingsPage::Link));
}

WebMenu::~WebMenu()
{
}

void WebMenu::renderNavBar(std::ostream& output, const std::string& activeTitle)
{
    output << "<nav class='navbar navbar-inverse navbar-fixed-top'>";
    output << "    <div class='container-fluid'>";
    output << "        <div class='navbar-header'>";
    output << "            <button type='button' class='navbar-toggle collapsed' data-toggle='collapse' data-target='#navbar' aria-expanded='false' aria-controls='navbar'>";
    output << "                <span class='sr-only'>Toggle navigation</span>";
    output << "                <span class='icon-bar'></span>";
    output << "                <span class='icon-bar'></span>";
    output << "                <span class='icon-bar'></span>";
    output << "            </button>";
    output << Poco::format("<a class='navbar-brand' href='%s'>%s</a>", ThingsPage::Link, _productName);
    output << "        </div>";
    output << "        <div id='navbar' class='navbar-collapse collapse'>";
    output << "            <ul class='nav navbar-nav navbar-right'>";
    output << "                <li><a href='http://lagildo.com'>Site</a></li>";
    output << "                <li><a href=''>About</a></li>";
    output << "            </ul>";
    output << "        </div>";
    output << "    </div>";
    output << "</nav>";
    output << "";
    output << "<div class='container-fluid'>";
    output << "    <div class='row'>";
    output << "        <div class='col-sm-3 col-md-2 sidebar'>";
    output << "            <ul class='nav nav-sidebar'>";
    for (auto item : _navbarItems) {
        output << "<li";
        if (item.first == activeTitle) {

            output << " class='active'";
        }
        output << "><a href = '";
        output << item.second;
        output << "'>";
        output << item.first;
        output << "</a></li>";
    }
    output << "              </ul>";
    output << "          </div>";
    output << "     </div>";
    output << "</div>";
}

void WebMenu::renderHomeButton(std::ostream& output, const std::string& text)
{
    renderLinkButton(output, text, ThingsPage::Link);
}

void WebMenu::renderLinkButton(std::ostream& output, const std::string& text, const std::string& target)
{
    output << Poco::format("<a href='%s' class='btn btn-primary'>%s</a> ", target, text);
}
