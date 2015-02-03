/*
 * File:   AutoJSONConfiguration.h
 * Author: danny
 *
 * Created on February 2, 2015, 10:23 AM
 */

#ifndef AUTOJSONCONFIGURATION_H
#define	AUTOJSONCONFIGURATION_H

#include <Poco/Util/JSONConfiguration.h>
#include <Poco/Path.h>
#include <Poco/Logger.h>
#include <Poco/DirectoryWatcher.h>
#include <string>

class AutoJSONConfiguration : public Poco::Util::JSONConfiguration
{
public:
    AutoJSONConfiguration(const Poco::Path& folder, const std::string& fileName);
protected:
    virtual ~AutoJSONConfiguration();
private:
    void onItemModified(const Poco::DirectoryWatcher::DirectoryEvent& event);
    void reload();
    std::string _configFile;
    Poco::DirectoryWatcher _watcher;
    Poco::Logger& _logger;
};

#endif	/* AUTOJSONCONFIGURATION_H */
