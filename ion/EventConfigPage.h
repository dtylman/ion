/*
 * File:   EventConfigPage.h
 * Author: danny
 *
 * Created on February 15, 2015, 4:25 PM
 */

#ifndef EVENTCONFIGPAGE_H
#define	EVENTCONFIGPAGE_H

#include "PageRequestHandler.h"

class EventConfigPage : public PageRequestHandler
{
public:
    EventConfigPage();
    virtual ~EventConfigPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);

    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderPanel(std::ostream& output, const std::string& eventName);
    void renderCheckbox(std::ostream& output, const std::string& eventName, const std::string& eventType, const std::string& desc);
};

#endif	/* EVENTCONFIGPAGE_H */

