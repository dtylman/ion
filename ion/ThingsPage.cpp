/*
 * File:   DevicesRequestHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 10:30 PM
 */

#include "ThingsPage.h"
#include "DataSubsystem.h"
#include "WebMenu.h"
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Util/Application.h>
#include <Poco/Format.h>
using namespace Poco::Data::Keywords;

ThingsPage::ThingsPage()
{
}

ThingsPage::~ThingsPage()
{

}

std::string ThingsPage::title() const
{
    return "My Things";
}

void ThingsPage::renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    renderTable(output);
    output << Poco::format(" <a href='%s' class='btn btn-primary'>Authorize All</a>", WebMenu::PAGE_THINGS);
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
                    output << Poco::format("<a href='%s?action=auth&id=%s&auth=%s'>", WebMenu::PAGE_SAVE_THING, rs["id"].toString(), rs["auth"].toString());
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
    output << Poco::format("<a href='%s?id=%s'>", WebMenu::PAGE_EDIT_THING, rs["id"].toString());
    output << "<span class='glyphicon glyphicon-edit' ></span> Edit</a> ";
    output << Poco::format("<a href='%s?action=delete&id=%s'>", WebMenu::PAGE_SAVE_THING, rs["id"].toString());
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
    return false;
}
