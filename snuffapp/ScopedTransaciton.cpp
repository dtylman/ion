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
    _logger.debug("Constructor");
    if (!_session.isTransaction()) {
        _logger.debug("Begin");
        _session.begin();
    }
}

ScopedTransaciton::~ScopedTransaciton()
{
    _logger.debug("Destructor");
    if (_session.isTransaction()) {
        try {
            _logger.debug("Commit");
            _session.commit();
        }
        catch (Poco::Exception& ex) {
            _logger.warning(ex.displayText());
            _logger.debug("Rollback");
            _session.rollback();
        }
    }
}

