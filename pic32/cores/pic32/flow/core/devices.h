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

#ifndef FLOW_USERS_DEVICES_H_
#define FLOW_USERS_DEVICES_H_
#include "flow/core/base_types.h"
#include "flow/core/device.h"
#include "flow/core/device_type.h"
#include "flow/core/devicecreatedresponse_type.h"
#include "flow/core/devices_type.h"
#include "flow/core/devicetypes_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/pageinfo.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDevices
 * \brief Creates a new FlowDevices.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDevices FlowDevices_New(FlowMemoryManager memoryManager){ return (FlowDevices)FlowMemoryManager_NewObject(memoryManager, 2, 5, FlowType_Devices);}
/**
 * \memberof FlowDevices
 * \brief Registers meta data used for (de)serialising FlowDevices to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDevices_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Devices))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Devices, "Devices", 2, 5);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Devices, _FlowDevices_PageInfo, FlowType_PageInfo, "PageInfo", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Devices, _FlowDevices_Items, "Items", "Device", FlowType_Device, FlowType_Devices);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Devices, _FlowDevices_rel_Add, "add");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Devices, _FlowDevices_rel_Alldevices, "alldevices");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Devices, _FlowDevices_rel_Associateddevices, "associateddevices");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Devices, _FlowDevices_rel_Devicetypes, "devicetypes");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Devices, _FlowDevices_rel_Owneddevices, "owneddevices");
	}
}
/**
 * \memberof FlowDevices
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevices_HasItems(FlowDevices self) { return FlowObject_HasProperty(self, _FlowDevices_Items);}
/**
 * \memberof FlowDevices
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowDevice FlowDevices_GetItem(FlowDevices self, uint index) { return (FlowDevice)FlowObject_GetArrayObjectProperty(self, _FlowDevices_Items, index);}
/**
 * \memberof FlowDevices
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowDevices_GetCount(FlowDevices self) { return FlowObject_GetArrayPropertyCount(self, _FlowDevices_Items);}
/**
 * \memberof FlowDevices
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowDevice FlowDevices_NewItem(FlowDevices self)
{
	FlowDevice result = FlowDevice_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowDevices_Items, result);
	return result;
}
/**
 * \memberof FlowDevices
 * \brief Returns the total number of items available from Server (NOTE this make return -1 when this total in unknown).
 * 
 * The value returned by this method is unrelated to the number of items already loaded in the list. But is the total available from Server
 * \param self Object on which the method will be applied
*/
static inline int FlowDevices_GetTotalCount(FlowDevices self)
{
	int result = 0;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowDevices_PageInfo);
	if (pageInfo)
		result = FlowPageInfo_GetTotalCount(pageInfo);
	else
		result = FlowObject_GetArrayPropertyCount(self, _FlowDevices_Items);
	return result;
}
/**
 * \memberof FlowDevices
 * \brief load the next page form the server into the list (NOTE removes existing items).
 * 
 * Returned whether was able to load next page in to list (NOTE this could be because there are no more item or error see \ref Errors#Flow_GetLastError ).
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevices_RetrieveNextPage(FlowDevices self)
{
	bool result = false;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowDevices_PageInfo);
	if (pageInfo)
	{
		char *url = FlowPageInfo_GetNext(pageInfo);
			if (url)
		result = FlowObject_LoadNextPage(self, url);
	}
	return result;
}
/**
 * \memberof FlowDevices
 * \ingroup FlowRegistration
 * \brief Indicates whether \ref FlowDevices_Add is available on this object.
 * 
 * Checks whether \ref FlowDevices_Add is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevices_CanAdd(FlowDevices self) { return FlowObject_HasLink(self, _FlowDevices_rel_Add);}
/**
 * \memberof FlowDevices
 * \ingroup FlowRegistration
 * \brief Register device
 *
 * Register (or re-register) a device with the Flow infrastructure. A device can not use Flow until this registration process has been completed.
 * A successful registration provides a new session token and remember-me token (for device re-authentication or user login on the device later on).
 * 
 * The following elements of a Device object must be specified:
 * 
 * | Field | Description |
 * | :---- | :---------- |
 * | DeviceType | licensee defined device type e.g. MiniMorph |
 * | DeviceName | user defined (or licensee default) |
 * | SerialNumber | device serial number |
 * | MacAddress | device MAC address |
 * | AllowDirectMarketing | optional Boolean value, defaults to False |
 * | SoftwareVersion | device firmware version |
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDeviceCreatedResponse FlowDevices_Add(FlowDevices self, FlowDevice data) { return (FlowDeviceCreatedResponse) FlowObject_HTTPRequest(self, _FlowDevices_rel_Add, FlowHTTPMethod_Post, data, FlowType_DeviceCreatedResponse);}
/**
 * \memberof FlowDevices
 * \ingroup UserDevices
 * \brief Indicates whether \ref FlowDevices_RetrieveAllDevices is available on this object.
 * 
 * Checks whether \ref FlowDevices_RetrieveAllDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevices_CanRetrieveAllDevices(FlowDevices self) { return FlowObject_HasLink(self, _FlowDevices_rel_Alldevices);}
/**
 * \memberof FlowDevices
 * \ingroup UserDevices
 * \brief Retrieve all owned or associated devices
 *
 * Retrieves all the devices owned by or associated with the specified user.
 * A user is associated with a device if it has at least one DeviceRole on the device.
 * This API retrieves less device information than the API for "Get owned devices".
 * The user must be authenticated to use this API.
 * 
 * It is also possible for a user to retrieve the device list for another user (e.g a friend).
 * Only devices that have been made visible to the current user will be retrieved if the userID not the same (refer to Examples for details).
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevices FlowDevices_RetrieveAllDevices(FlowDevices self, int pageSize)
{
	FlowDevices result = NULL;
	if(FlowObject_HasLink(self, _FlowDevices_rel_Alldevices))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevices_rel_Alldevices));
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
 * \memberof FlowDevices
 * \ingroup UserDevices
 * \brief Indicates whether \ref FlowDevices_RetrieveAssociatedDevices is available on this object.
 * 
 * Checks whether \ref FlowDevices_RetrieveAssociatedDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevices_CanRetrieveAssociatedDevices(FlowDevices self) { return FlowObject_HasLink(self, _FlowDevices_rel_Associateddevices);}
/**
 * \memberof FlowDevices
 * \ingroup UserDevices
 * \brief Retrieve associated devices
 *
 * Retrieves all the devices associated with the specified user.
 * A user is associated with a device if it has at least one DeviceRole, but does not own the device.
 * The user must be authenticated to use this API.
 * 
 * Note: this API retrieves the same device information as "Get all devices" (less than "Get owned devices").
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevices FlowDevices_RetrieveAssociatedDevices(FlowDevices self, int pageSize)
{
	FlowDevices result = NULL;
	if(FlowObject_HasLink(self, _FlowDevices_rel_Associateddevices))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevices_rel_Associateddevices));
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
 * \memberof FlowDevices
 * \ingroup Device
 * \brief Indicates whether \ref FlowDevices_RetrieveDeviceTypes is available on this object.
 * 
 * Checks whether \ref FlowDevices_RetrieveDeviceTypes is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevices_CanRetrieveDeviceTypes(FlowDevices self) { return FlowObject_HasLink(self, _FlowDevices_rel_Devicetypes);}
/**
 * \memberof FlowDevices
 * \ingroup Device
 * \brief Retrieve device types
 *
 * Retrieves all device types for the licensee associated with the requesting client.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDeviceTypes FlowDevices_RetrieveDeviceTypes(FlowDevices self, int pageSize)
{
	FlowDeviceTypes result = NULL;
	if(FlowObject_HasLink(self, _FlowDevices_rel_Devicetypes))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevices_rel_Devicetypes));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowDeviceTypes) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_DeviceTypes);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowDevices
 * \ingroup UserDevices
 * \brief Indicates whether \ref FlowDevices_RetrieveOwnedDevices is available on this object.
 * 
 * Checks whether \ref FlowDevices_RetrieveOwnedDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDevices_CanRetrieveOwnedDevices(FlowDevices self) { return FlowObject_HasLink(self, _FlowDevices_rel_Owneddevices);}
/**
 * \memberof FlowDevices
 * \ingroup UserDevices
 * \brief Retrieve owned devices
 *
 * Retrieves all the devices owned by (registered to) the specified user. The user must be authenticated to use this API.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevices FlowDevices_RetrieveOwnedDevices(FlowDevices self, int pageSize)
{
	FlowDevices result = NULL;
	if(FlowObject_HasLink(self, _FlowDevices_rel_Owneddevices))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDevices_rel_Owneddevices));
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
#endif /* FLOW_USERS_DEVICES_H_ */
