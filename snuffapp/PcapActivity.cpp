/*
 * File:   PcapActivity.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:41 PM
 */

#include "PcapActivity.h"

PcapActivity::PcapActivity(pcap_t* pcap) :
_pcap(pcap),
_activity(this, &PcapActivity::runActivity), _logger(Poco::Logger::get("PcapActivity"))
{
    _activity.start();
}

PcapActivity::~PcapActivity()
{
    _activity.stop();
}

void PcapActivity::runActivity()
{
    while (!_activity.isStopped()) {
        const u_char* packet = nullptr;
        pcap_pkthdr* header;
        int ret = pcap_next_ex(_pcap, &header, &packet);
        if (ret == -1) {
            //error!
            return;
        }
        _logger.notice("got packet");
    }
}

