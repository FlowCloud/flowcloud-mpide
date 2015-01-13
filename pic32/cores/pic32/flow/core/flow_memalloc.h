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


#ifndef FLOW_MEMALLOC_H_
#define FLOW_MEMALLOC_H_

#include <stddef.h>

/**
 * \brief Returns a newly allocated buffer of \a size bytes.
 *
 * @param size number of bytes that the buffer should return
 * @return NULL if that buffer couldn't be allocated
 */
void *Flow_MemAlloc(size_t size);

/**
 * \brief Returns a newly allocated and cleared buffer of \a blockCount * \a blockSize bytes.
 *
 * @param blockCount number of memory blocks to be returned
 * @param blockSize of each memory block to be returned
 * @return NULL if that buffer couldn't be allocated
 */
void *Flow_MemCalloc(size_t blockCount, size_t blockSize);

/**
 * \brief Resizes a previously allocated buffer to the new size \a size.
 *
 * \note if NULL is returned, buffer will not be freed.
 * i.e. do not overwrite buffer with the return value straight away or
 * you will leak memory when the resize fails.
 *
 * @param buffer buffer previously allocated by \ref Flow_MemAlloc
 * @param size expected new size of the result buffer
 * @return NULL if that buffer couldn't be allocated or resized
 */
void *Flow_MemRealloc(void *buffer, size_t size);

/**
 * Free a previously allocated buffer and set buffer pointer to NULL
 *
 * @param buffer buffer to free
 */
void Flow_MemFree(void **buffer);

/**
 * Free a previously allocated buffer
 *
 * @param buffer buffer to free
 */
void Flow_MemSafeFree(void *buffer);


#endif /* FLOW_MEMALLOC_H_ */
