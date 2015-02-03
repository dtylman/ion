/*
 * File:   TableOSDHCP.h
 * Author: danny
 *
 * Created on February 3, 2015, 9:38 AM
 */

#ifndef TABLEOSDHCP_H
#define	TABLEOSDHCP_H

#include <Poco/Data/Session.h>

class TableOSDHCP
{
public:
    TableOSDHCP(Poco::Data::Session& session);
    virtual ~TableOSDHCP();
    void create();
private:
    void insert(const std::string vendor, const std::string& hostname, const std::string& os);
    Poco::Data::Session& _session;
};

#endif	/* TABLEOSDHCP_H */

