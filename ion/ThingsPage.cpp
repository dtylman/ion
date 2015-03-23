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
#include <Poco/File.h>
#include <Poco/Path.h>

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

std::string ThingsPage::subtitle() const
{
    return "List of things connected to the network:";
}

void ThingsPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    handleParams(request);
    renderTable(output);
}

void ThingsPage::renderButtons(std::ostream& output)
{
    output << Poco::format("<a href='%s?%s=%s' class='btn btn-primary'>Authorize All</a> ", Link, ParamAction, ActionAuthAll);
    output << Poco::format("<a href='%s?%s=%s' class='btn btn-primary'>UnAuthorize All</a>", Link, ParamAction, ActionUnAuthAll);
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
    output << "            <th>Operating System</th>";
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
        std::string columnName = rs.columnName(i);
        if (columnName != "id") {
            output << "<td>";
            if (!rs[i].isEmpty()) {
                std::string value = rs[i].toString();
                if (columnName == "type") {
                    renderIcon(output, value);
                }
                if (columnName == "auth") {
                    output << Poco::format("<a href='%s?%s=%s&%s=%s'>", Link, ParamAction, ActionToggleAuth, ParamThingID, rs["id"].toString());
                }
                output << value;
                if (columnName == "auth") {
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
    output << "        $('#things').dataTable({ stateSave: true });";
    output << "    });";
    output << "</script>";

}

bool ThingsPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void ThingsPage::handleDelete(Poco::Net::HTTPServerRequest& request)
{
    std::string id;
    if (getQueryParam(ParamThingID, id, request)) {
        IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
        ion.removeThing(Poco::UUID(id));
    }

}

void ThingsPage::handleToggleAuth(Poco::Net::HTTPServerRequest& request)
{
    std::string id;
    if (getQueryParam(ParamThingID, id, request)) {
        IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
        Poco::UUID thingid(id);
        bool auth = ion.thingAuthorized(thingid);
        ion.authorizeThing(thingid, !auth);
    }
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

void ThingsPage::handleParams(Poco::Net::HTTPServerRequest& request)
{
    std::string action;
    if (getQueryParam(ParamAction, action, request)) {
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
    }
}

void ThingsPage::renderIcon(std::ostream& output, const std::string& type)
{
    if (!type.empty()) {
        Poco::Path imageFile = Poco::Util::Application::instance().config().getString("application.dir");
        imageFile.pushDirectory("web");
        imageFile.pushDirectory("images");
        imageFile.pushDirectory("things");
        imageFile.setBaseName(Poco::toLower(type));
        imageFile.setExtension("png");
        if (Poco::File(imageFile).exists()) {
            output << Poco::format("<img src='images/things/%s.png' /> ", Poco::toLower(type), type);
        }
        else {
            output << "<img src='images/things/box.png' /> ";
        }
    }
}
