/*
 * File:   WhoisPage.cpp
 * Author: danny
 *
 * Created on March 16, 2015, 9:16 PM
 */

#include "WhoisPage.h"
#include "Whois.h"
#include "WebMenu.h"
#include <Poco/String.h>

const std::string WhoisPage::Title("Whois");
const std::string WhoisPage::Link("whois.bin");

WhoisPage::WhoisPage()
{
}

WhoisPage::~WhoisPage()
{
}

std::string WhoisPage::title() const
{
    return Title;
}

std::string WhoisPage::subtitle() const
{
    return "whois";
}

void WhoisPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    std::string query;
    if (getQueryParam("query", query, request)) {
        Whois whois;
        whois.query(query);
        std::stringstream& record = whois.record();
        bool code = true;
        output << "<code>";
        while (record.good()) {
            std::string line;
            std::getline(record, line);

            Poco::trimInPlace(line);
            if (!line.empty()) {
                output << line;
            }
            output << "</br>";
        }
        if (code) {
            output << "</code>";
        }
    }
}

bool WhoisPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void WhoisPage::renderButtons(std::ostream& output)
{
    WebMenu::renderHomeButton(output, "Close");
}
