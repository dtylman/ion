/*
 * File:   TrafficData.h
 * Author: danny
 *
 * Created on March 11, 2015, 4:59 PM
 */

#ifndef TRAFFICDATA_H
#define	TRAFFICDATA_H

#include "MAC.h"
#include <Poco/Data/TypeHandler.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Timestamp.h>
#include <string>

class TrafficData
{
public:
    TrafficData();
    TrafficData(const MAC& toMAC, const Poco::Net::IPAddress& toIP, Poco::UInt16 toPort, const std::string& transport);
    virtual ~TrafficData();

    const Poco::Timestamp& time() const;
    void setTime(const Poco::Timestamp& timestamp);
    const Poco::UInt32 count() const;
    void setCount(Poco::UInt32 count);
    const MAC& mac() const;
    void setMAC(const MAC& mac);
    const Poco::Net::IPAddress& ip() const;
    void setIP(const Poco::Net::IPAddress& toIP);
    const Poco::UInt16 port() const;
    void setPort(Poco::UInt16 port);
    const std::string& transport() const;
    void setTransport(const std::string& transport);
    const std::string& process() const;
    void setProcess(const std::string& process);
    const std::string& host() const;
    void setHost(const std::string& host);

    std::string toString() const;
    std::size_t hash() const;
    void update();
private:
    Poco::Timestamp _time;
    Poco::UInt32 _count = 0;
    MAC _mac;
    Poco::Net::IPAddress _ip;
    Poco::UInt16 _port = 0;
    std::string _host;
    std::string _transport;
    std::string _process;
};


namespace Poco
{
    namespace Data
    {

        template<> class TypeHandler<class TrafficData>
        {
        public:
            //"CREATE TABLE traffic (time INTEGER NOT NULL, count INTEGER NOT NULL, mac TEXT NOT NULL, ip TEXT NOT NULL, "
            //"port NUMBER NOT NULL, host TEXT, transport TEXT NOT NULL, process TEXT)", now;

            static void bind(std::size_t pos, const TrafficData &trafficData, AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
            {
                poco_assert_dbg(!pBinder.isNull());
                TypeHandler<std::time_t>::bind(pos++, trafficData.time().epochTime(), pBinder, dir);
                TypeHandler<Poco::UInt32>::bind(pos++, trafficData.count(), pBinder, AbstractBinder::PD_IN_OUT);

                TypeHandler<std::string>::bind(pos++, trafficData.mac().toString(), pBinder, AbstractBinder::PD_IN_OUT);
                TypeHandler<std::string>::bind(pos++, trafficData.ip().toString(), pBinder, AbstractBinder::PD_IN_OUT);
                TypeHandler<Poco::UInt16>::bind(pos++, trafficData.port(), pBinder, AbstractBinder::PD_IN_OUT);

                TypeHandler<std::string>::bind(pos++, trafficData.host(), pBinder, AbstractBinder::PD_IN_OUT);
                TypeHandler<std::string>::bind(pos++, trafficData.transport(), pBinder, AbstractBinder::PD_IN_OUT);
                TypeHandler<std::string>::bind(pos++, trafficData.process(), pBinder, AbstractBinder::PD_IN_OUT);
            }

            static std::size_t size()
            {
                return 8;
            }

            static void prepare(std::size_t pos, const TrafficData &trafficData, AbstractPreparator::Ptr pPreparator)
            {
                poco_assert_dbg(!pPreparator.isNull());
                TypeHandler<std::time_t>::prepare(pos++, trafficData.time().epochTime(), pPreparator);
                TypeHandler<Poco::UInt32>::prepare(pos++, trafficData.count(), pPreparator);

                TypeHandler<std::string>::prepare(pos++, trafficData.mac().toString(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, trafficData.ip().toString(), pPreparator);
                TypeHandler<Poco::UInt16>::prepare(pos++, trafficData.port(), pPreparator);

                TypeHandler<std::string>::prepare(pos++, trafficData.host(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, trafficData.transport(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, trafficData.process(), pPreparator);
            }

            static void extract(std::size_t pos, TrafficData &trafficData, const TrafficData & defVal, AbstractExtractor::Ptr pExt)
            {
                poco_assert_dbg(!pExt.isNull());
                std::time_t time;
                Poco::UInt32 count;
                std::string mac, ip, host, transport, process;
                Poco::UInt16 toport;

                TypeHandler<std::time_t>::extract(pos++, time, defVal.time().epochTime(), pExt);
                TypeHandler<Poco::UInt32>::extract(pos++, count, defVal.count(), pExt);

                TypeHandler<std::string>::extract(pos++, mac, defVal.mac().toString(), pExt);
                TypeHandler<std::string>::extract(pos++, ip, defVal.ip().toString(), pExt);
                TypeHandler<Poco::UInt16>::extract(pos++, toport, defVal.port(), pExt);

                TypeHandler<std::string>::extract(pos++, host, defVal.host(), pExt);
                TypeHandler<std::string>::extract(pos++, transport, defVal.transport(), pExt);
                TypeHandler<std::string>::extract(pos++, process, defVal.process(), pExt);
                trafficData.setTime(Poco::Timestamp::fromEpochTime(time));
                trafficData.setCount(count);

                trafficData.setMAC(MAC(mac));
                trafficData.setIP(Poco::Net::IPAddress(ip));
                trafficData.setPort(toport);

                trafficData.setHost(host);
                trafficData.setTransport(transport);
                trafficData.setProcess(process);
            }
        private:
            TypeHandler();
            ~TypeHandler();
            TypeHandler(const TypeHandler&);
            TypeHandler& operator=(const TypeHandler&);
        };
    }
}
#endif	/* TRAFFICDATA_H */

