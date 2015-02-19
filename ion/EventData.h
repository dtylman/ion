/*
 * File:   EventData.h
 * Author: danny
 *
 * Created on February 3, 2015, 10:10 PM
 */

#ifndef EVENTDATA_H
#define	EVENTDATA_H

#include <Poco/Timestamp.h>
#include <Poco/Data/TypeHandler.h>

class EventData
{
public:
    EventData();
    virtual ~EventData();

    const Poco::Timestamp& time() const;
    void setTime(const Poco::Timestamp& time);
    const std::string& name() const;
    void setName(const std::string& name);
    const std::string& details() const;
    void setDetails(const std::string& details);

    std::string toString() const;
private:
    Poco::Timestamp _time;
    std::string _name;
    std::string _details;
};


namespace Poco
{
    namespace Data
    {

        template<> class TypeHandler<class EventData>
        {
        public:
            //time INTEGER NOT NULL, name TEXT NOT NULL, mac TEXT ,ip TEXT, details TEXT

            static void bind(std::size_t pos, const EventData &eventData,
                             AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
            {
                poco_assert_dbg(!pBinder.isNull());
                TypeHandler<std::time_t>::bind(pos++, eventData.time().epochTime(), pBinder, dir);
                TypeHandler<std::string>::bind(pos++, eventData.name(), pBinder, dir);
                TypeHandler<std::string>::bind(pos++, eventData.details(), pBinder, dir);
            }

            static std::size_t size()
            {
                return 3;
            }

            static void prepare(std::size_t pos, const EventData &eventData, AbstractPreparator::Ptr pPreparator)
            {
                poco_assert_dbg(!pPreparator.isNull());
                TypeHandler<std::time_t>::prepare(pos++, eventData.time().epochTime(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, eventData.name(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, eventData.details(), pPreparator);
            }

            static void extract(std::size_t pos, EventData &eventData, const EventData & defVal, AbstractExtractor::Ptr pExt)
            {
                poco_assert_dbg(!pExt.isNull());
                std::string name, mac, ip, details;
                std::time_t time;
                TypeHandler<std::time_t>::extract(pos++, time, defVal.time().epochTime(), pExt);
                TypeHandler<std::string>::extract(pos++, name, defVal.name(), pExt);
                TypeHandler<std::string>::extract(pos++, details, defVal.details(), pExt);
                eventData.setTime(Poco::Timestamp::fromEpochTime(time));
                eventData.setName(name);
                eventData.setDetails(details);
            }
        private:
            TypeHandler();
            ~TypeHandler();
            TypeHandler(const TypeHandler&);
            TypeHandler& operator=(const TypeHandler&);
        };
    }
}
#endif	/* EVENTDATA_H */

