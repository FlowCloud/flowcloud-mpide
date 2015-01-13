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

/*! \file flow_object_methods.h
 *  \brief LibFlowCore .
 */


#ifndef FLOW_OBJECT_METHODS_H_
#define FLOW_OBJECT_METHODS_H_

#include "flow/core/base_types.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"

void FlowObject_AddArrayBooleanProperty(FlowObject self, int propertyIndex, bool value);
void FlowObject_AddArrayCharProperty(FlowObject self, int propertyIndex, char value);
void FlowObject_AddArrayDateTimeProperty(FlowObject self, int propertyIndex, FlowDatetime value);
void FlowObject_AddArrayIDProperty(FlowObject self, int propertyIndex, FlowID value);
void FlowObject_AddArrayIntegerProperty(FlowObject self, int propertyIndex, int value);
void FlowObject_AddArrayObjectProperty(FlowObject self, int propertyIndex, FlowObject value);
void FlowObject_AddArrayStringProperty(FlowObject self, int propertyIndex, char *value);
void FlowObject_AddArrayTimespanProperty(FlowObject self, int propertyIndex,  FlowTimespan value);
void FlowObject_AddArrayTokenProperty(FlowObject self, int propertyIndex,  FlowToken value);

void FlowObject_CopyFrom(FlowObject self, FlowObject src);

void FlowObject_Free(FlowObject *self);

bool FlowObject_GetArrayBooleanProperty(FlowObject self, int propertyIndex, int itemIndex);
char FlowObject_GetArrayCharProperty(FlowObject self, int propertyIndex, int itemIndex);
FlowDatetime FlowObject_GetArrayDateTimeProperty(FlowObject self, int propertyIndex, int itemIndex);
FlowID FlowObject_GetArrayIDProperty(FlowObject self, int propertyIndex, int itemIndex);
int FlowObject_GetArrayIntegerProperty(FlowObject self, int propertyIndex, int itemIndex);
FlowObject FlowObject_GetArrayObjectProperty(FlowObject self, int propertyIndex, int itemIndex);
char *FlowObject_GetArrayStringProperty(FlowObject self, int propertyIndex, int itemIndex);
FlowTimespan FlowObject_GetArrayTimespanProperty(FlowObject self, int propertyIndex, int itemIndex);
FlowToken FlowObject_GetArrayTokenProperty(FlowObject self, int propertyIndex, int itemIndex);

int FlowObject_GetArrayPropertyCount(FlowObject self, int propertyIndex);


bool FlowObject_GetBooleanProperty(FlowObject self, int index);
char FlowObject_GetCharProperty(FlowObject self, int index);
FlowDatetime FlowObject_GetDateTimeProperty(FlowObject self, int index);
FlowID FlowObject_GetIDProperty(FlowObject self, int index);
int FlowObject_GetIntegerProperty(FlowObject self, int index);
char *FlowObject_GetLink(FlowObject self, int index);
FlowObject FlowObject_GetObjectProperty(FlowObject self, int index);
char *FlowObject_GetStringProperty(FlowObject self, int index);
FlowTimespan FlowObject_GetTimespanProperty(FlowObject self, int index);
FlowToken FlowObject_GetTokenProperty(FlowObject self, int index);

FlowMemoryManager FlowObject_GetMemoryManager(FlowObject self);

FlowType FlowObject_GetType(FlowObject self);

bool FlowObject_HasLink(FlowObject self, int index);

bool FlowObject_HasProperty(FlowObject self, int index);

bool FlowObject_LoadNextPage(FlowObject self, char *url);
void FlowObject_LoadPage(FlowObject self, char *url, uint startIndex);

FlowObject FlowObject_HTTPRequest(FlowObject self, int linkIndex,FlowHTTPMethod method,FlowObject data, FlowType returnType);

bool FlowObject_HTTPRequestWithStatusResponse(FlowObject self, int linkIndex,FlowHTTPMethod method,FlowObject data);

FlowObject FlowObject_New(uint8 propertyCount, uint8 linkCount, FlowType type);


void FlowObject_SetBooleanProperty(FlowObject self, int index, bool value);
void FlowObject_SetCharProperty(FlowObject self, int index, char value);
void FlowObject_SetDateTimeProperty(FlowObject self, int index, FlowDatetime value);
void FlowObject_SetIDProperty(FlowObject self, int index, FlowID value);
void FlowObject_SetIntegerProperty(FlowObject self, int index, int value);
void FlowObject_SetLink(FlowObject self, int index, char *value);
void FlowObject_SetObjectProperty(FlowObject self, int index, FlowObject value);
void FlowObject_SetStringProperty(FlowObject self, int index, char *value);
void FlowObject_SetTimespanProperty(FlowObject self, int index, FlowTimespan value);
void FlowObject_SetTokenProperty(FlowObject self, int index, FlowToken value);



#endif /* FLOW_OBJECT_METHODS_H_ */
