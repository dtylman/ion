/*
 * File:   ThingData.h
 * Author: danny
 *
 * Created on February 18, 2015, 4:01 PM
 */

#ifndef THINGDATA_H
#define	THINGDATA_H

#include <Poco/Data/TypeHandler.h>
#include <Poco/UUID.h>
#include <string>

class ThingData
{
public:
    ThingData();
    virtual ~ThingData();

    void setUUID(const Poco::UUID& uuid);
    const Poco::UUID& uuid() const;
    void setType(const std::string& type);
    const std::string& type() const;
    void setName(const std::string& name);
    const std::string& name() const;
    void setVendor(const std::string& vendor);
    const std::string& vendor() const;
    void setOS(const std::string& os);
    const std::string& os() const;
    void setDesc(const std::string& desc);
    const std::string& desc() const;

private:
    Poco::UUID _uuid;
    std::string _type;
    std::string _name;
    std::string _vendor;
    std::string _os;
    std::string _desc;
};


namespace Poco
{
    namespace Data
    {

        template<> class TypeHandler<class ThingData>
        {
        public:

            //CREATE TABLE thing (id TEXT NOT NULL, type TEXT, name TEXT, vendor TEXT, os TEXT, desc TEXT)

            static void bind(std::size_t pos, const ThingData &thingData,
                             AbstractBinder::Ptr pBinder, AbstractBinder::Direction dir)
            {
                poco_assert_dbg(!pBinder.isNull());
                TypeHandler<std::string>::bind(pos++, thingData.uuid().toString(), pBinder,
                                               AbstractBinder::PD_IN_OUT);
                TypeHandler<std::string>::bind(pos++, thingData.type(), pBinder, dir);
                TypeHandler<std::string>::bind(pos++, thingData.name(), pBinder, dir);
                TypeHandler<std::string>::bind(pos++, thingData.vendor(), pBinder, dir);
                TypeHandler<std::string>::bind(pos++, thingData.os(), pBinder, dir);
                TypeHandler<std::string>::bind(pos++, thingData.desc(), pBinder, dir);

            }

            static std::size_t size()
            {
                return 6;
            }

            static void prepare(std::size_t pos, const ThingData &thingData, AbstractPreparator::Ptr pPreparator)
            {
                poco_assert_dbg(!pPreparator.isNull());
                TypeHandler<std::string>::prepare(pos++, thingData.uuid().toString(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, thingData.type(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, thingData.name(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, thingData.vendor(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, thingData.os(), pPreparator);
                TypeHandler<std::string>::prepare(pos++, thingData.desc(), pPreparator);
            }

            static void extract(std::size_t pos, ThingData &thingData, const ThingData & defVal, AbstractExtractor::Ptr pExt)
            {
                poco_assert_dbg(!pExt.isNull());
                std::string uuid, type, name, vendor, os, desc;
                TypeHandler<std::string>::extract(pos++, uuid, defVal.uuid().toString(), pExt);
                TypeHandler<std::string>::extract(pos++, type, defVal.type(), pExt);
                TypeHandler<std::string>::extract(pos++, name, defVal.name(), pExt);
                TypeHandler<std::string>::extract(pos++, vendor, defVal.vendor(), pExt);
                TypeHandler<std::string>::extract(pos++, os, defVal.os(), pExt);
                TypeHandler<std::string>::extract(pos++, desc, defVal.desc(), pExt);
                thingData.setUUID(Poco::UUID(uuid));
                thingData.setType(type);
                thingData.setName(name);
                thingData.setVendor(vendor);
                thingData.setOS(os);
                thingData.setDesc(desc);
            }
        private:
            TypeHandler();
            ~TypeHandler();
            TypeHandler(const TypeHandler&);
            TypeHandler& operator=(const TypeHandler&);
        };
    }
}
#endif	/* THINGDATA_H */

