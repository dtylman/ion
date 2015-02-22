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
    static const std::string Title;
    static const std::string Link;
    static const std::string ParamThingID;
    static const std::string ParamAction;
    static const std::string ActionAuthAll;
    static const std::string ActionUnAuthAll;
    static const std::string ActionToggleAuth;
    static const std::string ActionDelete;
    ThingsPage();
    virtual ~ThingsPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void handleToggleAuth(Poco::Net::HTTPServerRequest& request);
    void handleAuthAll(bool auth);
    void handleDelete(Poco::Net::HTTPServerRequest& request);
    void renderTable(std::ostream& output);
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
    void renderScripts(std::ostream& output);
};

#endif	/* DEVICESREQUESTHANDLER_H */

