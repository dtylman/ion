/*
 * File:   HostObserver.cpp
 * Author: danny
 *
 * Created on January 28, 2015, 3:10 PM
 */

#include "HostObserver.h"

#include <Poco/Util/Application.h>
#include "DissectSubsystem.h"
#include "ProtocolDHCP.h"
#include <Poco/Delegate.h>

HostObserver::HostObserver(const Poco::Data::Session& session) : _dao(session)
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame += Poco::delegate(this, &HostObserver::onFrameEvent);
}

HostObserver::~HostObserver()
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame -= Poco::delegate(this, &HostObserver::onFrameEvent);
}

void HostObserver::onFrameEvent(Frame::Ptr& frame)
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
        _dao.addHostInfo(dhcp->clientMAC(), hostName, vendorClass, frame->device());
    }
}
