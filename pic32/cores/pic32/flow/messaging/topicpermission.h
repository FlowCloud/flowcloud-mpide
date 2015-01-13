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

#ifndef FLOW_MESSAGING_TOPICPERMISSION_H_
#define FLOW_MESSAGING_TOPICPERMISSION_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
#include "flow/messaging/topicpermission_type.h"
#include "flow/messaging/topicpermissiontype_type.h"
/**
 * \memberof FlowTopicPermission
 * \param memoryManager Memory manager on which the method will be applied
 * \brief Creates a new FlowTopicPermission.
 * 
 * You should use the result of this method whenever you need to submit a FlowUser as a \a data parameter.
*/
static inline FlowTopicPermission FlowTopicPermission_New(FlowMemoryManager memoryManager){ return (FlowTopicPermission)FlowMemoryManager_NewObject(memoryManager, 4, 1, FlowType_TopicPermission);}
/**
 * \memberof FlowTopicPermission
 * \brief Registers meta data used for (de)serialising FlowTopicPermission to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowTopicPermission_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_TopicPermission))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_TopicPermission, "TopicPermission", 4, 1);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TopicPermission, _FlowTopicPermission_UserID, FlowType_ID, "UserID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TopicPermission, _FlowTopicPermission_DeviceID, FlowType_ID, "DeviceID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TopicPermission, _FlowTopicPermission_Topic, FlowType_String, "Topic", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TopicPermission, _FlowTopicPermission_Permission, FlowType_TopicPermissionType, "Permission", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_TopicPermission, _FlowTopicPermission_rel_Remove, "remove");
	}
}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property UserID is set on this object.
 * 
 * Can be used to check whether UserID is available on this object without making an HTTP call.
*/
static inline bool FlowTopicPermission_HasUserID(FlowTopicPermission self) { return FlowObject_HasProperty(self, _FlowTopicPermission_UserID);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowTopicPermission_GetUserID(FlowTopicPermission self) { return FlowObject_GetIDProperty(self, _FlowTopicPermission_UserID);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTopicPermission_SetUserID(FlowTopicPermission self, FlowID value) { FlowObject_SetIDProperty(self, _FlowTopicPermission_UserID, value);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property DeviceID is set on this object.
 * 
 * Can be used to check whether DeviceID is available on this object without making an HTTP call.
*/
static inline bool FlowTopicPermission_HasDeviceID(FlowTopicPermission self) { return FlowObject_HasProperty(self, _FlowTopicPermission_DeviceID);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowTopicPermission_GetDeviceID(FlowTopicPermission self) { return FlowObject_GetIDProperty(self, _FlowTopicPermission_DeviceID);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTopicPermission_SetDeviceID(FlowTopicPermission self, FlowID value) { FlowObject_SetIDProperty(self, _FlowTopicPermission_DeviceID, value);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Topic is set on this object.
 * 
 * Can be used to check whether Topic is available on this object without making an HTTP call.
*/
static inline bool FlowTopicPermission_HasTopic(FlowTopicPermission self) { return FlowObject_HasProperty(self, _FlowTopicPermission_Topic);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
*/
static inline char *FlowTopicPermission_GetTopic(FlowTopicPermission self) { return FlowObject_GetStringProperty(self, _FlowTopicPermission_Topic);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTopicPermission_SetTopic(FlowTopicPermission self, char *value) { FlowObject_SetStringProperty(self, _FlowTopicPermission_Topic, value);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Permission is set on this object.
 * 
 * Can be used to check whether Permission is available on this object without making an HTTP call.
*/
static inline bool FlowTopicPermission_HasPermission(FlowTopicPermission self) { return FlowObject_HasProperty(self, _FlowTopicPermission_Permission);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
*/
static inline FlowTopicPermissionType FlowTopicPermission_GetPermission(FlowTopicPermission self) { return (FlowTopicPermissionType)FlowObject_GetIntegerProperty(self, _FlowTopicPermission_Permission);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTopicPermission_SetPermission(FlowTopicPermission self, FlowTopicPermissionType value) { FlowObject_SetIntegerProperty(self, _FlowTopicPermission_Permission, value);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
 * \brief Indicates whether \ref FlowTopicPermission_RemoveTopicPermission is available on this object.
 * 
 * Checks whether \ref FlowTopicPermission_RemoveTopicPermission is available on this object without making an HTTP call.
*/
static inline bool FlowTopicPermission_CanRemoveTopicPermission(FlowTopicPermission self) { return FlowObject_HasLink(self, _FlowTopicPermission_rel_Remove);}
/**
 * \memberof FlowTopicPermission
 * \param self Object on which the method will be applied
*/
static inline bool FlowTopicPermission_RemoveTopicPermission(FlowTopicPermission self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowTopicPermission_rel_Remove, FlowHTTPMethod_Delete, NULL);}
#endif /* FLOW_MESSAGING_TOPICPERMISSION_H_ */
