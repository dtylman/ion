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

/*

--select  datetime(time,'unixepoch','localtime') AS time, sum(count) AS count, traffic.ip, host, domain, process, port, transport  FROM traffic
--left join ip on traffic.ip=ip.ip WHERE ip.ip is  null group by port order by count DESC

--select  datetime(time,'unixepoch','localtime') AS time, count, traffic.ip, host, domain, process, port, transport  FROM traffic
--left join ip on traffic.ip=ip.ip WHERE ip.ip is  null AND domain=''  group by traffic.ip order by count DESC
 */
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
    output << "            <th>Domain</th>";
    output << "            <th>Process</th>";
    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    std::string groupby;
    if (!getQueryParam("group", groupby, request)) {
        groupby = "domain";
    }
    std::string ipip;
    if (queryParam("local", request) == "yes") {
        ipip = " IS NOT NULL";
    }
    else {
        ipip = " IS NULL";
    }
    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT datetime(time,'unixepoch','localtime') AS time, sum(count) AS count, traffic.ip as ip, host, domain, process FROM traffic ";
    query << "LEFT JOIN ip ON traffic.ip=ip.ip ";
    query << "WHERE ip.ip " << ipip;
    query << " GROUP BY " << groupby << " ORDER BY count DESC";
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

void TrafficPage::renderRow(std::ostream& output, Poco::Data::RecordSet & rs)
{
    output << "<tr>";
    for (size_t i = 0; i < rs.columnCount(); ++i) {

        output << "<td>";
        output << rs[i].toString();
        output << "</td>";
    }
    output << "</tr>";
}

void TrafficPage::renderScripts(std::ostream & output)
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

bool TrafficPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse & response)
{

    return false;
}

void TrafficPage::renderButtons(std::ostream & output)
{

}
