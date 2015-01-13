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

/*! \file flow_timer.h
 *  \brief LibFlowCore .
 */


#ifndef FLOW_TIMER_H_
#define FLOW_TIMER_H_

#include "flow/core/base_types.h"

/**
 * \class FlowTimer
 * Abstract timer from platform specific implementation
 */
typedef void *FlowTimer;

/**
 * \memberof FlowTimer
 * Timer callback function
 * @param context context passed to \ref FlowTimer_New
 */
typedef void (*FlowTimer_Callback)(FlowTimer self, void *context);


/**
 * \memberof FlowTimer
 * \brief Releases the identifier and resources allocated to a timer.
 *
 * @param self timer to free
 */
void FlowTimer_Free(FlowTimer *self);

/**
 * \memberof FlowTimer
 * \brief Get the number of ticks that have pass since library initialise
 *
 */
uint FlowTimer_GetTickCount(void);

/**
 * \memberof FlowTimer
 * \brief Get the number of tick per second for platform
 *
 */
uint FlowTimer_GetTicksPerSecond(void);

/**
 * \brief Initializes the timer library.
 *
 * Called by \ref FlowCore_Initialise.
 *
 */
void FlowTimer_Initialise(void);

/**
 * \memberof FlowTimer
 * \brief Create a new timer.
 *
 * @param name for debug purposes to identify thread.
 * @param periodInMilliseconds time period (milliseconds) after which \a runnable is called.
 * @param continuous whether it is a one shot or continuous calls \a runnable after period has elapsed.
 * @param runnable method that will be called after period has elapsed.
 * @param context parameter to pass to the \a runnable
 * @return the instance of the timer
 */
FlowTimer FlowTimer_New(const char *name, uint periodInMilliseconds, bool continuous, FlowTimer_Callback runnable, void *context);

/**
 * \memberof FlowTimer
 * \brief Reset/restart period on timer.
 *
 * @param self timer to reset
 */
bool FlowTimer_Reset(FlowTimer self);



/**
 * \memberof FlowTimer
 * \brief Change period on timer.
 *
 * @param self timer to change
 * @param periodInMilliseconds time period (milliseconds) after which timer will fire.
 */

bool FlowTimer_SetPeriod(FlowTimer self, uint periodInMilliseconds);

/**
 * \memberof FlowTimer
 * \brief Set the number of tick per second for platform
 *
 * @param ticks Ticks per scond
 */
void FlowTimer_SetTicksPerSecond(uint ticks);

/**
 * \memberof FlowTimer
 * \brief Start timer.
 *
 * @param self timer to start
 */
bool FlowTimer_Start(FlowTimer self);

/**
 * \memberof FlowTimer
 * \brief Stop timer.
 *
 * @param self timer to stop
 */
bool FlowTimer_Stop(FlowTimer self);


/**
 * \brief Frees the timer library.
 *
 * Called by \ref FlowCore_Shutdown.
 */
void FlowTimer_Shutdown(void);


#endif /* FLOW_TIMER_H_ */
