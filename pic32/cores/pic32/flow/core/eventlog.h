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

#ifndef FLOW_CORE_EVENTLOG_H_
#define FLOW_CORE_EVENTLOG_H_
#include "flow/core/base_types.h"
#include "flow/core/eventlog_type.h"
#include "flow/core/eventseverity_type.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowEventLog
 * \brief Creates a new FlowEventLog.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowEventLog FlowEventLog_New(FlowMemoryManager memoryManager){ return (FlowEventLog)FlowMemoryManager_NewObject(memoryManager, 4, 0, FlowType_EventLog);}
/**
 * \memberof FlowEventLog
 * \brief Registers meta data used for (de)serialising FlowEventLog to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowEventLog_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_EventLog))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_EventLog, "EventLog", 4, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_EventLog, _FlowEventLog_EventDate, FlowType_Datetime, "EventDate", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_EventLog, _FlowEventLog_Category, FlowType_String, "Category", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_EventLog, _FlowEventLog_Severity, FlowType_EventSeverity, "Severity", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_EventLog, _FlowEventLog_Message, FlowType_String, "Message", true);
	}
}
/**
 * \memberof FlowEventLog
 * \brief Indicates whether the property EventDate is set on this object.
 * 
 * Can be used to check whether EventDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowEventLog_HasEventDate(FlowEventLog self) { return FlowObject_HasProperty(self, _FlowEventLog_EventDate);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowEventLog_GetEventDate(FlowEventLog self) { return FlowObject_GetDateTimeProperty(self, _FlowEventLog_EventDate);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowEventLog_SetEventDate(FlowEventLog self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowEventLog_EventDate, value);}
/**
 * \memberof FlowEventLog
 * \brief Indicates whether the property Category is set on this object.
 * 
 * Can be used to check whether Category is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowEventLog_HasCategory(FlowEventLog self) { return FlowObject_HasProperty(self, _FlowEventLog_Category);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
*/
static inline char *FlowEventLog_GetCategory(FlowEventLog self) { return FlowObject_GetStringProperty(self, _FlowEventLog_Category);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowEventLog_SetCategory(FlowEventLog self, char *value) { FlowObject_SetStringProperty(self, _FlowEventLog_Category, value);}
/**
 * \memberof FlowEventLog
 * \brief Indicates whether the property Severity is set on this object.
 * 
 * Can be used to check whether Severity is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowEventLog_HasSeverity(FlowEventLog self) { return FlowObject_HasProperty(self, _FlowEventLog_Severity);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
*/
static inline FlowEventSeverity FlowEventLog_GetSeverity(FlowEventLog self) { return (FlowEventSeverity)FlowObject_GetIntegerProperty(self, _FlowEventLog_Severity);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowEventLog_SetSeverity(FlowEventLog self, FlowEventSeverity value) { FlowObject_SetIntegerProperty(self, _FlowEventLog_Severity, value);}
/**
 * \memberof FlowEventLog
 * \brief Indicates whether the property Message is set on this object.
 * 
 * Can be used to check whether Message is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowEventLog_HasMessage(FlowEventLog self) { return FlowObject_HasProperty(self, _FlowEventLog_Message);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
*/
static inline char *FlowEventLog_GetMessage(FlowEventLog self) { return FlowObject_GetStringProperty(self, _FlowEventLog_Message);}
/**
 * \memberof FlowEventLog
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowEventLog_SetMessage(FlowEventLog self, char *value) { FlowObject_SetStringProperty(self, _FlowEventLog_Message, value);}
#endif /* FLOW_CORE_EVENTLOG_H_ */
