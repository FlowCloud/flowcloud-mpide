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


#ifndef FLOW_NVS_H_
#define FLOW_NVS_H_

#include <stdbool.h>
#include <stddef.h>

#include "flow/core/client_type.h"


/**
 * \brief Initializes the Non Volatile Storage library.
 *
 * Called by \ref FlowCore_Initialise.
 *
 * @return true if successful, false otherwise
 */
bool FlowNVS_Initialise(void);

/**
 * \brief Sets a value in Non-Volatile-Storage.
 *
 * if \a value is NULL or \a size is 0, the value should be removed from NVS.
 *
 * @param key key that the value is mapping to
 * @param value binary buffer holding the value to store
 * @param size size of the buffer
 */
void FlowNVS_Set(const char *key, const void *value, size_t size);

/**
 * \brief Returns a newly allocated buffer containing the value for this key.
 *
 * The buffer should be allocated by \ref Flow_MemAlloc and freed by the caller using \ref Flow_MemFree.
 *
 * @param key key that the value is mapping to
 * @param[out] size pointer to the size of buffer that is returned
 * @return NULL if data could not be allocated or found for that key.
 */
void *FlowNVS_Get(const char *key, size_t *size);


bool FlowNVS_Read(size_t offset, void *value, size_t size);


bool FlowNVS_Write(size_t offset, const void *value, size_t size);

/**
 * \brief Frees the Non Volatile Storage library.
 *
 * Called by \ref FlowCore_Shutdown.
 */
void FlowNVS_Shutdown(void);


#endif /* FLOW_NVS_H_ */
