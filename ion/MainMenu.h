/*
 * File:   MainMenu.h
 * Author: danny
 *
 * Created on February 12, 2015, 12:44 PM
 */

#ifndef MAINMENU_H
#define	MAINMENU_H

#include <iostream>
#include <list>

#include <string>

class MainMenu
{
public:
    MainMenu();
    virtual ~MainMenu();
    void render(std::ostream& output, const std::string& activeTitle);
private:
    typedef std::pair<std::string, std::string> MenuItem;
    typedef std::list<MenuItem> MenuItems;
    MenuItems _items;
};

#endif	/* MAINMENU_H */

