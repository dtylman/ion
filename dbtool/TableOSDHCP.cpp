/*
 * File:   TableOSDHCP.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 9:38 AM
 */

#include "TableOSDHCP.h"
using namespace Poco::Data::Keywords;

TableOSDHCP::TableOSDHCP(Poco::Data::Session& session) : _session(session)
{

}

TableOSDHCP::~TableOSDHCP()
{
}

void TableOSDHCP::create()
{
    _session << "CREATE TABLE os_dhcp (vendor TEXT NOT NULL, hostname TEXT NOT NULL, os TEXT NOT NULL)", now;
    _session << "CREATE UNIQUE INDEX pk_os_dhcp on os_dhcp (vendor ASC, hostname ASC)", now;

    insert("MSFT 5.0", "*", "microsoft windows");
    insert("dhcpcd*", "android*", "google android");
}

void TableOSDHCP::insert(const std::string vendor, const std::string& hostname, const std::string& os)
{
    std::string vendorstr(vendor);
    std::string hostnamestr(hostname);
    std::string osstr(os);
    _session << "INSERT INTO os_dhcp (vendor, hostname, os) VALUES (?,?,?)", use(vendorstr), use(hostnamestr), use(osstr), now;
}
