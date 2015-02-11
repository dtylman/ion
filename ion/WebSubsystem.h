/*
 * File:   WebSubsystem.h
 * Author: danny
 *
 * Created on February 10, 2015, 8:39 AM
 */

#ifndef WEBSUBSYSTEM_H
#define	WEBSUBSYSTEM_H

#include <Poco/Util/Subsystem.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Logger.h>

class WebSubsystem : public Poco::Util::Subsystem
{
public:
    WebSubsystem();
protected:
    virtual void initialize(Poco::Util::Application& app);
    virtual const char* name() const;
    virtual void uninitialize();

    virtual ~WebSubsystem();
private:
    Poco::Net::HTTPServer* _server;
    Poco::Logger& _logger;
};

#endif	/* WEBSUBSYSTEM_H */

