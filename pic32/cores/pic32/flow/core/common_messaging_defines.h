/****************************************************************************
 Copyright (c) 2014, Imagination Technologies Limited
 All rights reserved.

 Redistribution and use of the Software in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

     1. The Software (including after any modifications that you make to it) must support the FlowCloud Web Service API provided by Licensor and accessible at  http://ws-uat.flowworld.com and/or some other location(s) that we specify.

     2. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

     3. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

     4. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this Software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#ifndef  _H_FLOW_SIPCMP_COMON_H_
#define  _H_FLOW_SIPCMP_COMON_H_

#include "flow/core/flow_debug.h"
#include "flow/core/base_types.h"


#define FLOW_TCP         1
#define FLOW_TLS         2
#define FLOW_UDP         3
#define FLOW_MAX_CONNECTIONS  3
#define FLOW_MAX_PACKET_LEN   1500
#define FLOW_COMMON_MESSAGING_SUCCESS 1
#define FLOW_COMMON_MESSAGING_FAIL 0
#define CMP_TASK_STACK_SIZE  0	// Beware - SIP callbacks can send SSL messages!
#define CMP_TASK_PRIORITY  2

//#define COMMON_MESSAGING_DEBUG
#ifdef COMMON_MESSAGING_DEBUG
#define COMMON_MESSAGING_LOG Flow_Log
#else
#define COMMON_MESSAGING_LOG(level, format, ...)   while(0) {}
#endif

typedef enum
{
	FlowCommonMessaging_CallbackEventType_Response,
	FlowCommonMessaging_CallbackEventType_Header,
	FlowCommonMessaging_CallbackEventType_HeaderEnd,
	FlowCommonMessaging_CallbackEventType_Data,
	FlowCommonMessaging_CallbackEventType_Finished,
	FlowCommonMessaging_CallbackEventType_NetworkFailure
} FlowCommonMessaging_CallbackEventType;

typedef void (*FlowCommonMessaging_ProtocolCallBack)(FlowCommonMessaging_CallbackEventType callbackEvent, char *headerName, char *value, int length, void *context);



typedef struct
{
	uint32 ConnectionSourceAddress;
	uint32 ConnectionDestinationAddress;
	ushort ConnectionSourcePort;
	ushort ConnectionDestinationPort;
	bool SendRecoveryEnabled;
	uchar ConnectionTransportType;
	char *TLSCertificateData;
} FlowCommonMessaging_ConnectionInformation;

#endif

