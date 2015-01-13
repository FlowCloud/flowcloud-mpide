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

#ifndef FLOW_USERS_CONTACTREQUEST_H_
#define FLOW_USERS_CONTACTREQUEST_H_
#include "flow/core/base_types.h"
#include "flow/core/contactrequest_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowContactRequest
 * \brief Creates a new FlowContactRequest.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowContactRequest FlowContactRequest_New(FlowMemoryManager memoryManager){ return (FlowContactRequest)FlowMemoryManager_NewObject(memoryManager, 5, 2, FlowType_ContactRequest);}
/**
 * \memberof FlowContactRequest
 * \brief Registers meta data used for (de)serialising FlowContactRequest to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowContactRequest_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_ContactRequest))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_ContactRequest, "ContactRequest", 5, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContactRequest, _FlowContactRequest_UserID, FlowType_ID, "UserID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContactRequest, _FlowContactRequest_UserName, FlowType_String, "UserName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContactRequest, _FlowContactRequest_DisplayName, FlowType_String, "DisplayName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContactRequest, _FlowContactRequest_FriendRequest, FlowType_Boolean, "FriendRequest", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContactRequest, _FlowContactRequest_Message, FlowType_String, "Message", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_ContactRequest, _FlowContactRequest_rel_Accept, "accept");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_ContactRequest, _FlowContactRequest_rel_Reject, "reject");
	}
}
/**
 * \memberof FlowContactRequest
 * \brief Indicates whether the property UserID is set on this object.
 * 
 * Can be used to check whether UserID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_HasUserID(FlowContactRequest self) { return FlowObject_HasProperty(self, _FlowContactRequest_UserID);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowContactRequest_GetUserID(FlowContactRequest self) { return FlowObject_GetIDProperty(self, _FlowContactRequest_UserID);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContactRequest_SetUserID(FlowContactRequest self, FlowID value) { FlowObject_SetIDProperty(self, _FlowContactRequest_UserID, value);}
/**
 * \memberof FlowContactRequest
 * \brief Indicates whether the property UserName is set on this object.
 * 
 * Can be used to check whether UserName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_HasUserName(FlowContactRequest self) { return FlowObject_HasProperty(self, _FlowContactRequest_UserName);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
*/
static inline char *FlowContactRequest_GetUserName(FlowContactRequest self) { return FlowObject_GetStringProperty(self, _FlowContactRequest_UserName);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContactRequest_SetUserName(FlowContactRequest self, char *value) { FlowObject_SetStringProperty(self, _FlowContactRequest_UserName, value);}
/**
 * \memberof FlowContactRequest
 * \brief Indicates whether the property DisplayName is set on this object.
 * 
 * Can be used to check whether DisplayName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_HasDisplayName(FlowContactRequest self) { return FlowObject_HasProperty(self, _FlowContactRequest_DisplayName);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
*/
static inline char *FlowContactRequest_GetDisplayName(FlowContactRequest self) { return FlowObject_GetStringProperty(self, _FlowContactRequest_DisplayName);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContactRequest_SetDisplayName(FlowContactRequest self, char *value) { FlowObject_SetStringProperty(self, _FlowContactRequest_DisplayName, value);}
/**
 * \memberof FlowContactRequest
 * \brief Indicates whether the property FriendRequest is set on this object.
 * 
 * Can be used to check whether FriendRequest is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_HasFriendRequest(FlowContactRequest self) { return FlowObject_HasProperty(self, _FlowContactRequest_FriendRequest);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_GetFriendRequest(FlowContactRequest self) { return FlowObject_GetBooleanProperty(self, _FlowContactRequest_FriendRequest);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContactRequest_SetFriendRequest(FlowContactRequest self, bool value) { FlowObject_SetBooleanProperty(self, _FlowContactRequest_FriendRequest, value);}
/**
 * \memberof FlowContactRequest
 * \brief Indicates whether the property Message is set on this object.
 * 
 * Can be used to check whether Message is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_HasMessage(FlowContactRequest self) { return FlowObject_HasProperty(self, _FlowContactRequest_Message);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
*/
static inline char *FlowContactRequest_GetMessage(FlowContactRequest self) { return FlowObject_GetStringProperty(self, _FlowContactRequest_Message);}
/**
 * \memberof FlowContactRequest
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContactRequest_SetMessage(FlowContactRequest self, char *value) { FlowObject_SetStringProperty(self, _FlowContactRequest_Message, value);}
/**
 * \memberof FlowContactRequest
 * \ingroup Contactrequests
 * \brief Indicates whether \ref FlowContactRequest_Accept is available on this object.
 * 
 * Checks whether \ref FlowContactRequest_Accept is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_CanAccept(FlowContactRequest self) { return FlowObject_HasLink(self, _FlowContactRequest_rel_Accept);}
/**
 * \memberof FlowContactRequest
 * \ingroup Contactrequests
 * \brief Accept contact request
 *
 * For a friend contact request this adds a new contact in the friend list for the user and sets status to 'accepted' for both the user and the new contact.
 * For a not-friend contact request this makes the current user discoverable by the requesting user (for search users) and shares non-sensitive user details (DisplayName and FlowMessagingAddress).
 * The contact request is removed from the contact request list.
 * The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowContactRequest_Accept(FlowContactRequest self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowContactRequest_rel_Accept, FlowHTTPMethod_Put, NULL);}
/**
 * \memberof FlowContactRequest
 * \ingroup Contactrequests
 * \brief Indicates whether \ref FlowContactRequest_Reject is available on this object.
 * 
 * Checks whether \ref FlowContactRequest_Reject is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContactRequest_CanReject(FlowContactRequest self) { return FlowObject_HasLink(self, _FlowContactRequest_rel_Reject);}
/**
 * \memberof FlowContactRequest
 * \ingroup Contactrequests
 * \brief Reject contact request
 *
 * For a friend contact request this changes the status to 'Declined' for the requesting user. The contact request is removed from the contact request list.
 * The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowContactRequest_Reject(FlowContactRequest self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowContactRequest_rel_Reject, FlowHTTPMethod_Delete, NULL);}
#endif /* FLOW_USERS_CONTACTREQUEST_H_ */
