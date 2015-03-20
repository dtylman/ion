/*
 * File:   AuthorizedTrafficPage.h
 * Author: danny
 *
 * Created on March 18, 2015, 4:30 PM
 */

#ifndef TRAFFICAUTHORIZEPAGE_H
#define	TRAFFICAUTHORIZEPAGE_H

#include "PageRequestHandler.h"
#include <Poco/Data/Session.h>
#include <string>

class AuthorizedTrafficPage : public PageRequestHandler
{
public:
    static const std::string Title;
    static const std::string Link;
    AuthorizedTrafficPage();
    virtual ~AuthorizedTrafficPage();
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse & response);
protected:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void renderScripts(std::ostream& output);
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual void renderButtons(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void authTraffic(const std::string& type, const std::string& value);
    void unAuthTraffic(const std::string& type, const std::string& value);
    void renderTrafficTable(std::ostream& output, Poco::Net::HTTPServerRequest& request, Poco::Data::Session& session);
};

#endif	/* TRAFFICAUTHORIZEPAGE_H */

