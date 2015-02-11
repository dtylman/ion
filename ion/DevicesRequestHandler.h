/*
 * File:   DevicesRequestHandler.h
 * Author: danny
 *
 * Created on February 11, 2015, 10:30 PM
 */

#ifndef DEVICESREQUESTHANDLER_H
#define	DEVICESREQUESTHANDLER_H

#include "PageRequestHandler.h"
#include <Poco/Data/RecordSet.h>

class DevicesRequestHandler : public PageRequestHandler
{
public:
    DevicesRequestHandler();
    virtual ~DevicesRequestHandler();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output);
private:
    void renderTable(std::ostream& output);
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
};

#endif	/* DEVICESREQUESTHANDLER_H */

