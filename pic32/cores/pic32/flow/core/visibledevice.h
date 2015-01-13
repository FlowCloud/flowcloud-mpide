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

#ifndef FLOW_USERS_VISIBLEDEVICE_H_
#define FLOW_USERS_VISIBLEDEVICE_H_
#include "flow/core/base_types.h"
#include "flow/core/device_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/user_type.h"
#include "flow/core/visibledevice_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowVisibleDevice
 * \brief Creates a new FlowVisibleDevice.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowVisibleDevice FlowVisibleDevice_New(FlowMemoryManager memoryManager){ return (FlowVisibleDevice)FlowMemoryManager_NewObject(memoryManager, 5, 2, FlowType_VisibleDevice);}
/**
 * \memberof FlowVisibleDevice
 * \brief Registers meta data used for (de)serialising FlowVisibleDevice to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowVisibleDevice_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_VisibleDevice))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_VisibleDevice, "VisibleDevice", 5, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_VisibleDevice, _FlowVisibleDevice_DeviceID, FlowType_ID, "DeviceID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_VisibleDevice, _FlowVisibleDevice_UserID, FlowType_ID, "UserID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_VisibleDevice, _FlowVisibleDevice_DeviceName, FlowType_String, "DeviceName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_VisibleDevice, _FlowVisibleDevice_DeviceType, FlowType_ID, "DeviceType", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_VisibleDevice, _FlowVisibleDevice_UserName, FlowType_String, "UserName", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_VisibleDevice, _FlowVisibleDevice_rel_Device, "device");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_VisibleDevice, _FlowVisibleDevice_rel_User, "user");
	}
}
/**
 * \memberof FlowVisibleDevice
 * \brief Indicates whether the property DeviceID is set on this object.
 * 
 * Can be used to check whether DeviceID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowVisibleDevice_HasDeviceID(FlowVisibleDevice self) { return FlowObject_HasProperty(self, _FlowVisibleDevice_DeviceID);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowVisibleDevice_GetDeviceID(FlowVisibleDevice self) { return FlowObject_GetIDProperty(self, _FlowVisibleDevice_DeviceID);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowVisibleDevice_SetDeviceID(FlowVisibleDevice self, FlowID value) { FlowObject_SetIDProperty(self, _FlowVisibleDevice_DeviceID, value);}
/**
 * \memberof FlowVisibleDevice
 * \brief Indicates whether the property UserID is set on this object.
 * 
 * Can be used to check whether UserID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowVisibleDevice_HasUserID(FlowVisibleDevice self) { return FlowObject_HasProperty(self, _FlowVisibleDevice_UserID);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowVisibleDevice_GetUserID(FlowVisibleDevice self) { return FlowObject_GetIDProperty(self, _FlowVisibleDevice_UserID);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowVisibleDevice_SetUserID(FlowVisibleDevice self, FlowID value) { FlowObject_SetIDProperty(self, _FlowVisibleDevice_UserID, value);}
/**
 * \memberof FlowVisibleDevice
 * \brief Indicates whether the property DeviceName is set on this object.
 * 
 * Can be used to check whether DeviceName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowVisibleDevice_HasDeviceName(FlowVisibleDevice self) { return FlowObject_HasProperty(self, _FlowVisibleDevice_DeviceName);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowVisibleDevice_GetDeviceName(FlowVisibleDevice self) { return FlowObject_GetStringProperty(self, _FlowVisibleDevice_DeviceName);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowVisibleDevice_SetDeviceName(FlowVisibleDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowVisibleDevice_DeviceName, value);}
/**
 * \memberof FlowVisibleDevice
 * \brief Indicates whether the property DeviceType is set on this object.
 * 
 * Can be used to check whether DeviceType is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowVisibleDevice_HasDeviceType(FlowVisibleDevice self) { return FlowObject_HasProperty(self, _FlowVisibleDevice_DeviceType);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowVisibleDevice_GetDeviceType(FlowVisibleDevice self) { return FlowObject_GetIDProperty(self, _FlowVisibleDevice_DeviceType);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowVisibleDevice_SetDeviceType(FlowVisibleDevice self, FlowID value) { FlowObject_SetIDProperty(self, _FlowVisibleDevice_DeviceType, value);}
/**
 * \memberof FlowVisibleDevice
 * \brief Indicates whether the property UserName is set on this object.
 * 
 * Can be used to check whether UserName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowVisibleDevice_HasUserName(FlowVisibleDevice self) { return FlowObject_HasProperty(self, _FlowVisibleDevice_UserName);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
*/
static inline char *FlowVisibleDevice_GetUserName(FlowVisibleDevice self) { return FlowObject_GetStringProperty(self, _FlowVisibleDevice_UserName);}
/**
 * \memberof FlowVisibleDevice
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowVisibleDevice_SetUserName(FlowVisibleDevice self, char *value) { FlowObject_SetStringProperty(self, _FlowVisibleDevice_UserName, value);}
/**
 * \memberof FlowVisibleDevice
 * \ingroup UserDeviceVisibility
 * \brief Indicates whether \ref FlowVisibleDevice_RetrieveDevice is available on this object.
 * 
 * Checks whether \ref FlowVisibleDevice_RetrieveDevice is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowVisibleDevice_CanRetrieveDevice(FlowVisibleDevice self) { return FlowObject_HasLink(self, _FlowVisibleDevice_rel_Device);}
/**
 * \memberof FlowVisibleDevice
 * \ingroup UserDeviceVisibility
 * \brief Retrieve device details
 *
 * Retrieve the details of the device from the visible device. The device information retrieved depends on the current client and is consistent with GetDevice in the user service.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevice FlowVisibleDevice_RetrieveDevice(FlowVisibleDevice self) { return (FlowDevice) FlowObject_HTTPRequest(self, _FlowVisibleDevice_rel_Device, FlowHTTPMethod_Get, NULL, FlowType_Device);}
/**
 * \memberof FlowVisibleDevice
 * \ingroup UserDeviceVisibility
 * \brief Indicates whether \ref FlowVisibleDevice_RetrieveUser is available on this object.
 * 
 * Checks whether \ref FlowVisibleDevice_RetrieveUser is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowVisibleDevice_CanRetrieveUser(FlowVisibleDevice self) { return FlowObject_HasLink(self, _FlowVisibleDevice_rel_User);}
/**
 * \memberof FlowVisibleDevice
 * \ingroup UserDeviceVisibility
 * \brief Retrieve details of user who made the device visible
 *
 * Retrieve the details of the user who made the device visible to the current user. The user details retrieved for the current user are consistent with GetUser in the user service.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUser FlowVisibleDevice_RetrieveUser(FlowVisibleDevice self) { return (FlowUser) FlowObject_HTTPRequest(self, _FlowVisibleDevice_rel_User, FlowHTTPMethod_Get, NULL, FlowType_User);}
#endif /* FLOW_USERS_VISIBLEDEVICE_H_ */
