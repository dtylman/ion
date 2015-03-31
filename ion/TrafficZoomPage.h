/*
 * File:   TrafficZoomPage.h
 * Author: danny
 *
 * Created on March 18, 2015, 2:41 PM
 */

#ifndef TRAFFICZOOMPAGE_H
#define	TRAFFICZOOMPAGE_H

#include "PageRequestHandler.h"
#include <Poco/Data/RecordSet.h>
#include <string>

class TrafficZoomPage : public PageRequestHandler
{
public:
    static const std::string Title;
    static const std::string Link;
    TrafficZoomPage();
    virtual ~TrafficZoomPage();
protected:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void renderScripts(std::ostream& output);
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual void renderButtons(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
private:
    std::string _field;
    std::string _value;
};

#endif	/* TRAFFICZOOMPAGE_H */

