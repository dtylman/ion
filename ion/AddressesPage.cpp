/*
 * File:   AddressesPage.cpp
 * Author: danny
 *
 * Created on February 16, 2015, 12:26 PM
 */

#include "AddressesPage.h"
#include "DataSubsystem.h"
#include "WebMenu.h"
#include <Poco/Data/Session.h>
#include <Poco/Util/Application.h>

AddressesPage::AddressesPage()
{
}

AddressesPage::~AddressesPage()
{
}

std::string AddressesPage::title() const
{
    return "My Addresses";
}

bool AddressesPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void AddressesPage::renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    renderTable(output);
    renderScripts(output);
}

void AddressesPage::renderTable(std::ostream& output)
{
    output << "<div class='table-responsive'>";
    output << "<table id='addresses' class='table table-responsive' >";
    output << "    <thead>";
    output << "        <tr>";
    output << "            <th>MAC</th>";
    output << "            <th>IP</th>";
    output << "            <th>Last</th>";
    output << "            <th>Type</th>";
    output << "            <th>Name</th>";
    output << "            <th>Vendor</th>";
    output << "            <th>OS</th>";
    output << "            <th>HW</th>";
    output << "            <th>Description</th>";
    output << "            <th>Authorized</th>";
    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT mac, ip, datetime(last_seen,'unixepoch','localtime') as last_seen, "
            "thing.id, thing.type, thing.name, thing.vendor, "
            "thing.os, desc, oui.vendor as hw_vendor , case when  authorized.mac is null then 'no' else 'yes' end as auth "
            "FROM ip LEFT JOIN thing ON ip.thingid=thing.id "
            "LEFT JOIN oui ON substr(ip.mac,0,9)=oui.prefix "
            "LEFT JOIN authorized on ip.mac=authorized.mac "
            "ORDER BY ip.mac";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    while (more) {
        renderRow(output, rs);
        more = rs.moveNext();
    }
    output << "    </tbody>";
    output << "</table>";
}

void AddressesPage::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    output << "<tr>";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        if (rs.columnName(i) == "id") {
            continue;
        }
        output << "<td>";
        if (!rs[i].isEmpty()) {
            if (rs.columnName(i) == "mac") {
                output << Poco::format("<a href='%s?id=%s'>", WebMenu::PAGE_EDIT_THING, rs["id"].toString());
            }
            output << rs[i].toString();
            if (rs.columnName(i) == "mac") {
                output << "</a>";
            }
        }
        output << "</td>";
    }
    output << "</tr>";
}

void AddressesPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#addresses').dataTable();";
    output << "    });";
    output << "</script>";

}

