/*
 * File:   ZakifApp.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */


#include "Main.h"
#include "Sniff/PcapSubsystem.h"
#include "Dissect/DissectSubsystem.h"
#include "Model/ModelSubsystem.h"
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
    logger().notice(mac.toString());
    waitForTerminationRequest();
    return EXIT_OK;
}

POCO_SERVER_MAIN(Main)