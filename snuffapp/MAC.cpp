/*
 * File:   MAC.cpp
 * Author: danny
 *
 * Created on January 20, 2015, 6:01 PM
 */

#include "MAC.h"

MAC::MAC()
{
}

MAC::MAC(const Poco::Net::NetworkInterface::MACAddress& address) : _address(address)
{

}

MAC::~MAC()
{
}

