/*
 * File:   TrafficZoomPage.cpp
 * Author: danny
 *
 * Created on March 18, 2015, 2:41 PM
 */

#include "TrafficZoomPage.h"
#include <Poco/Data/Session.h>
#include <Poco/Util/Application.h>
#include "DataSubsystem.h"
#include "AuthorizationPage.h"

using namespace Poco::Data::Keywords;

const std::string TrafficZoomPage::Link("trafficzoom.bin");
const std::string TrafficZoomPage::Title("Traffic");

TrafficZoomPage::TrafficZoomPage()
{
}

TrafficZoomPage::~TrafficZoomPage()
{
}

bool TrafficZoomPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void TrafficZoomPage::renderButtons(std::ostream& output)
{
    output << Poco::format("<a href='%s?type=%s&value=%s' class='btn btn-primary'>Authorize %s</a> ", AuthorizationPage::Link, _field, _value, _value);
}

void TrafficZoomPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << "<div class='table-responsive'>";
    output << "<table id='trafficzoom' class='table table-responsive' >";
    output << "    <thead>";
    output << "        <tr>";
    output << "            <th>Time</th>";
    output << "            <th>Count</th>";
    output << "            <th>Transport</th>";
    output << "            <th>IP</th>";
    output << "            <th>Port</th>";
    output << "            <th>Service</th>";
    output << "            <th>Host</th>";
    output << "            <th>Domain</th>";
    output << "            <th>Process</th>";
    output << "        </tr>";
    output << "    </thead>";

    output << "    <tbody>";

    _field = queryParam("field", request);
    _value = queryParam("value", request);
    if (_value == "-") {
        _value = "";
    }
    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);

    query << "SELECT datetime(time,'unixepoch','localtime') as time,count,traffic.transport, ip,traffic.port,service.service, host,domain, process FROM traffic "
            "LEFT JOIN service on traffic.port=service.port ";
    if (!_field.empty()) {
        query << "WHERE " << _field << " = '" << _value << "'";
    }
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

void TrafficZoomPage::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    output << "<tr>";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        const std::string& columnName = rs.columnName(i);
        std::string value = rs[i].toString();
        output << "<td>";
        if (columnName == "port") {
            output << Poco::format("<a href=%s?type=port&value=%s><span class='glyphicon glyphicon-ok' aria-hidden='true'></span></a> ", AuthorizationPage::Link, value);
        }
        output << value;
        output << "</td>";
    }
    output << "</tr>";
}

void TrafficZoomPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#trafficzoom').dataTable( { stateSave: true });";
    output << "    });";
    output << "</script>";
}

std::string TrafficZoomPage::subtitle() const
{
    return "cool stuff";
}

std::string TrafficZoomPage::title() const
{
    return Title;
}

