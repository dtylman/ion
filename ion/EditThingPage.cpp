/*
 * File:   EditThing2.cpp
 * Author: danny
 *
 * Created on February 13, 2015, 12:18 AM
 */

#include "EditThingPage.h"
#include "WebMenu.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Format.h>
#include <Poco/Util/Application.h>
#include <Poco/Data/Session.h>
#include <Poco/URI.h>
#include "DataSubsystem.h"
#include <Poco/String.h>

using namespace Poco::Data::Keywords;

EditThingPage::EditThingPage()
{
    _types.push_back("Camera");
    _types.push_back("Phone");
    _types.push_back("Router");
    _types.push_back("Computer");
    _vendors.push_back("Microsoft");
    _vendors.push_back("Google");
    _vendors.push_back("Samsung");
    _os.push_back("Linux");
    _os.push_back("Windows");
    _os.push_back("Android");

}

EditThingPage::~EditThingPage()
{
}

void EditThingPage::renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{

    _mac = getQueryParam("mac", request);

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    std::string type, vendor, os, desc;
    session << "SELECT type, vendor,os,desc FROM thing WHERE mac=?", use(_mac), into(type), into(vendor), into(os), into(desc), now;

    output << "<div class='panel panel-default'>";

    output << "<div class='panel-heading'>";
    output << "<h3 class='panel-title'>This will explain you stuff:</h3>";
    output << "</div>";
    output << "<div class='panel-body'>";
    output << Poco::format("<form method='POST' action='%s' class='form-inline' name='form-edit-thing' >", WebMenu::PAGE_SAVE_THING);
    output << "    <fieldset>\n";

    output << Poco::format("<input type='hidden' name='mac' value='%s'/>", _mac);
    renderInput(output, "Type: ", "type", "txtType", type);
    output << "<br/>";
    renderInput(output, "Vendor: ", "vendor", "txtVendor", vendor);
    output << "<br/>";
    renderInput(output, "Operating System: ", "os", "txtOS", os);
    output << "<br/>";

    output << "<label class='label label-info'>Description: </label><br/>";
    output << Poco::format("<textarea name='desc' class='input-xlarge' style='width: 80%'>%s</textarea>", desc);

    output << "</fieldset>";
    output << "<input class='btn btn-success' type='submit' value='Save' >\n";
    output << "</form>\n";
    output << "</div>\n";
    output << "<script>";
    output << "var substringMatcher = function (strs) {";
    output << "return function (q, cb) {";
    output << "var matches, substrRegex;";
    output << "matches = [];";
    output << "substrRegex = new RegExp(q, 'i');";
    output << "$.each(strs, function (i, str) {";
    output << "if (substrRegex.test(str)) {";
    output << "matches.push({value: str});";
    output << "}";
    output << "});";
    output << "cb(matches);";
    output << "};";
    output << "};";

    renderTypeAheadScript(output, "type", "txtType", _types);
    renderTypeAheadScript(output, "vendor", "txtVendor", _vendors);
    renderTypeAheadScript(output, "os", "txtOS", _os);

    output << "</script>";
}

std::string EditThingPage::title() const
{
    return Poco::format("Edit %s", _mac);
}

bool EditThingPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    return false;
}

void EditThingPage::renderInput(std::ostream& output, const std::string& displayName, const std::string& name, const std::string& id, const std::string& value)
{
    output << "<div class='row'><div class='col-lg-6'>";
    output << Poco::format("<label class='label label-info'>%s</label><br/>", displayName);
    output << Poco::format("<input class='typeahead form-control' name='%s' type='text' placeholder='Value..' id='%s' value='%s'/>", name, id, value);
    output << "</div></div>";
}

void EditThingPage::renderTypeAheadScript(std::ostream& output, const std::string& name, const std::string& id, const std::list<std::string>& list)
{
    std::string listName = name + "_list";
    output << Poco::format("var %s = [", listName);
    std::list<std::string>::const_iterator iter = list.begin();
    while (iter != list.end()) {
        output << "'" << *iter << "'";
        ++iter;
        if (iter != list.end()) {
            output << ",";
        }
    }
    output << "];";
    output << Poco::format("$('#%s').typeahead({", id);
    output << Poco::format("hint: true, highlight : true,minLength : 0 }, {name:'%s',displayKey : 'value', source : substringMatcher(%s) });",
                           name, listName);
}
