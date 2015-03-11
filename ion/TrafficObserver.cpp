/*
 * File:   TrafficObserver.cpp
 * Author: danny
 *
 * Created on March 10, 2015, 5:55 PM
 */

#include "TrafficObserver.h"
#include "DissectSubsystem.h"
#include "ProtocolTCP.h"
#include "ProtocolUDP.h"
#include "ProtocolIP.h"
#include "ProtocolEthernet.h"
#include <Poco/Util/Application.h>
#include <Poco/Delegate.h>

TrafficObserver::TrafficObserver(const Poco::Data::Session& session) : _bulk(session),
_logger(Poco::Logger::get("TrafficObserver"))
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame += Poco::delegate(this, &TrafficObserver::onFrameEvent);
}

TrafficObserver::~TrafficObserver()
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame -= Poco::delegate(this, &TrafficObserver::onFrameEvent);
}

void TrafficObserver::onFrameEvent(Frame::Ptr& frame)
{
    if (frame.isNull()) {
        return;
    }
    if (handleTCP(frame)) {
        return;
    }
    handleUDP(frame);
}

bool TrafficObserver::handleTCP(Frame::Ptr& frame)
{
    const ProtocolTCP* tcp = frame->getProtocol<ProtocolTCP>();
    if (tcp == nullptr) {
        return false;
    }
    if (tcp->isSynAck()) {
        handleIP("tcp", tcp->srcPort(), tcp->destPort(), frame);
    }
    return true;
}

bool TrafficObserver::handleUDP(Frame::Ptr& frame)
{
    const ProtocolUDP* udp = frame->getProtocol<ProtocolUDP>();
    if (udp == nullptr) {
        return false;
    }
    handleIP("udp", udp->srcPort(), udp->destPort(), frame);
    return true;
}

void TrafficObserver::handleIP(const std::string& transport, const Poco::UInt16 srcPort, const Poco::UInt16 destPort, Frame::Ptr& frame)
{
    const ProtocolIP* ip = frame->getProtocol<ProtocolIP>();
    if (ip == nullptr) {
        _logger.warning("UDP or TCP without IPv4 layer: %s", frame->toString());
        return;
    }
    const ProtocolEthernet* eth = frame->getProtocol<ProtocolEthernet>();
    if (eth == nullptr) {
        _logger.warning("Packet without ethernet layer: %s", frame->toString());
    }

    _bulk.add(eth->source(), eth->dest(), ip->source(), ip->dest(), srcPort, destPort, transport);
}
