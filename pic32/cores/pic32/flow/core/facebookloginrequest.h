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

#ifndef FLOW_USERS_FACEBOOKLOGINREQUEST_H_
#define FLOW_USERS_FACEBOOKLOGINREQUEST_H_
#include "flow/core/authenticationtokencreatedresponse_type.h"
#include "flow/core/base_types.h"
#include "flow/core/facebookloginrequest_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/strings_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowFacebookLoginRequest
 * \brief Creates a new FlowFacebookLoginRequest.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowFacebookLoginRequest FlowFacebookLoginRequest_New(FlowMemoryManager memoryManager){ return (FlowFacebookLoginRequest)FlowMemoryManager_NewObject(memoryManager, 4, 1, FlowType_FacebookLoginRequest);}
/**
 * \memberof FlowFacebookLoginRequest
 * \brief Registers meta data used for (de)serialising FlowFacebookLoginRequest to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowFacebookLoginRequest_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_FacebookLoginRequest))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_FacebookLoginRequest, "FacebookLoginRequest", 4, 1);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookLoginRequest, _FlowFacebookLoginRequest_AppID, FlowType_ID, "AppID", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_FacebookLoginRequest, _FlowFacebookLoginRequest_Permissions, "Permissions", "Permission", FlowType_String, FlowType_Strings);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookLoginRequest, _FlowFacebookLoginRequest_Token, FlowType_String, "Token", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookLoginRequest, _FlowFacebookLoginRequest_TokenExpiry, FlowType_Datetime, "TokenExpiry", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_FacebookLoginRequest, _FlowFacebookLoginRequest_rel_Update, "update");
	}
}
/**
 * \memberof FlowFacebookLoginRequest
 * \brief Indicates whether the property AppID is set on this object.
 * 
 * Can be used to check whether AppID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookLoginRequest_HasAppID(FlowFacebookLoginRequest self) { return FlowObject_HasProperty(self, _FlowFacebookLoginRequest_AppID);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowFacebookLoginRequest_GetAppID(FlowFacebookLoginRequest self) { return FlowObject_GetIDProperty(self, _FlowFacebookLoginRequest_AppID);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookLoginRequest_SetAppID(FlowFacebookLoginRequest self, FlowID value) { FlowObject_SetIDProperty(self, _FlowFacebookLoginRequest_AppID, value);}
/**
 * \memberof FlowFacebookLoginRequest
 * \brief Indicates whether the property Permissions is set on this object.
 * 
 * Can be used to check whether Permissions is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookLoginRequest_HasPermissions(FlowFacebookLoginRequest self) { return FlowObject_HasProperty(self, _FlowFacebookLoginRequest_Permissions);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
*/
static inline FlowStrings FlowFacebookLoginRequest_GetPermissions(FlowFacebookLoginRequest self) { return (FlowStrings)FlowObject_GetObjectProperty(self, _FlowFacebookLoginRequest_Permissions);}
/**
 * \memberof FlowFacebookLoginRequest
 * \brief Indicates whether the property Token is set on this object.
 * 
 * Can be used to check whether Token is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookLoginRequest_HasToken(FlowFacebookLoginRequest self) { return FlowObject_HasProperty(self, _FlowFacebookLoginRequest_Token);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
*/
static inline char *FlowFacebookLoginRequest_GetToken(FlowFacebookLoginRequest self) { return FlowObject_GetStringProperty(self, _FlowFacebookLoginRequest_Token);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookLoginRequest_SetToken(FlowFacebookLoginRequest self, char *value) { FlowObject_SetStringProperty(self, _FlowFacebookLoginRequest_Token, value);}
/**
 * \memberof FlowFacebookLoginRequest
 * \brief Indicates whether the property TokenExpiry is set on this object.
 * 
 * Can be used to check whether TokenExpiry is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookLoginRequest_HasTokenExpiry(FlowFacebookLoginRequest self) { return FlowObject_HasProperty(self, _FlowFacebookLoginRequest_TokenExpiry);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowFacebookLoginRequest_GetTokenExpiry(FlowFacebookLoginRequest self) { return FlowObject_GetDateTimeProperty(self, _FlowFacebookLoginRequest_TokenExpiry);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookLoginRequest_SetTokenExpiry(FlowFacebookLoginRequest self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowFacebookLoginRequest_TokenExpiry, value);}
/**
 * \memberof FlowFacebookLoginRequest
 * \brief Indicates whether \ref FlowFacebookLoginRequest_CompleteFacebookLogin is available on this object.
 * 
 * Checks whether \ref FlowFacebookLoginRequest_CompleteFacebookLogin is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookLoginRequest_CanCompleteFacebookLogin(FlowFacebookLoginRequest self) { return FlowObject_HasLink(self, _FlowFacebookLoginRequest_rel_Update);}
/**
 * \memberof FlowFacebookLoginRequest
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthenticationTokenCreatedResponse FlowFacebookLoginRequest_CompleteFacebookLogin(FlowFacebookLoginRequest self, FlowFacebookLoginRequest data) { return (FlowAuthenticationTokenCreatedResponse) FlowObject_HTTPRequest(self, _FlowFacebookLoginRequest_rel_Update, FlowHTTPMethod_Put, data, FlowType_AuthenticationTokenCreatedResponse);}
#endif /* FLOW_USERS_FACEBOOKLOGINREQUEST_H_ */
