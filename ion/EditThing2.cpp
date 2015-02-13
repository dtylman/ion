/*
 * File:   EditThing2.cpp
 * Author: danny
 *
 * Created on February 13, 2015, 12:18 AM
 */

#include "EditThing2.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Format.h>

EditThing2::EditThing2(const Poco::URI::QueryParameters& params)
{
    for (auto param : params) {
        if (param.first == "mac") {
            _mac = param.second;
        }
    }
}

EditThing2::~EditThing2()
{
}

void EditThing2::renderBody(std::ostream& output)
{
    output << "<form method='POST' action='/lala' class='form-inline' name='form-edit-thing' >\n";
    output << "    <fieldset>\n";
    output << "        <label class='label label-info'>Type: </label><br/>\n";
    output << "        <select class='combobox form-control' name='type' >\n";
    output << "            <option value=''></option>\n";
    output << "            <option value='Type'>Type</option>\n";
    output << "            <option value='Camera'>Camera</option>\n";
    output << "        </select>\n";
    output << "        <br/>\n";
    output << "        <label class='label label-info'>Vendor: </label><br/>\n";
    output << "        <select class='combobox form-control' name='vendor'>\n";
    output << "            <option value='Microsoft'>Microsoft</option>\n";
    output << "            <option value='Google'>Google</option>\n";
    output << "        </select>\n";
    output << "        <br/>\n";
    output << "        <label class='label label-info'>Operating System: </label><br/>\n";
    output << "        <select class='combobox form-control' name='os'>\n";
    output << "            <option value='Windows'>Windows</option>\n";
    output << "            <option value='Android'>Android</option>\n";
    output << "        </select>\n";
    output << "        <br/>\n";
    output << "        <label class='label label-info'>Description</label><br/>\n";
    output << "        <textarea name='desc' class='input-xlarge' style='width: 80%' id='txt-modush'></textarea>\n";
    output << "    </fieldset>\n";
    output << "<input class='btn btn-success' type='submit' value='Send!' >\n";
    output << "</form>\n";
}

std::string EditThing2::title() const
{
    return Poco::format("Edit %s", _mac);

}

bool EditThing2::handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    //    std::ostream& ostr = response.send();
    //    ostr << "<h2>Form</h2><p>\n";
    //
    //    Poco::Net::NameValueCollection::ConstIterator it = form.begin();
    //    Poco::Net::NameValueCollection::ConstIterator end = form.end();
    //    for (; it != end; ++it) {
    //        ostr << it->first << ": " << it->second << "<br>\n";
    //    }
    //    ostr << "</p>";
    return false;
    //    response.redirect("devices.bin");
    //    return true;
}
