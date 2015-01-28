/*
 * File:   ModelSubsystem.h
 * Author: danny
 *
 * Created on January 24, 2015, 6:42 PM
 */

#ifndef MODELSUBSYSTEM_H
#define	MODELSUBSYSTEM_H

#include <Poco/Data/Session.h>
#include <Poco/Util/Subsystem.h>
#include "DataObserver.h"

class DataSubsystem : public Poco::Util::Subsystem
{
public:
    DataSubsystem();
    Poco::Data::Session createSession();
protected:
    virtual ~DataSubsystem();
    virtual const char* name() const;
    virtual void initialize(Poco::Util::Application& app);
    virtual void uninitialize();
private:
    DataObserver::Container _observers;
};

#endif	/* MODELSUBSYSTEM_H */

