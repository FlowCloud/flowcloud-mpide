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

#ifndef FLOW_CORE_SERVICE_H_
#define FLOW_CORE_SERVICE_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/service_type.h"
#include "flow/core/serviceidentity_type.h"
#include "flow/core/servicesettings_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowService
 * \brief Creates a new FlowService.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowService FlowService_New(FlowMemoryManager memoryManager){ return (FlowService)FlowMemoryManager_NewObject(memoryManager, 2, 7, FlowType_Service);}
/**
 * \memberof FlowService
 * \brief Registers meta data used for (de)serialising FlowService to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowService_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Service))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Service, "Service", 2, 7);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Service, _FlowService_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Service, _FlowService_Subscribed, FlowType_Boolean, "Subscribed", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Service, _FlowService_rel_Callrouting, "callrouting");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Service, _FlowService_rel_Identity, "identity");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Service, _FlowService_rel_Publishevent, "publishevent");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Service, _FlowService_rel_Publishmessage, "publishmessage");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Service, _FlowService_rel_Settings, "settings");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Service, _FlowService_rel_Topicpermissions, "topicpermissions");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Service, _FlowService_rel_Turncredentials, "turncredentials");
	}
}
/**
 * \memberof FlowService
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowService_HasName(FlowService self) { return FlowObject_HasProperty(self, _FlowService_Name);}
/**
 * \memberof FlowService
 * \param self Object on which the method will be applied
*/
static inline char *FlowService_GetName(FlowService self) { return FlowObject_GetStringProperty(self, _FlowService_Name);}
/**
 * \memberof FlowService
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowService_SetName(FlowService self, char *value) { FlowObject_SetStringProperty(self, _FlowService_Name, value);}
/**
 * \memberof FlowService
 * \brief Indicates whether the property Subscribed is set on this object.
 * 
 * Can be used to check whether Subscribed is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowService_HasSubscribed(FlowService self) { return FlowObject_HasProperty(self, _FlowService_Subscribed);}
/**
 * \memberof FlowService
 * \param self Object on which the method will be applied
*/
static inline bool FlowService_GetSubscribed(FlowService self) { return FlowObject_GetBooleanProperty(self, _FlowService_Subscribed);}
/**
 * \memberof FlowService
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowService_SetSubscribed(FlowService self, bool value) { FlowObject_SetBooleanProperty(self, _FlowService_Subscribed, value);}
/**
 * \memberof FlowService
 * \brief Indicates whether \ref FlowService_RetrieveServiceIdentity is available on this object.
 * 
 * Checks whether \ref FlowService_RetrieveServiceIdentity is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowService_CanRetrieveServiceIdentity(FlowService self) { return FlowObject_HasLink(self, _FlowService_rel_Identity);}
/**
 * \memberof FlowService
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowServiceIdentity FlowService_RetrieveServiceIdentity(FlowService self) { return (FlowServiceIdentity) FlowObject_HTTPRequest(self, _FlowService_rel_Identity, FlowHTTPMethod_Get, NULL, FlowType_ServiceIdentity);}
/**
 * \memberof FlowService
 * \brief Indicates whether \ref FlowService_RetrieveServiceSettings is available on this object.
 * 
 * Checks whether \ref FlowService_RetrieveServiceSettings is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowService_CanRetrieveServiceSettings(FlowService self) { return FlowObject_HasLink(self, _FlowService_rel_Settings);}
/**
 * \memberof FlowService
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowServiceSettings FlowService_RetrieveServiceSettings(FlowService self) { return (FlowServiceSettings) FlowObject_HTTPRequest(self, _FlowService_rel_Settings, FlowHTTPMethod_Get, NULL, FlowType_ServiceSettings);}
#endif /* FLOW_CORE_SERVICE_H_ */
