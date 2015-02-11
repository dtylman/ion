/*
 * File:   PageRequestHandler.cpp
 * Author: danny
 *
 * Created on February 10, 2015, 9:17 AM
 */

#include "FileRequestHandler.h"
#include <Poco/FileStream.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/String.h>

FileRequestHandler::FileRequestHandler() : _logger(Poco::Logger::get("PageRequestHandler"))
{
}

FileRequestHandler::~FileRequestHandler()
{
}

void FileRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    setContentType(request, response);
    std::ostream& ostr = response.send();
    try {
        Poco::FileInputStream fis("/home/danny/src/ion/web" + request.getURI());
        Poco::StreamCopier::copyStream(fis, ostr);
        response.setStatus(Poco::Net::HTTPResponse::HTTPStatus::HTTP_OK);
    }
    catch (Poco::Exception& ex) {
        response.setStatus(Poco::Net::HTTPResponse::HTTPStatus::HTTP_NOT_FOUND);
        ostr << ex.displayText();
        _logger.error("Request failed: %s: %s", request.getURI(), ex.displayText());
    }

}

void FileRequestHandler::setContentType(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    Poco::Path path(request.getURI());
    std::string extension = Poco::toLower(path.getExtension());
    if (extension == "css") {
        response.setContentType("text/css");
    }
    else if (extension == "js") {
        response.setContentType("application/javascript");
    }
    else {
        response.setContentType("text/html");
    }
}
