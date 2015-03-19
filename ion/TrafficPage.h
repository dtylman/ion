/*
 * File:   TrafficPage.h
 * Author: danny
 *
 * Created on March 12, 2015, 11:16 PM
 */

#ifndef TRAFFICPAGE_H
#define	TRAFFICPAGE_H

#include "PageRequestHandler.h"
#include <Poco/Data/RecordSet.h>

class TrafficPage : public PageRequestHandler
{
public:
    static const std::string Title;
    static const std::string Link;
    TrafficPage();
    virtual ~TrafficPage();
protected:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void renderScripts(std::ostream& output);
    virtual void renderPanelBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual void renderButtons(std::ostream& output);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
    bool _local = false;
    bool _all = false;
    std::string _group = "Domain";
};

#endif	/* TRAFFICPAGE_H */

