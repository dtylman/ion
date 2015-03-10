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
    _logger.debug("DissectSubsystem::initialize");
    _activity.start();
}

const char* DissectSubsystem::name() const
{
    return "DissectSubsystem";
}

void DissectSubsystem::uninitialize()
{
    _logger.debug("DissectSubsystem::uninitialize");
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
    _logger.information("Activity Started");
    while (!_activity.isStopped()) {
        try {
            Poco::Notification::Ptr notif(_queue.waitDequeueNotification(2500));
            Frame::Ptr frame = notif.cast<Frame>();
            if (!frame.isNull()) {
                frame->dissect();
                if (_logger.trace()) {
                    _logger.trace("Frame: %s", frame->toString());
                }
                onFrame.notify(this, frame);
            }
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
        catch (std::exception& ex) {
            _logger.error(std::string(ex.what()));
        }
        catch (...) {
            _logger.error("Unknown exception in DissectSubsystem::runActivity");
        }
    }
    _logger.information("Activity Ended");
}
