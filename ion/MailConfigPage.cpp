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

void MailConfigPage::renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    output << "<form class='form-group'>";
    output << "<div class='panel panel-default'>";
    output << "<div class='panel-heading'>";
    output << "<h3 class='panel-title'>This should explain what this page is for</h3>";
    output << "</div>";
    output << "<div class='panel-body'>";
    output << "</div>";
    output << "</div>";
    output << "<input class='btn btn-success' type='submit' value='Save' >";
    WebMenu::renderHomeButton(output, "Close");
    output << "</div>";

    output << "</form>";
}
