/*
 * File:   DissectSubsystem.cpp
 * Author: danny
 *
 * Created on January 21, 2015, 9:18 PM
 */

#include "DissectSubsystem.h"

DissectSubsystem::DissectSubsystem() : _activity(this, &DissectSubsystem::runActivity),
_logger(Poco::Logger::get("DissectSubsystem"))
{
}

DissectSubsystem::~DissectSubsystem()
{

}

void DissectSubsystem::initialize(Poco::Util::Application& app)
{
    _activity.start();
}

const char* DissectSubsystem::name() const
{
    return "DissectSubsystem";
}

void DissectSubsystem::uninitialize()
{
    _logger.notice("DissectSubsystem::uninitialize");
    _activity.stop();
    _queue.wakeUpAll();
    _activity.wait(2500);
}

void DissectSubsystem::queueFrame(Frame* frame)
{
    _queue.enqueueNotification(frame);
}

void DissectSubsystem::runActivity()
{
    while (!_activity.isStopped()) {
        Poco::Notification::Ptr notif(_queue.waitDequeueNotification(2500), true);
        Frame::Ptr frame = notif.cast<Frame>();
        if (!frame.isNull()) {
            frame->dissect();
            _logger.debug("Frame: %s", frame->toString());
            onFrame.notifyAsync(this, frame);
        }
    }
}
