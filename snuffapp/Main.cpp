/*
 * File:   ZakifApp.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */


#include "Main.h"
#include "PcapSubsystem.h"
#include "DissectSubsystem.h"
#include "ModelSubsystem.h"
#include "MAC.h"
#include "Arper.h"
#include "Injector.h"
#include "Arping.h"
#include <iostream>

Main::Main()
{
    addSubsystem(new ModelSubsystem());
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

    MAC mac("aa-bb:CC:03:04:05");
    logger().notice(MAC::Broadcast.toString());
    {
        //Injector injector("wlan0", Poco::Net::IPAddress("10.0.0.1"));
		Injector injector("\\Device\\NPF_{078C4C05-99A7-4B2E-A3E8-1F9544656015}", Poco::Net::IPAddress("10.0.0.1"));		
        {
            Arping arping(injector, Poco::Net::IPAddress("10.0.0.1"));
            arping.ping();
            logger().notice(arping.targetMAC().toString());
        }
        {
            Arping arping(injector, Poco::Net::IPAddress("192.168.10.1"));
            arping.ping();
            logger().notice(arping.targetMAC().toString());
        }
    }
    waitForTerminationRequest();
    return EXIT_OK;
}

POCO_SERVER_MAIN(Main)