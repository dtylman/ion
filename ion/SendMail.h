/*
 * File:   SendMail.h
 * Author: danny
 *
 * Created on February 4, 2015, 11:10 AM
 */

#ifndef SENDMAIL_H
#define	SENDMAIL_H

#include "EventData.h"
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Logger.h>

class SendMail
{
public:
    SendMail();
    void sendEvent(const EventData& event);
    void sendMessage(const std::string& content);
    virtual ~SendMail();
private:
    Poco::Net::SMTPClientSession::LoginMethod getLoginMethod(const std::string& method);
    Poco::Logger& _logger;
};

#endif	/* SENDMAIL_H */

