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

#ifndef FLOW_USERS_DEVICEREGISTRATIONKEY_H_
#define FLOW_USERS_DEVICEREGISTRATIONKEY_H_
#include "flow/core/base_types.h"
#include "flow/core/device_type.h"
#include "flow/core/deviceregistrationkey_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDeviceRegistrationKey
 * \brief Creates a new FlowDeviceRegistrationKey.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDeviceRegistrationKey FlowDeviceRegistrationKey_New(FlowMemoryManager memoryManager){ return (FlowDeviceRegistrationKey)FlowMemoryManager_NewObject(memoryManager, 3, 1, FlowType_DeviceRegistrationKey);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \brief Registers meta data used for (de)serialising FlowDeviceRegistrationKey to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDeviceRegistrationKey_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_DeviceRegistrationKey))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_DeviceRegistrationKey, "DeviceRegistrationKey", 3, 1);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceRegistrationKey, _FlowDeviceRegistrationKey_RegistrationKey, FlowType_Token, "RegistrationKey", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceRegistrationKey, _FlowDeviceRegistrationKey_ExpiryDate, FlowType_Datetime, "ExpiryDate", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceRegistrationKey, _FlowDeviceRegistrationKey_Status, FlowType_String, "Status", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DeviceRegistrationKey, _FlowDeviceRegistrationKey_rel_Device, "device");
	}
}
/**
 * \memberof FlowDeviceRegistrationKey
 * \brief Indicates whether the property RegistrationKey is set on this object.
 * 
 * Can be used to check whether RegistrationKey is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceRegistrationKey_HasRegistrationKey(FlowDeviceRegistrationKey self) { return FlowObject_HasProperty(self, _FlowDeviceRegistrationKey_RegistrationKey);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowDeviceRegistrationKey_GetRegistrationKey(FlowDeviceRegistrationKey self) { return FlowObject_GetTokenProperty(self, _FlowDeviceRegistrationKey_RegistrationKey);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceRegistrationKey_SetRegistrationKey(FlowDeviceRegistrationKey self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowDeviceRegistrationKey_RegistrationKey, value);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \brief Indicates whether the property ExpiryDate is set on this object.
 * 
 * Can be used to check whether ExpiryDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceRegistrationKey_HasExpiryDate(FlowDeviceRegistrationKey self) { return FlowObject_HasProperty(self, _FlowDeviceRegistrationKey_ExpiryDate);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowDeviceRegistrationKey_GetExpiryDate(FlowDeviceRegistrationKey self) { return FlowObject_GetDateTimeProperty(self, _FlowDeviceRegistrationKey_ExpiryDate);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceRegistrationKey_SetExpiryDate(FlowDeviceRegistrationKey self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowDeviceRegistrationKey_ExpiryDate, value);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \brief Indicates whether the property Status is set on this object.
 * 
 * Can be used to check whether Status is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceRegistrationKey_HasStatus(FlowDeviceRegistrationKey self) { return FlowObject_HasProperty(self, _FlowDeviceRegistrationKey_Status);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \param self Object on which the method will be applied
*/
static inline char *FlowDeviceRegistrationKey_GetStatus(FlowDeviceRegistrationKey self) { return FlowObject_GetStringProperty(self, _FlowDeviceRegistrationKey_Status);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceRegistrationKey_SetStatus(FlowDeviceRegistrationKey self, char *value) { FlowObject_SetStringProperty(self, _FlowDeviceRegistrationKey_Status, value);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \brief Indicates whether \ref FlowDeviceRegistrationKey_RetrieveDevice is available on this object.
 * 
 * Checks whether \ref FlowDeviceRegistrationKey_RetrieveDevice is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceRegistrationKey_CanRetrieveDevice(FlowDeviceRegistrationKey self) { return FlowObject_HasLink(self, _FlowDeviceRegistrationKey_rel_Device);}
/**
 * \memberof FlowDeviceRegistrationKey
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevice FlowDeviceRegistrationKey_RetrieveDevice(FlowDeviceRegistrationKey self) { return (FlowDevice) FlowObject_HTTPRequest(self, _FlowDeviceRegistrationKey_rel_Device, FlowHTTPMethod_Get, NULL, FlowType_Device);}
#endif /* FLOW_USERS_DEVICEREGISTRATIONKEY_H_ */
