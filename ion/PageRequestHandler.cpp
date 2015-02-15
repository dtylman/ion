/*
 * File:   PageRequestHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 10:02 PM
 */

#include "PageRequestHandler.h"
#include "WebMenu.h"
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

PageRequestHandler::PageRequestHandler()
{
}

PageRequestHandler::~PageRequestHandler()
{
}

void PageRequestHandler::renderHeader(std::ostream& output)
{
    output << "<!DOCTYPE html>";
    output << "<html lang='" << _language << "'>";
    output << "    <head>";
    output << "        <meta http-equiv='Content-Type' content='text/html; charset=UTF-8'>";
    output << "        <meta charset='utf-8'>";
    output << "        <meta name='viewport' content='width=device-width, initial-scale=1'>";
    output << "        <meta name='description' content=''>";
    output << "        <meta name='author' content=''>";
    output << "        <link href='css/bootstrap.min.css' rel='stylesheet'>";
    output << "        <link href='css/dashboard.css' rel='stylesheet'>";
    output << "        <link href='css/jquery.dataTables.min.css' rel='stylesheet' >";
    output << "        <link href='css/typeaheadjs.css' rel='stylesheet' >";
    output << "        <script src='js/jquery-2.1.3.min.js'></script>";
    output << "        <script src='js/jquery.dataTables.min.js'></script>";
    output << "        <script src='js/bootstrap.min.js'></script>";
    output << "        <script src='js/typeahead.bundle.js'></script>";
    output << "        <title>" << title() << "</title>";
    output << "    </head>";
    output << "    <body>";
}

void PageRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    Poco::Net::HTMLForm form(request, request.stream());
    if (!form.empty()) {
        if (handleForm(form, request, response)) {
            return;
        }
    }
    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");

    std::ostream& output = response.send();
    renderHeader(output);
    WebMenu menu;
    menu.renderNavBar(output, title());
    output << "<div class='col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 main'>";
    output << "<h2 class='sub-header'>" << title() << "</h2>";
    renderBody(output);
    output << "</div>";
    renderFooter(output);
}

void PageRequestHandler::renderFooter(std::ostream& output)
{
    output << "        <svg xmlns='http://www.w3.org/2000/svg' width='200' height='200' viewBox='0 0 200 200' preserveAspectRatio='none' style='visibility: hidden; position: absolute; top: -100%; left: -100%;'>";
    output << "        <defs></defs>";
    output << "        <text x='0' y='10' style='font-weight:bold;font-size:10pt;font-family:Arial, Helvetica, Open Sans, sans-serif;dominant-baseline:middle'>200x200</text></svg>";
    output << "    </body>";
    output << "</html>";
}
