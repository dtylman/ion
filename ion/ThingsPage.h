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
    virtual std::string subtitle() const;
    virtual void renderButtons(std::ostream& output);

    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    virtual void renderScripts(std::ostream& output);
private:
    void handleParams(Poco::Net::HTTPServerRequest& request);
    void handleToggleAuth(Poco::Net::HTTPServerRequest& request);
    void handleAuthAll(bool auth);
    void handleDelete(Poco::Net::HTTPServerRequest& request);
    void renderTable(std::ostream& output);
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
    void renderIcon(std::ostream& output, const std::string& type);
};

#endif	/* DEVICESREQUESTHANDLER_H */

