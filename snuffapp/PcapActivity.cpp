/*
 * File:   PcapActivity.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:41 PM
 */

#include "PcapActivity.h"
#include "EtherFrame.h"
#include "IPFrame.h"
#include <Poco/Buffer.h>

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
            _logger.error("pcap_next_ex returned error");
            return;
        }
        if (packet != nullptr) {
            Frame::Ptr frame(EtherFrame::createFrame((const char*) packet, header->len));
            if (!frame.isNull()) {
                Poco::AutoPtr<IPFrame> ipFrame = frame.cast<IPFrame>();
                if (!ipFrame.isNull()) {
                    _logger.notice(ipFrame->toString());
                }
            }
        }
        _logger.notice("got packet");
    }
}

