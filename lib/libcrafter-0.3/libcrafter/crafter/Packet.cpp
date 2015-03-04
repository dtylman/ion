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

#include <sstream>

#include "Packet.h"
#include "Crafter.h"
#include "Utils/RawSocket.h"

using namespace std;
using namespace Crafter;

pthread_mutex_t Packet::mutex_compile;

template<typename T>
static T fromString(const std::string& str) {
	std::istringstream s(str);
	T t;
	s >> t;
	return t;
}

template<typename T>
static std::string toString(const T& t) {
	std::ostringstream s;
	s << t;
	return s.str();
}

void Packet::HexDump(ostream& str) {
	if(!pre_crafted)
		Craft();
	size_t lSize = bytes_size;

	byte *pAddressIn = new byte[lSize];

	for (size_t i = 0 ; i < bytes_size  ; i++)
		pAddressIn[i] = raw_data[i];

	char szBuf[100];
	long lIndent = 1;
	long lOutLen, lIndex, lIndex2, lOutLen2;
	long lRelPos;
	struct { char *pData; unsigned long lSize; } buf;
	unsigned char *pTmp,ucTmp;
	unsigned char *pAddress = (unsigned char *)pAddressIn;

   buf.pData   = (char *)pAddress;
   buf.lSize   = lSize;

   while (buf.lSize > 0)
   {
      pTmp     = (unsigned char *)buf.pData;
      lOutLen  = (int)buf.lSize;
      if (lOutLen > 16)
          lOutLen = 16;

      // create a 64-character formatted output line:
      sprintf(szBuf, "                              "
                     "                      "
                     "    %08lX", (long unsigned int) (pTmp-pAddress));
      lOutLen2 = lOutLen;

      for(lIndex = 1+lIndent, lIndex2 = 53-15+lIndent, lRelPos = 0;
          lOutLen2;
          lOutLen2--, lIndex += 2, lIndex2++
         )
      {
         ucTmp = *pTmp++;

         sprintf(szBuf + lIndex, "%02X ", (unsigned short)ucTmp);
         if(!isprint(ucTmp))  ucTmp = '.'; // nonprintable char
         szBuf[lIndex2] = ucTmp;

         if (!(++lRelPos & 3))     // extra blank after 4 bytes
         {  lIndex++; szBuf[lIndex+2] = ' '; }
      }

      if (!(lRelPos & 3)) lIndex--;

      szBuf[lIndex  ]   = ' ';
      szBuf[lIndex+1]   = ' ';

      str << szBuf << endl;

      buf.pData   += lOutLen;
      buf.lSize   -= lOutLen;
   }

   delete [] pAddressIn;
}

/* Print Payload */
void Packet::RawString(ostream& str) {
	if(!pre_crafted)
		Craft();
	/* Print raw data in hexadecimal format */
	for(size_t i = 0 ; i < bytes_size ; i++) {
		str << "\\x";
		str << std::hex << (unsigned int)(raw_data)[i];
	}

	str << endl;
}

void Packet::Print(ostream& str) const {
	std::vector<Layer*>::const_iterator it_layer;

	for (it_layer = Stack.begin() ; it_layer != Stack.end() ; it_layer++)
		(*it_layer)->Print(str);
}

void Packet::Print() const {
	Print(std::cout);
}

void Packet::PushLayer(Layer* layer)
{
	Stack.push_back(layer);
	/* Update size of the packet */
	bytes_size += layer->GetSize();

	/* Get number of layers */
	size_t layers = Stack.size();
	if ((layers - 1) > 0) {
		layer->PushBottomLayer(Stack[(layers - 2)]);
		Stack[(layers - 2)]->PushTopLayer(layer);
	} else
		layer->PushBottomLayer(0);

	layer->PushTopLayer(0);
}

void Packet::PushLayer(const Layer& user_layer) {
	/* Create a new layer from the one that was supplied by the user */
	Layer* layer = Protocol::AccessFactory()->GetLayerByName(user_layer.GetName());

	/* Call = operator */
	(*layer) = user_layer;

	PushLayer(layer);
}

