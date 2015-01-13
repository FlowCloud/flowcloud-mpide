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

#ifndef FLOW_CORE_COUNTRY_H_
#define FLOW_CORE_COUNTRY_H_
#include "flow/core/base_types.h"
#include "flow/core/country_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/timezones_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowCountry
 * \brief Creates a new FlowCountry.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowCountry FlowCountry_New(FlowMemoryManager memoryManager){ return (FlowCountry)FlowMemoryManager_NewObject(memoryManager, 2, 4, FlowType_Country);}
/**
 * \memberof FlowCountry
 * \brief Registers meta data used for (de)serialising FlowCountry to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowCountry_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Country))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Country, "Country", 2, 4);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Country, _FlowCountry_CountryCode, FlowType_ID, "CountryCode", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Country, _FlowCountry_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Country, _FlowCountry_rel_Countries, "countries");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Country, _FlowCountry_rel_Locations, "locations");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Country, _FlowCountry_rel_Regions, "regions");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Country, _FlowCountry_rel_Zones, "zones");
	}
}
/**
 * \memberof FlowCountry
 * \brief Indicates whether the property CountryCode is set on this object.
 * 
 * Can be used to check whether CountryCode is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowCountry_HasCountryCode(FlowCountry self) { return FlowObject_HasProperty(self, _FlowCountry_CountryCode);}
/**
 * \memberof FlowCountry
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowCountry_GetCountryCode(FlowCountry self) { return FlowObject_GetIDProperty(self, _FlowCountry_CountryCode);}
/**
 * \memberof FlowCountry
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowCountry_SetCountryCode(FlowCountry self, FlowID value) { FlowObject_SetIDProperty(self, _FlowCountry_CountryCode, value);}
/**
 * \memberof FlowCountry
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowCountry_HasName(FlowCountry self) { return FlowObject_HasProperty(self, _FlowCountry_Name);}
/**
 * \memberof FlowCountry
 * \param self Object on which the method will be applied
*/
static inline char *FlowCountry_GetName(FlowCountry self) { return FlowObject_GetStringProperty(self, _FlowCountry_Name);}
/**
 * \memberof FlowCountry
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowCountry_SetName(FlowCountry self, char *value) { FlowObject_SetStringProperty(self, _FlowCountry_Name, value);}
/**
 * \memberof FlowCountry
 * \ingroup Time
 * \brief Indicates whether \ref FlowCountry_RetrieveTimeZones is available on this object.
 * 
 * Checks whether \ref FlowCountry_RetrieveTimeZones is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowCountry_CanRetrieveTimeZones(FlowCountry self) { return FlowObject_HasLink(self, _FlowCountry_rel_Zones);}
/**
 * \memberof FlowCountry
 * \ingroup Time
 * \brief Retrieve country timezones
 *
 * Retrieve a list of time zones associated with a specified country code
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowTimeZones FlowCountry_RetrieveTimeZones(FlowCountry self) { return (FlowTimeZones) FlowObject_HTTPRequest(self, _FlowCountry_rel_Zones, FlowHTTPMethod_Get, NULL, FlowType_TimeZones);}
#endif /* FLOW_CORE_COUNTRY_H_ */
