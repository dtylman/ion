/*
 * File:   TrafficPage.cpp
 * Author: danny
 *
 * Created on March 12, 2015, 11:16 PM
 */

#include "TrafficPage.h"
#include <Poco/Data/Session.h>
#include <Poco/Util/Application.h>
#include "DataSubsystem.h"

const std::string TrafficPage::Title("My Traffic");
const std::string TrafficPage::Link("traffic.bin");

TrafficPage::TrafficPage()
{
}

TrafficPage::~TrafficPage()
{
}

void TrafficPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << "<div class='table-responsive'>";
    output << "<table id='traffic' class='table table-responsive' >";
    output << "    <thead>";
    output << "        <tr>";
    output << "            <th>Time</th>";
    output << "            <th>Count</th>";
    output << "            <th>IP</th>";
    output << "            <th>Host</th>";
    output << "            <th>Process</th>";
    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT datetime(time,'unixepoch','localtime') AS time, sum(count) AS count, ip, host, process FROM traffic GROUP BY ip ORDER BY count DESC, time DESC";
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

void TrafficPage::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    output << "<tr>";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        output << "<td>";
        output << rs[i].toString();
        output << "</td>";
    }
    output << "</tr>";
}

void TrafficPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#traffic').dataTable();";
    output << "    });";
    output << "</script>";
}

std::string TrafficPage::subtitle() const
{
    return "All traffic";
}

std::string TrafficPage::title() const
{
    return "My Traffic";
}

bool TrafficPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void TrafficPage::renderButtons(std::ostream& output)
{

}
