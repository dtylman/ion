/*
 * File:   SendMail.cpp
 * Author: danny
 *
 * Created on February 4, 2015, 11:10 AM
 */

#include "SendMail.h"
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/MailRecipient.h>
#include <Poco/Net/StringPartSource.h>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Util/Application.h>

using Poco::Net::MailMessage;
using Poco::Net::MailRecipient;
using Poco::Net::SMTPClientSession;

SendMail::SendMail()
{

}

SendMail::~SendMail()
{

}

void SendMail::send(const EventData& event)
{
    Poco::Util::AbstractConfiguration& config = Poco::Util::Application::instance().config();
    //("ion.mail");
    MailMessage message;
    message.setSender(config.getString("ion.mail.sender"));
    message.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT, config.getString("ion.mail.recipient")));

    message.setSubject(config.getString("ion.mail.subject"));
    std::string content = config.getString("ion.mail.content");
    message.addContent(new Poco::Net::StringPartSource(content));

    SMTPClientSession session(config.getString("ion.mail.host"), config.getInt("ion.mail.port", 25));
    std::string loginMethod = Poco::toUpper(config.getString("ion.mail.loginmethod"));
    SMTPClientSession::LoginMethod method = SMTPClientSession::LoginMethod::AUTH_NONE;
    if (loginMethod == "AUTH_CRAM_MD5") {
        method = SMTPClientSession::LoginMethod::AUTH_CRAM_MD5;
    }
    else if (loginMethod == "AUTH_CRAM_SHA1") {
        method = SMTPClientSession::LoginMethod::AUTH_CRAM_SHA1;
    }
    else if (loginMethod == "AUTH_LOGIN") {
        method = SMTPClientSession::LoginMethod::AUTH_LOGIN;
    }
    else if (loginMethod == "AUTH_PLAIN") {
        method = SMTPClientSession::LoginMethod::AUTH_PLAIN;
    }
    session.login(method, config.getString("ion.mail.user"), config.getString("ion.mail.password"));
    session.sendMessage(message);
    session.close();
}
