/*
 * File:   MailConfigPage.cpp
 * Author: danny
 *
 * Created on February 16, 2015, 6:14 PM
 */

#include "MailConfigPage.h"
#include "WebMenu.h"
#include "Main.h"
#include "WebForm.h"
#include "MailSendPage.h"
#include <Poco/Format.h>
#include <Poco/Util/Application.h>

const std::string MailConfigPage::Link("mailsetup.bin");
const std::string MailConfigPage::Title("Email Alert Settings");

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
    updateSettings(form, "host", "ion.mail.host");
    updateSettings(form, "port", "ion.mail.port");
    updateSettings(form, "user", "ion.mail.user");
    updateSettings(form, "password", "ion.mail.password");
    updateSettings(form, "loginmethod", "ion.mail.loginmethod");
    updateSettings(form, "from", "ion.mail.sender");
    updateSettings(form, "to", "ion.mail.recipient");
    updateSettings(form, "subject", "ion.mail.subject");
    if (form.has("ssl")) {
        Poco::Util::Application::instance().config().setBool("ion.mail.ssl", true);
    }
    else {
        Poco::Util::Application::instance().config().setBool("ion.mail.ssl", false);
    }
    Main& main = dynamic_cast<Main&> (Poco::Util::Application::instance());
    main.saveConfig();
    return false;
}

bool MailConfigPage::updateSettings(Poco::Net::HTMLForm& form, const std::string& name, const std::string& confKey)
{
    if (form.has(name)) {
        Poco::Util::Application::instance().config().setString(confKey, form.get(name));
        return true;
    }
    return false;
}

void MailConfigPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    Poco::Util::LayeredConfiguration& config = Poco::Util::Application::instance().config();
    WebForm wf(output);
    wf.startRow();
    wf.renderInput("host", "SMTP Server", "server name or ip", config.getString("ion.mail.host"));
    wf.renderInput("port", "SMTP Port", "port number...", config.getString("ion.mail.port"), true, "number", 1);
    wf.renderChkbox("ssl", "Use SSL", config.getBool("ion.mail.ssl"));
    wf.endRow();

    wf.startRow();
    wf.renderInput("user", "SMTP Username", "user name if applicable", config.getString("ion.mail.user"));
    wf.renderInput("password", "SMTP Password", "password if applicable", config.getString("ion.mail.password"), true, "password");
    WebForm::Options options;
    options.push_back("AUTH_NONE");
    options.push_back("AUTH_CRAM_MD5");
    options.push_back("AUTH_CRAM_SHA1");
    options.push_back("AUTH_LOGIN");
    options.push_back("AUTH_PLAIN");
    wf.renderSelect("loginmethod", "Login Method", config.getString("ion.mail.loginmethod"), options);
    wf.endRow();

    wf.startRow();
    wf.renderInput("from", "Sender address", "your e-mail address", config.getString("ion.mail.sender"), true, "email", 3);
    wf.renderInput("to", "Recipient address", "e-mail address", config.getString("ion.mail.recipient"), true, "email", 3);
    wf.endRow();

    wf.startRow();
    wf.renderInput("subject", "Subject", "Message subject", config.getString("ion.mail.subject"), true, "text", 5);
    wf.endRow();

}

std::string MailConfigPage::subtitle() const
{
    return "Configuration settings for email alerts:";
}

void MailConfigPage::renderButtons(std::ostream& output)
{
    output << "<input class='btn btn-success' type='submit' value='Save'> ";
    output << "<div class='btn btn-primary' onclick='configuregmail()'>I am using GMAIL</div> ";
    WebMenu::renderLinkButton(output, "Test", MailSendPage::Link);
    WebMenu::renderHomeButton(output, "Close");
}

bool MailConfigPage::renderFormStart(std::ostream& output)
{

    output << Poco::format("<form method='POST' action='%s'>", Link);
    return true;
}

void MailConfigPage::renderScripts(std::ostream& output)
{
    output << "<script>";
    output << "function configuregmail()";
    output << "{";
    output << "$('#id_host').val('smtp.gmail.com');";
    output << "$('#id_port').val('465');";
    output << "$('#id_ssl').prop('checked', true);";
    output << "$('#id_loginmethod').val('AUTH_LOGIN');";
    output << "$('#id_user').val('@gmail.com');";
    output << "$('#id_from').val('@gmail.com');";
    output << "$('#id_user').focus();";
    output << "}";
    output << "</script>";
}
