/*
 * File:   ErrorRequestHandler.h
 * Author: danny
 *
 * Created on February 14, 2015, 3:59 PM
 */

#ifndef ERRORPAGE_H
#define	ERRORPAGE_H

#include "PageRequestHandler.h"

class ErrorPage : public PageRequestHandler
{
public:
    ErrorPage(const Poco::Net::HTTPResponse::HTTPStatus& status);
    virtual ~ErrorPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output);
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    Poco::Net::HTTPResponse::HTTPStatus _httpStatus;
};

#endif	/* ERRORREQUESTHANDLER_H */

