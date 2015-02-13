/*
 * File:   DevicesRequestHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 10:30 PM
 */

#include "ThingsRequestHandler.h"
#include "DataSubsystem.h"
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Util/Application.h>

using namespace Poco::Data::Keywords;

ThingsRequestHandler::ThingsRequestHandler()
{
}

ThingsRequestHandler::~ThingsRequestHandler()
{

}

std::string ThingsRequestHandler::title() const
{
    return "My Things";
}

void ThingsRequestHandler::renderBody(std::ostream& output)
{
    output << "                    <div class='table-responsive'>\n";
    renderTable(output);
    output << "                    </div>\n";
    renderScripts(output);
}

void ThingsRequestHandler::renderTable(std::ostream& output)
{
    output << "<table id='things' class='table table-responsive' >\n";
    output << "    <thead>\n";
    output << "        <tr>\n";
    output << "            <td>Actions</td>\n";
    output << "            <th>MAC</th>\n";
    output << "            <th>IP</th>\n";
    output << "            <th>Last</th>\n";
    output << "            <th>Type</th>\n";
    output << "            <th>Name</th>\n";
    output << "            <th>Vendor</th>\n";
    output << "            <th>OS</th>\n";
    output << "            <th>HW</th>\n";
    output << "            <th>Description</th>\n";
    output << "            <th>Authorized</th>\n";
    output << "        </tr>\n";
    output << "    </thead>\n";

    output << "    <tbody>\n";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT ip.mac, ip, datetime(last_seen,'unixepoch','localtime') as last_seen, "
            "thing.type, thing.name, thing.vendor, "
            "thing.os, desc, oui.vendor as hw_vendor , case when  authorized.mac is null then 'no' else 'yes' end as auth "
            "    FROM ip LEFT JOIN thing ON ip.mac=thing.mac "
            "    LEFT JOIN oui ON substr(ip.mac,0,9)=oui.prefix "
            "LEFT JOIN authorized on ip.mac=authorized.mac "
            "ORDER BY ip.mac";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    while (more) {
        renderRow(output, rs);
        more = rs.moveNext();
    }
    output << "    </tbody>\n";
    output << "</table>\n";

}

void ThingsRequestHandler::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    output << "<tr>";
    output << "<td>";
    output << "<a href='edithing.bin?mac=";
    output << rs["mac"].toString();
    output << "'>"
            "<span class='glyphicon glyphicon-edit' ></span>"
            " Edit</a>";
    output << "</td>";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        output << "<td>";
        if (!rs[i].isEmpty()) {
            output << rs[i].toString();
        }
        output << "</td>";
    }
    output << "</tr>";
}

void ThingsRequestHandler::renderScripts(std::ostream& output)
{
    output << "<script>\n";
    output << "    $(document).ready(function () {\n";
    output << "        $('#things').dataTable();\n";
    output << "    });\n";
    output << "    $('.combobox').combobox();\n";
    output << "</script>\n";

}

bool ThingsRequestHandler::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}
