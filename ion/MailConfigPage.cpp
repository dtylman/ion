/*
 * File:   MailConfigPage.cpp
 * Author: danny
 *
 * Created on February 16, 2015, 6:14 PM
 */

#include "MailConfigPage.h"
#include "WebMenu.h"
#include <Poco/Format.h>
#include <Poco/Util/Application.h>

const std::string MailConfigPage::Link("mailsetup.bin");
const std::string MailConfigPage::Title("Mail Settings");
const std::string MailConfigPage::ParamAction("action");
const std::string MailConfigPage::GMail("gmail");

MailConfigPage::MailConfigPage()
{
}

MailConfigPage::~MailConfigPage()
{
}

std::string MailConfigPage::title() const
{
    return Title;
}

bool MailConfigPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void MailConfigPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    if (getQueryParam(ParamAction, request) == GMail) {
        configureGMail();
    }
    output << "<div class='row'>";
    renderInput(output, "host", "SMTP Server", "server name or ip", "ion.mail.host");
    renderInput(output, "port", "SMTP Port", "port number...", "ion.mail.port", "text", 1);
    renderChkbox(output, "ssl", "Use SSL", "ion.mail.ssl");
    output << "</div>";

    output << "<div class='row'>";
    renderInput(output, "user", "SMTP Username", "user name if applicable", "ion.mail.user");
    renderInput(output, "password", "SMTP Password", "password if applicable", "ion.mail.password", "password");
    renderSelect(output, "loginmethod", "Login Method", "ion.mail.loginmethod");
    output << "</div>";

    output << "<div class='row'>";
    renderInput(output, "from", "Sender address", "your e-mail address", "ion.mail.sender", "email", 3);
    renderInput(output, "to", "Recipient address", "e-mail address", "ion.mail.recipient", "email", 3);
    output << "</div>";


    output << "<div class='row'>";
    renderInput(output, "subject", "Subject", "Message subject", "ion.mail.subject", "text", 5);
    output << "</div>";

}

void MailConfigPage::renderInput(std::ostream& output, const std::string& name, const std::string& text, const std::string& placeHolder, const std::string& configKey, const std::string& type, int cols)
{
    std::string id = Poco::format("id_%s", name);
    output << Poco::format("<div class='form-group col-xs-%d'>", cols);
    output << Poco::format("<label for='%s'>%s</label>", id, text);
    std::string value = Poco::Util::Application::instance().config().getString(configKey);
    output << Poco::format("<input type='%s' class='form-control' id='%s' placeholder='%s' name='%s' value='%s'>", type, id, placeHolder, name, value);
    output << "</div>";
}

void MailConfigPage::renderChkbox(std::ostream& output, const std::string& name, const std::string& text, const std::string& configKey, int cols)
{
    std::string id = Poco::format("id_%s", name);
    output << Poco::format("<div class='form-group col-xs-%d'>", cols);
    output << Poco::format("<label for='%s'>%s</label>", id, text);
    std::string checked = "";
    if (Poco::Util::Application::instance().config().getBool(configKey)) {
        checked = "checked";
    }
    output << Poco::format("<input type='checkbox' class='form-control' id='%s' name='%s' %s>", id, name, checked);
    output << "</div>";
}

std::string MailConfigPage::subtitle() const
{

    return "this is some text";
}

void MailConfigPage::renderButtons(std::ostream& output)
{
    output << "<input class='btn btn-success' type='submit' value='Save'> ";
    output << Poco::format("<a href='%s?%s=%s' class='btn btn-primary'>I am using GMAIL</a> ", MailConfigPage::Link, MailConfigPage::ParamAction, MailConfigPage::GMail);
    output << "<input class='btn btn-primary' type='submit' value='Test'> ";
    WebMenu::renderHomeButton(output, "Close");
}

bool MailConfigPage::renderFormStart(std::ostream& output)
{
    output << Poco::format("<form method='POST' action='%s'>", Link);
    return true;

}

void MailConfigPage::renderSelect(std::ostream& output, const std::string& name, const std::string& text, const std::string& configKey)
{
    std::string id = Poco::format("id_%s", name);
    output << "<div class='form-group col-xs-2'>";
    output << Poco::format("<label for='%s'>%s</label>", id, text);
    std::string value = Poco::Util::Application::instance().config().getString(configKey);
    output << Poco::format("<select class='form-control' id='%s' name='%s'>", id, name);
    renderOption(output, value, "AUTH_NONE");
    renderOption(output, value, "AUTH_CRAM_MD5");
    renderOption(output, value, "AUTH_CRAM_SHA1");
    renderOption(output, value, "AUTH_LOGIN");
    renderOption(output, value, "AUTH_PLAIN");
    output << "</select >";
    output << "</div>";
}

void MailConfigPage::renderOption(std::ostream& output, const std::string& value, const std::string& option)
{
    if (value == option) {
        output << Poco::format("<option selected>%s</option>", option);
    }
    else {
        output << Poco::format("<option>%s</option>", option);
    }

}

void MailConfigPage::configureGMail()
{

}
