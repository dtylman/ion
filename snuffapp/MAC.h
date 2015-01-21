/*
 * File:   MAC.h
 * Author: danny
 *
 * Created on January 20, 2015, 6:01 PM
 */

#ifndef MAC_H
#define	MAC_H

#include <Poco/Net/NetworkInterface.h>

class MAC : public Poco::Net::NetworkInterface::MACAddress
{
public:
    MAC();
    virtual ~MAC();
private:
};

#endif	/* MAC_H */

