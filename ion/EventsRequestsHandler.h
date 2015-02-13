/*
 * File:   EventsRequestsHandler.h
 * Author: danny
 *
 * Created on February 11, 2015, 11:08 PM
 */

#ifndef EVENTSREQUESTSHANDLER_H
#define	EVENTSREQUESTSHANDLER_H

#include "PageRequestHandler.h"

class EventsRequestsHandler : public PageRequestHandler
{
public:
    EventsRequestsHandler();
    virtual ~EventsRequestsHandler();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:

};

#endif	/* EVENTSREQUESTSHANDLER_H */

