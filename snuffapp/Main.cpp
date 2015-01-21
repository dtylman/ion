/*
 * File:   ZakifApp.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:33 PM
 */


#include "Main.h"
#include "PcapSubsystem.h"

#include <iostream>

Main::Main()
{
    addSubsystem(new PcapSubsystem());
}

Main::~Main()
{
}

int Main::main(const std::vector<std::string>& args)
{
    waitForTerminationRequest();
    return EXIT_OK;
}

POCO_SERVER_MAIN(Main)