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

#ifndef FLOW_USERS_USER_H_
#define FLOW_USERS_USER_H_
#include "flow/core/authorisations_type.h"
#include "flow/core/base_types.h"
#include "flow/core/contacts_type.h"
#include "flow/core/datastore_type.h"
#include "flow/core/device_type.h"
#include "flow/core/deviceregistrationkeys_type.h"
#include "flow/core/devicerole.h"
#include "flow/core/deviceroles_type.h"
#include "flow/core/devices_type.h"
#include "flow/core/discoverable_type.h"
#include "flow/core/emailtype_type.h"
#include "flow/core/firmwareimages_type.h"
#include "flow/core/flow_enum.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/permission.h"
#include "flow/core/permissions_type.h"
#include "flow/core/setting_type.h"
#include "flow/core/settings_type.h"
#include "flow/core/socialnetworks_type.h"
#include "flow/core/tokencreatedresponse_type.h"
#include "flow/core/tokencredentials_type.h"
#include "flow/core/user_type.h"
#include "flow/core/userrefertype_type.h"
#include "flow/core/users_type.h"
#include "flow/core/visibledevices_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowUser
 * \brief Creates a new FlowUser.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowUser FlowUser_New(FlowMemoryManager memoryManager){ return (FlowUser)FlowMemoryManager_NewObject(memoryManager, 21, 37, FlowType_User);}
