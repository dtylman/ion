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
    renderScripts(output);
}

void ThingsPage::renderTable(std::ostream& output)
{
    output << "<div class='table-responsive'>\n";
    output << "<table id='things' class='table table-responsive' >\n";
    output << "    <thead>\n";
    output << "        <tr>\n";
    output << "            <th>Type</th>\n";
    output << "            <th>Name</th>\n";
    output << "            <th>Vendor</th>\n";
    output << "            <th>OS</th>\n";
    output << "            <th>Description</th>\n";
    output << "            <th>Authorized</th>\n";
    output << "            <th></th>\n";
    output << "        </tr>\n";
    output << "    </thead>\n";

    output << "    <tbody>\n";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT  thing.mac, thing.type, thing.name, thing.vendor, "
            "thing.os, desc, case when authorized.mac is null then 'no' else 'yes' end as auth "
            "FROM thing "
            "LEFT JOIN authorized on thing.mac = authorized.mac "
            "ORDER BY thing.type desc";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    while (more) {
        renderRow(output, rs);
        more = rs.moveNext();
    }
    output << "    </tbody>\n";
    output << "</table>\n";
    output << "</div>\n";

}

void ThingsPage::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    output << "<tr>";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        if (rs.columnName(i) != "mac") {
            output << "<td>";
            if (!rs[i].isEmpty()) {
                if (rs.columnName(i) == "auth") {
                    output << Poco::format("<a href='%s?mac=%s&auth=toggle'>", WebMenu::PAGE_EDIT_THING, rs["mac"].toString());
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
    output << Poco::format("<a href='%s?mac=%s'>", WebMenu::PAGE_EDIT_THING, rs["mac"].toString());
    output << "<span class='glyphicon glyphicon-edit' ></span> Edit</a>";

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
