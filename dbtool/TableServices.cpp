/*
 * File:   TableServices.cpp
 * Author: danny
 *
 * Created on March 18, 2015, 3:06 PM
 */

#include "TableServices.h"
#include <Poco/FileStream.h>
#include <Poco/Util/Application.h>
#include <Poco/Buffer.h>
#include <Poco/StringTokenizer.h>
#include <Poco/NumberParser.h>

using namespace Poco::Data::Keywords;

TableServices::TableServices(Poco::Data::Session& session) : _session(session), _logger(Poco::Logger::get("TableServices"))
{

}

TableServices::~TableServices()
{
}

void TableServices::create()
{
    _session << "CREATE TABLE service (port INTEGER NOT NULL, transport TEXT NOT NULL, service TEXT NOT NULL)", now;
    _session << "CREATE UNIQUE INDEX pk_service on service (port ASC, transport ASC)", now;
    populate();
}

void TableServices::populate()
{
    std::string servicesFile = Poco::Util::Application::instance().config().getString("servicefile", "service-names-port-numbers.csv");
    Poco::FileInputStream fis(servicesFile);
    Poco::Buffer<char> buff(255);
    fis.getline(buff.begin(), buff.size()); // header
    while (!fis.eof() && (!fis.fail())) {
        fis.getline(buff.begin(), buff.size());
        std::string line(buff.begin());
        try {
            Poco::StringTokenizer tok(line, ",", Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
            if (tok.count() >= 4) {
                std::string name = tok[0];
                std::string port = tok[1];
                std::string transport = tok[2];
                std::string desc = tok[3];
                if (!name.empty()) {
                    if ((transport == "udp") || (transport == "tcp")) {
                        int portNum;
                        if (Poco::NumberParser::tryParse(port, portNum)) {
                            _session << "INSERT INTO service (port,transport,service) VALUES (?,?,?)", use(portNum), use(transport), use(desc), now;
                        }
                    }
                }
            }
        }
        catch (Poco::Exception&ex) {
            _logger.error("%s: %s", line, ex.displayText());
        }
    }
}
