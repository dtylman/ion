/*
 * File:   newsimpletest.cpp
 * Author: danny
 *
 * Created on Mar 10, 2015, 5:03:49 PM
 */

#include <stdlib.h>
#include <iostream>
#include "../ProtocolTCP.h"
#include <Poco/HexBinaryDecoder.h>
#include <Poco/FileStream.h>

/*
 * Simple C++ Test Suite
 */


void testDissect()
{
    Poco::FileInputStream fis("/tmp/tcp.raw");
    ProtocolTCP::Ptr tcp = new ProtocolTCP();

    FrameBuffer buffer(66);
    fis.read((char*) buffer.begin(), 66);
    Protocol::Ptr next = nullptr;
    size_t offset = 66 - 32;
    tcp->dissect(buffer, offset, next);
}

int main(int argc, char** argv)
{
    testDissect();
    return (EXIT_SUCCESS);
}

