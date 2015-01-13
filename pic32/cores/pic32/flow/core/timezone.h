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

#ifndef FLOW_CORE_TIMEZONE_H_
#define FLOW_CORE_TIMEZONE_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/timezone_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowTimeZone
 * \brief Creates a new FlowTimeZone.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowTimeZone FlowTimeZone_New(FlowMemoryManager memoryManager){ return (FlowTimeZone)FlowMemoryManager_NewObject(memoryManager, 5, 1, FlowType_TimeZone);}
/**
 * \memberof FlowTimeZone
 * \brief Registers meta data used for (de)serialising FlowTimeZone to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowTimeZone_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_TimeZone))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_TimeZone, "TimeZone", 5, 1);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TimeZone, _FlowTimeZone_TimeZoneID, FlowType_ID, "TimeZoneID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TimeZone, _FlowTimeZone_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TimeZone, _FlowTimeZone_Offset, FlowType_Timespan, "Offset", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TimeZone, _FlowTimeZone_CurrentTime, FlowType_Datetime, "CurrentTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_TimeZone, _FlowTimeZone_CurrentUtcTime, FlowType_Datetime, "CurrentUtcTime", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_TimeZone, _FlowTimeZone_rel_Self, "self");
	}
}
/**
 * \memberof FlowTimeZone
 * \brief Indicates whether the property TimeZoneID is set on this object.
 * 
 * Can be used to check whether TimeZoneID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTimeZone_HasTimeZoneID(FlowTimeZone self) { return FlowObject_HasProperty(self, _FlowTimeZone_TimeZoneID);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowTimeZone_GetTimeZoneID(FlowTimeZone self) { return FlowObject_GetIDProperty(self, _FlowTimeZone_TimeZoneID);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTimeZone_SetTimeZoneID(FlowTimeZone self, FlowID value) { FlowObject_SetIDProperty(self, _FlowTimeZone_TimeZoneID, value);}
/**
 * \memberof FlowTimeZone
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTimeZone_HasName(FlowTimeZone self) { return FlowObject_HasProperty(self, _FlowTimeZone_Name);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
*/
static inline char *FlowTimeZone_GetName(FlowTimeZone self) { return FlowObject_GetStringProperty(self, _FlowTimeZone_Name);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTimeZone_SetName(FlowTimeZone self, char *value) { FlowObject_SetStringProperty(self, _FlowTimeZone_Name, value);}
/**
 * \memberof FlowTimeZone
 * \brief Indicates whether the property Offset is set on this object.
 * 
 * Can be used to check whether Offset is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTimeZone_HasOffset(FlowTimeZone self) { return FlowObject_HasProperty(self, _FlowTimeZone_Offset);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
*/
static inline FlowTimespan FlowTimeZone_GetOffset(FlowTimeZone self) { return FlowObject_GetTimespanProperty(self, _FlowTimeZone_Offset);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTimeZone_SetOffset(FlowTimeZone self, FlowTimespan value) { FlowObject_SetTimespanProperty(self, _FlowTimeZone_Offset, value);}
/**
 * \memberof FlowTimeZone
 * \brief Indicates whether the property CurrentTime is set on this object.
 * 
 * Can be used to check whether CurrentTime is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTimeZone_HasCurrentTime(FlowTimeZone self) { return FlowObject_HasProperty(self, _FlowTimeZone_CurrentTime);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowTimeZone_GetCurrentTime(FlowTimeZone self) { return FlowObject_GetDateTimeProperty(self, _FlowTimeZone_CurrentTime);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTimeZone_SetCurrentTime(FlowTimeZone self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowTimeZone_CurrentTime, value);}
/**
 * \memberof FlowTimeZone
 * \brief Indicates whether the property CurrentUtcTime is set on this object.
 * 
 * Can be used to check whether CurrentUtcTime is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTimeZone_HasCurrentUtcTime(FlowTimeZone self) { return FlowObject_HasProperty(self, _FlowTimeZone_CurrentUtcTime);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowTimeZone_GetCurrentUtcTime(FlowTimeZone self) { return FlowObject_GetDateTimeProperty(self, _FlowTimeZone_CurrentUtcTime);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTimeZone_SetCurrentUtcTime(FlowTimeZone self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowTimeZone_CurrentUtcTime, value);}
/**
 * \memberof FlowTimeZone
 * \brief Indicates whether \ref FlowTimeZone_RetrieveDetails is available on this object.
 * 
 * Checks whether \ref FlowTimeZone_RetrieveDetails is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTimeZone_CanRetrieveDetails(FlowTimeZone self) { return FlowObject_HasLink(self, _FlowTimeZone_rel_Self);}
/**
 * \memberof FlowTimeZone
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowTimeZone FlowTimeZone_RetrieveDetails(FlowTimeZone self) { return (FlowTimeZone) FlowObject_HTTPRequest(self, _FlowTimeZone_rel_Self, FlowHTTPMethod_Get, NULL, FlowType_TimeZone);}
#endif /* FLOW_CORE_TIMEZONE_H_ */
