/*
 * File:   AutoJSONConfiguration.cpp
 * Author: danny
 *
 * Created on February 2, 2015, 10:23 AM
 */

#include "AutoConfiguration.h"
#include <Poco/File.h>
#include <Poco/Delegate.h>
#include <Poco/Util/LoggingConfigurator.h>
#include <Poco/Util/Application.h>

AutoConfiguration::AutoConfiguration(const Poco::Path& folder, const std::string& fileName) :
_watcher(folder),
_logger(Poco::Logger::get("AutoConfiguration"))
{
    Poco::Path filePath = folder;
    filePath.setFileName(fileName);
    Poco::File file(filePath);
    if (file.exists() && file.canRead()) {
        _configFile = filePath.absolute().toString();
        reload();
    }
    _watcher.itemModified += Poco::delegate(this, &AutoConfiguration::onItemModified);
    _watcher.itemAdded += Poco::delegate(this, &AutoConfiguration::onItemModified);
}

AutoConfiguration::~AutoConfiguration()
{
}

void AutoConfiguration::onItemModified(const Poco::DirectoryWatcher::DirectoryEvent& event)
{
    if (event.item.path() == _configFile) {
        _logger.notice("%s changed", _configFile);
        reload();
    }
}

void AutoConfiguration::reload()
{
    try {
        clear();
        _logger.notice("Loading configuration from %s", _configFile);
        load(_configFile);
        Poco::Util::LoggingConfigurator().configure(&Poco::Util::Application::instance().config());
    }
    catch (Poco::Exception& ex) {
        _logger.error("Failed to load configuration file: %s", ex.displayText());
    }
}
