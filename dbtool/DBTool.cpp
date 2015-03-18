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
#include "TableServices.h"
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
    try {
        std::string dbFile = config().getString("dbfile", "ion.db");

        Poco::File file(dbFile);
        if (file.exists()) {
            if (config().hasOption("overwrite")) {
                logger().notice("Removing existing database file");
                file.remove(false);
            }
            else {
                logger().notice("DB file already exits");
                return EXIT_OK;
            }
        }
        Poco::Data::Session session(Poco::Data::SQLite::Connector::KEY, dbFile);
        session.setConnectionTimeout(30000); // 30 seconds
        session << "PRAGMA synchronous = OFF", now;
        session << "PRAGMA journal_mode = MEMORY", now;
        TableServices services(session);
        services.create();
        TableOUI oui(session);
        std::string ouifile = config().getString("ouifile", "oui.txt");
        oui.create(ouifile);
        TableOSDHCP dhcp(session);
        dhcp.create();
        Tables tables(session);
        tables.create();
    }
    catch (Poco::Exception& ex) {
        std::cerr << ex.displayText();
    }
    return EXIT_OK;
}

void DBTool::defineOptions(Poco::Util::OptionSet& options)
{
    Application::defineOptions(options);
    options.addOption(Option("help", "h", "display help ").required(false).repeatable(false).callback(OptionCallback<DBTool>(this, &DBTool::handleHelp)));
    options.addOption(Option("oui", "i", "oui file").repeatable(false).argument("name").binding("ouifile"));
    options.addOption(Option("svs", "s", "services file").repeatable(false).argument("name").binding("servicefile"));
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
