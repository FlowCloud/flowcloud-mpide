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
#ifndef FLOW_THREADING_H_
#define FLOW_THREADING_H_

#include <stdbool.h>
#include "flow/core/base_types.h"
#include "flow/core/errortype.h"

/**
 * \class FlowSemaphore
 * Abstract semaphore from platform specific implementation
 */
typedef void *FlowSemaphore;

/**
 * \memberof FlowSemaphore
 * Creates a new semaphore.
 *
 * @param tokensTotal number of tokens this semaphore has
 * @param tokensTaken number of tokens that are already taken from the semaphore
 * @return the handler to the semaphore
 */
FlowSemaphore FlowSemaphore_New(uint tokensTotal, uint tokensTaken);

/**
 * \memberof FlowSemaphore
 * Waits until \a tokens can be taken from the semaphore.
 *
 * @param self semaphore to take tokens from
 * @param tokens number of tokens to take from \a self
 */
void FlowSemaphore_Wait(FlowSemaphore self, uint tokens);

/**
 * \memberof FlowSemaphore
 * Waits up to specified timeout until \a tokens can be taken from the semaphore.
 *
 * @param self semaphore to take tokens from
 * @param tokens number of tokens to take from \a self
 * @param milliseconds number of milliseconds to wait for
 * @return whether successfully obtained semaphore
 */
bool FlowSemaphore_WaitFor(FlowSemaphore self, uint tokens, uint milliseconds);

/**
 * \memberof FlowSemaphore
 * Releases \a tokens into the semaphore.
 *
 * @param self semaphore to release tokens from
 * @param tokens number of tokens to release from \a self
 */
void FlowSemaphore_Release(FlowSemaphore self, uint tokens);

/**
 * \memberof FlowSemaphore
 * Frees the resources allocated to a given semaphore.
 *
 * @param self semaphore to free
 */
void FlowSemaphore_Free(FlowSemaphore *self);



/**
 * \class FlowThread
 * Abstract threading from platform specific implementation
 */
typedef void *FlowThread;

/**
 * \memberof FlowThread
 * Thread main method
 * @param thread thread callback is runnning on
 * @param context context passed to \ref FlowThread_New
 */
typedef void (*FlowThread_Callback)(FlowThread thread, void *context);

/**
 * \brief Clear error state for current Thread.
 *
 */
void FlowThread_ClearLastError(void);

/**
 * \memberof FlowThread
 * \brief Releases the identifier and resources allocated to a thread.
 *
 * @param self thread to free
 */
void FlowThread_Free(FlowThread *self);

/**
 * \brief Provides the error that the current Thread encountered, if any.
 *
 * @return the error status (\ref FlowError_NoError if not error)
 */
FlowErrorType FlowThread_GetLastError(void);


/**
 * \memberof FlowThread
 * \brief Return ID for thread (passing NULL defaults to current Thread).
 *
 * @param self Thread to get ID for (passing NULL defaults to current Thread).
 * @return the error status (\ref FlowError_NoError if not error)
 */
uint FlowThread_GetThreadID(FlowThread self);

/**
 * \brief Wait for a thread to complete.
 *
 * @param self thread to wait for
 */
void FlowThread_Join(FlowThread self);

/**
 * \memberof FlowThread
 * \brief Create a new thread that will start immediately.
 *
 * @param name for debug purposes to identify thread.
 * @param priority used to determine amount of CPU time this thread receives.
 * @param stackSize method that will be used as main method of the new thread.
 * @param runnable method that will be used as main method of the new thread.
 * @param context parameter to pass to the \a runnable
 * @return the instance of the thread
 */
FlowThread FlowThread_New(const char *name, uint priority, uint stackSize, FlowThread_Callback runnable, void *context);


/**
 * \brief Set the error that the current Thread has encountered.
 *
 */
void FlowThread_SetError(FlowErrorType error);

/**
 * \memberof FlowThread
 * \brief Makes the current thread (which must be passed in parameter) sleep.
 *
 * @param self id of the current thread
 * @param seconds number of seconds to sleep for
 * @return true if interrupted, false otherwise
 */
bool FlowThread_Sleep(FlowThread self, uint seconds);

/**
 * \memberof FlowThread
 * \brief Makes the current thread (which must be passed in parameter) sleep.
 *
 * @param self id of the current thread
 * @param milliseconds number of milliseconds to sleep for
 * @return true if interrupted, false otherwise
 */
bool FlowThread_SleepMilliseconds(FlowThread self, uint milliseconds);

/**
 * \memberof FlowThread
 * \brief Makes the current thread (which must be passed in parameter) sleep.
 *
 * @param self id of the current thread
 * @param ticks number of ticks to sleep for
 * @return true if interrupted, false otherwise
 */
bool FlowThread_SleepTicks(FlowThread self, uint ticks);

/**
 * \brief Wake up a thread that was previously sent to sleep by \ref FlowThread_Sleep.
 *
 * @param self thread to wake up
 */
void FlowThread_Wakeup(FlowThread self);

#endif /* FLOW_THREADING_H_ */
