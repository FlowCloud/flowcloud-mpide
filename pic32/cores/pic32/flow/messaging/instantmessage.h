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

#ifndef FLOW_MESSAGING_INSTANTMESSAGE_H_
#define FLOW_MESSAGING_INSTANTMESSAGE_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
#include "flow/messaging/instantmessage_type.h"
/**
 * \memberof FlowInstantMessage
 * \param memoryManager Memory manager on which the method will be applied
 * \brief Creates a new FlowInstantMessage.
 * 
 * You should use the result of this method whenever you need to submit a FlowUser as a \a data parameter.
*/
static inline FlowInstantMessage FlowInstantMessage_New(FlowMemoryManager memoryManager){ return (FlowInstantMessage)FlowMemoryManager_NewObject(memoryManager, 9, 0, FlowType_InstantMessage);}
/**
 * \memberof FlowInstantMessage
 * \brief Registers meta data used for (de)serialising FlowInstantMessage to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowInstantMessage_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_InstantMessage))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_InstantMessage, "InstantMessage", 9, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_Topic, FlowType_String, "Topic", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_ContentType, FlowType_String, "ContentType", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_Priority, FlowType_Integer, "Priority", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_CreateTime, FlowType_Datetime, "CreateTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_ExpiryTime, FlowType_Datetime, "ExpiryTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_DestinationUserID, FlowType_ID, "DestinationUserID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_DestinationDeviceID, FlowType_ID, "DestinationDeviceID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_ContentEncoding, FlowType_String, "ContentEncoding", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_InstantMessage, _FlowInstantMessage_Content, FlowType_RawString, "Content", true);
	}
}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Topic is set on this object.
 * 
 * Can be used to check whether Topic is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasTopic(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_Topic);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline char *FlowInstantMessage_GetTopic(FlowInstantMessage self) { return FlowObject_GetStringProperty(self, _FlowInstantMessage_Topic);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetTopic(FlowInstantMessage self, char *value) { FlowObject_SetStringProperty(self, _FlowInstantMessage_Topic, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property ContentType is set on this object.
 * 
 * Can be used to check whether ContentType is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasContentType(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_ContentType);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline char *FlowInstantMessage_GetContentType(FlowInstantMessage self) { return FlowObject_GetStringProperty(self, _FlowInstantMessage_ContentType);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetContentType(FlowInstantMessage self, char *value) { FlowObject_SetStringProperty(self, _FlowInstantMessage_ContentType, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Priority is set on this object.
 * 
 * Can be used to check whether Priority is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasPriority(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_Priority);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline int FlowInstantMessage_GetPriority(FlowInstantMessage self) { return FlowObject_GetIntegerProperty(self, _FlowInstantMessage_Priority);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetPriority(FlowInstantMessage self, int value) { FlowObject_SetIntegerProperty(self, _FlowInstantMessage_Priority, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property CreateTime is set on this object.
 * 
 * Can be used to check whether CreateTime is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasCreateTime(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_CreateTime);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowInstantMessage_GetCreateTime(FlowInstantMessage self) { return FlowObject_GetDateTimeProperty(self, _FlowInstantMessage_CreateTime);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetCreateTime(FlowInstantMessage self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowInstantMessage_CreateTime, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property ExpiryTime is set on this object.
 * 
 * Can be used to check whether ExpiryTime is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasExpiryTime(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_ExpiryTime);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowInstantMessage_GetExpiryTime(FlowInstantMessage self) { return FlowObject_GetDateTimeProperty(self, _FlowInstantMessage_ExpiryTime);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetExpiryTime(FlowInstantMessage self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowInstantMessage_ExpiryTime, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property DestinationUserID is set on this object.
 * 
 * Can be used to check whether DestinationUserID is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasDestinationUserID(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_DestinationUserID);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowInstantMessage_GetDestinationUserID(FlowInstantMessage self) { return FlowObject_GetIDProperty(self, _FlowInstantMessage_DestinationUserID);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetDestinationUserID(FlowInstantMessage self, FlowID value) { FlowObject_SetIDProperty(self, _FlowInstantMessage_DestinationUserID, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property DestinationDeviceID is set on this object.
 * 
 * Can be used to check whether DestinationDeviceID is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasDestinationDeviceID(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_DestinationDeviceID);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowInstantMessage_GetDestinationDeviceID(FlowInstantMessage self) { return FlowObject_GetIDProperty(self, _FlowInstantMessage_DestinationDeviceID);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetDestinationDeviceID(FlowInstantMessage self, FlowID value) { FlowObject_SetIDProperty(self, _FlowInstantMessage_DestinationDeviceID, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property ContentEncoding is set on this object.
 * 
 * Can be used to check whether ContentEncoding is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasContentEncoding(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_ContentEncoding);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline char *FlowInstantMessage_GetContentEncoding(FlowInstantMessage self) { return FlowObject_GetStringProperty(self, _FlowInstantMessage_ContentEncoding);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetContentEncoding(FlowInstantMessage self, char *value) { FlowObject_SetStringProperty(self, _FlowInstantMessage_ContentEncoding, value);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Content is set on this object.
 * 
 * Can be used to check whether Content is available on this object without making an HTTP call.
*/
static inline bool FlowInstantMessage_HasContent(FlowInstantMessage self) { return FlowObject_HasProperty(self, _FlowInstantMessage_Content);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
*/
static inline char *FlowInstantMessage_GetContent(FlowInstantMessage self) { return FlowObject_GetStringProperty(self, _FlowInstantMessage_Content);}
/**
 * \memberof FlowInstantMessage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowInstantMessage_SetContent(FlowInstantMessage self, char *value) { FlowObject_SetStringProperty(self, _FlowInstantMessage_Content, value);}
#endif /* FLOW_MESSAGING_INSTANTMESSAGE_H_ */
