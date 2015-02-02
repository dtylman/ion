/*
 * File:   ZakifApp.h
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */

#ifndef ZAKIFAPP_H
#define	ZAKIFAPP_H

#include <Poco/Util/ServerApplication.h>

class Main : public Poco::Util::ServerApplication
{
public:
    Main();
    virtual ~Main();

protected:
    virtual int main(const std::vector<std::string>& args);
    void initialize(Poco::Util::Application& self);
    int loadConfiguration(int priority = PRIO_DEFAULT);
private:
    void addRouters();
    void arpAll();
};

#endif	/* ZAKIFAPP_H */

