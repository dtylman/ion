/*
 * File:   Syslog.cpp
 * Author: danny
 *
 * Created on March 9, 2015, 8:41 PM
 */

#include "Syslog.h"

Syslog::Syslog() : _logger(Poco::Logger::get("Syslog"))
{
}

Syslog::~Syslog()
{
}

void Syslog::log(const EventData& eventData)
{
	HANDLE eventLog = RegisterEventSource(0, "ion");
	if (eventLog == 0)
	{
		_logger.error("Cannot register event source. Last error: %u", (unsigned)GetLastError());
		return;
	}
	std::string message = eventData.toString();
	const char* lines = message.c_str();
	if (FALSE == ReportEvent(eventLog, EVENTLOG_WARNING_TYPE, 1, 1, NULL, 1, 0, &lines, NULL))
	{
		_logger.error("Failed to write message to event log. Last error: %u", (unsigned)GetLastError());
	}
	DeregisterEventSource(eventLog);
}
