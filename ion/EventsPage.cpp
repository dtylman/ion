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
#include "EventDataObject.h"

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
    output << Poco::format("<a href='%s?action=delete' class='btn btn-primary'>Delete All Events</a> ", EventsPage::Link);
}

std::string EventsPage::subtitle() const
{
    return "List of network events:";
}

void EventsPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    std::string action;
    if (getQueryParam("action", action, request)) {
        if (action == "delete") {
            EventDataObject edo(session);
            edo.deleteAll();
        }
    }
    output << "<table id='events' class='table table-responsive' >";
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
    if ((name == EventNotification::NOT_AUTHORIZED) || (name == EventNotification::NOT_AUTHORIZED_TRAFFIC)) {
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
    output << "        $('#events').dataTable({ stateSave: true });";
    output << "    });";
    output << "</script>";
}
