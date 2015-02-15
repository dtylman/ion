/*
 * File:   DevicesRequestHandler.h
 * Author: danny
 *
 * Created on February 11, 2015, 10:30 PM
 */

#ifndef THINGSPAGE_H
#define	THINGSPAGE_H

#include "PageRequestHandler.h"
#include <Poco/Data/RecordSet.h>

class ThingsPage : public PageRequestHandler
{
public:
    ThingsPage();
    virtual ~ThingsPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderTable(std::ostream& output);
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
    void renderScripts(std::ostream& output);
};

#endif	/* DEVICESREQUESTHANDLER_H */

