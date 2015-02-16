/*
 * File:   MainMenu.cpp
 * Author: danny
 *
 * Created on February 12, 2015, 12:44 PM
 */

#include "WebMenu.h"
#include <Poco/Format.h>

std::string WebMenu::PAGE_THINGS("things.bin");
std::string WebMenu::PAGE_EVENTS("events.bin");
std::string WebMenu::PAGE_ADDRESSES("addresses.bin");
std::string WebMenu::PAGE_EVENTS_CONFIG("events.config.bin");
std::string WebMenu::PAGE_EDIT_THING("edit.thing.bin");
std::string WebMenu::PAGE_SAVE_THING("save.thing.bin");
std::string WebMenu::PAGE_MAIL_CONFIG("mail.config.bin");

WebMenu::WebMenu()
{
    _navbarItems.push_back(MenuItem("My Things", PAGE_THINGS));
    _navbarItems.push_back(MenuItem("My Addresses", PAGE_ADDRESSES));
    _navbarItems.push_back(MenuItem("My Events", PAGE_EVENTS));
    _navbarItems.push_back(MenuItem("Events Settings", PAGE_EVENTS_CONFIG));
    _navbarItems.push_back(MenuItem("Mail Settings", PAGE_MAIL_CONFIG));
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
    output << Poco::format("<a class='navbar-brand' href='%s'>%s</a>", WebMenu::PAGE_THINGS, _productName);
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
