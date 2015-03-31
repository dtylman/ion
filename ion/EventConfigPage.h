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
    static const std::string Title;
    static const std::string Link;
    EventConfigPage();
    virtual ~EventConfigPage();
protected:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void renderButtons(std::ostream& output);

    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);

    virtual bool renderFormStart(std::ostream& output);

    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderPanel(std::ostream& output, const std::string& eventName);
    void renderCheckbox(std::ostream& output, const std::string& eventName, const std::string& eventType, const std::string& desc);
    void updateConfig(Poco::Net::HTMLForm& form, const std::string& eventName, const std::string& eventType);
    void updateConfig(Poco::Net::HTMLForm& form, const std::string& eventName);
};

#endif	/* EVENTCONFIGPAGE_H */

