/*
 * File:   EventsRequestsHandler.h
 * Author: danny
 *
 * Created on February 11, 2015, 11:08 PM
 */

#ifndef EVENTSPAGE_H
#define	EVENTSPAGE_H

#include "PageRequestHandler.h"

class EventsPage : public PageRequestHandler
{
public:
    EventsPage();
    virtual ~EventsPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:

};

#endif	/* EVENTSREQUESTSHANDLER_H */

