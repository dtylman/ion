/*
 * File:   ServerSettingsPage.h
 * Author: danny
 *
 * Created on February 24, 2015, 4:15 PM
 */

#ifndef SERVERSETTINGSPAGE_H
#define	SERVERSETTINGSPAGE_H

#include "PageRequestHandler.h"
#include <Poco/Net/HTMLForm.h>

class ServerSettingsPage : public PageRequestHandler
{
public:
    static const std::string Link;
    static const std::string Title;
    ServerSettingsPage();
    virtual ~ServerSettingsPage();
protected:
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool renderFormStart(std::ostream& output);
    virtual void renderButtons(std::ostream& output);
    virtual std::string subtitle() const;
    virtual std::string title() const;
private:
    bool updateSettings(Poco::Net::HTMLForm& form, const std::string& name, const std::string& confKey);

};

#endif	/* SERVERSETTINGSPAGE_H */

