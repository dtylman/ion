/*
 * File:   WhoisPage.h
 * Author: danny
 *
 * Created on March 16, 2015, 9:16 PM
 */

#ifndef WHOISPAGE_H
#define	WHOISPAGE_H

#include "PageRequestHandler.h"

class WhoisPage : public PageRequestHandler
{
public:
    static const std::string Title;
    static const std::string Link;
    WhoisPage();
    virtual ~WhoisPage();
protected:
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual void renderScripts(std::ostream& output);
    virtual std::string subtitle() const;
    virtual std::string title() const;
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    virtual void renderButtons(std::ostream& output);
private:

};

#endif	/* WHOISPAGE_H */

