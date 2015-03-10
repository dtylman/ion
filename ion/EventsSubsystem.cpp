/*
 * File:   EventsSubsystem.cpp
 * Author: danny
 *
 * Created on February 4, 2015, 9:04 AM
 */

#include "EventsSubsystem.h"
#include "EventDataObject.h"
#include "DataSubsystem.h"
#include "SendMail.h"
#include "Syslog.h"
#include <Poco/NObserver.h>
#include <Poco/NotificationCenter.h>
#include <Poco/Util/Application.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/PrivateKeyPassphraseHandler.h>
#include <Poco/Net/InvalidCertificateHandler.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/SharedPtr.h>

EventsSubsystem::EventsSubsystem() : _activity(this, &EventsSubsystem::runActivity),
_logger(Poco::Logger::get("EventsSubsystem"))
{

}

EventsSubsystem::~EventsSubsystem()
{

}

void EventsSubsystem::initialize(Poco::Util::Application& app)
{
    _logger.debug("EventsSubsystem::initialize");
    Poco::SharedPtr<Poco::Net::InvalidCertificateHandler> cert(new Poco::Net::AcceptCertificateHandler(true));
    Poco::Net::Context::Ptr context = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "", "", "", Poco::Net::Context::VERIFY_RELAXED, 9, true, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
    Poco::Net::SSLManager::instance().initializeClient(nullptr, cert, context);
    _activity.start();
}

const char* EventsSubsystem::name() const
{
    return "EventsSubsystem";
}

void EventsSubsystem::uninitialize()
{
    _logger.debug("EventsSubsystem::uninitialize");
    _activity.stop();
    _queue.wakeUpAll();
    _activity.wait(2500);
    Poco::Net::uninitializeSSL();
}

void EventsSubsystem::notify(EventNotification::Ptr notif)
{
    _queue.enqueueNotification(notif);
}

void EventsSubsystem::persistEvent(const EventData& eventData)
{
    DataSubsystem& data = Poco::Util::Application::instance().getSubsystem<DataSubsystem>();
    EventDataObject edo(data.createSession());
    edo.insert(eventData);
}

void EventsSubsystem::processEvent(const EventData& eventData)
{
    if (_logger.debug()) {
        _logger.debug("Event: %s", eventData.toString());
    }
    Poco::Util::AbstractConfiguration& config = Poco::Util::Application::instance().config();
    const std::string& eventName = eventData.name();
    if (config.getBool(Poco::format("ion.events.%s.save", eventName), true)) {
        persistEvent(eventData);
    }
    if (config.getBool(Poco::format("ion.events.%s.mail", eventName), false)) {
        mailEvent(eventData);
    }
    if (config.getBool(Poco::format("ion.events.%s.syslog", eventName), false)) {
        syslogEvent(eventData);
    }
}

void EventsSubsystem::runActivity()
{
    _logger.information("Activity Started");
    while (!_activity.isStopped()) {
        try {
            Poco::Notification::Ptr notif(_queue.waitDequeueNotification(2500), true);
            EventNotification::Ptr event = notif.cast<EventNotification>();
            if (!event.isNull()) {
                processEvent(event->event());
            }
        }
        catch (Poco::Exception& ex) {
            _logger.error(ex.displayText());
        }
        catch (std::exception& ex) {
            _logger.error(std::string(ex.what()));
        }
        catch (...) {
            _logger.error("Unknown exception in EventsSubsystem::runActivity");
        }
    }
    _logger.information("Activity Ended");
}

void EventsSubsystem::mailEvent(const EventData & eventData)
{
    try {
        SendMail mail;
        mail.sendEvent(eventData);
    }
    catch (Poco::Exception& ex) {
        _logger.error("Failed to send mail: %s", ex.displayText());
    }
}

void EventsSubsystem::syslogEvent(const EventData& eventData)
{
    try {
        _syslog.log(eventData);
    }
    catch (Poco::Exception& ex) {
        _logger.error("Failed to write syslog event: %s", ex.displayText());
    }
}
