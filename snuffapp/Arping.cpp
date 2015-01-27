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

Arping::Arping(Injector& injector, const Poco::Net::IPAddress& targetIP, MAC& targetMAC) : _injector(injector),
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
            if ((arp->opCode() == ARPOP_REPLY) && (arp->targetIP() == _targetIP)) {
                _targetMAC = arp->targetMAC();
                _counter++;
            }
        }
    }
}

bool Arping::ping(int retries, const Poco::Timespan& interval)
{
    for (int i = 0; i < retries; ++i) {
        if (_targetMAC.isUnicast()) {
            _injector.arpRequest(_targetIP, _targetMAC);
        }
        else {
            _injector.arpRequest(_targetIP);
        }
        Poco::Thread::sleep(interval.totalMilliseconds());
        if (_counter > 0) {
            return true;
        }
    }
    return false;
}

const MAC& Arping::targetMAC() const
{
    return _targetMAC;
}
