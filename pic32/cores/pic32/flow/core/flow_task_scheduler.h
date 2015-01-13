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


#ifndef FLOW_TASK_SCHEDULER_H_
#define FLOW_TASK_SCHEDULER_H_

#include "flow/core/base_types.h"

typedef uint FlowTaskID;

/**
 * Task to execute.
 *
 * @param taskID identifier of executing task
 * @param context value of context passed to \ref FlowScheduler_ScheduleTask.
 */
typedef void (*FlowScheduler_TaskCallback)(FlowTaskID taskID, void *context);

#define FLOW_TASKID_INVALID (0)

/**
 * \brief Initializes the task scheduler library.
 *
 * Called by \ref FlowCore_Initialise.
 *
 * @return true if successful, false otherwise
 */
bool FlowScheduler_Initialise(void);

/**
 * Schedule a task for execution.
 *
 * @param executor the method that will execute the task
 * @param context context pointer that will be passed to \a executor
 * @param delayBeforeExecution delay in second before the execution must be triggered
 * @param continuous if true, the task will be executed every \a delayBeforeExecution
 * @return the identifier of the task
 */
FlowTaskID FlowScheduler_ScheduleTask(FlowScheduler_TaskCallback executor, void *context, ulong delayBeforeExecution, bool continuous);

/**
 * \brief Removes a task from scheduling.
 *
 * If the task is already executing as this gets called, the task will finish its execution nonetheless.
 * However further recurrences of the task will be cancelled.
 *
 * @param taskID the identifier returned by \ref FlowScheduler_ScheduleTask
 */
void FlowScheduler_UnscheduleTask(FlowTaskID taskID);

/**
 * \brief Frees the task scheduler library.
 *
 * Called by \ref FlowCore_Shutdown.
 */
void FlowScheduler_Shutdown(void);


#endif /* FLOW_TASK_SCHEDULER_H_ */
