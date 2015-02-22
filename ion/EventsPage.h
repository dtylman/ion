/*
 * File:   EventsRequestsHandler.h
 * Author: danny
 *
 * Created on February 11, 2015, 11:08 PM
 */

#ifndef EVENTSPAGE_H
#define	EVENTSPAGE_H

#include "PageRequestHandler.h"
#include <Poco/Data/RecordSet.h>

class EventsPage : public PageRequestHandler
{
public:
    static const std::string Title;
    static const std::string Link;
    EventsPage();
    virtual ~EventsPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
};

#endif	/* EVENTSREQUESTSHANDLER_H */

