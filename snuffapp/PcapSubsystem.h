/*
 * File:   PcapSubsystem.h
 * Author: danny
 *
 * Created on January 19, 2015, 10:35 PM
 */

#ifndef PCAPSUBSYSTEM_H
#define	PCAPSUBSYSTEM_H

#include "PcapActivity.h"
#include "PcapDevice.h"
#include <Poco/Util/Subsystem.h>
#include <Poco/Logger.h>
#include <Poco/Mutex.h>
#include <string>
#include <map>

class PcapSubsystem : public Poco::Util::Subsystem
{
public:
    PcapSubsystem();
    void start();

    typedef std::list<PcapDevice> Devices;
    PcapDevice getDevice(const std::string& name) const;
    void getAllDevices(Devices& devices);
protected:
    virtual void initialize(Poco::Util::Application& app);
    virtual const char* name() const;
    virtual void uninitialize();
    virtual ~PcapSubsystem();
private:
    typedef std::map<std::string, PcapActivity::Ptr> ActivityContainer;
    mutable Poco::FastMutex _mutex;
    ActivityContainer _activities;

    Devices _devices;
    Poco::Logger& _logger;
};

#endif	/* PCAPSUBSYSTEM_H */

