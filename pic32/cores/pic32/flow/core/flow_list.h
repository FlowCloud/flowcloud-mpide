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

#ifndef FLOW_LIST_H_
#define FLOW_LIST_H_

#include "flow/core/base_types.h"

/**
 * \class FlowList
 * Generic List implementation
 */
typedef struct FlowListImpl *FlowList;

/**
 * \memberof FlowList
 * Add item to list.
 *
 * @param self list add to
 * @param item item to add to list
 */
bool FlowList_Add(FlowList self, void *item);

/**
 * \memberof FlowList
 * Check if item is already in list.
 *
 * @param self list to check
 * @param item item to find
 */
bool FlowList_Contains(FlowList self, void *item);


void FlowList_Free(FlowList *self, bool freeItems);

/**
 * \memberof FlowList
 * Get number of items in list.
 *
 * @param self list to check
 */
uint FlowList_GetCount(FlowList self);

/**
 * \memberof FlowList
 * Retrieve selected items from list.
 *
 * @param self list to check
 * @param index index of item in list
 */
void *FlowList_GetItem(FlowList self, uint index);

/**
 * \memberof FlowList
 * Create new instance of a list.
 *
 * @param initialCapacity initial number of items that can be added before list will need to grow
 */
FlowList FlowList_New(uint initialCapacity);

/**
 * \memberof FlowList
 * Remove item from list.
 *
 * @param self list to remove item from
 * @param item item to remove from list
 */
bool FlowList_Remove(FlowList self, void *item);

/**
 * \memberof FlowList
 * Remove selected items from list.
 *
 * @param self list to check
 * @param index index of item in list
 */
void *FlowList_RemoveAt(FlowList self, uint index);

#endif /* FLOW_LIST_H_ */
