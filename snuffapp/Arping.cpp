/*
 * File:   Arping.cpp
 * Author: danny
 *
 * Created on January 27, 2015, 10:54 AM
 */

#include "Arping.h"
#include "DissectSubsystem.h"
#include "Injector.h"
#include "ProtocolARP.h"
#include <Poco/Util/Application.h>
#include <Poco/Delegate.h>

Arping::Arping(Injector& injector, const Poco::Net::IPAddress& targetIP, const MAC& targetMAC) : _injector(injector),
_targetIP(targetIP), _targetMAC(targetMAC)
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame += Poco::delegate(this, &Arping::onFrameEvent);
}

Arping::~Arping()
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame -= Poco::delegate(this, &Arping::onFrameEvent);
}

void Arping::onFrameEvent(Frame::Ptr& frame)
{
    if (frame->device() == _injector.device()) {
        const ProtocolARP* arp = frame->getProtocol<ProtocolARP>();
        if (arp != nullptr) {
            if ((arp->isReply()) && (arp->senderIP() == _targetIP)) {
                Poco::FastMutex::ScopedLock lock(_mutex);
                _targetMAC = arp->senderMAC();
                _event.set();
            }
        }
    }
}

bool Arping::ping(int retries, const Poco::Timespan& interval)
{
    for (int i = 0; i < retries; ++i) {
        {
            Poco::FastMutex::ScopedLock lock(_mutex);
            if (_targetMAC.isUnicast()) {
                _injector.arpRequest(_targetIP, _targetMAC);
            }
            else {
                _injector.arpRequest(_targetIP);
            }
        }
        if (_event.tryWait((long) interval.totalMilliseconds())) {
            return true;
        }
    }
    return false;
}

const MAC& Arping::targetMAC() const
{
    Poco::FastMutex::ScopedLock lock(_mutex);
    return _targetMAC;
}
