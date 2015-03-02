/*
 * File:   LibnetException.cpp
 * Author: danny
 *
 * Created on March 2, 2015, 10:47 AM
 */

#include "LibnetException.h"

LibnetException::LibnetException(const std::string& msg, libnet_t* libnet)
{
    poco_check_ptr(libnet);
    message(msg + std::string(libnet_geterror(libnet)));
}

LibnetException::~LibnetException()
{
}
