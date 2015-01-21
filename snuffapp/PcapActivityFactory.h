/*
 * File:   PcapActivityFactory.h
 * Author: danny
 *
 * Created on January 20, 2015, 2:25 PM
 */

#ifndef PCAPACTIVITYFACTORY_H
#define	PCAPACTIVITYFACTORY_H

#include "PcapActivity.h"
#include <pcap.h>

class PcapActivityFactory
{
public:
    static PcapActivity* createActivity(pcap_if_t *iface);

};

#endif	/* PCAPACTIVITYFACTORY_H */

