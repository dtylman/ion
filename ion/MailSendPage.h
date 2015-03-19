/*
 * File:   MailSendPage.h
 * Author: danny
 *
 * Created on February 24, 2015, 3:44 PM
 */

#ifndef MAILSENDPAGE_H
#define	MAILSENDPAGE_H

#include "PageRequestHandler.h"

class MailSendPage : public PageRequestHandler
{
public:
    static const std::string Link;
    MailSendPage();
    virtual ~MailSendPage();
protected:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void renderButtons(std::ostream& output);
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);

    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

private:

};

#endif	/* MAILSENDPAGE_H */

