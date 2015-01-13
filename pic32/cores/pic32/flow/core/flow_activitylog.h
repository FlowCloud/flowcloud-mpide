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

#ifndef FLOW_ACTIVITYLOG_H_
#define FLOW_ACTIVITYLOG_H_

#include <stdbool.h>
#include <stdarg.h>
#include "flow/core/base_types.h"


#define	FLOW_ACTIVITY_ERRORCODE_NONE	0

typedef enum
{
	FlowActivityLogLevel_None = 0,
	FlowActivityLogLevel_Error,
	FlowActivityLogLevel_Warning,
	FlowActivityLogLevel_Information,
	FlowActivityLogLevel_Debug,
	FlowActivityLogLevel_Max
} FlowActivityLogLevel;

typedef enum
{
	FlowActivityLogCategory_HardwareBoot = 0,
	FlowActivityLogCategory_Startup,
	FlowActivityLogCategory_SystemRuntime,
	FlowActivityLogCategory_App,
	FlowActivityLogCategory_Shutdown,
	FlowActivityLogCategory_Max
} FlowActivityLogCategory;


typedef void (*FlowActivity_LogHandler)(FlowActivityLogLevel level, FlowActivityLogCategory category, int errorCode, char *message, va_list vl);


void FlowActivity_SetLogLevel(FlowActivityLogLevel level);

/**
 * \brief Logs an activity message. Activity messages are stored if logging is enabled for the level and category.
 *
 * @param level importance ofs the message
 * @param category of the message
 * @param message printf-formatted message
 *
 * @return true if message was stored in the activity log
 */
void FlowActivity_Log(FlowActivityLogLevel level, FlowActivityLogCategory category, int errorCode, char *message, ...);

void FlowActivity_SetLogHandler(FlowActivity_LogHandler handler);

#endif /* FLOW_ACTIVITYLOG_H_ */
