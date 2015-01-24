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
    getSubsystem<PcapSubsystem>().start();
    waitForTerminationRequest();
    return EXIT_OK;
}

POCO_SERVER_MAIN(Main)