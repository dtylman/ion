/*
 * File:   DevicesRequestHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 10:30 PM
 */

#include "ThingsPage.h"
#include "DataSubsystem.h"
#include "WebMenu.h"
#include "IONDataObject.h"
#include "AuthDataObject.h"
#include "EditThingPage.h"
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Util/Application.h>
#include <Poco/Format.h>

using namespace Poco::Data::Keywords;

const std::string ThingsPage::Title("My Things");
const std::string ThingsPage::Link("things.bin");
const std::string ThingsPage::ParamAction("action");
const std::string ThingsPage::ParamThingID("id");
const std::string ThingsPage::ActionAuthAll("authall");
const std::string ThingsPage::ActionToggleAuth("toggleauth");
const std::string ThingsPage::ActionUnAuthAll("unauthall");
const std::string ThingsPage::ActionDelete("delete");

ThingsPage::ThingsPage()
{
}

ThingsPage::~ThingsPage()
{

}

std::string ThingsPage::title() const
{
    return Title;
}

void ThingsPage::renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << "<div class='panel panel-default'>";
    output << "<div class='panel-heading'>";
    output << "<h3 class='panel-title'>This should explain what this page is for</h3>";
    output << "</div>";

    renderTable(output);
    output << "<div class='panel-footer clearfix'>";
    output << Poco::format("<a href='%s?%s=%s' class='btn btn-primary'>Authorize All</a> ", Link, ParamAction, ActionAuthAll);
    output << Poco::format("<a href='%s?%s=%s' class='btn btn-primary'>UnAuthorize All</a>", Link, ParamAction, ActionUnAuthAll);
    output << "</div>";
    output << "</div>";
    renderScripts(output);
}

void ThingsPage::renderTable(std::ostream& output)
{
    output << "<div class='table-responsive'>";
    output << "<table id='things' class='table table-responsive' >";
    output << "    <thead>";
    output << "        <tr>";
    output << "            <th>Type</th>";
    output << "            <th>Name</th>";
    output << "            <th>Vendor</th>";
    output << "            <th>OS</th>";
    output << "            <th>Description</th>";
    output << "            <th>Authorized</th>";
    output << "            <th></th>";
    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT DISTINCT thing.id, thing.type, thing.name, thing.vendor, thing.os, thing.desc, "
            "case when authorized.mac is null then 'no' else 'yes' end as auth "
            "FROM ip "
            "LEFT JOIN thing on ip.thingid = thing.id "
            "LEFT JOIN authorized on ip.mac = authorized.mac "
            "ORDER BY thing.type desc ";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    while (more) {
        renderRow(output, rs);
        more = rs.moveNext();
    }
    output << "    </tbody>";
    output << "</table>";
    output << "</div>";

}

void ThingsPage::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    output << "<tr>";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        if (rs.columnName(i) != "id") {
            output << "<td>";
            if (!rs[i].isEmpty()) {
                if (rs.columnName(i) == "auth") {
                    output << Poco::format("<a href='%s?%s=%s&%s=%s'>", Link, ParamAction, ActionToggleAuth, ParamThingID, rs["id"].toString());
                }
                output << rs[i].toString();
                if (rs.columnName(i) == "auth") {
                    output << "</a>";
                }
            }
            output << "</td>";
        }
    }
    output << "<td>";
    output << Poco::format("<a href='%s?%s=%s'>", EditThingPage::Link, EditThingPage::ParamThingID, rs["id"].toString());
    output << "<span class='glyphicon glyphicon-edit' ></span> Edit</a> ";
    output << Poco::format("<a href='%s?%s=%s&%s=%s'>", Link, ParamAction, ActionDelete, ParamThingID, rs["id"].toString());
    output << "<span class='glyphicon glyphicon-remove' ></span> Remove</a>";
    output << "</td>";

    output << "</tr>";
}

void ThingsPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#things').dataTable();";
    output << "    });";
    output << "</script>";

}

bool ThingsPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    std::string action = getQueryParam(ParamAction, request);
    if (action == ActionAuthAll) {
        handleAuthAll(true);
    }
    else if (action == ActionUnAuthAll) {
        handleAuthAll(false);
    }
    else if (action == ActionToggleAuth) {
        handleToggleAuth(request);
    }
    else if (action == ActionDelete) {
        handleDelete(request);
    }
    return false;
}

void ThingsPage::handleDelete(Poco::Net::HTTPServerRequest& request)
{
    Poco::UUID thingid = Poco::UUID(getQueryParam(ParamThingID, request));
    IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    ion.removeThing(thingid);
}

void ThingsPage::handleToggleAuth(Poco::Net::HTTPServerRequest& request)
{
    Poco::UUID thingid = Poco::UUID(getQueryParam(ParamThingID, request));
    IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    bool auth = ion.thingAuthorized(thingid);
    ion.authorizeThing(thingid, !auth);
}

void ThingsPage::handleAuthAll(bool auth)
{
    AuthDataObject ado(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    if (auth) {
        ado.authorizeAll();
    }
    else {
        ado.unAuthorizeAll();
    }
}