void Packet::PopLayer() {
	/* Get number of layers */
	size_t layers = Stack.size();

	if(layers > 0) {
		/* Get the top layer */
		Layer* top_layer = Stack[layers-1];

		/* Set the new top layer */
		if( (layers - 1) > 0) {
			Layer* new_top_layer = Stack[layers-2];
			new_top_layer->PushTopLayer(0);
		}

		/* Delete the pop layer */
		bytes_size -= top_layer->GetSize();
		/* Delete the last layer */
		delete top_layer;
		/* Pop back the pointer */
		Stack.pop_back();
	}
}

timeval Packet::GetTimestamp() const {
	return ts;
}

void Packet::SetTimestamp(timeval timestamp) {
	ts = timestamp;
}

Layer* Packet::operator[](size_t pos) {
	if(pos < Stack.size())
		return Stack[pos];
	else {
		Crafter::PrintMessage(Crafter::PrintCodes::PrintWarning,
				     "Packet::operator[]",
		             "Layer requested out of bounds.");
		return 0;
	}
}

const Layer* Packet::operator[](size_t pos) const {
	if(pos < Stack.size())
		return Stack[pos];
	else {
		Crafter::PrintMessage(Crafter::PrintCodes::PrintWarning,
				     "Packet::operator[]",
		             "Layer requested out of bounds.");
		return 0;
	}
}

Packet Packet::SubPacket(LayerStack::const_iterator begin, LayerStack::const_iterator end) const {
	Packet pck;
	LayerStack::const_iterator it = begin;
	for(; it != end ; it++)
		pck.PushLayer(*(*it));
	return pck;
}

Packet Packet::SubPacket(size_t begin, size_t end) const {
	Packet pck;
	for(size_t i = begin; i < end ; i++)
		pck.PushLayer(*(Stack[i]));
	return pck;
}

/* Copy Constructor */
Packet::Packet(const Packet& copy_packet) : raw_data(0), bytes_size(0), pre_crafted(0), ts(copy_packet.ts) {
	/* Push layer one by one */
	vector<Layer*>::const_iterator it_layer;
	for (it_layer = copy_packet.Stack.begin() ; it_layer != copy_packet.Stack.end() ; ++it_layer)
		PushLayer(*(*it_layer));

}

Packet::Packet(const byte* data, size_t length, short_word proto_id) : raw_data(0), bytes_size(0), pre_crafted(0) {
	GetFromLayer(data,length,proto_id);
}

Packet::Packet(const RawLayer& data, short_word proto_id) : raw_data(0), bytes_size(0), pre_crafted(0) {
	GetFromLayer(data.GetPayload().GetRawPointer(),data.GetSize(),proto_id);
}

Packet& Packet::operator=(const Packet& right) {
	/* Copy time stamp */
	ts = right.ts;

	/* Delete layer one by one */
	vector<Layer*>::iterator it_layer;
	for (it_layer = Stack.begin() ; it_layer != Stack.end() ; ++it_layer)
		delete (*it_layer);

	Stack.clear();

	if(raw_data) {
		delete [] raw_data;
		raw_data = 0;
	}

	/* Init the size in bytes of the packet */
	bytes_size = 0;

	vector<Layer*>::const_iterator it_const;

	/* Copy the Pre-Crafted flag */
	pre_crafted = right.pre_crafted;

	for (it_const = right.Stack.begin() ; it_const != right.Stack.end() ; ++it_const)
		PushLayer(*(*it_const));

	return *this;
}

Packet& Packet::operator=(const Layer& right) {
	/* Delete layer one by one */
	vector<Layer*>::iterator it_layer;
	for (it_layer = Stack.begin() ; it_layer != Stack.end() ; ++it_layer)
		delete (*it_layer);

	Stack.clear();

	if(raw_data) {
		delete [] raw_data;
		raw_data = 0;
	}

	/* Init the size in bytes of the packet */
	bytes_size = 0;
	/* Put the Pre-Crafted flag at zero */
	pre_crafted = 0;

	PushLayer(right);

	return *this;
}

