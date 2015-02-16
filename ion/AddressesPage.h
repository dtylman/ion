/*
 * File:   AddressesPage.h
 * Author: danny
 *
 * Created on February 16, 2015, 12:26 PM
 */

#ifndef ADDRESSESPAGE_H
#define	ADDRESSESPAGE_H

#include "PageRequestHandler.h"
#include <Poco/Data/RecordSet.h>

class AddressesPage : public PageRequestHandler
{
public:
    AddressesPage();
    virtual ~AddressesPage();
protected:
    virtual std::string title() const;
    virtual void renderBody(std::ostream& output, Poco::Net::HTTPServerRequest& request);
    virtual bool handleForm(Poco::Net::HTMLForm& form, Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    void renderTable(std::ostream& output);
    void renderRow(std::ostream& output, Poco::Data::RecordSet& rs);
    void renderScripts(std::ostream& output);
};

#endif	/* ADDRESSESPAGE_H */

