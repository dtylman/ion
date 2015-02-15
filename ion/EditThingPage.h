/*
 * File:   EditThing2.h
 * Author: danny
 *
 * Created on February 13, 2015, 12:18 AM
 */

#ifndef EDITTHINGPAGE_H
#define	EDITTHINGPAGE_H

#include "PageRequestHandler.h"
#include <Poco/URI.h>
#include <list>

class EditThingPage : public PageRequestHandler
{
public:
    EditThingPage(const Poco::URI::QueryParameters& params);
    virtual ~EditThingPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderInput(std::ostream& output, const std::string& displayName, const std::string& name, const std::string& id);
    void renderTypeAheadScript(std::ostream& output, const std::string& name, const std::string& id, const std::string& value, const std::list<std::string>& list);
    std::string _mac;
    std::list<std::string> _types;
    std::list<std::string> _vendors;
    std::list<std::string> _os;
};

#endif	/* EDITTHING2_H */
