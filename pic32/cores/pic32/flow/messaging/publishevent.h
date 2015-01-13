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

#ifndef FLOW_MESSAGING_PUBLISHEVENT_H_
#define FLOW_MESSAGING_PUBLISHEVENT_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
#include "flow/messaging/publishevent_type.h"
/**
 * \memberof FlowPublishEvent
 * \param memoryManager Memory manager on which the method will be applied
 * \brief Creates a new FlowPublishEvent.
 * 
 * You should use the result of this method whenever you need to submit a FlowUser as a \a data parameter.
*/
static inline FlowPublishEvent FlowPublishEvent_New(FlowMemoryManager memoryManager){ return (FlowPublishEvent)FlowMemoryManager_NewObject(memoryManager, 8, 0, FlowType_PublishEvent);}
/**
 * \memberof FlowPublishEvent
 * \brief Registers meta data used for (de)serialising FlowPublishEvent to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowPublishEvent_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_PublishEvent))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_PublishEvent, "PublishEvent", 8, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_Topic, FlowType_String, "Topic", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_ContentType, FlowType_String, "ContentType", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_Priority, FlowType_Integer, "Priority", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_Retain, FlowType_Boolean, "Retain", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_CreateTime, FlowType_Datetime, "CreateTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_ExpiryTime, FlowType_Datetime, "ExpiryTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_ContentEncoding, FlowType_String, "ContentEncoding", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PublishEvent, _FlowPublishEvent_Content, FlowType_RawString, "Content", true);
	}
}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Topic is set on this object.
 * 
 * Can be used to check whether Topic is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasTopic(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_Topic);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline char *FlowPublishEvent_GetTopic(FlowPublishEvent self) { return FlowObject_GetStringProperty(self, _FlowPublishEvent_Topic);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetTopic(FlowPublishEvent self, char *value) { FlowObject_SetStringProperty(self, _FlowPublishEvent_Topic, value);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property ContentType is set on this object.
 * 
 * Can be used to check whether ContentType is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasContentType(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_ContentType);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline char *FlowPublishEvent_GetContentType(FlowPublishEvent self) { return FlowObject_GetStringProperty(self, _FlowPublishEvent_ContentType);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetContentType(FlowPublishEvent self, char *value) { FlowObject_SetStringProperty(self, _FlowPublishEvent_ContentType, value);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Priority is set on this object.
 * 
 * Can be used to check whether Priority is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasPriority(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_Priority);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline int FlowPublishEvent_GetPriority(FlowPublishEvent self) { return FlowObject_GetIntegerProperty(self, _FlowPublishEvent_Priority);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetPriority(FlowPublishEvent self, int value) { FlowObject_SetIntegerProperty(self, _FlowPublishEvent_Priority, value);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Retain is set on this object.
 * 
 * Can be used to check whether Retain is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasRetain(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_Retain);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline bool FlowPublishEvent_GetRetain(FlowPublishEvent self) { return FlowObject_GetBooleanProperty(self, _FlowPublishEvent_Retain);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetRetain(FlowPublishEvent self, bool value) { FlowObject_SetBooleanProperty(self, _FlowPublishEvent_Retain, value);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property CreateTime is set on this object.
 * 
 * Can be used to check whether CreateTime is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasCreateTime(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_CreateTime);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowPublishEvent_GetCreateTime(FlowPublishEvent self) { return FlowObject_GetDateTimeProperty(self, _FlowPublishEvent_CreateTime);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetCreateTime(FlowPublishEvent self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowPublishEvent_CreateTime, value);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property ExpiryTime is set on this object.
 * 
 * Can be used to check whether ExpiryTime is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasExpiryTime(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_ExpiryTime);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowPublishEvent_GetExpiryTime(FlowPublishEvent self) { return FlowObject_GetDateTimeProperty(self, _FlowPublishEvent_ExpiryTime);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetExpiryTime(FlowPublishEvent self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowPublishEvent_ExpiryTime, value);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property ContentEncoding is set on this object.
 * 
 * Can be used to check whether ContentEncoding is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasContentEncoding(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_ContentEncoding);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline char *FlowPublishEvent_GetContentEncoding(FlowPublishEvent self) { return FlowObject_GetStringProperty(self, _FlowPublishEvent_ContentEncoding);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetContentEncoding(FlowPublishEvent self, char *value) { FlowObject_SetStringProperty(self, _FlowPublishEvent_ContentEncoding, value);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \brief Indicates whether the property Content is set on this object.
 * 
 * Can be used to check whether Content is available on this object without making an HTTP call.
*/
static inline bool FlowPublishEvent_HasContent(FlowPublishEvent self) { return FlowObject_HasProperty(self, _FlowPublishEvent_Content);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
*/
static inline char *FlowPublishEvent_GetContent(FlowPublishEvent self) { return FlowObject_GetStringProperty(self, _FlowPublishEvent_Content);}
/**
 * \memberof FlowPublishEvent
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPublishEvent_SetContent(FlowPublishEvent self, char *value) { FlowObject_SetStringProperty(self, _FlowPublishEvent_Content, value);}
#endif /* FLOW_MESSAGING_PUBLISHEVENT_H_ */
