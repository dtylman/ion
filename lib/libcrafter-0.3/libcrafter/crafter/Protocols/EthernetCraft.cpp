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

#include "Ethernet.h"
#include "RawLayer.h"

using namespace Crafter;
using namespace std;

void Ethernet::ReDefineActiveFields() {
}

void Ethernet::Craft() {
	/* Get transport layer protocol */
	if(TopLayer) {
		if(!IsFieldSet(FieldType)) {
			short_word network_layer = TopLayer->GetID();
			/* Set Protocol */
			if(network_layer != RawLayer::PROTO)
				SetType(network_layer);
			else
				SetType(0x0);

			ResetField(FieldType);
		}
	}
	else {
		PrintMessage(Crafter::PrintCodes::PrintWarning,
				     "Ethernet::Craft()","No Network Layer Protocol associated with Ethernet Layer.");
	}
}

void Ethernet::ParseLayerData(ParseInfo* info) {
	short_word network_layer = GetType();
	info->next_layer = Protocol::AccessFactory()->GetLayerByID(network_layer);
}