/**
 * \memberof FlowUser
 * \brief Registers meta data used for (de)serialising FlowUser to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowUser_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_User))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_User, "User", 21, 37);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_UserID, FlowType_ID, "UserID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_UserName, FlowType_String, "UserName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_DisplayName, FlowType_String, "DisplayName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_GivenName, FlowType_String, "GivenName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_Surname, FlowType_String, "Surname", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_DateOfBirth, FlowType_Datetime, "DateOfBirth", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_Email, FlowType_String, "Email", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_MobilePhoneNumber, FlowType_String, "MobilePhoneNumber", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_OldPassword, FlowType_String, "OldPassword", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_Password, FlowType_String, "Password", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_Activated, FlowType_Boolean, "Activated", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_Discoverable, FlowType_Discoverable, "Discoverable", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_AllowEmailCommunication, FlowType_Boolean, "AllowEmailCommunication", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_AllowDirectMarketing, FlowType_Boolean, "AllowDirectMarketing", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_CountryCode, FlowType_String, "CountryCode", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_Locale, FlowType_ID, "Locale", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_CreatedDate, FlowType_Datetime, "CreatedDate", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_ReferType, FlowType_UserReferType, "ReferType", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_User, _FlowUser_Refer, FlowType_String, "Refer", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_User, _FlowUser_DeviceRoles, "DeviceRoles", "DeviceRole", FlowType_DeviceRole, FlowType_DeviceRoles);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_User, _FlowUser_Permissions, "Permissions", "Permission", FlowType_Permission, FlowType_Permissions);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Activate, "activate");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Alldevices, "alldevices");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Allfavourites, "allfavourites");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Authorisation, "authorisation");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Contacts, "contacts");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Datastores, "datastores");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Deviceregistrationkeys, "deviceregistrationkeys");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Devices, "devices");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Discoverableby, "discoverableby");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Firmwares, "firmwares");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Flowconnect, "flowconnect");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Flowmessaging, "flowmessaging");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Flowrcs, "flowrcs");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Flowsongs, "flowsongs");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Juke, "juke");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Localcontent, "localcontent");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Musicfavourites, "musicfavourites");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Pausedactivities, "pausedactivities");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Recentcontent, "recentcontent");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Recenttracks, "recenttracks");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Recommendedcontent, "recommendedcontent");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Recommendedreleases, "recommendedreleases");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Remove, "remove");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Self, "self");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Settings, "settings");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Siriusxm, "siriusxm");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Siriusxmfavourites, "siriusxmfavourites");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Siriusxmrecent, "siriusxmrecent");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Sms, "sms");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Socialnetworks, "socialnetworks");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Storage, "storage");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Storedvalueaccounts, "storedvalueaccounts");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Subscriptions, "subscriptions");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Update, "update");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Visibledevices, "visibledevices");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Vouchers, "vouchers");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_User, _FlowUser_rel_Emails, "emails");
	}
}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property UserID is set on this object.
 * 
 * Can be used to check whether UserID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasUserID(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_UserID);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowUser_GetUserID(FlowUser self) { return FlowObject_GetIDProperty(self, _FlowUser_UserID);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetUserID(FlowUser self, FlowID value) { FlowObject_SetIDProperty(self, _FlowUser_UserID, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property UserName is set on this object.
 * 
 * Can be used to check whether UserName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasUserName(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_UserName);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetUserName(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_UserName);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetUserName(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_UserName, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property DisplayName is set on this object.
 * 
 * Can be used to check whether DisplayName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasDisplayName(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_DisplayName);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetDisplayName(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_DisplayName);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetDisplayName(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_DisplayName, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property GivenName is set on this object.
 * 
 * Can be used to check whether GivenName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasGivenName(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_GivenName);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetGivenName(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_GivenName);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetGivenName(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_GivenName, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Surname is set on this object.
 * 
 * Can be used to check whether Surname is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasSurname(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Surname);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetSurname(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_Surname);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetSurname(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_Surname, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property DateOfBirth is set on this object.
 * 
 * Can be used to check whether DateOfBirth is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasDateOfBirth(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_DateOfBirth);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowUser_GetDateOfBirth(FlowUser self) { return FlowObject_GetDateTimeProperty(self, _FlowUser_DateOfBirth);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetDateOfBirth(FlowUser self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowUser_DateOfBirth, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Email is set on this object.
 * 
 * Can be used to check whether Email is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasEmail(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Email);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetEmail(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_Email);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetEmail(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_Email, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property MobilePhoneNumber is set on this object.
 * 
 * Can be used to check whether MobilePhoneNumber is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasMobilePhoneNumber(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_MobilePhoneNumber);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetMobilePhoneNumber(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_MobilePhoneNumber);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetMobilePhoneNumber(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_MobilePhoneNumber, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property OldPassword is set on this object.
 * 
 * Can be used to check whether OldPassword is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasOldPassword(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_OldPassword);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetOldPassword(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_OldPassword);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetOldPassword(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_OldPassword, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Password is set on this object.
 * 
 * Can be used to check whether Password is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasPassword(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Password);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetPassword(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_Password);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetPassword(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_Password, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Activated is set on this object.
 * 
 * Can be used to check whether Activated is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasActivated(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Activated);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_GetActivated(FlowUser self) { return FlowObject_GetBooleanProperty(self, _FlowUser_Activated);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetActivated(FlowUser self, bool value) { FlowObject_SetBooleanProperty(self, _FlowUser_Activated, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Discoverable is set on this object.
 * 
 * Can be used to check whether Discoverable is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasDiscoverable(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Discoverable);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowDiscoverable FlowUser_GetDiscoverable(FlowUser self) { return (FlowDiscoverable)FlowObject_GetIntegerProperty(self, _FlowUser_Discoverable);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetDiscoverable(FlowUser self, FlowDiscoverable value) { FlowObject_SetIntegerProperty(self, _FlowUser_Discoverable, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property AllowEmailCommunication is set on this object.
 * 
 * Can be used to check whether AllowEmailCommunication is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasAllowEmailCommunication(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_AllowEmailCommunication);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_GetAllowEmailCommunication(FlowUser self) { return FlowObject_GetBooleanProperty(self, _FlowUser_AllowEmailCommunication);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetAllowEmailCommunication(FlowUser self, bool value) { FlowObject_SetBooleanProperty(self, _FlowUser_AllowEmailCommunication, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property AllowDirectMarketing is set on this object.
 * 
 * Can be used to check whether AllowDirectMarketing is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasAllowDirectMarketing(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_AllowDirectMarketing);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_GetAllowDirectMarketing(FlowUser self) { return FlowObject_GetBooleanProperty(self, _FlowUser_AllowDirectMarketing);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetAllowDirectMarketing(FlowUser self, bool value) { FlowObject_SetBooleanProperty(self, _FlowUser_AllowDirectMarketing, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property CountryCode is set on this object.
 * 
 * Can be used to check whether CountryCode is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasCountryCode(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_CountryCode);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetCountryCode(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_CountryCode);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetCountryCode(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_CountryCode, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Locale is set on this object.
 * 
 * Can be used to check whether Locale is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasLocale(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Locale);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowUser_GetLocale(FlowUser self) { return FlowObject_GetIDProperty(self, _FlowUser_Locale);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetLocale(FlowUser self, FlowID value) { FlowObject_SetIDProperty(self, _FlowUser_Locale, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property CreatedDate is set on this object.
 * 
 * Can be used to check whether CreatedDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasCreatedDate(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_CreatedDate);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowUser_GetCreatedDate(FlowUser self) { return FlowObject_GetDateTimeProperty(self, _FlowUser_CreatedDate);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetCreatedDate(FlowUser self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowUser_CreatedDate, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property ReferType is set on this object.
 * 
 * Can be used to check whether ReferType is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasReferType(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_ReferType);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowUserReferType FlowUser_GetReferType(FlowUser self) { return (FlowUserReferType)FlowObject_GetIntegerProperty(self, _FlowUser_ReferType);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetReferType(FlowUser self, FlowUserReferType value) { FlowObject_SetIntegerProperty(self, _FlowUser_ReferType, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Refer is set on this object.
 * 
 * Can be used to check whether Refer is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasRefer(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Refer);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetRefer(FlowUser self) { return FlowObject_GetStringProperty(self, _FlowUser_Refer);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUser_SetRefer(FlowUser self, char *value) { FlowObject_SetStringProperty(self, _FlowUser_Refer, value);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property DeviceRoles is set on this object.
 * 
 * Can be used to check whether DeviceRoles is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasDeviceRoles(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_DeviceRoles);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowDeviceRoles FlowUser_GetDeviceRoles(FlowUser self) { return (FlowDeviceRoles)FlowObject_GetObjectProperty(self, _FlowUser_DeviceRoles);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Permissions is set on this object.
 * 
 * Can be used to check whether Permissions is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasPermissions(FlowUser self) { return FlowObject_HasProperty(self, _FlowUser_Permissions);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline FlowPermissions FlowUser_GetPermissions(FlowUser self) { return (FlowPermissions)FlowObject_GetObjectProperty(self, _FlowUser_Permissions);}
/**
 * \memberof FlowUser
 * \ingroup OwnershipToken
 * \brief Indicates whether \ref FlowUser_Activate is available on this object.
 * 
 * Checks whether \ref FlowUser_Activate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanActivate(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Activate);}
/**
 * \memberof FlowUser
 * \ingroup OwnershipToken
 * \brief Creates a device ownership token for the user
 *
 * User password parameter is required in TokenCredentials body parameter if the current session is not for an authenticated user. TODO - document 'body' parameters
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowTokenCreatedResponse FlowUser_Activate(FlowUser self, FlowTokenCredentials data) { return (FlowTokenCreatedResponse) FlowObject_HTTPRequest(self, _FlowUser_rel_Activate, FlowHTTPMethod_Post, data, FlowType_TokenCreatedResponse);}
/**
 * \memberof FlowUser
 * \ingroup UserDevices
 * \brief Indicates whether \ref FlowUser_RetrieveAllDevices is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveAllDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveAllDevices(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Alldevices);}
/**
 * \memberof FlowUser
 * \ingroup UserDevices
 * \brief Retrieve all devices owned by or associated with the user. A user is associated with a device if it has at least one DeviceRole on the device.
 *
 * Note: this API retrieves less device information than "Get owned devices". It is also possible for a user to retrieve the device list for another user (e.g a friend).
 * A friend will only be able to see devices that have been made visible to the current user.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevices FlowUser_RetrieveAllDevices(FlowUser self, int pageSize)
{
	FlowDevices result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Alldevices))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Alldevices));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowDevices) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Devices);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup AuthorisationGroups
 * \brief Indicates whether \ref FlowUser_RetrieveAuthorisations is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveAuthorisations is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveAuthorisations(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Authorisation);}
/**
 * \memberof FlowUser
 * \ingroup AuthorisationGroups
 * \brief Retrieve user authorisation groups
 *
 * Retrieve a list of authorisation groups that the specified user belongs to.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthorisations FlowUser_RetrieveAuthorisations(FlowUser self) { return (FlowAuthorisations) FlowObject_HTTPRequest(self, _FlowUser_rel_Authorisation, FlowHTTPMethod_Get, NULL, FlowType_Authorisations);}
/**
 * \memberof FlowUser
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowUser_RetrieveContacts is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveContacts is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveContacts(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Contacts);}
/**
 * \memberof FlowUser
 * \ingroup Contacts
 * \brief Retrieve contacts
 *
 * Retrieves the list of all user and device contacts. This also provides the entry point to get other links for the contact service.
 * The response can be used to get specific contact types (e.g. users, devices, friends, not friends), contact requests, blocked users and all contact labels.
 * 
 * Note: if a user contact is not 'Discoverable' then only the UserName is retrieved for the contact (not the DisplayName or flowmessagingaddress link).
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContacts FlowUser_RetrieveContacts(FlowUser self, int pageSize)
{
	FlowContacts result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Contacts))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Contacts));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowContacts) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Contacts);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup Userdatastores
 * \brief Indicates whether \ref FlowUser_RetrieveDataStore is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveDataStore is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveDataStore(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Datastores);}
/**
 * \memberof FlowUser
 * \ingroup Userdatastores
 * \brief Retrieve data store
 *
 * Retrieve the data store for the specified user. NOTE: data store doesn't have to exists it will be create once first record is added The client must be authenticated to use this call.
 * \param self Object on which the method will be applied
 * \param dataStoreName dataStoreName
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDataStore FlowUser_RetrieveDataStore(FlowUser self, char *dataStoreName)
{
	FlowDataStore result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Datastores))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Datastores));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, dataStoreName);
			result = (FlowDataStore) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Get, NULL, FlowType_DataStore);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \brief Indicates whether \ref FlowUser_RetrieveDeviceRegistrationKeys is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveDeviceRegistrationKeys is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveDeviceRegistrationKeys(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Deviceregistrationkeys);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDeviceRegistrationKeys FlowUser_RetrieveDeviceRegistrationKeys(FlowUser self, int pageSize)
{
	FlowDeviceRegistrationKeys result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Deviceregistrationkeys))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Deviceregistrationkeys));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowDeviceRegistrationKeys) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_DeviceRegistrationKeys);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup UserDevices
 * \brief Indicates whether \ref FlowUser_RetrieveOwnedDevices is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveOwnedDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveOwnedDevices(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Devices);}
/**
 * \memberof FlowUser
 * \ingroup UserDevices
 * \brief Retrieve all the devices registered to the user
 *
 * The user must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevices FlowUser_RetrieveOwnedDevices(FlowUser self, int pageSize)
{
	FlowDevices result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Devices))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Devices));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowDevices) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Devices);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup Deviceownership
 * \brief Indicates whether \ref FlowUser_AddOwnedDevice is available on this object.
 * 
 * Checks whether \ref FlowUser_AddOwnedDevice is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanAddOwnedDevice(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Devices);}
/**
 * \memberof FlowUser
 * \ingroup Deviceownership
 * \brief Add an owned device
 *
 * Registers the user as the owner of the specified device. The device will have access to the users resources.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Conflict "FlowError_Conflict"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUser_AddOwnedDevice(FlowUser self, FlowDevice data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowUser_rel_Devices, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowUser
 * \ingroup UserDiscoverability
 * \brief Indicates whether \ref FlowUser_RetrieveDiscoverableByUsers is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveDiscoverableByUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveDiscoverableByUsers(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Discoverableby);}
/**
 * \memberof FlowUser
 * \ingroup UserDiscoverability
 * \brief Retrieve a list of users who can discover this user
 *
 * Retrieves the list of users who can discover this user.
 * 
 * Note: If User Discoverable is set to Public then all other users can discover this user by default.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowUser_RetrieveDiscoverableByUsers(FlowUser self, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Discoverableby))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Discoverableby));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowUsers) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Users);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup UserDiscoverability
 * \brief Indicates whether \ref FlowUser_AddDiscoverableByUsers is available on this object.
 * 
 * Checks whether \ref FlowUser_AddDiscoverableByUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanAddDiscoverableByUsers(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Discoverableby);}
/**
 * \memberof FlowUser
 * \ingroup UserDiscoverability
 * \brief Add discoverable by users
 *
 * Add users to the discoverableby user list for the current user. A discoverableby user can discover the current user even if their discoverable level is not public. Users can added using the <b>discoverableby</b> link for a <b>User</b>.<h3>Request</h3>The Request body must be of type <b>Users</b> where each <b>User</b> must have the UserName or UserID field.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUser_AddDiscoverableByUsers(FlowUser self, FlowUsers data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowUser_rel_Discoverableby, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowUser
 * \ingroup UserFirmwares
 * \brief Indicates whether \ref FlowUser_RetrieveAllFirmwareImages is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveAllFirmwareImages is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveAllFirmwareImages(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Firmwares);}
/**
 * \memberof FlowUser
 * \ingroup UserFirmwares
 * \brief Retrieve all firmware images available for devices owned by or firmware published by a user
 *
 * Note: the user must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowFirmwareImages FlowUser_RetrieveAllFirmwareImages(FlowUser self, int pageSize)
{
	FlowFirmwareImages result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Firmwares))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Firmwares));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowFirmwareImages) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_FirmwareImages);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup FlowUserAccountManagement
 * \brief Indicates whether \ref FlowUser_Remove is available on this object.
 * 
 * Checks whether \ref FlowUser_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRemove(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Remove);}
/**
 * \memberof FlowUser
 * \ingroup FlowUserAccountManagement
 * \brief Delete the user and their associated favourites, subscriptions and stored value accounts
 *
 * The user must be logged in (not using a device session) and authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUser_Remove(FlowUser self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowUser_rel_Remove, FlowHTTPMethod_Delete, NULL);}
/**
 * \memberof FlowUser
 * \brief Indicates whether \ref FlowUser_RetrieveDetails is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveDetails is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveDetails(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Self);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUser FlowUser_RetrieveDetails(FlowUser self) { return (FlowUser) FlowObject_HTTPRequest(self, _FlowUser_rel_Self, FlowHTTPMethod_Get, NULL, FlowType_User);}
/**
 * \memberof FlowUser
 * \ingroup UserSettings
 * \brief Indicates whether \ref FlowUser_RetrieveSetting is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveSetting is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveSetting(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Settings);}
/**
 * \memberof FlowUser
 * \ingroup UserSettings
 * \brief Retrieve specified key/value setting for the user
 *
 * The user must be logged in to use this API.
 * \param self Object on which the method will be applied
 * \param key key
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSetting FlowUser_RetrieveSetting(FlowUser self, FlowID key)
{
	FlowSetting result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Settings))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Settings));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, key);
			result = (FlowSetting) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Get, NULL, FlowType_Setting);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup UserSettings
 * \brief Indicates whether \ref FlowUser_RetrieveSettingsByQuery is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveSettingsByQuery is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveSettingsByQuery(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Settings);}
/**
 * \memberof FlowUser
 * \ingroup UserSettings
 * \brief Retrieve all settings that match the query for the user
 *
 * The user must be logged in to use this API.
 * 
 * To obtain a subset of settings a query can be passed into the request. A query takes the form:
 * \@Key {operator} {key pattern}
 * 
 * The supported query operators are:
 * | Operator | Description |
 * | :------: | :---------- |
 * | CONTAINS | key contains a value. e.g. \@Key CONTAINS 'ui'|
 * | LIKE | key like a value (including multiple wildcards, represented by the % character). e.g. \@Key LIKE 'myapp.ui.%''|
 * | IN | key in a list of possible values. e.g. \@Key IN ('pattern1', 'pattern2')|
 * | == | key equals specific value. e.g. \@Key == 'myapp.ui.theme'|
 * | != | key is not equal to specific value. e.g. \@Key != 'example' |
 * | > | key greater than specific value. e.g. \@Key > 12345 |
 * | >= | key greater than or equal to specific value. e.g. \@Key >= 12345 |
 * | < | key less than specific value. e.g. \@Key < 12345 |
 * | <= | key less than or equal tospecific value. e.g. \@Key <= 12345 |
 * \param self Object on which the method will be applied
 * \param query query
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowUser_RetrieveSettingsByQuery(FlowUser self, char *query, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Settings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Settings));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "query", query);
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowSettings) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Settings);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup UserSettings
 * \brief Indicates whether \ref FlowUser_RetrieveSettings is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveSettings is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveSettings(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Settings);}
/**
 * \memberof FlowUser
 * \ingroup UserSettings
 * \brief Retrieve all settings for the user
 *
 * The user must be logged in to use this API.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowUser_RetrieveSettings(FlowUser self, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Settings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Settings));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowSettings) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Settings);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \brief Indicates whether \ref FlowUser_SendUserSMS is available on this object.
 * 
 * Checks whether \ref FlowUser_SendUserSMS is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanSendUserSMS(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Sms);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param smsType smsType
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUser_SendUserSMS(FlowUser self, char *smsType)
{
	bool result = false;
	if(FlowObject_HasLink(self, _FlowUser_rel_Sms))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Sms));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, smsType);
			result = FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Post, NULL);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \brief Indicates whether \ref FlowUser_SendUserSMSForGroup is available on this object.
 * 
 * Checks whether \ref FlowUser_SendUserSMSForGroup is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanSendUserSMSForGroup(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Sms);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param smsType smsType
 * \param templateGroup templateGroup
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUser_SendUserSMSForGroup(FlowUser self, char *smsType, FlowID templateGroup)
{
	bool result = false;
	if(FlowObject_HasLink(self, _FlowUser_rel_Sms))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Sms));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, smsType);
			FlowHTTPQuery_AppendPathSuffix(query, "group");
			FlowHTTPQuery_AppendPathSuffix(query, templateGroup);
			result = FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Post, NULL);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \ingroup SocialNetworks
 * \brief Indicates whether \ref FlowUser_RetrieveSocialNetworks is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveSocialNetworks is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveSocialNetworks(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Socialnetworks);}
/**
 * \memberof FlowUser
 * \ingroup SocialNetworks
 * \brief Retrieve the top level social networks for the user
 *
 * This contains links for flow contacts and facebook resources. The user must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSocialNetworks FlowUser_RetrieveSocialNetworks(FlowUser self) { return (FlowSocialNetworks) FlowObject_HTTPRequest(self, _FlowUser_rel_Socialnetworks, FlowHTTPMethod_Get, NULL, FlowType_SocialNetworks);}
/**
 * \memberof FlowUser
 * \brief Indicates whether the property Storage is set on this object.
 * 
 * Can be used to check whether Storage is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_HasStorage(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Storage);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
*/
static inline char *FlowUser_GetStorage(FlowUser self) { return FlowObject_GetLink(self, _FlowUser_rel_Storage);}
/**
 * \memberof FlowUser
 * \ingroup FlowUserAccountManagement
 * \brief Indicates whether \ref FlowUser_Update is available on this object.
 * 
 * Checks whether \ref FlowUser_Update is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanUpdate(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Update);}
/**
 * \memberof FlowUser
 * \ingroup FlowUserAccountManagement
 * \brief Update the details/preferences for the user
 *
 * This can be used to change: username, password, email address, displayname, discoverable level (for Social Networks) and other preferences.
 * The user must be logged in (not using a device session) and authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Conflict "FlowError_Conflict"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUser_Update(FlowUser self, FlowUser data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowUser_rel_Update, FlowHTTPMethod_Put, data);}
/**
 * \memberof FlowUser
 * \ingroup UserDeviceVisibility
 * \brief Indicates whether \ref FlowUser_RetrieveVisibleDevices is available on this object.
 * 
 * Checks whether \ref FlowUser_RetrieveVisibleDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanRetrieveVisibleDevices(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Visibledevices);}
/**
 * \memberof FlowUser
 * \ingroup UserDeviceVisibility
 * \brief Retrieve a list of devices made visible by other users
 *
 * Retrieves a list of devices made visible to this user by other users.
 * 
 * Note: this API can be useful when looking for devices to add as device contacts in the contact service. The UserID, UserName in each VisibleDevice indicates who made the device visible.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowVisibleDevices FlowUser_RetrieveVisibleDevices(FlowUser self, int pageSize)
{
	FlowVisibleDevices result = NULL;
	if(FlowObject_HasLink(self, _FlowUser_rel_Visibledevices))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Visibledevices));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowVisibleDevices) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_VisibleDevices);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowUser
 * \brief Indicates whether \ref FlowUser_SendUserEmailForGroup is available on this object.
 * 
 * Checks whether \ref FlowUser_SendUserEmailForGroup is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUser_CanSendUserEmailForGroup(FlowUser self) { return FlowObject_HasLink(self, _FlowUser_rel_Emails);}
/**
 * \memberof FlowUser
 * \param self Object on which the method will be applied
 * \param emailType emailType
 * \param templateGroup templateGroup
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUser_SendUserEmailForGroup(FlowUser self, FlowEmailType emailType, FlowID templateGroup)
{
	bool result = false;
	if(FlowObject_HasLink(self, _FlowUser_rel_Emails))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUser_rel_Emails));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, FlowEnum_Serialise(FlowType_EmailType, emailType));
			FlowHTTPQuery_AppendPathSuffix(query, "group");
			FlowHTTPQuery_AppendPathSuffix(query, templateGroup);
			result = FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Post, NULL);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
#endif /* FLOW_USERS_USER_H_ */
