/*
 * File:   PcapActivityFactory.cpp
 * Author: danny
 *
 * Created on January 20, 2015, 2:25 PM
 */

#include <Poco/Buffer.h>

#include "PcapActivityFactory.h"

PcapActivity* PcapActivityFactory::createActivity(pcap_if_t* iface)
{
    Poco::Logger& logger = Poco::Logger::get("pcap");
    Poco::Buffer<char> errBuf(PCAP_ERRBUF_SIZE);
    int snaplen = 1024;
    int timeout = 1000;
    pcap_t* pcap = pcap_open_live(iface->description, snaplen, true, timeout, errBuf.begin());
    if (pcap == nullptr) {
        logger.debug("Failed to open pcap iface: %s, error: %s", std::string(iface->description), std::string(errBuf.begin()));
        return nullptr;
    }
    return new PcapActivity(pcap);
}
