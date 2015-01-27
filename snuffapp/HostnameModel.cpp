/*
 * File:   HostnameModel.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 8:51 PM
 */

#include "HostnameModel.h"

using namespace Poco::Data::Keywords;

HostnameModel::HostnameModel()
{
}

HostnameModel::~HostnameModel()
{
}

void HostnameModel::initialize()
{
    _session << "create table if not exists host (mac text, hostname text, domain text, nmname text, nbdomain text)", now;
}
