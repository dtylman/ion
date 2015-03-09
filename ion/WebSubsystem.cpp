/*
 * File:   WebSubsystem.cpp
 * Author: danny
 *
 * Created on February 10, 2015, 8:39 AM
 */

#include "WebSubsystem.h"
#include "WebRequestHandlerFactory.h"
#include <Poco/Util/Application.h>

WebSubsystem::WebSubsystem() : _logger(Poco::Logger::get("WebSubsystem"))
{
}

WebSubsystem::~WebSubsystem()
{
}

void WebSubsystem::initialize(Poco::Util::Application& app)
{
	Poco::Net::SocketAddress address(app.config().getString("ion.web.address", "0.0.0.0:9980"));    
    Poco::Net::ServerSocket socket(address);
    _logger.notice("Starting server on %s", socket.address().toString());

    _server = new Poco::Net::HTTPServer(new WebRequestHandlerFactory(), socket, new Poco::Net::HTTPServerParams());
    // start the HTTPServer
    _server->start();

}

const char* WebSubsystem::name() const
{
    return "WebSubsystem";
}

void WebSubsystem::uninitialize()
{
    _server->stop();
    delete _server;
}
