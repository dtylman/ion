/*
 * File:   Routing.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 3:25 PM
 */

#include "Routing.h"
#include <Poco/FileStream.h>
#include <Poco/Buffer.h>
#include <Poco/StringTokenizer.h>
#include <Poco/NumberParser.h>

void Routing::load4()
{
    Poco::FileInputStream fis("/proc/net/route");
    Poco::Buffer<char> buff(255);
    fis.getline(buff.begin(), buff.size()); // header
    while (!fis.eof() && (!fis.fail())) {
        fis.getline(buff.begin(), buff.size());
        std::string line(buff.begin());
        Poco::StringTokenizer tok(std::string(buff.begin()), "\t ",
                                  Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
        if (tok.count() > 6) {
            std::string name = tok[0];
            Poco::UInt32 gwAddr = Poco::NumberParser::parseHex(tok[2]);
            if (gwAddr != 0) {
                Poco::Net::IPAddress gateway(reinterpret_cast<struct in_addr*> (&gwAddr), sizeof (struct in_addr));
                _gateways[gateway] = name;
            }
        }
    }
    fis.close();
}

Poco::Net::IPAddress parseIP6Address(const std::string& ipStr)
{
    if (ipStr == "00000000000000000000000000000000") {
        return Poco::Net::IPAddress(Poco::Net::IPAddress::IPv6);
    }
    std::string res = ipStr;
    for (int i = 7; i > 0; i--) {
        res.insert(res.end() - i * 4, ':');
    }
    return Poco::Net::IPAddress(res);
}

void Routing::load6()
{
    Poco::FileInputStream fis("/proc/net/ipv6_route");
    Poco::Buffer<char> buff(255);
    fis.getline(buff.begin(), buff.size()); // header
    while (!fis.eof() && (!fis.fail())) {
        fis.getline(buff.begin(), buff.size());
        std::string line(buff.begin());
        Poco::StringTokenizer tok(line, " ", Poco::StringTokenizer::TOK_IGNORE_EMPTY | Poco::StringTokenizer::TOK_TRIM);
        if (tok.count() > 8) {
            std::string ifaceName = tok[9];
            Poco::Net::IPAddress gwAddr = parseIP6Address(tok[4]);
            if (!gwAddr.isWildcard()) {
                _gateways[gwAddr] = ifaceName;
            }
        }
    }
}
