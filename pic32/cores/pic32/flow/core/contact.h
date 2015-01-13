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

#ifndef FLOW_USERS_CONTACT_H_
#define FLOW_USERS_CONTACT_H_
#include "flow/core/base_types.h"
#include "flow/core/contact_type.h"
#include "flow/core/contactstatus_type.h"
#include "flow/core/device_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/label.h"
#include "flow/core/labels_type.h"
#include "flow/core/user.h"
#include "flow/core/user_type.h"
#include "flow/core/users_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowContact
 * \brief Creates a new FlowContact.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowContact FlowContact_New(FlowMemoryManager memoryManager){ return (FlowContact)FlowMemoryManager_NewObject(memoryManager, 11, 4, FlowType_Contact);}
/**
 * \memberof FlowContact
 * \brief Registers meta data used for (de)serialising FlowContact to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowContact_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Contact))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Contact, "Contact", 11, 4);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_UserID, FlowType_ID, "UserID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_UserName, FlowType_String, "UserName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_IsFriend, FlowType_Boolean, "IsFriend", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_Message, FlowType_String, "Message", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_Status, FlowType_ContactStatus, "Status", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_DeviceID, FlowType_ID, "DeviceID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_DeviceName, FlowType_String, "DeviceName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_DeviceType, FlowType_ID, "DeviceType", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Contact, _FlowContact_Users, "Users", "User", FlowType_User, FlowType_Users);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contact, _FlowContact_DisplayName, FlowType_String, "DisplayName", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Contact, _FlowContact_Labels, "Labels", "Label", FlowType_Label, FlowType_Labels);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contact, _FlowContact_rel_Device, "device");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contact, _FlowContact_rel_Remove, "remove");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contact, _FlowContact_rel_Update, "update");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contact, _FlowContact_rel_User, "user");
	}
}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property UserID is set on this object.
 * 
 * Can be used to check whether UserID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasUserID(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_UserID);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowContact_GetUserID(FlowContact self) { return FlowObject_GetIDProperty(self, _FlowContact_UserID);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetUserID(FlowContact self, FlowID value) { FlowObject_SetIDProperty(self, _FlowContact_UserID, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property UserName is set on this object.
 * 
 * Can be used to check whether UserName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasUserName(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_UserName);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline char *FlowContact_GetUserName(FlowContact self) { return FlowObject_GetStringProperty(self, _FlowContact_UserName);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetUserName(FlowContact self, char *value) { FlowObject_SetStringProperty(self, _FlowContact_UserName, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property IsFriend is set on this object.
 * 
 * Can be used to check whether IsFriend is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasIsFriend(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_IsFriend);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_GetIsFriend(FlowContact self) { return FlowObject_GetBooleanProperty(self, _FlowContact_IsFriend);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetIsFriend(FlowContact self, bool value) { FlowObject_SetBooleanProperty(self, _FlowContact_IsFriend, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property Message is set on this object.
 * 
 * Can be used to check whether Message is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasMessage(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_Message);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline char *FlowContact_GetMessage(FlowContact self) { return FlowObject_GetStringProperty(self, _FlowContact_Message);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetMessage(FlowContact self, char *value) { FlowObject_SetStringProperty(self, _FlowContact_Message, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property Status is set on this object.
 * 
 * Can be used to check whether Status is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasStatus(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_Status);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline FlowContactStatus FlowContact_GetStatus(FlowContact self) { return (FlowContactStatus)FlowObject_GetIntegerProperty(self, _FlowContact_Status);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetStatus(FlowContact self, FlowContactStatus value) { FlowObject_SetIntegerProperty(self, _FlowContact_Status, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property DeviceID is set on this object.
 * 
 * Can be used to check whether DeviceID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasDeviceID(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_DeviceID);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowContact_GetDeviceID(FlowContact self) { return FlowObject_GetIDProperty(self, _FlowContact_DeviceID);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetDeviceID(FlowContact self, FlowID value) { FlowObject_SetIDProperty(self, _FlowContact_DeviceID, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property DeviceName is set on this object.
 * 
 * Can be used to check whether DeviceName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasDeviceName(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_DeviceName);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline char *FlowContact_GetDeviceName(FlowContact self) { return FlowObject_GetStringProperty(self, _FlowContact_DeviceName);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetDeviceName(FlowContact self, char *value) { FlowObject_SetStringProperty(self, _FlowContact_DeviceName, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property DeviceType is set on this object.
 * 
 * Can be used to check whether DeviceType is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasDeviceType(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_DeviceType);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowContact_GetDeviceType(FlowContact self) { return FlowObject_GetIDProperty(self, _FlowContact_DeviceType);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetDeviceType(FlowContact self, FlowID value) { FlowObject_SetIDProperty(self, _FlowContact_DeviceType, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property Users is set on this object.
 * 
 * Can be used to check whether Users is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasUsers(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_Users);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline FlowUsers FlowContact_GetUsers(FlowContact self) { return (FlowUsers)FlowObject_GetObjectProperty(self, _FlowContact_Users);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property DisplayName is set on this object.
 * 
 * Can be used to check whether DisplayName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasDisplayName(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_DisplayName);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline char *FlowContact_GetDisplayName(FlowContact self) { return FlowObject_GetStringProperty(self, _FlowContact_DisplayName);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContact_SetDisplayName(FlowContact self, char *value) { FlowObject_SetStringProperty(self, _FlowContact_DisplayName, value);}
/**
 * \memberof FlowContact
 * \brief Indicates whether the property Labels is set on this object.
 * 
 * Can be used to check whether Labels is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_HasLabels(FlowContact self) { return FlowObject_HasProperty(self, _FlowContact_Labels);}
/**
 * \memberof FlowContact
 * \param self Object on which the method will be applied
*/
static inline FlowLabels FlowContact_GetLabels(FlowContact self) { return (FlowLabels)FlowObject_GetObjectProperty(self, _FlowContact_Labels);}
/**
 * \memberof FlowContact
 * \ingroup Contactdetails
 * \brief Indicates whether \ref FlowContact_RetrieveDevice is available on this object.
 * 
 * Checks whether \ref FlowContact_RetrieveDevice is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_CanRetrieveDevice(FlowContact self) { return FlowObject_HasLink(self, _FlowContact_rel_Device);}
/**
 * \memberof FlowContact
 * \ingroup Contactdetails
 * \brief Retrieve device details
 *
 * Retrieve the details of the device from the device contact. The device information retrieved is the same as GetDevice in the user service.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevice FlowContact_RetrieveDevice(FlowContact self) { return (FlowDevice) FlowObject_HTTPRequest(self, _FlowContact_rel_Device, FlowHTTPMethod_Get, NULL, FlowType_Device);}
/**
 * \memberof FlowContact
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowContact_Remove is available on this object.
 * 
 * Checks whether \ref FlowContact_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_CanRemove(FlowContact self) { return FlowObject_HasLink(self, _FlowContact_rel_Remove);}
/**
 * \memberof FlowContact
 * \ingroup Contacts
 * \brief Delete a contact
 *
 * Delete a user or device contact from the contact list.
 * 
 * For a user contact if the contact status was for an 'Accepted' friend then it will change the corresponding entry in the friends contact list to 'removed', or if the status was 'Requested' it will delete the corresponding contact request.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowContact_Remove(FlowContact self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowContact_rel_Remove, FlowHTTPMethod_Delete, NULL);}
/**
 * \memberof FlowContact
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowContact_Update is available on this object.
 * 
 * Checks whether \ref FlowContact_Update is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_CanUpdate(FlowContact self) { return FlowObject_HasLink(self, _FlowContact_rel_Update);}
/**
 * \memberof FlowContact
 * \ingroup Contacts
 * \brief Update contact
 *
 * Update a user or device contact. This lets the user change DisplayName and Labels for a user or device contact. If a contact display name has not been set then the display name retrieved will come from the user.
 * 
 * For a user contact IsFriend can also be changed. When enabled it will send a friend request (with optional Message) and when disabled it will remove the friend status from the contact.
 * Any DisplayName or Labels not included in the update will be removed for the contact.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowContact_Update(FlowContact self, FlowUser data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowContact_rel_Update, FlowHTTPMethod_Put, data);}
/**
 * \memberof FlowContact
 * \ingroup Contactdetails
 * \brief Indicates whether \ref FlowContact_RetrieveUser is available on this object.
 * 
 * Checks whether \ref FlowContact_RetrieveUser is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContact_CanRetrieveUser(FlowContact self) { return FlowObject_HasLink(self, _FlowContact_rel_User);}
/**
 * \memberof FlowContact
 * \ingroup Contactdetails
 * \brief Retrieve user details
 *
 * Retrieve the details of the user from the user contact. The user information retrieved is the same as GetUser in the user service.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUser FlowContact_RetrieveUser(FlowContact self) { return (FlowUser) FlowObject_HTTPRequest(self, _FlowContact_rel_User, FlowHTTPMethod_Get, NULL, FlowType_User);}
#endif /* FLOW_USERS_CONTACT_H_ */
