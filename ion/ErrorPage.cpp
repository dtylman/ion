/*
 * File:   ErrorRequestHandler.cpp
 * Author: danny
 *
 * Created on February 14, 2015, 3:59 PM
 */


#include "ErrorPage.h"
#include <Poco/Format.h>

ErrorPage::ErrorPage(const Poco::Net::HTTPResponse::HTTPStatus& status) : _httpStatus(status)
{

}

ErrorPage::~ErrorPage()
{
}

void ErrorPage::renderBody(std::ostream& output)
{

}

bool ErrorPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void ErrorPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    PageRequestHandler::handleRequest(request, response);
    response.setStatus(_httpStatus);
}

std::string ErrorPage::title() const
{
    return Poco::format("Error %u", (unsigned) _httpStatus);
}