/* Copy Constructor */
Packet::Packet(const Layer& copy_layer) : raw_data(0), bytes_size(0), pre_crafted(0) {
	/* Push layer one by one */
	PushLayer(copy_layer);
}

const Packet Packet::operator/(const Layer& right) const {
	Packet ret_packet;

	vector<Layer*>::const_iterator it_const;

	for (it_const = Stack.begin() ; it_const != Stack.end() ; ++it_const)
		ret_packet.PushLayer(*(*it_const));

	ret_packet.PushLayer(right);

	return ret_packet;
}

const Packet Packet::operator/(const Packet& right) const {
	Packet ret_packet;

	vector<Layer*>::const_iterator it_const;

	for (it_const = Stack.begin() ; it_const != Stack.end() ; ++it_const)
		ret_packet.PushLayer(*(*it_const));

	for (it_const = right.Stack.begin() ; it_const != right.Stack.end() ; ++it_const)
		ret_packet.PushLayer(*(*it_const));

	return ret_packet;
}

Packet& Packet::operator/=(const Layer& right) {
	PushLayer(right);
	return *this;
}

Packet& Packet::operator/=(const Packet& right) {
	vector<Layer*>::const_iterator it_const;

	for (it_const = right.Stack.begin() ; it_const != right.Stack.end() ; ++it_const)
		PushLayer(*(*it_const));

	return *this;
}

void Packet::PreCraft() {
	/* Craft the packet */
	Craft();
	pre_crafted = 1;
}

void Packet::Craft() {
	/* First remove bytes for the raw data */
	if (raw_data) {
		bytes_size = 0;
		delete [] raw_data;
	}

 	if (Stack.size() > 0) {
		/* Craft layer one by one */
		vector<Layer*>::reverse_iterator it_layer;
		for (it_layer = Stack.rbegin() ; it_layer != Stack.rend() ; ++it_layer)
			(*it_layer)->Craft();

		/* Datagram size, including data */
		bytes_size = Stack[0]->GetRemainingSize();

		/* Now, allocate bytes */
		raw_data = new byte[bytes_size];

		Stack[0]->GetData(raw_data);
	} else
		PrintMessage(Crafter::PrintCodes::PrintWarning,
				     "Packet::Craft()","No data in the packet. Nothing to craft.");

}

size_t Packet::GetData(byte* raw_ptr) {
	/* Craft the data */
	if(!pre_crafted)
		Craft();
 	if (Stack.size() > 0)
 		return Stack[0]->GetData(raw_ptr);
 	else
 		return 0;
}

const byte* Packet::GetRawPtr() {
	/* Craft the data */
	if(!pre_crafted)
		Craft();
	/* Return raw pointer */
	return raw_data;
}

const byte* Packet::GetBuffer() const {
	return raw_data;
}

/* Send a packet */
int Packet::Send(const string& iface) {
	/* Check the size of the stack */
	if(Stack.size() == 0) {

		PrintMessage(Crafter::PrintCodes::PrintWarning,
					 "Packet::Send()",
					 "Not data in the packet. ");
		return 0;

	 }

	/* Craft the packet, so we fill all the information needed */
	if(!pre_crafted)
		Craft();

	/* Get the ID of the first layer */
	word current_id = Stack[0]->GetID();

	/* ----------- Begin Critical area ---------------- */

	pthread_mutex_lock (&mutex_compile);

	/* Request a raw socket with this specific protocol */
	int raw = SocketSender::RequestSocket(iface,current_id);

	pthread_mutex_unlock (&mutex_compile);

	/* ------------ End Critical area ----------------- */

	/* Write the packet on the wire */
	return SocketSender::SendSocket(raw, current_id, raw_data, bytes_size);
}

