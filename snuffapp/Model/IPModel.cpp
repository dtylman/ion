/*
 * File:   IPModel.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 8:50 PM
 */

#include "IPModel.h"
#include "../Dissect/DissectSubsystem.h"
#include "../Dissect/ProtocolIP.h"
#include "../Dissect/ProtocolEthernet.h"
#include <Poco/Data/Session.h>
#include <Poco/Delegate.h>
#include <Poco/Util/Application.h>

using namespace Poco::Data::Keywords;

IPModel::IPModel()
{
}

IPModel::~IPModel()
{
}

void IPModel::initialize()
{
    _session << "create table if not exists ip (mac text, ip text, time text)", now;
    Poco::Util::Application::instance().getSubsystem<DissectSubsystem>().onFrame += Poco::delegate(this, &IPModel::onFrameEvent);
}

void IPModel::onFrameEvent(Frame::Ptr& frame)
{
    if (frame.isNull()) {
        return;
    }
    const ProtocolIP* ip = frame->getProtocol <ProtocolIP>();
    if (ip == nullptr) {
        return;
    }
    const ProtocolEthernet* eth = frame->getProtocol<ProtocolEthernet>();
    if (eth == nullptr) {
        return;
    }
    link(ip->source(), eth->source());
    link(ip->dest(), eth->dest());
}

void IPModel::link(const Poco::Net::IPAddress& ip, const MAC& mac)
{
    std::string strIP = ip.toString();
    std::string strMAC = mac.toString();
    _session << "INSERT into IP (ip,mac) VALUES (?,?)", use(strIP), use(strMAC), now;
}
