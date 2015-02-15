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
#include "DataSubsystem.h"
#include <Poco/String.h>

using namespace Poco::Data::Keywords;

EditThingPage::EditThingPage(const Poco::URI::QueryParameters& params)
{
    for (auto param : params) {
        if (param.first == "mac") {
            _mac = param.second;
        }
    }
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

void EditThingPage::renderBody(std::ostream& output)
{
    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    //mac TEXT NOT NULL,type TEXT, name TEXT, vendor TEXT, os TEXT, desc TEXT
    std::string type, vendor, os, desc;
    session << "SELECT type, vendor,os,desc FROM thing WHERE mac=?", use(_mac), into(type), into(vendor), into(os), into(desc), now;
    output << Poco::format("<form method='POST' action='%s' class='form-inline' name='form-edit-thing' >", WebMenu::PAGE_SAVE_THING);
    output << "    <fieldset>\n";

    renderInput(output, "Type: ", "type", "txtType");
    output << "<br/>";
    renderInput(output, "Vendor: ", "vendor", "txtVendor");
    output << "<br/>";
    renderInput(output, "Operating System: ", "os", "txtOS");
    output << "<br/>";

    output << "<label class='label label-info'>Description</label><br/>";
    output << Poco::format("<textarea name='desc' class='input-xlarge' style='width: 80%'>%s</textarea>", desc);

    output << "</fieldset>";
    output << "<input class='btn btn-success' type='submit' value='Send!' >\n";
    output << "</form>\n";

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

    renderTypeAheadScript(output, "type", "txtType", type, _types);
    renderTypeAheadScript(output, "vendor", "txtVendor", vendor, _vendors);
    renderTypeAheadScript(output, "os", "txtOS", os, _os);

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

void EditThingPage::renderInput(std::ostream& output, const std::string& displayName, const std::string& name, const std::string& id)
{
    output << Poco::format("<label class='label label-info'>%s</label><br/>", displayName);
    output << Poco::format("<input class='typeahead form-control' name='%s' type='text' placeholder='Value..' id='%s' />", name, id);
}

void EditThingPage::renderTypeAheadScript(std::ostream& output, const std::string& name, const std::string& id, const std::string& value, const std::list<std::string>& list)
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
    output << Poco::format("$('#%s').val('%s');", id, value);
}