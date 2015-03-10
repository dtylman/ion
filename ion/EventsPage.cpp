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

const std::string EventsPage::Title("My Events");
const std::string EventsPage::Link("events.bin");

EventsPage::EventsPage()
{
}

EventsPage::~EventsPage()
{
}

void EventsPage::renderButtons(std::ostream& output)
{

}

std::string EventsPage::subtitle() const
{
    return "List of network events:";
}

void EventsPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << "<table id='events' class='table table-responsive' >";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT datetime(time,'unixepoch','localtime') as time,name,details FROM event ORDER BY time DESC";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    output << "<thead>";
    output << "<tr>";
    output << "<th>When</th>";
    output << "<th>What</th>";
    output << "</tr>";
    output << "</thead>";
    output << "<tbody>";
    while (more) {
        renderRow(output, rs);
        more = rs.moveNext();
    }
    output << "    </tbody>";
    output << "</table>";
}

std::string EventsPage::title() const
{
    return Title;
}

bool EventsPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void EventsPage::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    std::string name = rs["name"].toString();
    std::string details = rs["details"].toString();
    output << "<tr>";
    output << Poco::format("<td>%s</td>", rs["time"].toString());
    if (name == EventNotification::NOT_AUTHORIZED) {
        output << Poco::format("<td><font color='red'>%s</font></td>", details);
    }
    else {
        output << Poco::format("<td>%s</td>", details);
    }
    output << "</tr>";
}

void EventsPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "    $(document).ready(function () {";
    output << "        $('#events').dataTable();";
    output << "    });";
    output << "</script>";
}
