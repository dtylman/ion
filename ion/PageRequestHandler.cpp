/*
 * File:   PageRequestHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 10:02 PM
 */

#include "PageRequestHandler.h"
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
    output << "<!DOCTYPE html>\n";
    output << "<html lang='" << _language << "'>\n";
    output << "    <head>\n";
    output << "        <meta http-equiv='Content-Type' content='text/html; charset=UTF-8'>\n";
    output << "        <meta charset='utf-8'>\n";
    output << "        <meta name='viewport' content='width=device-width, initial-scale=1'>\n";
    output << "        <meta name='description' content=''>\n";
    output << "        <meta name='author' content=''>\n";
    output << "        <link href='css/bootstrap.min.css' rel='stylesheet'>\n";
    output << "        <link href='css/bootstrap-combobox.css' rel='stylesheet'>\n";
    output << "        <link href='css/dashboard.css' rel='stylesheet'>\n";
    output << "        <link href='css/jquery.dataTables.min.css' rel='stylesheet' >\n";
    output << "        <script src='js/jquery-2.1.3.min.js'></script>\n";
    output << "        <script src='js/jquery.dataTables.min.js'></script>\n";
    output << "        <script src='js/bootstrap.min.js'></script>\n";
    output << "        <script src='js/bootstrap-combobox.js'></script>\n";
    output << "        <title>" << title() << "</title>\n";
    output << "    </head>\n";
    output << "\n";
}

void PageRequestHandler::renderMenus(std::ostream& output)
{
    output << "    <body>\n";
    output << "        <nav class='navbar navbar-inverse navbar-fixed-top'>\n";
    output << "            <div class='container-fluid'>\n";
    output << "                <div class='navbar-header'>\n";
    output << "                    <button type='button' class='navbar-toggle collapsed' data-toggle='collapse' data-target='#navbar' aria-expanded='false' aria-controls='navbar'>\n";
    output << "                        <span class='sr-only'>Toggle navigation</span>\n";
    output << "                        <span class='icon-bar'></span>\n";
    output << "                        <span class='icon-bar'></span>\n";
    output << "                        <span class='icon-bar'></span>\n";
    output << "                    </button>\n";
    output << "                    <a class='navbar-brand' href='#'>Project name</a>\n";
    output << "                </div>\n";
    output << "                <div id='navbar' class='navbar-collapse collapse'>\n";
    output << "                    <ul class='nav navbar-nav navbar-right'>\n";
    output << "                        <li><a href='#'>Dashboard</a></li>\n";
    output << "                        <li><a href='#'>Settings</a></li>\n";
    output << "                        <li><a href='#'>Profile</a></li>\n";
    output << "                        <li><a href='#'>Help</a></li>\n";
    output << "                    </ul>\n";
    output << "                    <form class='navbar-form navbar-right'>\n";
    output << "                        <input type='text' class='form-control' placeholder='Search...'>\n";
    output << "                    </form>\n";
    output << "                </div>\n";
    output << "            </div>\n";
    output << "        </nav>\n";
    output << "\n";
    output << "        <div class='container-fluid'>\n";
    output << "            <div class='row'>\n";
    output << "                <div class='col-sm-3 col-md-2 sidebar'>\n";
    output << "                    <ul class='nav nav-sidebar'>\n";
    output << "                        <li class='active'><a href='devices.bin'>Things<span class='sr-only'>(current)</span></a></li>\n";
    output << "                        <li><a href='events.bin'>Events</a></li>\n";
    output << "                        <li><a href='#'>Analytics</a></li>\n";
    output << "                        <li><a href='#'>Export</a></li>\n";
    output << "                    </ul>\n";
    output << "                    <ul class='nav nav-sidebar'>\n";
    output << "                        <li><a href=''>Nav item</a></li>\n";
    output << "                        <li><a href=''>Nav item again</a></li>\n";
    output << "                        <li><a href=''>One more nav</a></li>\n";
    output << "                        <li><a href=''>Another nav item</a></li>\n";
    output << "                        <li><a href=''>More navigation</a></li>\n";
    output << "                    </ul>\n";
    output << "                    <ul class='nav nav-sidebar'>\n";
    output << "                        <li><a href=''>Nav item again</a></li>\n";
    output << "                        <li><a href=''>One more nav</a></li>\n";
    output << "                        <li><a href=''>Another nav item</a></li>\n";
    output << "                    </ul>\n";
    output << "                </div>\n";
    output << "                <div class='col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 main'>\n";
    output << "                    <h2 class='sub-header'>" << title() << "</h2>\n";
}

void PageRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");

    std::ostream& output = response.send();
    renderHeader(output);
    renderMenus(output);
    renderBody(output);
    renderFooter(output);
}

void PageRequestHandler::renderFooter(std::ostream& output)
{
    output << "        <svg xmlns='http://www.w3.org/2000/svg' width='200' height='200' viewBox='0 0 200 200' preserveAspectRatio='none' style='visibility: hidden; position: absolute; top: -100%; left: -100%;'>\n";
    output << "        <defs></defs>\n";
    output << "        <text x='0' y='10' style='font-weight:bold;font-size:10pt;font-family:Arial, Helvetica, Open Sans, sans-serif;dominant-baseline:middle'>200x200</text></svg>\n";
    output << "    </body>\n";
    output << "</html>\n";
}
