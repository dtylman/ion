/*
 * File:   ZakifApp.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */


#include "Main.h"
#include "PcapSubsystem.h"
#include "DissectSubsystem.h"
#include "DataSubsystem.h"
#include "MAC.h"
#include "Injector.h"
#include "Arping.h"
#include "Routing.h"
#include "IPDataObserver.h"
#include "AutoJSONConfiguration.h"
#include "ThingDataObject.h"
#include "EventsSubsystem.h"
#include "Selfy.h"
#include <iostream>
#include <Poco/Util/TimerTaskAdapter.h>
#include <Poco/Net/NetworkInterface.h>

Main::Main()
{
    addSubsystem(new DataSubsystem());
    addSubsystem(new EventsSubsystem());
    addSubsystem(new DissectSubsystem());
    addSubsystem(new PcapSubsystem());
}

Main::~Main()
{
}

int Main::main(const std::vector<std::string>& args)
{
    PcapSubsystem& pcap = getSubsystem<PcapSubsystem>();
    pcap.start();
    Selfy selfy;
    selfy.report();
    _solicitator.solicitateAll();
    waitForTerminationRequest();
    return EXIT_OK;
}

void Main::initialize(Poco::Util::Application& self)
{
    loadConfiguration();
    Poco::Util::ServerApplication::initialize(self);
    unsigned interval = config().getUInt("ion.offline-interval", 10) * 60 * 1000;
    _timer.scheduleAtFixedRate(new Poco::Util::TimerTaskAdapter<Main>(*this, &Main::onOnlineScan), interval, interval);
}

void Main::onOnlineScan(Poco::Util::TimerTask& timerTask)
{
    _solicitator.solicitateOnline();
}

int Main::loadConfiguration(int priority)
{
    Poco::Path path = config().getString("application.configDir");
    path.pushDirectory("config");
    Poco::File file(path);
    file.createDirectories();
    config().setString("application.configDir", path.toString());
    config().add(new AutoJSONConfiguration(path, "ion.config.json"), priority);
    return 1;
}

POCO_SERVER_MAIN(Main)
