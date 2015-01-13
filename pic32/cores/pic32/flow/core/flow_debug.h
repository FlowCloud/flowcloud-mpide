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


#ifndef FLOW_DEBUG_H_
#define FLOW_DEBUG_H_

#include <stdbool.h>

typedef enum
{
	FlowLogLevel_None,
	FlowLogLevel_Error,
	FlowLogLevel_Warning,
	FlowLogLevel_Info,
	FlowLogLevel_Debug

} FlowLogLevel;

/**
 * \brief Initializes the log library.
 *
 * Called by \ref FlowCore_Initialise.
 *
 * @return
 */
bool FlowLog_Initialise(void);

/**
 * \brief Frees the log library.
 *
 * Called by \ref FlowCore_Shutdown.
 */
void FlowLog_Shutdown(void);

/**
 * \brief Set logging level.
 *
 * @param level to log (messages with a higher level can be ignored)
 */
void FlowLog_SetLevel(FlowLogLevel level);

#ifdef FLOW_DEBUG_ON

#include <stdarg.h>
/**
 * \brief Called to check that no programmation error was encountered.
 *
 * @param assertion 0 if there is an error, non-0 otherwise
 * @param message printf-formatted message
 */
void Flow_Assert(int assertion, char *message, ...);

/**
 * \brief Logs a message.
 *
 * @param level importance of the message
 * @param message printf-formatted message
 */
void Flow_Log(FlowLogLevel level, char *message, ...);
//for internal calls from Flow_Assert to FlowLog
void Flow_Logv(FlowLogLevel level, char *message, va_list vl);

#else

#define Flow_Assert(assertion, message, ...) 	while(0) {}
#define Flow_Log(level, message, ...) 			while(0) {}
#define Flow_Logv(level, message, vl) 			while(0) {}

#endif



#endif /* FLOW_DEBUG_H_ */
