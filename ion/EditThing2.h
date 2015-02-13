/*
 * File:   EditThing2.h
 * Author: danny
 *
 * Created on February 13, 2015, 12:18 AM
 */

#ifndef EDITTHING2_H
#define	EDITTHING2_H

#include "PageRequestHandler.h"
#include <Poco/URI.h>

class EditThing2 : public PageRequestHandler
{
public:
    EditThing2(const Poco::URI::QueryParameters& params);
    virtual ~EditThing2();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    std::string _mac;
};

#endif	/* EDITTHING2_H */

