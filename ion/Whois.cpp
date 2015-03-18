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
    Poco::StringTokenizer tokens(hostName, ".", Poco::StringTokenizer::TOK_TRIM);
    std::string registrar = Poco::toLower(tokens[tokens.count() - 1]);
    std::string server = getServer(registrar);
    _logger.debug("Server for %s = %s", hostName, server);
    Poco::Net::StreamSocket socket(Poco::Net::SocketAddress(server, 43));
    Poco::Net::SocketStream stream(socket);
    stream << hostName << std::endl;
    Poco::StreamCopier::copyStream(stream, _record);
    _logger.debug(_record.str());
}

std::string Whois::getServer(const std::string& domain)
{
    Poco::Net::StreamSocket socket(Poco::Net::SocketAddress("whois.iana.org", 43));
    _logger.debug("Connecting to whois.iana.org:43, query: '%s'", domain);
    Poco::Net::SocketStream stream(socket);
    stream << domain << std::endl;
    while (stream.good()) {
        std::string line;
        std::getline(stream, line);
        _logger.debug(line);
        Poco::StringTokenizer tokens(line, ":", Poco::StringTokenizer::TOK_TRIM);
        if (tokens.count() > 1) {
            if (tokens[0] == "whois") {
                return tokens[1];
            }
        }
    }
}

std::stringstream& Whois::record()
{
    return _record;
}
