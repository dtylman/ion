/*
 * File:   LibnetException.h
 * Author: danny
 *
 * Created on March 2, 2015, 10:47 AM
 */

#ifndef LIBNETEXCEPTION_H
#define	LIBNETEXCEPTION_H

#include <Poco/Exception.h>
#include <libnet.h>

class LibnetException : public Poco::Exception
{
public:
    LibnetException(const std::string& message, libnet_t* libnet);
    virtual ~LibnetException();
    std::string displayText() const;
private:
};

#endif	/* LIBNETEXCEPTION_H */

