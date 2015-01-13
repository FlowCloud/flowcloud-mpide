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

#ifndef FLOW_USERS_AUTHENTICATIONTOKENCREATEDRESPONSE_H_
#define FLOW_USERS_AUTHENTICATIONTOKENCREATEDRESPONSE_H_
#include "flow/core/authenticationtokencreatedresponse_type.h"
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \brief Creates a new FlowAuthenticationTokenCreatedResponse.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowAuthenticationTokenCreatedResponse FlowAuthenticationTokenCreatedResponse_New(FlowMemoryManager memoryManager){ return (FlowAuthenticationTokenCreatedResponse)FlowMemoryManager_NewObject(memoryManager, 4, 0, FlowType_AuthenticationTokenCreatedResponse);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \brief Registers meta data used for (de)serialising FlowAuthenticationTokenCreatedResponse to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowAuthenticationTokenCreatedResponse_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_AuthenticationTokenCreatedResponse))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_AuthenticationTokenCreatedResponse, "AuthenticationTokenCreatedResponse", 4, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_AuthenticationTokenCreatedResponse, _FlowAuthenticationTokenCreatedResponse_SessionToken, FlowType_Token, "SessionToken", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_AuthenticationTokenCreatedResponse, _FlowAuthenticationTokenCreatedResponse_SessionTokenLifeTime, FlowType_Integer, "SessionTokenLifeTime", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_AuthenticationTokenCreatedResponse, _FlowAuthenticationTokenCreatedResponse_RememberMeToken, FlowType_Token, "RememberMeToken", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_AuthenticationTokenCreatedResponse, _FlowAuthenticationTokenCreatedResponse_RememberMeExpiryDate, FlowType_Datetime, "RememberMeExpiryDate", true);
	}
}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \brief Indicates whether the property SessionToken is set on this object.
 * 
 * Can be used to check whether SessionToken is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthenticationTokenCreatedResponse_HasSessionToken(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_HasProperty(self, _FlowAuthenticationTokenCreatedResponse_SessionToken);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowAuthenticationTokenCreatedResponse_GetSessionToken(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_GetTokenProperty(self, _FlowAuthenticationTokenCreatedResponse_SessionToken);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthenticationTokenCreatedResponse_SetSessionToken(FlowAuthenticationTokenCreatedResponse self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowAuthenticationTokenCreatedResponse_SessionToken, value);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \brief Indicates whether the property SessionTokenLifeTime is set on this object.
 * 
 * Can be used to check whether SessionTokenLifeTime is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthenticationTokenCreatedResponse_HasSessionTokenLifeTime(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_HasProperty(self, _FlowAuthenticationTokenCreatedResponse_SessionTokenLifeTime);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline int FlowAuthenticationTokenCreatedResponse_GetSessionTokenLifeTime(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_GetIntegerProperty(self, _FlowAuthenticationTokenCreatedResponse_SessionTokenLifeTime);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthenticationTokenCreatedResponse_SetSessionTokenLifeTime(FlowAuthenticationTokenCreatedResponse self, int value) { FlowObject_SetIntegerProperty(self, _FlowAuthenticationTokenCreatedResponse_SessionTokenLifeTime, value);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \brief Indicates whether the property RememberMeToken is set on this object.
 * 
 * Can be used to check whether RememberMeToken is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthenticationTokenCreatedResponse_HasRememberMeToken(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_HasProperty(self, _FlowAuthenticationTokenCreatedResponse_RememberMeToken);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowAuthenticationTokenCreatedResponse_GetRememberMeToken(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_GetTokenProperty(self, _FlowAuthenticationTokenCreatedResponse_RememberMeToken);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthenticationTokenCreatedResponse_SetRememberMeToken(FlowAuthenticationTokenCreatedResponse self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowAuthenticationTokenCreatedResponse_RememberMeToken, value);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \brief Indicates whether the property RememberMeExpiryDate is set on this object.
 * 
 * Can be used to check whether RememberMeExpiryDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthenticationTokenCreatedResponse_HasRememberMeExpiryDate(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_HasProperty(self, _FlowAuthenticationTokenCreatedResponse_RememberMeExpiryDate);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowAuthenticationTokenCreatedResponse_GetRememberMeExpiryDate(FlowAuthenticationTokenCreatedResponse self) { return FlowObject_GetDateTimeProperty(self, _FlowAuthenticationTokenCreatedResponse_RememberMeExpiryDate);}
/**
 * \memberof FlowAuthenticationTokenCreatedResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthenticationTokenCreatedResponse_SetRememberMeExpiryDate(FlowAuthenticationTokenCreatedResponse self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowAuthenticationTokenCreatedResponse_RememberMeExpiryDate, value);}
#endif /* FLOW_USERS_AUTHENTICATIONTOKENCREATEDRESPONSE_H_ */
