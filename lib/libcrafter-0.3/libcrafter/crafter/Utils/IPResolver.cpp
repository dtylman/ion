/*
Copyright (c) 2012, Esteban Pellegrino
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ESTEBAN PELLEGRINO BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "IPResolver.h"
#include "PrintMessage.h"

using namespace std;

/* Validate IPv4 address */
bool Crafter::validateIpv4Address(const std::string& ipAddress) {
	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	int result = inet_pton(AF_INET, ipAddress.c_str(), &(sa.sin_addr));
	return result != 0;
}

/* Validate IPv6 address */
bool Crafter::validateIpv6Address(const std::string& ipAddress) {
	struct sockaddr_in6 addr;
	int result = inet_pton(AF_INET6, ipAddress.c_str(), &addr.sin6_addr);
	return result != 0;
}

string Crafter::GetIP(const string& hostname) {
    /* We shoukd make a DNS query */
    struct addrinfo hints, *res;
    struct in_addr addr;
    int err;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;

    if ((err = getaddrinfo(hostname.c_str(), NULL, &hints, &res)) != 0) {
		PrintMessage(Crafter::PrintCodes::PrintWarningPerror,
				     "GetIPv4()","Error while resolving "+ hostname);
      return "";
    }

    /* Set the IP */
    addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;

    /* Get the IP address as a string */
    string ip_address (inet_ntoa(addr));

    freeaddrinfo(res);

    /* Return the address */
    return ip_address;
}

string Crafter::GetIPv6(const string& hostname) {
    struct addrinfo hints, *res;
    int err;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET6;

    if ((err = getaddrinfo(hostname.c_str(), NULL, &hints, &res)) != 0) {
		PrintMessage(Crafter::PrintCodes::PrintWarningPerror,
				     "GetIPv6()","Error while resolving "+ hostname);
      return "";
    }

    void* tmpAddrPtr = 0;

    /* Set the temp pointer */
    tmpAddrPtr = &((struct sockaddr_in6 *)res->ai_addr)->sin6_addr;

    char addressBuffer[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);

    freeaddrinfo(res);

    /* Return the address */
    return string(addressBuffer);
}

std::string Crafter::GetHostname(const std::string& ip_address) {
	/* Host and service name */
	char host[1024];
	char service[20];
	struct sockaddr_storage sa;
	size_t sa_len;

	memset(&sa, 0, sizeof(sa));
	/* Fill the sa structure with IP information */
	if (validateIpv4Address(ip_address)) {
		struct sockaddr_in *sin = (struct sockaddr_in *)&sa;
		sin->sin_family = AF_INET;
		sin->sin_addr.s_addr = inet_addr(ip_address.c_str());
		sa_len = sizeof(*sin);
	} else if (validateIpv6Address(ip_address)) {
		struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)&sa;
		sin6->sin6_family = AF_INET6;
		inet_pton(AF_INET6, ip_address.c_str(), &sin6->sin6_addr);
		sa_len = sizeof(*sin6);
	} else {
		return ip_address;
	}

	if (getnameinfo((struct sockaddr *)&sa, sa_len, host, sizeof(host), service, sizeof(service), 0) < 0)
		return ip_address;
	/* Make the inverse lookup */
	return string(host);
}
