/*
 * File:   TableOUI.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 9:03 AM
 */

#include "TableOUI.h"
#include <Poco/FileStream.h>
#include <Poco/Buffer.h>
#include <Poco/StringTokenizer.h>

using namespace Poco::Data::Keywords;

TableOUI::TableOUI(Poco::Data::Session& session) : _session(session), _logger(Poco::Logger::get("TableOUI"))
{

}

TableOUI::~TableOUI()
{
}

void TableOUI::create(const std::string& ouiFile)
{
    _session << "CREATE TABLE oui (prefix TEXT NOT NULL, vendor TEXT NOT NULL)", now;
    _session << "CREATE UNIQUE INDEX pk_oui on oui (prefix ASC)", now;
    populate(ouiFile);
}

void TableOUI::populate(const std::string& ouiFile)
{
    Poco::FileInputStream fis(ouiFile);
    Poco::Buffer<char> buff(255);
    fis.getline(buff.begin(), buff.size()); // header
    while (!fis.eof() && (!fis.fail())) {
        fis.getline(buff.begin(), buff.size());
        Poco::StringTokenizer tok(std::string(buff.begin()), "\t",
                                  Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
        if (tok.count() == 2) {
            std::string prefix = tok[0];
            std::string vendor = tok[1];
            Poco::StringTokenizer tok1(prefix, " ", Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
            if (tok1.count() > 1) {
                if (tok1[1] == "(hex)") {
                    prefix = Poco::translate(tok1[0], "-", ":");
                    insert(prefix, vendor);
                }
            }
        }

    }
}

void TableOUI::insert(const std::string& prefix, const std::string& vendor)
{
    try {
        std::string prefixstr = Poco::toLower(Poco::trim(prefix));
        std::string vendorstr = camel(Poco::trim((vendor)));
        _session << "INSERT INTO oui (prefix,vendor) VALUES (?,?)", use(prefixstr), use(vendorstr), now;
    }
    catch (Poco::Exception& ex) {
        _logger.error(ex.displayText());
    }
}

std::string TableOUI::camel(const std::string& text)
{
    std::string output;
    bool whitespace = true;
    for (char c : text) {
        if (whitespace) {
            output += toupper(c);
        }
        else {
            output += tolower(c);
        }
        whitespace = isspace(c);
    }
    return output;
}
