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

#ifndef FLOW_CORE_SERVICESETTINGS_H_
#define FLOW_CORE_SERVICESETTINGS_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/serviceendpoint.h"
#include "flow/core/serviceendpoints_type.h"
#include "flow/core/servicesettings_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowServiceSettings
 * \brief Creates a new FlowServiceSettings.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowServiceSettings FlowServiceSettings_New(FlowMemoryManager memoryManager){ return (FlowServiceSettings)FlowMemoryManager_NewObject(memoryManager, 2, 0, FlowType_ServiceSettings);}
/**
 * \memberof FlowServiceSettings
 * \brief Registers meta data used for (de)serialising FlowServiceSettings to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowServiceSettings_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_ServiceSettings))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_ServiceSettings, "ServiceSettings", 2, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ServiceSettings, _FlowServiceSettings_Identity, FlowType_String, "Identity", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_ServiceSettings, _FlowServiceSettings_ServiceEndpoints, "ServiceEndpoints", "ServiceEndpoint", FlowType_ServiceEndpoint, FlowType_ServiceEndpoints);
	}
}
/**
 * \memberof FlowServiceSettings
 * \brief Indicates whether the property Identity is set on this object.
 * 
 * Can be used to check whether Identity is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceSettings_HasIdentity(FlowServiceSettings self) { return FlowObject_HasProperty(self, _FlowServiceSettings_Identity);}
/**
 * \memberof FlowServiceSettings
 * \param self Object on which the method will be applied
*/
static inline char *FlowServiceSettings_GetIdentity(FlowServiceSettings self) { return FlowObject_GetStringProperty(self, _FlowServiceSettings_Identity);}
/**
 * \memberof FlowServiceSettings
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowServiceSettings_SetIdentity(FlowServiceSettings self, char *value) { FlowObject_SetStringProperty(self, _FlowServiceSettings_Identity, value);}
/**
 * \memberof FlowServiceSettings
 * \brief Indicates whether the property ServiceEndpoints is set on this object.
 * 
 * Can be used to check whether ServiceEndpoints is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceSettings_HasServiceEndpoints(FlowServiceSettings self) { return FlowObject_HasProperty(self, _FlowServiceSettings_ServiceEndpoints);}
/**
 * \memberof FlowServiceSettings
 * \param self Object on which the method will be applied
*/
static inline FlowServiceEndpoints FlowServiceSettings_GetServiceEndpoints(FlowServiceSettings self) { return (FlowServiceEndpoints)FlowObject_GetObjectProperty(self, _FlowServiceSettings_ServiceEndpoints);}
#endif /* FLOW_CORE_SERVICESETTINGS_H_ */
