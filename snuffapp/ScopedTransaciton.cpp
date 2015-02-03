/*
 * File:   ScopedTransaciton.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 1:34 PM
 */

#include "ScopedTransaciton.h"

ScopedTransaciton::ScopedTransaciton(Poco::Data::Session& session) : _session(session)
{
    _session.begin();
}

ScopedTransaciton::~ScopedTransaciton()
{
    _session.commit();
}

