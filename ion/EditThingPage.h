/*
 * File:   EditThing2.h
 * Author: danny
 *
 * Created on February 13, 2015, 12:18 AM
 */

#ifndef EDITTHINGPAGE_H
#define	EDITTHINGPAGE_H

#include "PageRequestHandler.h"
#include "ThingData.h"
#include <list>

class EditThingPage : public PageRequestHandler
{
public:
    EditThingPage();
    virtual ~EditThingPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderInput(std::ostream& output, const std::string& displayName, const std::string& name, const std::string& id, const std::string& value);
    void renderTypeAheadScript(std::ostream& output, const std::string& name, const std::string& id, const std::list<std::string>& list);
    ThingData _thing;
    std::list<std::string> _types;
    std::list<std::string> _vendors;
    std::list<std::string> _os;
};

#endif	/* EDITTHING2_H */

