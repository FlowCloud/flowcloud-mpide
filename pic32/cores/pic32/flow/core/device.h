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

#ifndef FLOW_USERS_DEVICE_H_
#define FLOW_USERS_DEVICE_H_
#include "flow/core/authenticationtokencreatedresponse_type.h"
#include "flow/core/base_types.h"
#include "flow/core/datastore_type.h"
#include "flow/core/device_type.h"
#include "flow/core/deviceroles_type.h"
#include "flow/core/deviceuserregistrationcredentials_type.h"
#include "flow/core/firmwareimages_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/flowserverlicence_type.h"
#include "flow/core/http_query.h"
#include "flow/core/permission.h"
#include "flow/core/permissions_type.h"
#include "flow/core/setting_type.h"
#include "flow/core/settings_type.h"
#include "flow/core/strings_type.h"
#include "flow/core/upgrades_type.h"
#include "flow/core/user_type.h"
#include "flow/core/users_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDevice
 * \brief Creates a new FlowDevice.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDevice FlowDevice_New(FlowMemoryManager memoryManager){ return (FlowDevice)FlowMemoryManager_NewObject(memoryManager, 14, 21, FlowType_Device);}
/**
 * \memberof FlowDevice
 * \brief Registers meta data used for (de)serialising FlowDevice to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDevice_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Device))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Device, "Device", 14, 21);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_DeviceID, FlowType_ID, "DeviceID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_DeviceName, FlowType_String, "DeviceName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_DeviceType, FlowType_ID, "DeviceType", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_SerialNumber, FlowType_String, "SerialNumber", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_MACAddress, FlowType_String, "MACAddress", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_SoftwareVersion, FlowType_String, "SoftwareVersion", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_FlowServerKey, FlowType_String, "FlowServerKey", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_RemoteAccessIPAddress, FlowType_String, "RemoteAccessIPAddress", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_RemoteAccessPort, FlowType_Integer, "RemoteAccessPort", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_CreatedDate, FlowType_Datetime, "CreatedDate", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_ClaimOwnershipExpiryDate, FlowType_Datetime, "ClaimOwnershipExpiryDate", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Device, _FlowDevice_RegistrationKey, FlowType_Token, "RegistrationKey", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Device, _FlowDevice_Capabilities, "Capabilities", "Capability", FlowType_String, FlowType_Strings);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Device, _FlowDevice_Permissions, "Permissions", "Permission", FlowType_Permission, FlowType_Permissions);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Allfavourites, "allfavourites");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Datastores, "datastores");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Firmwares, "firmwares");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Flowmessaging, "flowmessaging");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Flowserverkey, "flowserverkey");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Offlinestreamingstatus, "offlinestreamingstatus");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Pausedactivities, "pausedactivities");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Recentcontent, "recentcontent");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Recenttracks, "recenttracks");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Registeruser, "registeruser");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Roles, "roles");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Self, "self");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Settings, "settings");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Unregisteruser, "unregisteruser");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Update, "update");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Upgrades, "upgrades");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_User, "user");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Userpausedactivities, "userpausedactivities");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Users, "users");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Usersettings, "usersettings");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Device, _FlowDevice_rel_Visibility, "visibility");
	}
}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property DeviceID is set on this object.
 * 
 * Can be used to check whether DeviceID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasDeviceID(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_DeviceID);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowDevice_GetDeviceID(FlowDevice self) { return FlowObject_GetIDProperty(self, _FlowDevice_DeviceID);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetDeviceID(FlowDevice self, FlowID value) { FlowObject_SetIDProperty(self, _FlowDevice_DeviceID, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property DeviceName is set on this object.
 * 
 * Can be used to check whether DeviceName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasDeviceName(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_DeviceName);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowDevice_GetDeviceName(FlowDevice self) { return FlowObject_GetStringProperty(self, _FlowDevice_DeviceName);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetDeviceName(FlowDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowDevice_DeviceName, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property DeviceType is set on this object.
 * 
 * Can be used to check whether DeviceType is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasDeviceType(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_DeviceType);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowDevice_GetDeviceType(FlowDevice self) { return FlowObject_GetIDProperty(self, _FlowDevice_DeviceType);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetDeviceType(FlowDevice self, FlowID value) { FlowObject_SetIDProperty(self, _FlowDevice_DeviceType, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property SerialNumber is set on this object.
 * 
 * Can be used to check whether SerialNumber is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasSerialNumber(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_SerialNumber);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowDevice_GetSerialNumber(FlowDevice self) { return FlowObject_GetStringProperty(self, _FlowDevice_SerialNumber);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetSerialNumber(FlowDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowDevice_SerialNumber, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property MACAddress is set on this object.
 * 
 * Can be used to check whether MACAddress is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasMACAddress(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_MACAddress);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowDevice_GetMACAddress(FlowDevice self) { return FlowObject_GetStringProperty(self, _FlowDevice_MACAddress);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetMACAddress(FlowDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowDevice_MACAddress, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property SoftwareVersion is set on this object.
 * 
 * Can be used to check whether SoftwareVersion is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasSoftwareVersion(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_SoftwareVersion);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowDevice_GetSoftwareVersion(FlowDevice self) { return FlowObject_GetStringProperty(self, _FlowDevice_SoftwareVersion);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetSoftwareVersion(FlowDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowDevice_SoftwareVersion, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property FlowServerKey is set on this object.
 * 
 * Can be used to check whether FlowServerKey is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasFlowServerKey(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_FlowServerKey);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowDevice_GetFlowServerKey(FlowDevice self) { return FlowObject_GetStringProperty(self, _FlowDevice_FlowServerKey);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetFlowServerKey(FlowDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowDevice_FlowServerKey, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property RemoteAccessIPAddress is set on this object.
 * 
 * Can be used to check whether RemoteAccessIPAddress is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasRemoteAccessIPAddress(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_RemoteAccessIPAddress);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowDevice_GetRemoteAccessIPAddress(FlowDevice self) { return FlowObject_GetStringProperty(self, _FlowDevice_RemoteAccessIPAddress);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetRemoteAccessIPAddress(FlowDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowDevice_RemoteAccessIPAddress, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property RemoteAccessPort is set on this object.
 * 
 * Can be used to check whether RemoteAccessPort is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasRemoteAccessPort(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_RemoteAccessPort);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline int FlowDevice_GetRemoteAccessPort(FlowDevice self) { return FlowObject_GetIntegerProperty(self, _FlowDevice_RemoteAccessPort);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetRemoteAccessPort(FlowDevice self, int value) { FlowObject_SetIntegerProperty(self, _FlowDevice_RemoteAccessPort, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property CreatedDate is set on this object.
 * 
 * Can be used to check whether CreatedDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasCreatedDate(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_CreatedDate);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowDevice_GetCreatedDate(FlowDevice self) { return FlowObject_GetDateTimeProperty(self, _FlowDevice_CreatedDate);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetCreatedDate(FlowDevice self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowDevice_CreatedDate, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property ClaimOwnershipExpiryDate is set on this object.
 * 
 * Can be used to check whether ClaimOwnershipExpiryDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasClaimOwnershipExpiryDate(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_ClaimOwnershipExpiryDate);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowDevice_GetClaimOwnershipExpiryDate(FlowDevice self) { return FlowObject_GetDateTimeProperty(self, _FlowDevice_ClaimOwnershipExpiryDate);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetClaimOwnershipExpiryDate(FlowDevice self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowDevice_ClaimOwnershipExpiryDate, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property RegistrationKey is set on this object.
 * 
 * Can be used to check whether RegistrationKey is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasRegistrationKey(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_RegistrationKey);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowDevice_GetRegistrationKey(FlowDevice self) { return FlowObject_GetTokenProperty(self, _FlowDevice_RegistrationKey);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDevice_SetRegistrationKey(FlowDevice self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowDevice_RegistrationKey, value);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property Capabilities is set on this object.
 * 
 * Can be used to check whether Capabilities is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasCapabilities(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_Capabilities);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline FlowStrings FlowDevice_GetCapabilities(FlowDevice self) { return (FlowStrings)FlowObject_GetObjectProperty(self, _FlowDevice_Capabilities);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether the property Permissions is set on this object.
 * 
 * Can be used to check whether Permissions is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_HasPermissions(FlowDevice self) { return FlowObject_HasProperty(self, _FlowDevice_Permissions);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
*/
static inline FlowPermissions FlowDevice_GetPermissions(FlowDevice self) { return (FlowPermissions)FlowObject_GetObjectProperty(self, _FlowDevice_Permissions);}
/**
 * \memberof FlowDevice
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDevice_RetrieveDataStore is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveDataStore is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveDataStore(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Datastores);}
/**
 * \memberof FlowDevice
 * \ingroup DataStores
 * \brief Retrieve data store
 *
 * Retrieve the data store for the specified device. NOTE: data store doesn't have to exists it will be create once first record is added The client must be authenticated to use this call.
 * \param self Object on which the method will be applied
 * \param dataStoreName dataStoreName
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDataStore FlowDevice_RetrieveDataStore(FlowDevice self, char *dataStoreName)
{
	FlowDataStore result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Datastores))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Datastores));
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
 * \memberof FlowDevice
 * \ingroup Firmwares
 * \brief Indicates whether \ref FlowDevice_RetrieveFirmwareImages is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveFirmwareImages is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveFirmwareImages(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Firmwares);}
/**
 * \memberof FlowDevice
 * \ingroup Firmwares
 * \brief Retrieve device type firmwares
 *
 * Retrieves all firmware images available to the current client.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowFirmwareImages FlowDevice_RetrieveFirmwareImages(FlowDevice self, int pageSize)
{
	FlowFirmwareImages result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Firmwares))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Firmwares));
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
 * \memberof FlowDevice
 * \brief Indicates whether \ref FlowDevice_RetrieveFlowServerLicenceKey is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveFlowServerLicenceKey is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveFlowServerLicenceKey(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Flowserverkey);}
/**
 * \memberof FlowDevice
 * \brief Retrieve device FlowServerKey
 *
 * Retrieve the flow server key assigned to the current device. The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Internal "FlowError_Internal"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowFlowServerLicence FlowDevice_RetrieveFlowServerLicenceKey(FlowDevice self) { return (FlowFlowServerLicence) FlowObject_HTTPRequest(self, _FlowDevice_rel_Flowserverkey, FlowHTTPMethod_Get, NULL, FlowType_FlowServerLicence);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceOwnership
 * \brief Indicates whether \ref FlowDevice_AssignOwner is available on this object.
 * 
 * Checks whether \ref FlowDevice_AssignOwner is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanAssignOwner(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Registeruser);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceOwnership
 * \brief Assign device owner
 *
 * Assign the owner of the client device, so the device can share the owners resources (such as favourites and settings). This uses a device registration UserToken to identify the user.
 * 
 * This API can only be used if the device is not already owned by another user. The device client will re-authenticate after the owner has changed to start a new client session with access to owners resources.
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
static inline FlowAuthenticationTokenCreatedResponse FlowDevice_AssignOwner(FlowDevice self, FlowDeviceUserRegistrationCredentials data) { return (FlowAuthenticationTokenCreatedResponse) FlowObject_HTTPRequest(self, _FlowDevice_rel_Registeruser, FlowHTTPMethod_Post, data, FlowType_AuthenticationTokenCreatedResponse);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceUsers
 * \brief Indicates whether \ref FlowDevice_RetrieveRoles is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveRoles is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveRoles(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Roles);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceUsers
 * \brief Retrieve device roles
 *
 * Retrieve list of roles that are available for the device type and can be used when granting another user permission to use the device. The client must be authenticated to use this API.
 * 
 * Note: the roles returned are licensee application specific and the server has no knowledge of the roles.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDeviceRoles FlowDevice_RetrieveRoles(FlowDevice self, int pageSize)
{
	FlowDeviceRoles result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Roles))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Roles));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowDeviceRoles) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_DeviceRoles);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowDevice
 * \brief Indicates whether \ref FlowDevice_Remove is available on this object.
 * 
 * Checks whether \ref FlowDevice_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRemove(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Self);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDevice_Remove(FlowDevice self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowDevice_rel_Self, FlowHTTPMethod_Delete, NULL);}
/**
 * \memberof FlowDevice
 * \brief Indicates whether \ref FlowDevice_Reset is available on this object.
 * 
 * Checks whether \ref FlowDevice_Reset is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanReset(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Self);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \param reset reset
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDevice_Reset(FlowDevice self, char *reset)
{
	bool result = false;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Self))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Self));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "reset", reset);
			result = FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Delete, NULL);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowDevice
 * \brief Indicates whether \ref FlowDevice_RetrieveDetails is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveDetails is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveDetails(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Self);}
/**
 * \memberof FlowDevice
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevice FlowDevice_RetrieveDetails(FlowDevice self) { return (FlowDevice) FlowObject_HTTPRequest(self, _FlowDevice_rel_Self, FlowHTTPMethod_Get, NULL, FlowType_Device);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceSettings
 * \brief Indicates whether \ref FlowDevice_RetrieveSetting is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveSetting is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveSetting(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Settings);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceSettings
 * \brief Retrieve device setting
 *
 * Retrieve a specific key/value store setting assigned to the specified device. The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param key key
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSetting FlowDevice_RetrieveSetting(FlowDevice self, FlowID key)
{
	FlowSetting result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Settings))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Settings));
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
 * \memberof FlowDevice
 * \ingroup DeviceSettings
 * \brief Indicates whether \ref FlowDevice_RetrieveSettingsByQuery is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveSettingsByQuery is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveSettingsByQuery(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Settings);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceSettings
 * \brief Retrieve all device settings that match the query
 *
 * Retrieve subset of settings for the specified device. The device must be authenticated to use this API.
 * 
 * To obtain a subset of key/value settings a query takes the form:
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
static inline FlowSettings FlowDevice_RetrieveSettingsByQuery(FlowDevice self, char *query, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Settings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Settings));
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
 * \memberof FlowDevice
 * \ingroup DeviceSettings
 * \brief Indicates whether \ref FlowDevice_RetrieveSettings is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveSettings is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveSettings(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Settings);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceSettings
 * \brief Retrieve device settings
 *
 * Retrieve all key/value settings assigned to the specified device. This includes settings for the device type as well as individual device settings. The client must be authenticated to use this API. <BR /%gt;
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowDevice_RetrieveSettings(FlowDevice self, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Settings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Settings));
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
 * \memberof FlowDevice
 * \ingroup DeviceOwnership
 * \brief Indicates whether \ref FlowDevice_RemoveOwner is available on this object.
 * 
 * Checks whether \ref FlowDevice_RemoveOwner is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRemoveOwner(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Unregisteruser);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceOwnership
 * \brief Unassign device owner
 *
 * Unregisters the user from the specified device so that they no longer own the device. The specified device will no longer have access to any of the users resources. The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthenticationTokenCreatedResponse FlowDevice_RemoveOwner(FlowDevice self) { return (FlowAuthenticationTokenCreatedResponse) FlowObject_HTTPRequest(self, _FlowDevice_rel_Unregisteruser, FlowHTTPMethod_Delete, NULL, FlowType_AuthenticationTokenCreatedResponse);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceManagement
 * \brief Indicates whether \ref FlowDevice_Update is available on this object.
 * 
 * Checks whether \ref FlowDevice_Update is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanUpdate(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Update);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceManagement
 * \brief Update device details
 *
 * Updates the details of the specified device. The device must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDevice_Update(FlowDevice self, FlowDevice data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowDevice_rel_Update, FlowHTTPMethod_Put, data);}
/**
 * \memberof FlowDevice
 * \ingroup Upgrades
 * \brief Indicates whether \ref FlowDevice_RetrieveSoftwareUpgrades is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveSoftwareUpgrades is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveSoftwareUpgrades(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Upgrades);}
/**
 * \memberof FlowDevice
 * \ingroup Upgrades
 * \brief Retrieve device software upgrades
 *
 * Retrieve device upgrades for the specified device based on the currently associated software version. The device must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUpgrades FlowDevice_RetrieveSoftwareUpgrades(FlowDevice self) { return (FlowUpgrades) FlowObject_HTTPRequest(self, _FlowDevice_rel_Upgrades, FlowHTTPMethod_Get, NULL, FlowType_Upgrades);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceManagement
 * \brief Indicates whether \ref FlowDevice_RetrieveOwner is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveOwner is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveOwner(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_User);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceManagement
 * \brief Retrieve details for device owner
 *
 * Retrieve the user details of the device owner. The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUser FlowDevice_RetrieveOwner(FlowDevice self) { return (FlowUser) FlowObject_HTTPRequest(self, _FlowDevice_rel_User, FlowHTTPMethod_Get, NULL, FlowType_User);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceUsers
 * \brief Indicates whether \ref FlowDevice_RetrieveUsers is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveUsers(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Users);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceUsers
 * \brief Retrieve device users
 *
 * Retrieve a list of users who have been granted access to the device and their assigned roles (including the device owner). The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowDevice_RetrieveUsers(FlowDevice self, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Users))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Users));
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
 * \memberof FlowDevice
 * \ingroup DeviceUsers
 * \brief Indicates whether \ref FlowDevice_AddUsers is available on this object.
 * 
 * Checks whether \ref FlowDevice_AddUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanAddUsers(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Users);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceUsers
 * \brief Add device users
 *
 * Grant one or more guest users access to the device along with their assigned role(s). The user must have an existing Flow user account and the client should obtain a list of valid roles for the device type before calling this API.
 * 
 * The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDevice_AddUsers(FlowDevice self, FlowUsers data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowDevice_rel_Users, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowDevice
 * \ingroup UserDeviceSettings
 * \brief Indicates whether \ref FlowDevice_RetrieveDeviceUserSetting is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveDeviceUserSetting is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveDeviceUserSetting(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Usersettings);}
/**
 * \memberof FlowDevice
 * \ingroup UserDeviceSettings
 * \brief Retrieve specified setting associated with a user on a device
 *
 * Retrieve a specific key/value setting for the specified user on the device. The user must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param key key
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSetting FlowDevice_RetrieveDeviceUserSetting(FlowDevice self, FlowID key)
{
	FlowSetting result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Usersettings))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Usersettings));
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
 * \memberof FlowDevice
 * \ingroup UserDeviceSettings
 * \brief Indicates whether \ref FlowDevice_RetrieveDeviceUserSettingsByQuery is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveDeviceUserSettingsByQuery is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveDeviceUserSettingsByQuery(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Usersettings);}
/**
 * \memberof FlowDevice
 * \ingroup UserDeviceSettings
 * \brief Retrieve user device settings that match the query
 *
 * Retrieve subset of settings for a user on the specified device. The client must be authenticated to use this call.
 * 
 * To obtain a subset of key/value settings a query takes the form:
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
static inline FlowSettings FlowDevice_RetrieveDeviceUserSettingsByQuery(FlowDevice self, char *query, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Usersettings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Usersettings));
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
 * \memberof FlowDevice
 * \ingroup UserDeviceSettings
 * \brief Indicates whether \ref FlowDevice_RetrieveDeviceUserSettings is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveDeviceUserSettings is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveDeviceUserSettings(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Usersettings);}
/**
 * \memberof FlowDevice
 * \ingroup UserDeviceSettings
 * \brief Retrieve settings associated with a user on a device
 *
 * Retrieve all key/value settings or a subset of settings assigned as user on the specified device. The user must be authenticated to use this call
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
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowDevice_RetrieveDeviceUserSettings(FlowDevice self, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Usersettings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Usersettings));
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
 * \memberof FlowDevice
 * \ingroup DeviceVisibility
 * \brief Indicates whether \ref FlowDevice_RetrieveUsersWithVisibility is available on this object.
 * 
 * Checks whether \ref FlowDevice_RetrieveUsersWithVisibility is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanRetrieveUsersWithVisibility(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Visibility);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceVisibility
 * \brief Retrieve users this device is visible to
 *
 * Retrieve all remote users that a device has been made 'visible' to. The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowDevice_RetrieveUsersWithVisibility(FlowDevice self, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowDevice_rel_Visibility))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevice_rel_Visibility));
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
 * \memberof FlowDevice
 * \ingroup DeviceVisibility
 * \brief Indicates whether \ref FlowDevice_AddVisibleUsers is available on this object.
 * 
 * Checks whether \ref FlowDevice_AddVisibleUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevice_CanAddVisibleUsers(FlowDevice self) { return FlowObject_HasLink(self, _FlowDevice_rel_Visibility);}
/**
 * \memberof FlowDevice
 * \ingroup DeviceVisibility
 * \brief Add users for which this device is visble to
 *
 * Make a device 'visible' to a list of remote users. The granted user can then get a list of devices that are visible to them. The client must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDevice_AddVisibleUsers(FlowDevice self, FlowUsers data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowDevice_rel_Visibility, FlowHTTPMethod_Post, data);}
#endif /* FLOW_USERS_DEVICE_H_ */
