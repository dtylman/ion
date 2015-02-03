/*
 * File:   ScopedTransaciton.h
 * Author: danny
 *
 * Created on February 3, 2015, 1:34 PM
 */

#ifndef SCOPEDTRANSACITON_H
#define	SCOPEDTRANSACITON_H

#include <Poco/Data/Session.h>

class ScopedTransaciton
{
public:
    ScopedTransaciton(Poco::Data::Session& session);
    virtual ~ScopedTransaciton();
private:
    Poco::Data::Session& _session;
};

#endif	/* SCOPEDTRANSACITON_H */

