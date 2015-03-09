/*
 * File:   Syslog.cpp
 * Author: danny
 *
 * Created on March 9, 2015, 8:41 PM
 */

#include "Syslog.h"
#include <syslog.h>

Syslog::Syslog()
{
    openlog("ion", LOG_PID, LOG_AUTH);
}

Syslog::~Syslog()
{
    closelog();
}

void Syslog::log(const EventData& eventData)
{
    syslog(LOG_ALERT, "%s", eventData.toString().c_str());
}
