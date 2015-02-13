/*
 * File:   MainMenu.cpp
 * Author: danny
 *
 * Created on February 12, 2015, 12:44 PM
 */

#include "MainMenu.h"

MainMenu::MainMenu()
{
    _items.push_back(MenuItem("My Things", "things.bin"));
    _items.push_back(MenuItem("Events", "events.bin"));
}

MainMenu::~MainMenu()
{
}

void MainMenu::render(std::ostream& output, const std::string& activeTitle)
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
    output << "            <a class='navbar-brand' href='#'>Project name</a>";
    output << "        </div>";
    output << "        <div id='navbar' class='navbar-collapse collapse'>";
    output << "            <ul class='nav navbar-nav navbar-right'>";
    output << "                <li><a href='#'>Dashboard</a></li>";
    output << "                <li><a href='#'>Settings</a></li>";
    output << "                <li><a href='#'>Profile</a></li>";
    output << "                <li><a href='#'>Help</a></li>";
    output << "            </ul>";
    output << "            <form class='navbar-form navbar-right'>";
    output << "                <input type='text' class='form-control' placeholder='Search...'>";
    output << "            </form>";
    output << "        </div>";
    output << "    </div>";
    output << "</nav>";
    output << "";
    output << "<div class='container-fluid'>";
    output << "    <div class='row'>";
    output << "        <div class='col-sm-3 col-md-2 sidebar'>";
    output << "            <ul class='nav nav-sidebar'>";
    for (auto item : _items) {
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
    output << "               </ul>";
    output << "           </div>";
    output << "      </div>";
    output << " </div>";
}
