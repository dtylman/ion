/*
 * File:   MailConfigPage.cpp
 * Author: danny
 *
 * Created on February 16, 2015, 6:14 PM
 */

#include "MailConfigPage.h"
#include "WebMenu.h"
#include <Poco/Format.h>

const std::string MailConfigPage::Link("mailsetup.bin");
const std::string MailConfigPage::Title("Mail Settings");

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

}

std::string MailConfigPage::subtitle() const
{
    return "this is some text";
}

void MailConfigPage::renderButtons(std::ostream& output)
{
    output << "<input class='btn btn-success' type='submit' value='Save' >";
    WebMenu::renderHomeButton(output, "Close");
}

bool MailConfigPage::renderFormStart(std::ostream& output)
{
    output << Poco::format("<form method='POST' action='%s'>", Link);
    return true;

}
