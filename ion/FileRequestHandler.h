/*
 * File:   PageRequestHandler.h
 * Author: danny
 *
 * Created on February 10, 2015, 9:17 AM
 */

#ifndef FILEREQUESTHANDLER_H
#define	FILEREQUESTHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Logger.h>

class FileRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    FileRequestHandler();
    virtual ~FileRequestHandler();

    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

private:
    void setContentType(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    Poco::Logger& _logger;
};

#endif	/* PAGEREQUESTHANDLER_H */

