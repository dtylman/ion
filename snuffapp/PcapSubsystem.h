/*
 * File:   PcapSubsystem.h
 * Author: danny
 *
 * Created on January 19, 2015, 10:35 PM
 */

#ifndef PCAPSUBSYSTEM_H
#define	PCAPSUBSYSTEM_H

#include "PcapActivity.h"
#include <Poco/Util/Subsystem.h>
#include <Poco/Logger.h>
#include <list>

class PcapSubsystem : public Poco::Util::Subsystem
{
public:
    PcapSubsystem();
protected:
    virtual void initialize(Poco::Util::Application& app);
    virtual const char* name() const;
    virtual void uninitialize();
    virtual ~PcapSubsystem();
private:
    std::list<PcapActivity::Ptr> _activities;
    Poco::Logger& _logger;
};

#endif	/* PCAPSUBSYSTEM_H */

