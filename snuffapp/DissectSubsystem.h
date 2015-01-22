/*
 * File:   DissectSubsystem.h
 * Author: danny
 *
 * Created on January 21, 2015, 9:18 PM
 */

#ifndef DISSECTSUBSYSTEM_H
#define	DISSECTSUBSYSTEM_H

#include "Frame.h"
#include <Poco/Util/Subsystem.h>
#include <Poco/NotificationQueue.h>
#include <Poco/Activity.h>
#include <Poco/Logger.h>

class DissectSubsystem : public Poco::Util::Subsystem
{
public:
    DissectSubsystem();
    void queueFrame(Frame* frame);
protected:
    virtual ~DissectSubsystem();
    virtual const char* name() const;
    virtual void initialize(Poco::Util::Application& app);
    virtual void uninitialize();
    void runActivity();
private:
    Poco::NotificationQueue _queue;
    Poco::Activity<DissectSubsystem> _activity;
    Poco::Logger& _logger;
};

#endif	/* DISSECTSUBSYSTEM_H */

