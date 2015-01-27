/*
 * File:   IPModel.cpp
 * Author: danny
 *
 * Created on January 24, 2015, 8:50 PM
 */

#include "IPModel.h"
#include "DissectSubsystem.h"
#include "ProtocolIP.h"
#include "ProtocolEthernet.h"
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
    _session << "CREATE TABLE IF NOT EXISTS ip (mac TEXT NOT NULL,ip TEXT NOT NULL,last_seen INTEGER NOT NULL, iface TEXT)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_ip on ip (mac ASC, ip ASC, iface ASC)", now;
    _session << "CREATE TABLE IF NOT EXISTS router (mac TEXT NOT NULL, family INTEGER NOT NULL)", now;
    _session << "CREATE UNIQUE INDEX IF NOT EXISTS pk_router on router (mac ASC, family ASC)", now;
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
    if (ip->isDefaultTTL()) {
        link(ip->source(), eth->source(), frame->device());
    }
    else {
        linkRouter(ip->source(), eth->source(), frame->device());
    }
}

void IPModel::link(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& iface)
{
    if ((!ip.isUnicast()) || (!mac.isUnicast())) {
        return;
    }

    if (!_cache.exists(mac, ip, iface)) {
        std::string ipStr = ip.toString();
        std::string macSTR = mac.toString();
        std::string ifaceStr = iface;
        Poco::UInt64 ts = Poco::Timestamp().epochMicroseconds();
        _session << "INSERT OR REPLACE INTO ip (mac,ip,last_seen,iface) VALUES (?,?,?,?)",
                use(macSTR), use(ipStr), use(ts), use(ifaceStr), now;
    }
}

void IPModel::linkRouter(const Poco::Net::IPAddress& ip, const MAC& mac, const std::string& iface)
{
    if (_cache.exists(mac, ip, iface)) {
        return;
    }
    std::string macStr = mac.toString();
    int family = ip.af();
    bool isRouter = false;
    _session << "SELECT 1 FROM router WHERE mac=? AND family=?", use(macStr), use(family), into(isRouter), now;
    if (isRouter) {
        return;
    }
    else {
        int count = 0;
        _session << "SELECT count(ip) FROM ip WHERE mac=?", use(macStr), into(count), now;
        if (count > 3) {
            _session << "INSERT INTO router (mac, family) VALUES (?,?)", use(macStr), use(family), now;
            _session << "DELETE FROM ip WHERE mac=?", use(macStr), now;
        }
    }
}