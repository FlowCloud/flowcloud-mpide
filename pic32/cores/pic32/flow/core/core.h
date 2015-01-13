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
/** @file */

#ifndef FLOW_CORE_CORE_H_
#define FLOW_CORE_CORE_H_
#include "flow/core/base_types.h"
#include "flow/core/client_type.h"

/**
 * \brief Initializes libflow.
 * 
 * Initializes libflow and seeds the random number generator. If you are going to stop and restart libflow multiple times in the same process lifetime, you should use \ref FlowCore_InitialiseLibOnly. \n Until this method is called, all other libflow calls are unsafe.
*/
bool FlowCore_Initialise(void);
/**
 * \brief Initializes libflow.
 * 
 * Initializes libflow core and its dependencies only. Differs from \ref FlowCore_Initialise only in not seeding the random number generator. \n Until this method is called, all other libflow calls are unsafe.
*/
bool FlowCore_InitialiseLibOnly(void);
/**
 * \brief Shutdowns libflow.
 * 
 * Shutdowns libflow core and its dependencies. All libflow calls are unsafe after calling this method (except for \ref FlowCore_Initialise and \ref FlowCore_InitialiseLibOnly).
*/
void FlowCore_Shutdown(void);


		
#endif /* FLOW_CORE_CORE_H_ */