/* Send a packet */
Packet* Packet::SendRecv(const string& iface, double timeout, int retry, const string& user_filter) {

	char libcap_errbuf[PCAP_ERRBUF_SIZE];      /* Error messages */

	/* Name of the device */
	const char* device = iface.c_str();
	/* Handle for the opened pcap session */
	pcap_t *handle;
	/* IP address of interface */
	bpf_u_int32 netp;
	/* Subnet mask of interface */
	bpf_u_int32 maskp;
	/* Compiled BPF filter */
	struct bpf_program fp;

	if(Stack.size() == 0) {

		PrintMessage(Crafter::PrintCodes::PrintWarning,
					 "Packet::SendRecv()",
					 "Not data in the packet. ");
		return 0;

	 }

	/* Craft the packet */
	if(!pre_crafted)
		Craft();

	word current_id = Stack[0]->GetID();

	/* ----------- Begin Critical area ---------------- */

	pthread_mutex_lock (&mutex_compile);

	/* Link layer object, or some unknown protocol */
	int raw = SocketSender::RequestSocket(iface,current_id);

	pthread_mutex_unlock (&mutex_compile);

	/* ------------ End Critical area ----------------- */

	if (current_id != Ethernet::PROTO &&
		current_id != IP::PROTO       &&
		current_id != IPv6::PROTO     && user_filter == " ") {

		/* Print a warning message */
		PrintMessage(Crafter::PrintCodes::PrintWarning,
					 "Packet::SendRecv()",
					 "The first layer in the stack (" + Stack[0]->GetName() + ") is not IP or Ethernet.");

		/* Write the packet on the wire */
		if(SocketSender::SendSocket(raw, current_id, raw_data, bytes_size) < 0) {
			PrintMessage(Crafter::PrintCodes::PrintWarningPerror,
						 "Packet::SendRecv()",
						 "Sending packet (PF_PACKET socket)");
		}

		return 0;

	}

	/* Set error buffer to 0 length string to check for warnings */
	libcap_errbuf[0] = 0;

	/* Open device for sniffing */
	handle = pcap_open_live (device,  /* device to sniff on */
						     BUFSIZ,  /* maximum number of bytes to capture per packet */
									  /* BUFSIZE is defined in pcap.h */
				                  1,  /* promisc - 1 to set card in promiscuous mode, 0 to not */
		        (int)1000.0*timeout,  /* to_ms - amount of time to perform packet capture in milliseconds */
									  /* 0 = sniff until error */
				      libcap_errbuf); /* error message buffer if something goes wrong */


	if (handle == NULL)
	  /* There was an error */
		throw std::runtime_error("Packet::SendRecv() : Listening device " + string(libcap_errbuf));

	if (strlen (libcap_errbuf) > 0) {
			PrintMessage(Crafter::PrintCodes::PrintWarning,
					     "Packet::SendRecv()",
			              string(libcap_errbuf));

	  libcap_errbuf[0] = 0;    /* re-set error buffer */
	}

	int link_type = pcap_datalink(handle);

	/* Get the IP subnet mask of the device, so we set a filter on it */
	if (pcap_lookupnet (device, &netp, &maskp, libcap_errbuf) == -1)
		throw std::runtime_error("Packet::SendRecv() : Error getting device information " + string(libcap_errbuf));

	string filter = "";

	/* Get the IP layer */
	IP* ipv4_layer = 0;
	IPv6* ipv6_layer = 0;
	LayerStack::iterator it_layer = Stack.begin() ;
	for (; it_layer != Stack.end() ; ++it_layer) {
		if ((*it_layer)->GetID() == IP::PROTO) {
			ipv4_layer = dynamic_cast<IP*>( (*it_layer) );
			break;
		}
		if ((*it_layer)->GetID() == IPv6::PROTO) {
			ipv6_layer = dynamic_cast<IPv6*>( (*it_layer) );
			break;
		}
	}

	if (user_filter == " ") {
		string check_icmp;

		if (ipv4_layer) {

			/* Match first 8 bytes of next layer, if any */
			Layer* next_layer;
			string extra = "";
			if(it_layer != Stack.end()) {
				/* Next layer on top of IP */
				next_layer = *it_layer;
				while(next_layer && next_layer->GetName().find("IP") != string::npos) next_layer = next_layer->GetTopLayer();

				/* Get offset to next layer (from the ICMP layer)*/
				word offset_icmp = ipv4_layer->GetHeaderLength() * 4 + 8;
				word rem_size = next_layer->GetRemainingSize();
				/* Get offset to next layer (on the packet) */
				word offset_packet = GetSize() - rem_size;

				if(rem_size >= 8) {
					word* raw_packet = reinterpret_cast<word*>(raw_data + offset_packet);
					word first_word  = raw_packet[0];
					word second_word = raw_packet[1];

					extra =  " and (icmp[" + toString(offset_icmp) + ":4] == "+ toString(ntohl(first_word)) +")" +
							 " and (icmp[" + toString(offset_icmp + 4) + ":4] == "+ toString(ntohl(second_word)) +")";
				}

			}

			check_icmp = "( ( (icmp[icmptype] == icmp-unreach) or (icmp[icmptype] == icmp-timxceed) or "
						 "    (icmp[icmptype] == icmp-paramprob) or (icmp[icmptype] == icmp-sourcequench) or "
						 "    (icmp[icmptype] == icmp-redirect) ) and (icmp[12:2] == " + toString(ipv4_layer->GetIdentification()) + " )" +
						 extra +
						 " ) ";

		} else if(ipv6_layer) {
			/* Match first 8 bytes of next layer, if any */
			Layer* next_layer;
			string extra = "";
			if(it_layer != Stack.end()) {
				/* Next layer on top of IP */
				it_layer++;
				next_layer = *(it_layer);

				/* Get offset to next layer (from the ICMP layer)*/
				word offset_icmp = ipv6_layer->GetSize() + 8;
				word rem_size = next_layer->GetRemainingSize();
				/* Get offset to next layer (on the packet) */
				word offset_packet = GetSize() - rem_size;

				if(rem_size >= 8) {
					word* raw_packet = reinterpret_cast<word*>(raw_data + offset_packet);
					word first_word  = raw_packet[0];
					word second_word = raw_packet[1];

					extra =  " and (ip6[" + toString(40 + offset_icmp) + ":4] == "+ toString(ntohl(first_word)) +")" +
							 " and (ip6[" + toString(40 + offset_icmp + 4) + ":4] == "+ toString(ntohl(second_word)) +")";
				}

			}

			check_icmp = "( ( (ip6[40] == 1) or (ip6[40] == 2) or "
						 "    (ip6[40] == 3) or (ip6[40] == 4) )  "
						 + extra +
						 " ) ";
		} else
			check_icmp = " ";

		vector<string> layer_filter;

		/* Construct the filter for matching packets */
		vector<Layer*>::iterator it_layer;

		for (it_layer = Stack.begin() ; it_layer != Stack.end(); it_layer++) {
			string str_filter = (*it_layer)->MatchFilter();
			if(str_filter != " ") layer_filter.push_back(str_filter);
		}

		filter = "(" + layer_filter[0];

		vector<string>::iterator it_f;

		for(it_f = layer_filter.begin() + 1 ; it_f != layer_filter.end() ; it_f++) {
			vector<string>::iterator last = it_f - 1;
			if ( (*it_f) != " " && (*last) != " " )
				filter += " and " + (*it_f);
			else if ( (*it_f) != " " && (*last) == " ")
				filter += (*it_f);
		}

		if (check_icmp != " ")
			filter += ") or " + check_icmp;
		else
			filter += ")";
	} else
		filter = user_filter;

	//cout << filter << endl;

	/* ----------- Begin Critical area ---------------- */

    pthread_mutex_lock (&mutex_compile);

	/* Compile the filter, so we can capture only stuff we are interested in */
	if (pcap_compile (handle, &fp, filter.c_str(), 0, maskp) == -1) {
		cerr << "[!] Bad filter expression -> " << filter << endl;
		throw std::runtime_error("Packet::SendRecv() : Error compiling the filter : " + string(pcap_geterr(handle)));
	}

	/* Set the filter for the device we have opened */
	if (pcap_setfilter (handle, &fp) == -1)
		throw std::runtime_error("Packet::SendRecv() : Setting filter : " + string(pcap_geterr (handle)));

	/* We'll be nice and free the memory used for the compiled filter */
	pcap_freecode(&fp);

    pthread_mutex_unlock (&mutex_compile);

	/* ------------ End Critical area ----------------- */

	int r = 0;

	Packet* match_packet = new Packet;

	int count = 0;
	int success = 0;

	while (count < retry) {

		/* Write the packet on the wire */
		if(SocketSender::SendSocket(raw, current_id, raw_data, bytes_size) < 0) {
			PrintMessage(Crafter::PrintCodes::PrintWarningPerror,
						 "Packet::SendRecv()",
						 "Sending packet ");
			return 0;
		}

		struct pcap_pkthdr *header;
		const u_char *packet;

		if ((r = pcap_next_ex (handle, &header, &packet)) <= 0) {
			if (r == -1) {
			  /* Pcap error */
				PrintMessage(Crafter::PrintCodes::PrintError,
						     "Packet::SendRecv()",
			                 "Error calling pcap_next_ex() " + string(pcap_geterr (handle)));
			  return 0;
			}
			/* Otherwise return should be -2 */
		}

		if (r >= 1) {
			match_packet->PacketFromLinkLayer(packet, header->len,link_type);
			success = 1;
			break;
		}

		count++;

	}

	pcap_close (handle);

	if (success)
		return match_packet;
	else {
		delete match_packet;
		return 0;
	}

}

