/*
 * File:   HostObserver.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#include "ThingObserver.h"

#include <Poco/Util/Application.h>
#include "DissectSubsystem.h"
#include "ProtocolDHCP.h"
#include <Poco/Delegate.h>

ThingObserver::ThingObserver(const Poco::Data::Session& session) : _ion(session), _dhcp(session)
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame += Poco::delegate(this, &ThingObserver::onFrameEvent);
}

ThingObserver::~ThingObserver()
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame -= Poco::delegate(this, &ThingObserver::onFrameEvent);
}

void ThingObserver::onFrameEvent(Frame::Ptr& frame)
{
    if (frame.isNull()) {
        return;
    }
    const ProtocolDHCP* dhcp = frame->getProtocol<ProtocolDHCP>();
    if (dhcp == nullptr) {
        return;
    }
    if (dhcp->isRequest()) {
        std::string hostName = dhcp->getOption(12);
        std::string vendorClass = dhcp->getOption(60);
        std::string os = _dhcp.findOS(vendorClass, hostName);
        ThingData thing;
        if (_ion.getThingByMAC(dhcp->clientMAC(), thing)) {
            thing.setName(hostName);
            thing.setOS(os);
            _ion.setThing(thing, false);
        }
    }
}
