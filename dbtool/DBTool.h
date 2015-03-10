/*
 * File:   DBTool.h
 * Author: danny
 *
 * Created on February 3, 2015, 8:56 AM
 */

#ifndef DBTOOL_H
#define	DBTOOL_H

#include <Poco/Util/Application.h>

class DBTool : public Poco::Util::Application
{
public:
    DBTool();

    virtual ~DBTool();
protected:
    virtual int main(const std::vector<std::string>& args);
    void initialize(Poco::Util::Application& self);
    virtual void defineOptions(Poco::Util::OptionSet& options);
    void handleHelp(const std::string& name, const std::string& value);
private:

};

#endif	/* DBTOOL_H */

