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

#ifndef FLOW_MESSAGING_TOPICPERMISSIONS_TYPE_H_
#define FLOW_MESSAGING_TOPICPERMISSIONS_TYPE_H_

#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"

/**
 * \internal
*/
typedef enum
{
	_FlowTopicPermissions_PageInfo,
	_FlowTopicPermissions_Items,
}_FlowTopicPermissions_PropertyEnum;

/**
 * \internal
*/
typedef enum
{
	_FlowTopicPermissions_rel_Add,
	_FlowTopicPermissions_rel_Devicepermissions,
	_FlowTopicPermissions_rel_Userpermissions,
}_FlowTopicPermissions_LinkEnum;

/**
 * \class FlowTopicPermissions
*/
typedef FlowObject FlowTopicPermissions;

/**
 * \memberof FlowTopicPermissions
 * \param self Object on which the method will be applied
 * \param src reference Object to copy from
 * \brief Copies information from a FlowTopicPermissions to another.
 *
*/
static inline void FlowTopicPermissions_CopyFrom(FlowTopicPermissions self, FlowTopicPermissions src){ FlowObject_CopyFrom(self,src);}

#endif /* FLOW_MESSAGING_TOPICPERMISSIONS_TYPE_H_ */