int Packet::SocketSend(int sd) {
	if(Stack.size() == 0) {

		PrintMessage(Crafter::PrintCodes::PrintWarning,
					 "Packet::SendRecv()",
					 "Not data in the packet. ");
		return 0;

	 }

	/* Craft the packet */
	if(!pre_crafted)
		Craft();

	word current_id = Stack[0]->GetID();

	return SocketSender::SendSocket(sd,current_id,raw_data,bytes_size);
}

Packet* Packet::SocketSendRecv(int sd, const string& iface, double timeout, int retry, const string& user_filter) {
	char libcap_errbuf[PCAP_ERRBUF_SIZE];      /* Error messages */

	/* Name of the device */
	const char* device = iface.c_str();
	/* Handle for the opened pcap session */
	pcap_t *handle;
	/* IP address of interface */
	bpf_u_int32 netp;
	/* Subnet mask of interface */
	bpf_u_int32 maskp;
	/* Compiled BPF filter */
	struct bpf_program fp;

	if(Stack.size() == 0) {

		PrintMessage(Crafter::PrintCodes::PrintWarning,
					 "Packet::SendRecv()",
					 "Not data in the packet. ");
		return 0;

	 }

	/* Craft the packet */
	if(!pre_crafted)
		Craft();

	word current_id = Stack[0]->GetID();

	if (current_id != Ethernet::PROTO &&
		current_id != IP::PROTO       &&
		current_id != IPv6::PROTO     && user_filter == " ") {

		/* Print a warning message */
		PrintMessage(Crafter::PrintCodes::PrintWarning,
					 "Packet::SendRecv()",
					 "The first layer in the stack (" + Stack[0]->GetName() + ") is not IP or Ethernet.");

		/* Write the packet on the wire */
		if(	SocketSender::SendSocket(sd,current_id,raw_data,bytes_size) < 0) {
			PrintMessage(Crafter::PrintCodes::PrintWarningPerror,
						 "Packet::SendRecv()",
						 "Sending packet (PF_PACKET socket)");
		}

		return 0;

	}

	/* Set error buffer to 0 length string to check for warnings */
	libcap_errbuf[0] = 0;

	/* Open device for sniffing */
	handle = pcap_open_live (device,  /* device to sniff on */
						     BUFSIZ,  /* maximum number of bytes to capture per packet */
									  /* BUFSIZE is defined in pcap.h */
				                  1,  /* promisc - 1 to set card in promiscuous mode, 0 to not */
		        (int)1000.0*timeout,  /* to_ms - amount of time to perform packet capture in milliseconds */
									  /* 0 = sniff until error */
				      libcap_errbuf); /* error message buffer if something goes wrong */


	if (handle == NULL)
	  /* There was an error */
		throw std::runtime_error("Packet::SendRecv() : Listening device : " + string(libcap_errbuf));

	if (strlen (libcap_errbuf) > 0) {
			PrintMessage(Crafter::PrintCodes::PrintWarning,
					     "Packet::SendRecv()",
			              string(libcap_errbuf));

	  libcap_errbuf[0] = 0;    /* re-set error buffer */
	}

	int link_type = pcap_datalink(handle);

	/* Get the IP subnet mask of the device, so we set a filter on it */
	if (pcap_lookupnet (device, &netp, &maskp, libcap_errbuf) == -1)
		throw std::runtime_error("Packet::SendRecv() : Error getting device information " + string(libcap_errbuf));

	string filter = "";

	/* Get the IP layer */
	IP* ip_layer = 0;
	LayerStack::iterator it_layer = Stack.begin() ;
	for (; it_layer != Stack.end() ; ++it_layer) {
		if ((*it_layer)->GetName() == "IP") {
			ip_layer = dynamic_cast<IP*>( (*it_layer) );
			break;
		}
	}

	if (user_filter == " ") {
		string check_icmp;

		if (ip_layer) {

			/* Match first 8 bytes of next layer, if any */
			Layer* next_layer;
			string extra = "";
			if(it_layer != Stack.end()) {
				/* Next layer on top of IP */
				next_layer = *it_layer;
				while(next_layer && next_layer->GetName().find("IP") != string::npos) next_layer = next_layer->GetTopLayer();

				/* Get offset to next layer (from the ICMP layer)*/
				word offset_icmp = ip_layer->GetHeaderLength() * 4 + 8;
				word rem_size = next_layer->GetRemainingSize();
				/* Get offset to next layer (on the packet) */
				word offset_packet = GetSize() - rem_size;

				if(rem_size >= 8) {
					word* raw_packet = reinterpret_cast<word*>(raw_data + offset_packet);
					word first_word  = raw_packet[0];
					word second_word = raw_packet[1];

					extra =  " and (icmp[" + toString(offset_icmp) + ":4] == "+ toString(ntohl(first_word)) +")" +
							 " and (icmp[" + toString(offset_icmp + 4) + ":4] == "+ toString(ntohl(second_word)) +")";
				}

			}

			check_icmp = "( ( (icmp[icmptype] == icmp-unreach) or (icmp[icmptype] == icmp-timxceed) or "
						 "    (icmp[icmptype] == icmp-paramprob) or (icmp[icmptype] == icmp-sourcequench) or "
						 "    (icmp[icmptype] == icmp-redirect) ) and (icmp[12:2] == " + toString(ip_layer->GetIdentification()) + " )" +
						 extra +
						 " ) ";

		} else
			check_icmp = " ";

		vector<string> layer_filter;

		/* Construct the filter for matching packets */
		vector<Layer*>::iterator it_layer;

		for (it_layer = Stack.begin() ; it_layer != Stack.end(); it_layer++) {
			string str_filter = (*it_layer)->MatchFilter();
			if(str_filter != " ") layer_filter.push_back(str_filter);
		}

		filter = "(" + layer_filter[0];

		vector<string>::iterator it_f;

		for(it_f = layer_filter.begin() + 1 ; it_f != layer_filter.end() ; it_f++) {
			vector<string>::iterator last = it_f - 1;
			if ( (*it_f) != " " && (*last) != " " )
				filter += " and " + (*it_f);
			else if ( (*it_f) != " " && (*last) == " ")
				filter += (*it_f);
		}

		if (check_icmp != " ")
			filter += ") or " + check_icmp;
		else
			filter += ")";
	} else
		filter = user_filter;

	//cout << filter << endl;

	/* ----------- Begin Critical area ---------------- */

    pthread_mutex_lock (&mutex_compile);

	/* Compile the filter, so we can capture only stuff we are interested in */
	if (pcap_compile (handle, &fp, filter.c_str(), 0, maskp) == -1) {
		cerr << "[!] Bad filter expression -> " << filter << endl;
		throw std::runtime_error("Packet::SendRecv() : Error compiling the filter : " + string(pcap_geterr(handle)));
	}

	/* Set the filter for the device we have opened */
	if (pcap_setfilter (handle, &fp) == -1)
		throw std::runtime_error("Packet::SendRecv() : Error compiling the filter : Setting filter : " + string(pcap_geterr (handle)));

	/* We'll be nice and free the memory used for the compiled filter */
	pcap_freecode(&fp);

    pthread_mutex_unlock (&mutex_compile);

	/* ------------ End Critical area ----------------- */

	int r = 0;

	Packet* match_packet = new Packet;

	int count = 0;
	int success = 0;

	while (count < retry) {

		/* Write the packet on the wire */
		if(SocketSender::SendSocket(sd,current_id,raw_data,bytes_size) < 0) {
			PrintMessage(Crafter::PrintCodes::PrintWarningPerror,
						 "Packet::SendRecv()",
						 "Sending packet ");
			return 0;
		}

		struct pcap_pkthdr *header;
		const u_char *packet;

		if ((r = pcap_next_ex (handle, &header, &packet)) <= 0) {
			if (r == -1) {
			  /* Pcap error */
				PrintMessage(Crafter::PrintCodes::PrintError,
						     "Packet::SendRecv()",
			                 "Error calling pcap_next_ex() " + string(pcap_geterr (handle)));
			  return 0;
			}
			/* Otherwise return should be -2 */
		}

		if (r >= 1) {
			match_packet->PacketFromLinkLayer(packet, header->len,link_type);
			success = 1;
			break;
		}

		count++;

	}

	pcap_close (handle);

	if (success)
		return match_packet;
	else {
		delete match_packet;
		return 0;
	}
}

