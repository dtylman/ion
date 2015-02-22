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

    void renderNavBar(std::ostream& output, const std::string& activeTitle);
    static void renderHomeButton(std::ostream& output, const std::string& text);
private:
    typedef std::pair<std::string, std::string> MenuItem;
    typedef std::list<MenuItem> MenuItems;
    MenuItems _navbarItems;
    std::string _productName = "IoN";
};

#endif	/* MAINMENU_H */

