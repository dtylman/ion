/*
 * File:   MainMenu.h
 * Author: danny
 *
 * Created on February 12, 2015, 12:44 PM
 */

#ifndef WEBMENU_H
#define	WEBMENU_H

#include <iostream>
#include <list>

#include <string>

class WebMenu
{
public:
    WebMenu();
    virtual ~WebMenu();

    static std::string PAGE_THINGS;
    static std::string PAGE_ADDRESSES;
    static std::string PAGE_EVENTS;
    static std::string PAGE_EVENTS_CONFIG;
    static std::string PAGE_EDIT_THING;
    static std::string PAGE_SAVE_THING;
    static std::string PAGE_MAIL_CONFIG;

    void renderNavBar(std::ostream& output, const std::string& activeTitle);
private:
    typedef std::pair<std::string, std::string> MenuItem;
    typedef std::list<MenuItem> MenuItems;
    MenuItems _navbarItems;
    std::string _productName = "IoN";
};

#endif	/* MAINMENU_H */

