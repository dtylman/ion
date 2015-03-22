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
#include "WebForm.h"
#include "WhoisPage.h"
#include "TrafficZoomPage.h"
#include "AuthorizedTrafficPage.h"
#include "WebMenu.h"

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
    output << "            <th>Domain</th>";
    output << "            <th>Process</th>";
    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT datetime(time,'unixepoch','localtime') AS time, sum(count) AS count, "
            "traffic.ip as ip, traffic.host as host, traffic.domain as domain, traffic.process as process "
            "FROM traffic ";
    query << "LEFT JOIN ip ON traffic.ip=ip.ip ";
    if (_local) {
        query << "WHERE ip.ip IS NOT NULL ";
    }
    else {
        query << "WHERE ip.ip IS NULL ";
    }
    if (!_all) {
        query << "AND traffic.domain NOT IN (SELECT value FROM authorized_traffic WHERE  type='domain') AND ";
        query << "traffic.ip NOT IN (SELECT value FROM authorized_traffic WHERE  type='ip') AND ";
        query << "traffic.port NOT IN (SELECT value FROM authorized_traffic WHERE  type='port') AND ";
        query << "traffic.process NOT IN (SELECT value FROM authorized_traffic WHERE  type='process')";
    }
    query << " GROUP BY " << _group << " ORDER BY count DESC";
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
        const std::string& columnName = rs.columnName(i);
        std::string value = rs[i].toString();
        if (value.empty()) {
            value = "-";
        }
        output << "<td>";
        if (!_all) {
            if (columnName == "domain") {
                output << Poco::format("<a href=%s?query=%s><span class='glyphicon glyphicon-search' aria-hidden='true'></span></a> ", WhoisPage::Link, value);
                output << Poco::format("<a href=%s?type=domain&value=%s><span class='glyphicon glyphicon-ok' aria-hidden='true'></span></a> ", AuthorizedTrafficPage::Link, value);
            }
            else if (columnName == "ip") {
                output << Poco::format("<a href=%s?query=%s><span class='glyphicon glyphicon-search' aria-hidden='true'></span></a> ", WhoisPage::Link, value);
                output << Poco::format("<a href=%s?type=ip&value=%s><span class='glyphicon glyphicon-ok' aria-hidden='true'></span></a> ", AuthorizedTrafficPage::Link, value);
            }
            else if (columnName == "process") {
                output << Poco::format("<a href=%s?type=process&value=%s><span class='glyphicon glyphicon-ok' aria-hidden='true'></span></a> ", AuthorizedTrafficPage::Link, value);
            }
        }
        if ((columnName != "time") && (columnName != "count")) {
            output << Poco::format("<a href=%s?field=%s&value=%s>%s</a> ", TrafficZoomPage::Link, columnName, value, value);
        }
        else {
            output << value;
        }
        output << "</td>";
    }
    output << "</tr>";
}

void TrafficPage::renderScripts(std::ostream & output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#traffic').dataTable( {";
    output << "             'stateSave': true,";
    output << "             'order': [[2,'desc']]";
    output << "         });";
    output << "    });";
    output << "</script>";
}

std::string TrafficPage::subtitle() const
{
    std::string type = "remote";
    if (_local) {
        type = "local";
    }
    if (_all) {
        return Poco::format("Showing all %s traffic", type);
    }
    else {
        return Poco::format("Showing non authorized %s traffic", type);
    }
}

std::string TrafficPage::title() const
{
    return "My Traffic";
}

bool TrafficPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse &)
{
    _local = form.has("local");
    _all = form.has("all");
    if (form.has("filter")) {
        _group = form.get("filter");
        if (_group == "IP") {
            _group = "traffic.ip";
        }
    }
    return false;
}

void TrafficPage::renderButtons(std::ostream & output)
{
    output << Poco::format("<form method='POST' action='%s' class='form-inline'>", Link);
    WebForm form(output);
    form.startRow();
    form.renderChkbox("local", "Local Traffic only:  ", _local, 2);
    form.renderChkbox("all", "Show All traffic:  ", _all, 2);
    WebForm::Options filterOptions;
    filterOptions.push_back("Domain");
    filterOptions.push_back("Host");
    filterOptions.push_back("IP");
    filterOptions.push_back("Time");
    filterOptions.push_back("Process");
    form.renderSelect("filter", "Filter By:  ", _group, filterOptions, 2);
    output << "<input type='submit' class='btn btn-primary' value='Filter...'></input> ";
    form.endRow();
    form.startRow();
    WebMenu::renderLinkButton(output, "Authorize processes", Poco::format("%s?type=every&value=process", AuthorizedTrafficPage::Link));
    WebMenu::renderLinkButton(output, "Authorize domains", Poco::format("%s?type=every&value=domain", AuthorizedTrafficPage::Link));
    WebMenu::renderLinkButton(output, "Authorize ips", Poco::format("%s?type=every&value=ip", AuthorizedTrafficPage::Link));
    WebMenu::renderLinkButton(output, "Authorize ports", Poco::format("%s?type=every&value=port", AuthorizedTrafficPage::Link));
    WebMenu::renderLinkButton(output, "Authorize everything", Poco::format("%s?type=every&value=thing", AuthorizedTrafficPage::Link));
    form.endRow();
    output << "</form>";

}
