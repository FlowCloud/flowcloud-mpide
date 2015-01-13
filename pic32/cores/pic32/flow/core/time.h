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

#ifndef FLOW_CORE_TIME_H_
#define FLOW_CORE_TIME_H_
#include "flow/core/base_types.h"
#include "flow/core/countries_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/time_type.h"
#include "flow/core/timezones_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowTime
 * \brief Creates a new FlowTime.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowTime FlowTime_New(FlowMemoryManager memoryManager){ return (FlowTime)FlowMemoryManager_NewObject(memoryManager, 3, 3, FlowType_Time);}
/**
 * \memberof FlowTime
 * \brief Registers meta data used for (de)serialising FlowTime to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowTime_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Time))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Time, "Time", 3, 3);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Time, _FlowTime_CurrentTime, FlowType_Datetime, "CurrentTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Time, _FlowTime_CurrentUtcTime, FlowType_Datetime, "CurrentUtcTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Time, _FlowTime_CountryCode, FlowType_String, "CountryCode", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Time, _FlowTime_rel_Countries, "countries");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Time, _FlowTime_rel_Countryzones, "countryzones");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Time, _FlowTime_rel_Zones, "zones");
	}
}
/**
 * \memberof FlowTime
 * \brief Indicates whether the property CurrentTime is set on this object.
 * 
 * Can be used to check whether CurrentTime is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTime_HasCurrentTime(FlowTime self) { return FlowObject_HasProperty(self, _FlowTime_CurrentTime);}
/**
 * \memberof FlowTime
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowTime_GetCurrentTime(FlowTime self) { return FlowObject_GetDateTimeProperty(self, _FlowTime_CurrentTime);}
/**
 * \memberof FlowTime
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTime_SetCurrentTime(FlowTime self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowTime_CurrentTime, value);}
/**
 * \memberof FlowTime
 * \brief Indicates whether the property CurrentUtcTime is set on this object.
 * 
 * Can be used to check whether CurrentUtcTime is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTime_HasCurrentUtcTime(FlowTime self) { return FlowObject_HasProperty(self, _FlowTime_CurrentUtcTime);}
/**
 * \memberof FlowTime
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowTime_GetCurrentUtcTime(FlowTime self) { return FlowObject_GetDateTimeProperty(self, _FlowTime_CurrentUtcTime);}
/**
 * \memberof FlowTime
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTime_SetCurrentUtcTime(FlowTime self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowTime_CurrentUtcTime, value);}
/**
 * \memberof FlowTime
 * \brief Indicates whether the property CountryCode is set on this object.
 * 
 * Can be used to check whether CountryCode is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTime_HasCountryCode(FlowTime self) { return FlowObject_HasProperty(self, _FlowTime_CountryCode);}
/**
 * \memberof FlowTime
 * \param self Object on which the method will be applied
*/
static inline char *FlowTime_GetCountryCode(FlowTime self) { return FlowObject_GetStringProperty(self, _FlowTime_CountryCode);}
/**
 * \memberof FlowTime
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowTime_SetCountryCode(FlowTime self, char *value) { FlowObject_SetStringProperty(self, _FlowTime_CountryCode, value);}
/**
 * \memberof FlowTime
 * \ingroup Time
 * \brief Indicates whether \ref FlowTime_RetrieveCountries is available on this object.
 * 
 * Checks whether \ref FlowTime_RetrieveCountries is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTime_CanRetrieveCountries(FlowTime self) { return FlowObject_HasLink(self, _FlowTime_rel_Countries);}
/**
 * \memberof FlowTime
 * \ingroup Time
 * \brief Retrieve countries
 *
 * Retrieve a list countries with the links to the timezones for each country.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowCountries FlowTime_RetrieveCountries(FlowTime self, int pageSize)
{
	FlowCountries result = NULL;
	if(FlowObject_HasLink(self, _FlowTime_rel_Countries))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowTime_rel_Countries));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowCountries) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Countries);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowTime
 * \ingroup Time
 * \brief Indicates whether \ref FlowTime_RetrieveTimeZonesForCountry is available on this object.
 * 
 * Checks whether \ref FlowTime_RetrieveTimeZonesForCountry is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTime_CanRetrieveTimeZonesForCountry(FlowTime self) { return FlowObject_HasLink(self, _FlowTime_rel_Countryzones);}
/**
 * \memberof FlowTime
 * \ingroup Time
 * \brief Retrieve country timezones
 *
 * Retrieve a list of time zones associated with a specified country code.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowTimeZones FlowTime_RetrieveTimeZonesForCountry(FlowTime self, int pageSize)
{
	FlowTimeZones result = NULL;
	if(FlowObject_HasLink(self, _FlowTime_rel_Countryzones))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowTime_rel_Countryzones));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowTimeZones) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_TimeZones);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowTime
 * \ingroup Time
 * \brief Indicates whether \ref FlowTime_RetrieveAllTimeZones is available on this object.
 * 
 * Checks whether \ref FlowTime_RetrieveAllTimeZones is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowTime_CanRetrieveAllTimeZones(FlowTime self) { return FlowObject_HasLink(self, _FlowTime_rel_Zones);}
/**
 * \memberof FlowTime
 * \ingroup Time
 * \brief Retrieve all timezones
 *
 * Retrieve a list of the available time zones.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowTimeZones FlowTime_RetrieveAllTimeZones(FlowTime self, int pageSize)
{
	FlowTimeZones result = NULL;
	if(FlowObject_HasLink(self, _FlowTime_rel_Zones))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowTime_rel_Zones));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowTimeZones) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_TimeZones);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
#endif /* FLOW_CORE_TIME_H_ */
