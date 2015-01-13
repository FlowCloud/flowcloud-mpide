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


#ifndef FLOW_MEMORYMANAGER_METHODS_H_
#define FLOW_MEMORYMANAGER_METHODS_H_


#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/client_type.h"
#include "flow/core/api_type.h"
#include "flow/core/flow_object.h"


/**
 * \memberof FlowMemoryManager
 * \brief Attach an Flow object to the memoryManager so it can take care of freeing it.
 *
 * This attaches the object to the memoryManager which takes care of freeing the memory associated with that object.
 */
bool FlowMemoryManager_AttachObject(FlowMemoryManager memoryManager, FlowObject object);

/**
 * \memberof FlowMemoryManager
 * \brief Attach an pointer to the memoryManager so it can take care of freeing it.
 *
 * This attaches the pointer to the memoryManager which takes care of freeing the memory associated with that pointer.
 */
bool FlowMemoryManager_AttachPointer(FlowMemoryManager self, void *pointer);


/**
 * \memberof FlowMemoryManager
 * \brief Detach an Flow object from the memoryManager so it will not freeing it.
 *
 * This detaches the object from memoryManager so it will not free the memory associated with that object.
 */
bool FlowMemoryManager_DetachObject(FlowMemoryManager self, FlowObject *object);

/**
 * \memberof FlowMemoryManager
 * \brief Detach an pointer from the memoryManager so it will not freeing it.
 *
 * This detaches the pointer from memoryManager so it will not free the memory associated with that pointer.
 */
bool FlowMemoryManager_DetachPointer(FlowMemoryManager self, void *pointer);

/**
 * \memberof FlowMemoryManager
 * \brief Terminates a memoryManager and free resources attached to it.
 *
 * All values returned within that memoryManager's scope will become invalid.
 *
 * @param self pointer to the memoryManager to terminate
 */
void FlowMemoryManager_Free(FlowMemoryManager *self);

/**
 * \memberof FlowMemoryManager
 * \brief Create a new memoryManager.
 * @return a new memoryManager
 */
FlowMemoryManager FlowMemoryManager_New(void);


FlowObject FlowMemoryManager_NewObject(FlowMemoryManager memoryManager, uint8 propertyCount, uint8 linkCount, FlowType type);


#endif /* FLOW_JOB_METHODS_H_ */
