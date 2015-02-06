/*
 * File:   DHCPOSDataObject.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 10:05 AM
 */

#include "DHCPOSDataObject.h"

using namespace Poco::Data::Keywords;

DHCPOSDataObject::DHCPOSDataObject(const Poco::Data::Session& session) : DataObject(session),
_logger(Poco::Logger::get("DHCPOSDataObject"))
{

}

DHCPOSDataObject::~DHCPOSDataObject()
{
}

std::string DHCPOSDataObject::findOS(const std::string& vendor, const std::string& hostname)
{
    std::string vendorstr(vendor);
    std::string hostnamestr(hostname);
    std::string os;
    _session << "SELECT os FROM os_dhcp WHERE glob(vendor,?)=1 and glob(hostname,?)=1",
            use(vendorstr), use(hostnamestr), into(os), now;
    _logger.debug("Find OS vendor='%s', hostname='%s' result='%s'", vendorstr, hostnamestr, os);
    return os;
}
