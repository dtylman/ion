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
    static const std::string Link;
    static const std::string ParamThingID;
    EditThingPage();
    virtual ~EditThingPage();
protected:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual bool renderFormStart(std::ostream& output);
    virtual void renderButtons(std::ostream& output);
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    virtual void renderScripts(std::ostream& output);
private:
    void renderInput(std::ostream& output, const std::string& displayName, const std::string& name, const std::string& id, const std::string& value);
    void renderTypeAheadScript(std::ostream& output, const std::string& name, const std::string& id, const std::list<std::string>& list);
    ThingData _thing;
    std::list<std::string> _types;
    std::list<std::string> _vendors;
    std::list<std::string> _os;
};

#endif	/* EDITTHING2_H */

