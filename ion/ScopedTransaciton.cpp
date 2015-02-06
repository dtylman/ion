/*
 * File:   ScopedTransaciton.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 1:34 PM
 */

#include "ScopedTransaciton.h"

ScopedTransaciton::ScopedTransaciton(Poco::Data::Session& session) : _session(session),
_logger(Poco::Logger::get("ScopedTransaciton"))
{
    if (!_session.isTransaction()) {
        _session.begin();
    }
}

ScopedTransaciton::~ScopedTransaciton()
{
    if (_session.isTransaction()) {
        try {
            _session.commit();
        }
        catch (Poco::Exception& ex) {
            _logger.warning(ex.displayText());
            _session.rollback();
        }
    }
}

