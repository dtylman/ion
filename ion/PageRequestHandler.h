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
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
protected:
    virtual std::string title() const = 0;
    virtual void renderBody(std::ostream& output) = 0;
    virtual void renderHeader(std::ostream& output);
    virtual void renderFooter(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) = 0;
private:
    std::string _language = "en";

};

#endif	/* PAGEREQUESTHANDLER_H */

