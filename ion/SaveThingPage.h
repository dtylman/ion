/*
 * File:   SaveThingPage.h
 * Author: danny
 *
 * Created on February 15, 2015, 12:55 PM
 */

#ifndef SAVETHINGPAGE_H
#define	SAVETHINGPAGE_H

#include "PageRequestHandler.h"

class SaveThingPage : public PageRequestHandler
{
public:
    SaveThingPage();
    virtual ~SaveThingPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void handleUpdateThing(const Poco::Net::HTMLForm& form);
    void handleAuthThing(Poco::Net::HTTPServerRequest& request);
};

#endif	/* SAVETHINGPAGE_H */

