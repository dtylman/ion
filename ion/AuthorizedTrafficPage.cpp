/*
 * File:   TrafficAuthorizePage.cpp
 * Author: danny
 *
 * Created on March 18, 2015, 4:30 PM
 */

#include "AuthorizedTrafficPage.h"
#include "TrafficPage.h"
#include "AuthTrafficDataObject.h"
#include "DataSubsystem.h"
#include <Poco/Util/Application.h>

const std::string AuthorizedTrafficPage::Link("authtraff.bin");
const std::string AuthorizedTrafficPage::Title("Authorized Traffic");

AuthorizedTrafficPage::AuthorizedTrafficPage()
{
}

AuthorizedTrafficPage::~AuthorizedTrafficPage()
{
}

void AuthorizedTrafficPage::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
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

bool AuthorizedTrafficPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

std::string AuthorizedTrafficPage::subtitle() const
{
    return "Authorized stuff";
}

std::string AuthorizedTrafficPage::title() const
{
    return Title;
}

void AuthorizedTrafficPage::renderButtons(std::ostream& output)
{
    output << Poco::format("<a href='%s?remove=all' class='btn btn-primary'>Remove All</a> ", Link);
    output << Poco::format("<a href='%s' class='btn btn-primary'>%s</a> ", TrafficPage::Link, TrafficPage::Title);
}

void AuthorizedTrafficPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    std::string remove;
    if (getQueryParam("remove", remove, request)) {
        unAuthTraffic(remove, queryParam("value", request));
    }
    renderTrafficTable(output, request, session);
}

void AuthorizedTrafficPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#authtraffic').dataTable( { stateSave: true });";
    output << "    });";
    output << "</script>";
}

void AuthorizedTrafficPage::authTraffic(const std::string& type, const std::string& value)
{
    if (value.empty()) {
        return;
    }
    if (value == "-") {
        return;
    }
    AuthTrafficDataObject atdo(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    atdo.authorize(type, value);
}

void AuthorizedTrafficPage::unAuthTraffic(const std::string& type, const std::string& value)
{
    AuthTrafficDataObject atdo(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    if (type == "all") {
        atdo.unauthorizeAll();
    }
    else {
        atdo.unauthorize(type, value);
    }
}

void AuthorizedTrafficPage::renderTrafficTable(std::ostream& output, Poco::Net::HTTPServerRequest& request, Poco::Data::Session& session)
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
