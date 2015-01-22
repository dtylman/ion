/*
 * File:   PcapActivity.cpp
 * Author: danny
 *
 * Created on January 19, 2015, 10:41 PM
 */

#include "PcapActivity.h"
#include "DissectSubsystem.h"
#include <Poco/Util/Application.h>

PcapActivity::PcapActivity(const std::string& device) :
_device(device),
_pcap(nullptr),
_activity(this, &PcapActivity::runActivity), _logger(Poco::Logger::get("PcapActivity"))
{
}

PcapActivity::~PcapActivity()
{    
}

static void pcap_process(u_char *device, const struct pcap_pkthdr *header, const u_char *bytes)
{
    DissectSubsystem& dissect = Poco::Util::Application::instance().getSubsystem<DissectSubsystem>();
    dissect.queueFrame(new Frame(std::string((char*) device), bytes, header->caplen));
}

void PcapActivity::runActivity()
{
    Ptr me(this, true); //make sure not being deleted while in loop
    _logger.notice("Activity started on %s", _device);
    openLive();
    while (!_activity.isStopped()) {
        if (pcap_loop(_pcap, -1, &pcap_process, (u_char*) _device.c_str()) != 0) {
            break;
        }
    }
    _logger.notice("Activity ended on %s", _device);
}

void PcapActivity::start()
{
    _activity.start();
}

void PcapActivity::openLive()
{
    Poco::Buffer<char> errBuff(PCAP_ERRBUF_SIZE);
    _pcap = pcap_create(_device.c_str(), errBuff.begin());
    if (_pcap == nullptr) {
        throw Poco::ApplicationException(Poco::format("Couldn't open device %s: %s", _device, std::string(errBuff.begin())));
    }
    int status = pcap_set_snaplen(_pcap, 1500);
    if (status < 0) {
        _logger.warning("Can't set pcap snaplen: %s", std::string(pcap_strerror(status)));
    }
    status = pcap_set_promisc(_pcap, 1);
    if (status < 0) {
        _logger.warning("Can't set pcap promiscuous mode: %s", std::string(pcap_strerror(status)));
    }
    status = pcap_set_timeout(_pcap, 2500);
    if (status < 0) {
        _logger.warning("Can't set pcap timeout: %s", std::string(pcap_strerror(status)));
    }
#ifdef POCO_OS_FAMILY_UNIX
    status = pcap_set_buffer_size(_pcap, 2097152); //2MB
#else
    status = pcap_setbuff(_pcap, 2097152); //2MB
#endif
    if (status < 0) {
        _logger.warning("Can't set pcap buffer size: %s", std::string(pcap_strerror(status)));
    }
    status = pcap_activate(_pcap);
    if (status < 0) {
        throw Poco::ApplicationException(Poco::format("Couldn't activate device %s: %s", _device, std::string(pcap_strerror(status))));
    }
}

void PcapActivity::stop()
{
    if (_activity.isRunning()) {
        pcap_breakloop(_pcap);
        _activity.wait(2500);
        _activity.stop();
        _activity.wait(5000);
    }
}
