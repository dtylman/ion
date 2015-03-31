/*
 * File:   MailSendPage.cpp
 * Author: danny
 *
 * Created on February 24, 2015, 3:44 PM
 */

#include "MailSendPage.h"
#include "WebMenu.h"
#include "SendMail.h"
#include <Poco/Format.h>
#include <Poco/Util/Application.h>

const std::string MailSendPage::Link("mailsend.bin");

MailSendPage::MailSendPage()
{
}

MailSendPage::~MailSendPage()
{
}

void MailSendPage::renderButtons(std::ostream& output)
{
    WebMenu::renderHomeButton(output, "Close");
}

void MailSendPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << Poco::format("<p>Sending mail to %s...</p>", Poco::Util::Application::instance().config().getString("ion.mail.recipient"));
    output.flush();
    SendMail mail;
    try {
        mail.sendMessage("Test");
        output << "<div class='alert alert-success' role='alert'>";
        output << "Message Sent successfully";
        output << "</div>";
    }
    catch (Poco::Exception& ex) {
        output << "<div class='alert alert-danger' role='alert'>Error! ";
        output << ex.displayText();
        output << "</div>";
    }
}

std::string MailSendPage::subtitle() const
{
    return "Will send mail";
}

std::string MailSendPage::title() const
{
    return "Mail Test";
}

bool MailSendPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}
