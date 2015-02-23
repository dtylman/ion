/*
 * File:   MailConfigPage.h
 * Author: danny
 *
 * Created on February 16, 2015, 6:14 PM
 */

#ifndef MAILCONFIGPAGE_H
#define	MAILCONFIGPAGE_H

#include "PageRequestHandler.h"

class MailConfigPage : public PageRequestHandler
{
public:
    static const std::string Title;
    static const std::string Link;
    MailConfigPage();
    virtual ~MailConfigPage();
protected:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void renderButtons(std::ostream& output);
    virtual bool renderFormStart(std::ostream& output);
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest & request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse & response);
private:
    void renderInput(std::ostream& output, const std::string& name, const std::string& text,
                     const std::string& placeHolder, const std::string& configKey, const std::string& type = "text", int cols = 2);
    void renderChkbox(std::ostream& output, const std::string& name, const std::string& text, const std::string& configKey, int cols = 1);
};

#endif	/* MAILCONFIGPAGE_H */

