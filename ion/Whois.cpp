/*
 * File:   Whois.cpp
 * Author: danny
 *
 * Created on March 16, 2015, 9:40 PM
 */

#include "Whois.h"
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StringTokenizer.h>
#include <Poco/StreamCopier.h>
#include <Poco/String.h>

Whois::Whois() : _logger(Poco::Logger::get("Whois"))
{
}

Whois::~Whois()
{
}

void Whois::query(const std::string& hostName)
{
    std::string server = "whois.iana.org";
    while (!server.empty()) {
        server = query(hostName, server);
        _record << std::endl;
    }
}

std::stringstream& Whois::record()
{
    return _record;
}

std::string Whois::query(const std::string& host, const std::string& server)
{
    std::string nextServer;
    Poco::Net::StreamSocket socket(Poco::Net::SocketAddress(server, 43));
    _logger.debug("Connecting to %s:43, query: '%s'", server, host);
    Poco::Net::SocketStream stream(socket);
    stream << host << std::endl;
    while (stream.good()) {
        std::string line;
        std::getline(stream, line);
        _logger.debug(line);
        Poco::trimInPlace(line);
        if (!line.empty()) {
            if (isalpha(line[0])) {
                _record << line << std::endl;
                Poco::StringTokenizer tokens(line, ":", Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY);
                if (tokens.count() > 1) {
                    if (Poco::toLower(tokens[0]) == "whois") {
                        nextServer = tokens[1];
                    }
                }
            }
        }
    }
    return nextServer;
}
