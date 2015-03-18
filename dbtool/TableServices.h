/*
 * File:   TableServices.h
 * Author: danny
 *
 * Created on March 18, 2015, 3:06 PM
 */

#ifndef TABLESERVICES_H
#define	TABLESERVICES_H

#include <Poco/Data/Session.h>
#include <Poco/Logger.h>

class TableServices
{
public:
    TableServices(Poco::Data::Session& session);
    virtual ~TableServices();
    void create();
private:
    void populate();
    Poco::Data::Session& _session;
    Poco::Logger& _logger;
};

#endif	/* TABLESERVICES_H */

