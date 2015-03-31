/*
 * File:   WebForm.cpp
 * Author: danny
 *
 * Created on February 24, 2015, 11:04 AM
 */

#include "WebForm.h"
#include <Poco/Format.h>

WebForm::WebForm(std::ostream& output) : _output(output)
{

}

WebForm::~WebForm()
{
}

void WebForm::startRow()
{
    _output << "<div class='row'>";
}

void WebForm::endRow()
{
    _output << "</div>";
}

void WebForm::renderChkbox(const std::string& name, const std::string& text, bool value, int cols)
{
    std::string id = Poco::format("id_%s", name);
    _output << Poco::format("<div class='form-group col-xs-%d'>", cols);
    _output << Poco::format("<label for='%s'>%s</label>", id, text);
    std::string checked = "";
    if (value) {
        checked = "checked";
    }
    _output << Poco::format("<input type='checkbox' class='form-control' id='%s' name='%s' %s>", id, name, checked);
    _output << "</div>";
}

void WebForm::renderInput(const std::string& name, const std::string& text, const std::string& placeHolder, const std::string& value, bool required, const std::string& type, int cols)
{
    std::string id = Poco::format("id_%s", name);
    _output << Poco::format("<div class='form-group col-xs-%d'>", cols);
    _output << Poco::format("<label for='%s'>%s</label>", id, text);
    std::string req;
    if (required) {
        req = "required";
    }
    _output << Poco::format("<input type='%s' %s class='form-control' id='%s' placeholder='%s' name='%s' value='%s'>", type, req, id, placeHolder, name, value);
    _output << "</div>";
}

void WebForm::renderSelect(const std::string& name, const std::string& text, const std::string& value, const Options& options, int cols)
{
    std::string id = Poco::format("id_%s", name);
    _output << Poco::format("<div class='form-group col-xs-%d'>", cols);
    _output << Poco::format("<label for='%s'>%s</label>", id, text);
    _output << Poco::format("<select class='form-control' id='%s' name='%s'>", id, name);
    for (auto option : options) {
        if (value == option) {
            _output << Poco::format("<option selected>%s</option>", option);
        }
        else {
            _output << Poco::format("<option>%s</option>", option);
        }
    }
    _output << "</select >";
    _output << "</div>";
}
