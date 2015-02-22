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
    virtual void renderBody(std::ostream& output, Poco::Net::HTTPServerRequest & request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse & response);

};

#endif	/* MAILCONFIGPAGE_H */

