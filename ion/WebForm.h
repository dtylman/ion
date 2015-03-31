/*
 * File:   WebForm.h
 * Author: danny
 *
 * Created on February 24, 2015, 11:04 AM
 */

#ifndef WEBFORM_H
#define	WEBFORM_H

#include <ostream>
#include <string>
#include <list>

class WebForm
{
public:
    WebForm(std::ostream& output);
    virtual ~WebForm();

    void startRow();
    void endRow();
    void renderInput(const std::string& name, const std::string& text, const std::string& placeHolder, const
                     std::string& value, bool required = true, const std::string& type = "text", int cols = 2);
    void renderChkbox(const std::string& name, const std::string& text, bool value, int cols = 1);
    typedef std::list<std::string> Options;
    void renderSelect(const std::string& name, const std::string& text, const std::string& value, const Options& options, int cols = 2);
private:
    std::ostream& _output;
};

#endif	/* WEBFORM_H */

