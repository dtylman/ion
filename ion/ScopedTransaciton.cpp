/*
 * File:   ScopedTransaciton.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 1:34 PM
 */

#include "ScopedTransaciton.h"
#include <Poco/Data/SQLite/Utility.h>
using namespace Poco::Data::Keywords;

ScopedTransaciton::ScopedTransaciton(Poco::Data::Session& session) : _session(session),
_logger(Poco::Logger::get("ScopedTransaciton"))
{
    if (Poco::Data::SQLite::Utility::isAutoCommit(_session)) {
        _session << "BEGIN IMMEDIATE", now;
    }
}

ScopedTransaciton::~ScopedTransaciton()
{
    if (!Poco::Data::SQLite::Utility::isAutoCommit(_session))
        try {
            _session.commit();
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
            _session.rollback();
        }
}


