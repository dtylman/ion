/*
 * File:   IPData.h
 * Author: danny
 *
 * Created on February 3, 2015, 11:33 AM
 */

#ifndef IPDATA_H
#define	IPDATA_H

#include <Poco/Data/TypeHandler.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Timestamp.h>
#include "MAC.h"
#include <list>

class IPData
{
public:
    IPData();
    virtual ~IPData();

    typedef std::list<IPData> Container;
    const MAC& mac() const;
    void setMAC(const MAC& mac);
    const Poco::Net::IPAddress& ip() const;
    void setIP(const Poco::Net::IPAddress& ip);
    const Poco::Timestamp& lastSeen() const;
    void setLastSeen(const Poco::Timestamp& lastSeen);
    const std::string& iface() const;
    void setIface(const std::string& iface);

    std::string toString() const;
private:
    MAC _mac;
    Poco::Net::IPAddress _ip;
    Poco::Timestamp _lastSeen;
    std::string _iface;
};


namespace Poco
{
    namespace Data
    {

        template<> class TypeHandler<class IPData>
        {
        public:
            //CREATE TABLE IF NOT EXISTS ip (mac TEXT NOT NULL,ip TEXT NOT NULL,last_seen INTEGER NOT NULL, iface TEXT)

            static void bind(std::size_t pos, const IPData &ipData,
                             AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
            {
                poco_assert_dbg(!pBinder.isNull());
                TypeHandler<std::string>::bind(pos++, ipData.mac().toString(), pBinder,
                                               AbstractBinder::PD_IN_OUT);
                TypeHandler<std::string>::bind(pos++, ipData.ip().toString(), pBinder, dir);
                TypeHandler<std::time_t>::bind(pos++, ipData.lastSeen().epochTime(), pBinder, dir);
                TypeHandler<std::string>::bind(pos++, ipData.iface(), pBinder, dir);
            }

            static std::size_t size()
            {
                return 4;
            }

            static void prepare(std::size_t pos, const IPData &ipData, AbstractPreparator::Ptr pPreparator)
            {
                poco_assert_dbg(!pPreparator.isNull());
                TypeHandler<std::string>::prepare(pos++, ipData.mac().toString(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, ipData.ip().toString(), pPreparator);
                TypeHandler<std::time_t>::prepare(pos++, ipData.lastSeen().epochTime(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, ipData.iface(), pPreparator);
            }

            static void extract(std::size_t pos, IPData &ipData, const IPData & defVal, AbstractExtractor::Ptr pExt)
            {
                poco_assert_dbg(!pExt.isNull());
                std::string mac, ip, iface;
                std::time_t last;
                TypeHandler<std::string>::extract(pos++, mac, defVal.mac().toString(), pExt);
                TypeHandler<std::string>::extract(pos++, ip, defVal.ip().toString(), pExt);
                TypeHandler<std::time_t>::extract(pos++, last, defVal.lastSeen().epochTime(), pExt);
                TypeHandler<std::string>::extract(pos++, iface, defVal.iface(), pExt);
                ipData.setMAC(MAC(mac));
                ipData.setIP(Poco::Net::IPAddress(ip));
                ipData.setLastSeen(Poco::Timestamp::fromEpochTime(last));
                ipData.setIface(iface);
            }
        private:
            TypeHandler();
            ~TypeHandler();
            TypeHandler(const TypeHandler&);
            TypeHandler& operator=(const TypeHandler&);
        };
    }
}
#endif	/* IPDATA_H */

