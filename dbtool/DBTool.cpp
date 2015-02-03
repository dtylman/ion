/*
 * File:   DBTool.cpp
 * Author: danny
 *
 * Created on February 3, 2015, 8:56 AM
 */

#include "DBTool.h"
#include "TableOUI.h"
#include "TableOSDHCP.h"
#include "Tables.h"
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/File.h>

using namespace Poco::Data::Keywords;
using Poco::Util::OptionCallback;
using Poco::Util::Option;
using Poco::Util::HelpFormatter;

DBTool::DBTool()
{
}

DBTool::~DBTool()
{
}

void DBTool::initialize(Poco::Util::Application& self)
{
    Poco::Data::SQLite::Connector::registerConnector();
}

int DBTool::main(const std::vector<std::string>& args)
{
    if (config().hasOption("dbfile")) {
        std::string dbFile = config().getString("dbfile");
        if (config().hasOption("overwrite")) {
            Poco::File file(dbFile);
            if (file.exists()) {
                logger().notice("Removing existing database file");
                file.remove(false);
            }
        }
        Poco::Data::Session session(Poco::Data::SQLite::Connector::KEY, dbFile);
        session.setConnectionTimeout(30000); // 30 seconds
        session << "PRAGMA synchronous = OFF", now;
        session << "PRAGMA journal_mode = MEMORY", now;
        TableOUI oui(session);
        std::string ouifile = config().getString("ouifile");
        oui.create(ouifile);
        TableOSDHCP dhcp(session);
        dhcp.create();
        Tables tables(session);
        tables.create();

    }
    else {
        std::cout << "Missing parameters. Try -h or /?" << std::endl;
    }
}

void DBTool::defineOptions(Poco::Util::OptionSet& options)
{
    Application::defineOptions(options);
    options.addOption(Option("help", "h", "display help ").required(false).repeatable(false).callback(OptionCallback<DBTool>(this, &DBTool::handleHelp)));
    options.addOption(Option("oui", "i", "oui file").repeatable(false).argument("name").binding("ouifile"));
    options.addOption(Option("db", "o", "db file").repeatable(false).argument("name").binding("dbfile"));
    options.addOption(Option("overwrite", "o", "overwrite existing db file").repeatable(false).binding("overwrite"));
}

void DBTool::handleHelp(const std::string& name, const std::string& value)
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.format(std::cout);
    stopOptionsProcessing();
    exit(EXIT_USAGE);
}

POCO_APP_MAIN(DBTool)
