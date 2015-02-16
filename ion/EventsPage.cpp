/*
 * File:   EventsRequestsHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 11:08 PM
 */

#include "EventsPage.h"
#include <Poco/Util/Application.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include "DataSubsystem.h"
#include "EventNotification.h"

EventsPage::EventsPage()
{
}

EventsPage::~EventsPage()
{
}

void EventsPage::renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << "<table id='events' class='table table-responsive' >";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT mac, datetime(time,'unixepoch','localtime') as time,name,ip,details FROM event ORDER BY time DESC";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    output << "<thead>";
    output << "<tr>";
    output << "<th>When</th>";
    output << "<th>What</th>";
    output << "<th>Details</th>";
    output << "</tr>";
    output << "</thead>";
    output << "<tbody>";
    while (more) {
        renderRow(output, rs);
        more = rs.moveNext();
    }
    output << "    </tbody>";
    output << "</table>";

    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#events').dataTable();";
    output << "    });";
    output << "</script>";
}

std::string EventsPage::title() const
{
    return "My Events";
}

bool EventsPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void EventsPage::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    std::string name = rs["name"].toString();
    std::string mac = rs["mac"].toString();
    std::string ip = rs["ip"].toString();
    std::string what;
    if (name == EventNotification::IP_ONLINE) {
        what = Poco::format("%s connected to network", ip);
    }
    else if (name == EventNotification::IP_OFFLINE) {
        what = Poco::format("%s disconnected from network", ip);
    }
    else if (name == EventNotification::THING_ONLINE) {
        what = Poco::format("New things %s connected to network", mac);
    }
    else if (name == EventNotification::THING_OFFLINE) {
        what = Poco::format("Things %s disappeared from the network", mac);
    }
    else if (name == EventNotification::NOT_AUTHORIZED) {
        what = Poco::format("<font color='red'>Detected non authorized thing %s </font>", mac);
    }
    output << "<tr>";
    output << Poco::format("<td>%s</td>", rs["time"].toString());
    output << Poco::format("<td>%s</td>", what);
    output << Poco::format("<td>%s</td>", rs["details"].toString());
    output << "</tr>";
}
