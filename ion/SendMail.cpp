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

#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SecureStreamSocket.h>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/SharedPtr.h>
#include <Poco/Util/Application.h>

using Poco::Net::MailMessage;
using Poco::Net::MailRecipient;
using Poco::Net::SMTPClientSession;

SendMail::SendMail() : _logger(Poco::Logger::get("SendMail"))
{

}

SendMail::~SendMail()
{

}

void SendMail::sendMessage(const std::string& content)
{
    try {
        const Poco::Util::AbstractConfiguration* config = Poco::Util::Application::instance().config().createView("ion.mail");
        MailMessage message;
        message.setSender(config->getString("sender"));
        message.addRecipient(MailRecipient(MailRecipient::PRIMARY_RECIPIENT, config->getString("recipient")));
        message.setSubject(MailMessage::encodeWord(config->getString("subject"), "UTF-8"));
        message.setContentType("text/plain; charset=UTF-8");
        message.addContent(new Poco::Net::StringPartSource(content));
        Poco::Net::SocketAddress address(config->getString("host"), config->getInt("port"));
        Poco::SharedPtr<Poco::Net::StreamSocket> socket(nullptr);
        if (config->getBool("ssl")) {
            socket = new Poco::Net::SecureStreamSocket(address);
        }
        else {

            socket = new Poco::Net::StreamSocket(address);
        }
        _logger.debug("Connecting to %s", address.toString());
        SMTPClientSession session(*socket);
        session.login(getLoginMethod(config->getString("loginmethod")), config->getString("user"), config->getString("password"));
        session.sendMessage(message);
        session.close();
        _logger.debug("Message sent");
    }
    catch (Poco::Exception& ex) {
        _logger.error(ex.displayText());
        throw;
    }
}

void SendMail::sendEvent(const EventData& event)
{
    _logger.debug("Sending mail from %s", event.toString());
    sendMessage(event.toString());
}

Poco::Net::SMTPClientSession::LoginMethod SendMail::getLoginMethod(const std::string& method)
{
    std::string loginMethod = Poco::toUpper(method);
    if (loginMethod == "AUTH_NONE") {
        return SMTPClientSession::LoginMethod::AUTH_NONE;
    }
    if (loginMethod == "AUTH_CRAM_MD5") {
        return SMTPClientSession::LoginMethod::AUTH_CRAM_MD5;
    }
    else if (loginMethod == "AUTH_CRAM_SHA1") {
        return SMTPClientSession::LoginMethod::AUTH_CRAM_SHA1;
    }
    else if (loginMethod == "AUTH_LOGIN") {
        return SMTPClientSession::LoginMethod::AUTH_LOGIN;
    }
    else if (loginMethod == "AUTH_PLAIN") {
        return SMTPClientSession::LoginMethod::AUTH_PLAIN;
    }

}
