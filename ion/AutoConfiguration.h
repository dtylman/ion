/*
 * File:   AutoJSONConfiguration.h
 * Author: danny
 *
 * Created on February 2, 2015, 10:23 AM
 */

#ifndef AUTOCONFIGURATION_H
#define	AUTOCONFIGURATION_H

#include <Poco/Util/PropertyFileConfiguration.h>
#include <Poco/Path.h>
#include <Poco/Logger.h>
#include <Poco/DirectoryWatcher.h>
#include <string>

class AutoConfiguration : public Poco::Util::PropertyFileConfiguration
{
public:
    AutoConfiguration(const Poco::Path& folder, const std::string& fileName);
protected:
    virtual ~AutoConfiguration();
private:
    void onItemModified(const Poco::DirectoryWatcher::DirectoryEvent& event);
    void reload();
    std::string _configFile;
    Poco::DirectoryWatcher _watcher;
    Poco::Logger& _logger;
};

#endif	/* AUTOCONFIGURATION_H */

