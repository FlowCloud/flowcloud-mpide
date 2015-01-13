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

#ifndef FLOW_USERS_DEVICECREATEDRESPONSE_H_
#define FLOW_USERS_DEVICECREATEDRESPONSE_H_
#include "flow/core/authenticationtokencreatedresponse_type.h"
#include "flow/core/base_types.h"
#include "flow/core/device_type.h"
#include "flow/core/devicecreatedresponse_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/tokencredentials_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Creates a new FlowDeviceCreatedResponse.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDeviceCreatedResponse FlowDeviceCreatedResponse_New(FlowMemoryManager memoryManager){ return (FlowDeviceCreatedResponse)FlowMemoryManager_NewObject(memoryManager, 5, 2, FlowType_DeviceCreatedResponse);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Registers meta data used for (de)serialising FlowDeviceCreatedResponse to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDeviceCreatedResponse_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_DeviceCreatedResponse))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_DeviceCreatedResponse, "DeviceCreatedResponse", 5, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceCreatedResponse, _FlowDeviceCreatedResponse_ID, FlowType_ID, "ID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceCreatedResponse, _FlowDeviceCreatedResponse_SessionToken, FlowType_Token, "SessionToken", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceCreatedResponse, _FlowDeviceCreatedResponse_SessionTokenLifeTime, FlowType_Integer, "SessionTokenLifeTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceCreatedResponse, _FlowDeviceCreatedResponse_RememberMeToken, FlowType_Token, "RememberMeToken", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceCreatedResponse, _FlowDeviceCreatedResponse_RememberMeExpiryDate, FlowType_Datetime, "RememberMeExpiryDate", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DeviceCreatedResponse, _FlowDeviceCreatedResponse_rel_Authenticate, "authenticate");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DeviceCreatedResponse, _FlowDeviceCreatedResponse_rel_Self, "self");
	}
}
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Indicates whether the property ID is set on this object.
 * 
 * Can be used to check whether ID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceCreatedResponse_HasID(FlowDeviceCreatedResponse self) { return FlowObject_HasProperty(self, _FlowDeviceCreatedResponse_ID);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowDeviceCreatedResponse_GetID(FlowDeviceCreatedResponse self) { return FlowObject_GetIDProperty(self, _FlowDeviceCreatedResponse_ID);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceCreatedResponse_SetID(FlowDeviceCreatedResponse self, FlowID value) { FlowObject_SetIDProperty(self, _FlowDeviceCreatedResponse_ID, value);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Indicates whether the property SessionToken is set on this object.
 * 
 * Can be used to check whether SessionToken is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceCreatedResponse_HasSessionToken(FlowDeviceCreatedResponse self) { return FlowObject_HasProperty(self, _FlowDeviceCreatedResponse_SessionToken);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowDeviceCreatedResponse_GetSessionToken(FlowDeviceCreatedResponse self) { return FlowObject_GetTokenProperty(self, _FlowDeviceCreatedResponse_SessionToken);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceCreatedResponse_SetSessionToken(FlowDeviceCreatedResponse self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowDeviceCreatedResponse_SessionToken, value);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Indicates whether the property SessionTokenLifeTime is set on this object.
 * 
 * Can be used to check whether SessionTokenLifeTime is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceCreatedResponse_HasSessionTokenLifeTime(FlowDeviceCreatedResponse self) { return FlowObject_HasProperty(self, _FlowDeviceCreatedResponse_SessionTokenLifeTime);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline int FlowDeviceCreatedResponse_GetSessionTokenLifeTime(FlowDeviceCreatedResponse self) { return FlowObject_GetIntegerProperty(self, _FlowDeviceCreatedResponse_SessionTokenLifeTime);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceCreatedResponse_SetSessionTokenLifeTime(FlowDeviceCreatedResponse self, int value) { FlowObject_SetIntegerProperty(self, _FlowDeviceCreatedResponse_SessionTokenLifeTime, value);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Indicates whether the property RememberMeToken is set on this object.
 * 
 * Can be used to check whether RememberMeToken is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceCreatedResponse_HasRememberMeToken(FlowDeviceCreatedResponse self) { return FlowObject_HasProperty(self, _FlowDeviceCreatedResponse_RememberMeToken);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowDeviceCreatedResponse_GetRememberMeToken(FlowDeviceCreatedResponse self) { return FlowObject_GetTokenProperty(self, _FlowDeviceCreatedResponse_RememberMeToken);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceCreatedResponse_SetRememberMeToken(FlowDeviceCreatedResponse self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowDeviceCreatedResponse_RememberMeToken, value);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Indicates whether the property RememberMeExpiryDate is set on this object.
 * 
 * Can be used to check whether RememberMeExpiryDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceCreatedResponse_HasRememberMeExpiryDate(FlowDeviceCreatedResponse self) { return FlowObject_HasProperty(self, _FlowDeviceCreatedResponse_RememberMeExpiryDate);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowDeviceCreatedResponse_GetRememberMeExpiryDate(FlowDeviceCreatedResponse self) { return FlowObject_GetDateTimeProperty(self, _FlowDeviceCreatedResponse_RememberMeExpiryDate);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceCreatedResponse_SetRememberMeExpiryDate(FlowDeviceCreatedResponse self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowDeviceCreatedResponse_RememberMeExpiryDate, value);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \ingroup FlowAuthentication
 * \brief Indicates whether \ref FlowDeviceCreatedResponse_Authenticate is available on this object.
 * 
 * Checks whether \ref FlowDeviceCreatedResponse_Authenticate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceCreatedResponse_CanAuthenticate(FlowDeviceCreatedResponse self) { return FlowObject_HasLink(self, _FlowDeviceCreatedResponse_rel_Authenticate);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \ingroup FlowAuthentication
 * \brief Authenticate and authorise
 *
 * Creates a session authentication token based on the supplied credentials and optionally returns a Remember-Me token (if the RememberMe element in the request is set to True).
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthenticationTokenCreatedResponse FlowDeviceCreatedResponse_Authenticate(FlowDeviceCreatedResponse self, FlowTokenCredentials data) { return (FlowAuthenticationTokenCreatedResponse) FlowObject_HTTPRequest(self, _FlowDeviceCreatedResponse_rel_Authenticate, FlowHTTPMethod_Post, data, FlowType_AuthenticationTokenCreatedResponse);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \brief Indicates whether \ref FlowDeviceCreatedResponse_RetrieveDetails is available on this object.
 * 
 * Checks whether \ref FlowDeviceCreatedResponse_RetrieveDetails is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceCreatedResponse_CanRetrieveDetails(FlowDeviceCreatedResponse self) { return FlowObject_HasLink(self, _FlowDeviceCreatedResponse_rel_Self);}
/**
 * \memberof FlowDeviceCreatedResponse
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevice FlowDeviceCreatedResponse_RetrieveDetails(FlowDeviceCreatedResponse self) { return (FlowDevice) FlowObject_HTTPRequest(self, _FlowDeviceCreatedResponse_rel_Self, FlowHTTPMethod_Get, NULL, FlowType_Device);}
#endif /* FLOW_USERS_DEVICECREATEDRESPONSE_H_ */
