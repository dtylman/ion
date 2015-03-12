/*
 * File:   IPModel.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 8:50 PM
 */

#include "IPDataObserver.h"
#include "DissectSubsystem.h"
#include "ProtocolIP.h"
#include "ProtocolEthernet.h"
#include "ProtocolARP.h"
#include <Poco/Data/Session.h>
#include <Poco/Delegate.h>
#include <Poco/Util/Application.h>

using namespace Poco::Data::Keywords;

IPDataObserver::IPDataObserver(const Poco::Data::Session& session) : _ion(session)
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame += Poco::delegate(this, &IPDataObserver::onFrameEvent);
}

IPDataObserver::~IPDataObserver()
{
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame -= Poco::delegate(this, &IPDataObserver::onFrameEvent);
}

void IPDataObserver::onFrameEvent(Frame::Ptr& frame)
{
    if (frame.isNull()) {
        return;
    }

    if (handleIP(frame)) {
        return;
    }

    handleARP(frame);

}

bool IPDataObserver::handleARP(Frame::Ptr& frame)
{
    const ProtocolARP* arp = frame->getProtocol<ProtocolARP>();
    if (arp == nullptr) {
        return false;
    }
    if (arp->isReply()) {
        link(arp->senderIP(), arp->senderMAC(), frame->device());
    }
    return true;
}

bool IPDataObserver::handleIP(Frame::Ptr& frame)
{
    const ProtocolIP* ip = frame->getProtocol <ProtocolIP>();
    if (ip == nullptr) {
        return false;
    }
    const ProtocolEthernet* eth = frame->getProtocol<ProtocolEthernet>();
    if (eth == nullptr) {
        return false;
    }
    if (ip->isDefaultTTL()) {
        link(ip->source(), eth->source(), frame->device());
    }
    else {

        routerSuspected(ip->source(), eth->source(), frame->device());
    }
    return true;
}

void IPDataObserver::link(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device)
{
    if ((ip.family() == Poco::Net::IPAddress::Family::IPv4) && (ip.isLinkLocal())) {
        return;
    }
    if (_cache.exists(mac, ip, device)) {

        return;
    }
    _ion.updateIP(IPData(mac, ip, device));
}

void IPDataObserver::routerSuspected(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& device)
{
    if (_cache.exists(mac, ip, device)) {
        return;
    }
    _ion.setSuspectedRouter(ip, mac, device);
}
