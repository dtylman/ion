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
#include "IONDataObject.h"
#include "ThingsPage.h"
#include <Poco/String.h>

const std::string EditThingPage::Link("editthing.bin");
const std::string EditThingPage::ParamThingID("id");

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

std::string EditThingPage::title() const
{
    return Poco::format("Editing %s", _thing.toString());
}

std::string EditThingPage::subtitle() const
{
    return "This will explain you stuff";
}

void EditThingPage::renderButtons(std::ostream& output)
{
    output << "<input class='btn btn-success' type='submit' value='Save' >";
    output << Poco::format(" <a href='%s' class='btn btn-primary'>Cancel</a>", ThingsPage::Link);
}

bool EditThingPage::renderFormStart(std::ostream& output)
{
    output << Poco::format("<form method='POST' action='%s' class='form-inline'>", Link);
    return true;
}

void EditThingPage::renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request)
{
    Poco::UUID id(getQueryParam("id", request));
    IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    if (!ion.getThing(Poco::UUID(id), _thing)) {
        throw Poco::NotFoundException("Thing not found");
    }
    output << Poco::format("<input type='hidden' name='id' value='%s'/>", _thing.uuid().toString());
    renderInput(output, "Type: ", "type", "txtType", _thing.type());
    renderInput(output, "Vendor: ", "vendor", "txtVendor", _thing.vendor());
    renderInput(output, "Operating System: ", "os", "txtOS", _thing.os());
    output << "<div class='form-group col-xs-2'><label class='form-control'>Description:</label>";
    output << Poco::format("<textarea name='desc' class='form-control' style='height:33px;width:400px'>%s</textarea>", _thing.desc());
    output << "</div>";
}

void EditThingPage::renderScripts(std::ostream& output)
{
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

bool EditThingPage::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    if (!form.has("type")) {
        return false;
    }
    IONDataObject ion(Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession());
    std::string id = form.get("id");
    ThingData thing;
    if (!ion.getThing(Poco::UUID(id), thing)) {
        throw Poco::NotFoundException("Thing not found!");
    }
    thing.setType(form.get("type"));
    thing.setVendor(form.get("vendor"));
    thing.setOS(form.get("os"));
    thing.setDesc(form.get("desc"));
    ion.setThing(thing, true);
    response.redirect(ThingsPage::Link);
    return true;
}

void EditThingPage::renderInput(std::ostream& output, const std::string& displayName, const std::string& name, const std::string& id, const std::string& value)
{
    output << "<div class='form-group col-xs-2'>";
    output << Poco::format("<label class='form-control'>%s</label>", displayName);
    output << Poco::format("<input class='typeahead form-control' name='%s' type='text' placeholder='Value..' id='%s' value='%s'/>", name, id, value);
    output << "</div>";
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
