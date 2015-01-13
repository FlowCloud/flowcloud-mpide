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

#ifndef FLOW_USERS_AUTHENTICATIONMETHODS_H_
#define FLOW_USERS_AUTHENTICATIONMETHODS_H_
#include "flow/core/authenticationmethods_type.h"
#include "flow/core/authenticationtokencreatedresponse_type.h"
#include "flow/core/base_types.h"
#include "flow/core/externalloginrequest_type.h"
#include "flow/core/facebookloginrequest_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/tokencredentials_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowAuthenticationMethods
 * \brief Creates a new FlowAuthenticationMethods.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowAuthenticationMethods FlowAuthenticationMethods_New(FlowMemoryManager memoryManager){ return (FlowAuthenticationMethods)FlowMemoryManager_NewObject(memoryManager, 0, 2, FlowType_AuthenticationMethods);}
/**
 * \memberof FlowAuthenticationMethods
 * \brief Registers meta data used for (de)serialising FlowAuthenticationMethods to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowAuthenticationMethods_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_AuthenticationMethods))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_AuthenticationMethods, "AuthenticationMethods", 0, 2);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_AuthenticationMethods, _FlowAuthenticationMethods_rel_Facebook, "facebook");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_AuthenticationMethods, _FlowAuthenticationMethods_rel_Flow, "flow");
	}
}
/**
 * \memberof FlowAuthenticationMethods
 * \brief Indicates whether \ref FlowAuthenticationMethods_RetrieveFacebookSessionToken is available on this object.
 * 
 * Checks whether \ref FlowAuthenticationMethods_RetrieveFacebookSessionToken is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthenticationMethods_CanRetrieveFacebookSessionToken(FlowAuthenticationMethods self) { return FlowObject_HasLink(self, _FlowAuthenticationMethods_rel_Facebook);}
/**
 * \memberof FlowAuthenticationMethods
 * \param self Object on which the method will be applied
 * \param state state
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthenticationTokenCreatedResponse FlowAuthenticationMethods_RetrieveFacebookSessionToken(FlowAuthenticationMethods self, FlowID state)
{
	FlowAuthenticationTokenCreatedResponse result = NULL;
	if(FlowObject_HasLink(self, _FlowAuthenticationMethods_rel_Facebook))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAuthenticationMethods_rel_Facebook));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, state);
			result = (FlowAuthenticationTokenCreatedResponse) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Get, NULL, FlowType_AuthenticationTokenCreatedResponse);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowAuthenticationMethods
 * \brief Indicates whether \ref FlowAuthenticationMethods_InitiateFacebookLogin is available on this object.
 * 
 * Checks whether \ref FlowAuthenticationMethods_InitiateFacebookLogin is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthenticationMethods_CanInitiateFacebookLogin(FlowAuthenticationMethods self) { return FlowObject_HasLink(self, _FlowAuthenticationMethods_rel_Facebook);}
/**
 * \memberof FlowAuthenticationMethods
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowFacebookLoginRequest FlowAuthenticationMethods_InitiateFacebookLogin(FlowAuthenticationMethods self, FlowExternalLoginRequest data) { return (FlowFacebookLoginRequest) FlowObject_HTTPRequest(self, _FlowAuthenticationMethods_rel_Facebook, FlowHTTPMethod_Post, data, FlowType_FacebookLoginRequest);}
/**
 * \memberof FlowAuthenticationMethods
 * \brief Indicates whether \ref FlowAuthenticationMethods_Authenticate is available on this object.
 * 
 * Checks whether \ref FlowAuthenticationMethods_Authenticate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthenticationMethods_CanAuthenticate(FlowAuthenticationMethods self) { return FlowObject_HasLink(self, _FlowAuthenticationMethods_rel_Flow);}
/**
 * \memberof FlowAuthenticationMethods
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthenticationTokenCreatedResponse FlowAuthenticationMethods_Authenticate(FlowAuthenticationMethods self, FlowTokenCredentials data) { return (FlowAuthenticationTokenCreatedResponse) FlowObject_HTTPRequest(self, _FlowAuthenticationMethods_rel_Flow, FlowHTTPMethod_Post, data, FlowType_AuthenticationTokenCreatedResponse);}
#endif /* FLOW_USERS_AUTHENTICATIONMETHODS_H_ */
