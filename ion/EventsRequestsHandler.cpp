/*
 * File:   EventsRequestsHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 11:08 PM
 */

#include "EventsRequestsHandler.h"
#include <Poco/Util/Application.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include "DataSubsystem.h"

EventsRequestsHandler::EventsRequestsHandler()
{
}

EventsRequestsHandler::~EventsRequestsHandler()
{
}

void EventsRequestsHandler::renderBody(std::ostream& output)
{
    output << "                        <table id='events' class='table table-responsive' >\n";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT mac, datetime(time,'unixepoch','localtime') as time,name,ip,details FROM event ORDER BY time";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    output << "                            <thead>\n";
    output << "                                <tr>\n";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        output << "<th>" << rs.columnName(i) << "</th>";
    }
    output << "                                </tr>\n";
    output << "                            </thead>\n";
    output << "                            <tbody>\n";
    while (more) {
        output << "                                <tr>\n";

        for (size_t i = 0; i < rs.columnCount(); ++i) {
            output << "<td>";
            if (!rs[i].isEmpty()) {
                output << rs[i].toString();
            }
            output << "</td>";
        }
        more = rs.moveNext();
        output << "                                </tr>\n";
    }
    output << "                            </tbody>\n";
    output << "                        </table>\n";

    output << "        <script>\n";
    output << "            $(document).ready(function () {\n";
    output << "                $('#events').dataTable();\n";
    output << "            });\n";
    output << "        </script>\n";
}

std::string EventsRequestsHandler::title() const
{
    return "Events";
}
