/*
 * File:   TableOUI.h
 * Author: danny
 *
 * Created on February 3, 2015, 9:03 AM
 */

#ifndef TABLEOUI_H
#define	TABLEOUI_H

#include <Poco/Data/Session.h>
#include <Poco/Logger.h>

class TableOUI
{
public:
    TableOUI(Poco::Data::Session& session);
    virtual ~TableOUI();

    void create(const std::string& ouiFile);
private:
    void populate(const std::string& ouiFile);
    void insert(const std::string& prefix, const std::string& vendor);
    std::string camel(const std::string& text);
    Poco::Data::Session& _session;
    Poco::Logger& _logger;
};

#endif	/* TABLEOUI_H */

