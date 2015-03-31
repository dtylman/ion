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
    if (!_transaction) {
        _session << "BEGIN IMMEDIATE";
        _transaction = true;
    }
}

ScopedTransaciton::~ScopedTransaciton()
{
    if (_transaction)
        try {
            _session.commit();
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
            _session.rollback();
        }
}