template<>
IPLayer* Packet::GetLayer<IPLayer>() const {
	/* Search layer one by one */
	LayerStack::const_iterator it_layer;
	for (it_layer = begin() ; it_layer != end() ; ++it_layer)
		if ((*it_layer)->GetID() == IP::PROTO || (*it_layer)->GetID() == IPv6::PROTO)
			return dynamic_cast<IPLayer*>( (*it_layer) );
	/* No requested layer, returns zero */
	return 0;
}

template<>
ICMPLayer* Packet::GetLayer<ICMPLayer>() const {
	/* Search layer one by one */
	LayerStack::const_iterator it_layer;
	for (it_layer = begin() ; it_layer != end() ; ++it_layer)
		if ((*it_layer)->GetID() == ICMP::PROTO || (*it_layer)->GetID() == ICMPv6::PROTO)
			return dynamic_cast<ICMPLayer*>( (*it_layer) );
	/* No requested layer, returns zero */
	return 0;
}

void Packet::InitMutex() {
    pthread_mutex_init(&Packet::mutex_compile, NULL);
}

void Packet::DestroyMutex() {
    pthread_mutex_destroy(&Packet::mutex_compile);
}

/* Destructor */
Packet::~Packet() {
	/* Delete layer one by one */
	vector<Layer*>::iterator it_layer;
	for (it_layer = Stack.begin() ; it_layer != Stack.end() ; ++it_layer)
		delete (*it_layer);

	Stack.clear();

	if(raw_data) {
		delete [] raw_data;
		raw_data = 0;
	}
}
