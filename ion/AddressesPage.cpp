/*
 * File:   AddressesPage.cpp
 * Author: danny
 *
 * Created on February 16, 2015, 12:26 PM
 */

#include "AddressesPage.h"
#include "DataSubsystem.h"
#include "WebMenu.h"
#include "EditThingPage.h"
#include <Poco/Data/Session.h>
#include <Poco/Util/Application.h>

const std::string AddressesPage::Title("My Addresses");
const std::string AddressesPage::Link("addresses.bin");

AddressesPage::AddressesPage()
{
}

AddressesPage::~AddressesPage()
{
}

std::string AddressesPage::title() const
{
    return Title;
}

bool AddressesPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void AddressesPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    renderTable(output);

    renderScripts(output);
}

void AddressesPage::renderButtons(std::ostream& output)
{

}

std::string AddressesPage::subtitle() const
{
    return "Some text goes here";
}

void AddressesPage::renderTable(std::ostream& output)
{
    output << "<div class='table-responsive'>";
    output << "<table id='addresses' class='table table-responsive' >";
    output << "    <thead>";
    output << "        <tr>";
    output << "            <th>MAC Address</th>";
    output << "            <th>IP Address</th>";
    output << "            <th>Last Seen</th>";
    output << "            <th>Type</th>";
    output << "            <th>Name</th>";
    output << "            <th>Vendor</th>";
    output << "            <th>Operating System</th>";
    output << "            <th>Description</th>";
    output << "            <th>Hardware Family</th>";
    output << "            <th>Authorized</th>";
    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT ip.mac, ip, datetime(last_seen,'unixepoch','localtime') as last_seen, "
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
                output << Poco::format("<a href='%s?id=%s'>", EditThingPage::Link, rs["id"].toString());
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

