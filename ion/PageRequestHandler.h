/*
 * File:   PageRequestHandler.h
 * Author: danny
 *
 * Created on February 11, 2015, 10:02 PM
 */

#ifndef PAGEREQUESTHANDLER_H
#define	PAGEREQUESTHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>
#include <fstream>
#include <string>

class PageRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    PageRequestHandler();
    virtual ~PageRequestHandler();
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse & response);
protected:
    virtual std::string title() const = 0;
    virtual std::string subtitle() const = 0;
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest & request) = 0;
    virtual void renderButtons(std::ostream& output) = 0;
    virtual void renderHeader(std::ostream & output);
    virtual void renderScripts(std::ostream & output);
    virtual void renderPageFooter(std::ostream & output);
    virtual bool renderFormStart(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse & response) = 0;

    bool getQueryParam(const std::string& name, std::string& value, Poco::Net::HTTPServerRequest & request);
    std::string queryParam(const std::string& name, Poco::Net::HTTPServerRequest& request);
private:
    std::string _language = "en";

};

#endif	/* PAGEREQUESTHANDLER_H */

