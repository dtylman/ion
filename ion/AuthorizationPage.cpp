/*
 * File:   TrafficAuthorizePage.cpp
 * Author: danny
 *
 * Created on March 18, 2015, 4:30 PM
 */

#include "AuthorizationPage.h"
#include "TrafficPage.h"
#include "AuthTrafficDataObject.h"
#include "DataSubsystem.h"
#include <Poco/Util/Application.h>

const std::string AuthorizationPage::Link("auth.bin");
const std::string AuthorizationPage::Title("Authorization Settings");

AuthorizationPage::AuthorizationPage()
{
}

AuthorizationPage::~AuthorizationPage()
{
}

void AuthorizationPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    std::string type;
    if (getQueryParam("type", type, request)) {
        std::string value = queryParam("value", request);
        authTraffic(type, value);
        response.redirect(TrafficPage::Link);
        return;
    }
    PageRequestHandler::handleRequest(request, response);
}

bool AuthorizationPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

std::string AuthorizationPage::subtitle() const
{
    return "Authorized stuff";
}

std::string AuthorizationPage::title() const
{
    return Title;
}

void AuthorizationPage::renderButtons(std::ostream& output)
{

}

void AuthorizationPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    std::string remove;
    if (getQueryParam("remove", remove, request)) {
        unAuthTraffic(remove, queryParam("value", request));
    }
    renderTrafficTable(output, request, session);
}

void AuthorizationPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#authtraffic').dataTable( { stateSave: true });";
    output << "    });";
    output << "</script>";
}

void AuthorizationPage::authTraffic(const std::string& type, const std::string& value)
{
    AuthTrafficDataObject atdo(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    atdo.authorize(type, value);
}

void AuthorizationPage::unAuthTraffic(const std::string& type, const std::string& value)
{
    AuthTrafficDataObject atdo(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    atdo.unauthorize(type, value);
}

//
//void AuthorizationPage::renderMACTable(std::ostream& output, Poco::Net::HTTPServerRequest& request, Poco::Data::Session& session)
//{
//    output << "<table id='authmac' class='table well' >";
//    output << "    <thead>";
//    output << "        <tr>";
//    output << "            <th>MAC</th>";
//    output << "        </tr>";
//    output << "    </thead>";
//
//    output << "    <tbody>";
//
//    Poco::Data::Statement query(session);
//    query << "SELECT mac FROM authorized";
//    query.execute();
//    Poco::Data::RecordSet rs(query);
//    bool more = rs.moveFirst();
//    while (more) {
//        output << "<tr><td>" << rs[0].toString() << "</td></tr>";
//        more = rs.moveNext();
//    }
//    output << "    </tbody>";
//    output << "</table>";
//}

void AuthorizationPage::renderTrafficTable(std::ostream& output, Poco::Net::HTTPServerRequest& request, Poco::Data::Session& session)
{
    output << "<table id='authtraffic' class='table well' >";
    output << "    <thead>";
    output << "        <tr>";
    output << "            <th>Type</th>";
    output << "            <th>Value</th>";
    output << "            <th>Actions</th>";

    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    Poco::Data::Statement query(session);
    query << "SELECT type,value FROM authorized_traffic";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    while (more) {
        const std::string& type = rs[0].toString();
        const std::string& value = rs[1].toString();
        output << "<tr>";
        output << "<td>" << type << "</td>";
        output << "<td>" << value << "</td>";
        output << Poco::format("<td><a href=%s?remove=%s&value=%s><span class='glyphicon glyphicon-trash' aria-hidden='true'></span> Remove</a></td>", Link, type, value);
        output << "</tr>";
        more = rs.moveNext();
    }
    output << "    </tbody>";
    output << "</table>";
}
