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
#include "Selfy.h"
#include "WebSubsystem.h"
#include "EventsSubsystem.h"
#include <iostream>
#include <Poco/Util/TimerTaskAdapter.h>
#include <Poco/Net/NetworkInterface.h>
#include <Poco/Util/SystemConfiguration.h>
#include <Poco/Util/PropertyFileConfiguration.h>

Main::Main()
{
    addSubsystem(new DataSubsystem());
    addSubsystem(new EventsSubsystem());
    addSubsystem(new DissectSubsystem());
    addSubsystem(new PcapSubsystem());
    addSubsystem(new WebSubsystem());
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
    Poco::Net::initializeNetwork();
    config().add(new Poco::Util::SystemConfiguration(), PRIO_SYSTEM);
    _config = new Poco::Util::PropertyFileConfiguration(configFileName());
    config().addWriteable(_config, PRIO_APPLICATION, true);
    Poco::Util::ServerApplication::initialize(self);
    unsigned interval = config().getUInt("ion.offline-interval", 10) * 60 * 1000;
    _timer.scheduleAtFixedRate(new Poco::Util::TimerTaskAdapter<Main>(*this, &Main::onOnlineScan), interval, interval);
}

void Main::uninitialize()
{
    Poco::Util::ServerApplication::uninitialize();
    Poco::Net::uninitializeNetwork();
}

void Main::onOnlineScan(Poco::Util::TimerTask& timerTask)
{
    try {
        _solicitator.solicitateOnline();
    }
    catch (Poco::Exception& ex) {
        logger().error("Exception on online scan", ex.displayText());
    }
}

std::string Main::configFileName() const
{
    Poco::Path path(config().getString("application.dir"));
    path.setFileName("ion.properties");
    return path.toString();
}

void Main::saveConfig()
{
    _config->save(configFileName());
    logger().notice("Saving configuration");
}


POCO_SERVER_MAIN(Main)
