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

#ifndef FLOW_USERS_DEVICE_TYPE_H_
#define FLOW_USERS_DEVICE_TYPE_H_

#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"

/**
 * \internal
*/
typedef enum
{
	_FlowDevice_DeviceID,
	_FlowDevice_DeviceName,
	_FlowDevice_DeviceType,
	_FlowDevice_SerialNumber,
	_FlowDevice_MACAddress,
	_FlowDevice_SoftwareVersion,
	_FlowDevice_FlowServerKey,
	_FlowDevice_RemoteAccessIPAddress,
	_FlowDevice_RemoteAccessPort,
	_FlowDevice_CreatedDate,
	_FlowDevice_ClaimOwnershipExpiryDate,
	_FlowDevice_RegistrationKey,
	_FlowDevice_Capabilities,
	_FlowDevice_Permissions,
}_FlowDevice_PropertyEnum;

/**
 * \internal
*/
typedef enum
{
	_FlowDevice_rel_Allfavourites,
	_FlowDevice_rel_Datastores,
	_FlowDevice_rel_Firmwares,
	_FlowDevice_rel_Flowmessaging,
	_FlowDevice_rel_Flowserverkey,
	_FlowDevice_rel_Offlinestreamingstatus,
	_FlowDevice_rel_Pausedactivities,
	_FlowDevice_rel_Recentcontent,
	_FlowDevice_rel_Recenttracks,
	_FlowDevice_rel_Registeruser,
	_FlowDevice_rel_Roles,
	_FlowDevice_rel_Self,
	_FlowDevice_rel_Settings,
	_FlowDevice_rel_Unregisteruser,
	_FlowDevice_rel_Update,
	_FlowDevice_rel_Upgrades,
	_FlowDevice_rel_User,
	_FlowDevice_rel_Userpausedactivities,
	_FlowDevice_rel_Users,
	_FlowDevice_rel_Usersettings,
	_FlowDevice_rel_Visibility,
}_FlowDevice_LinkEnum;

/**
 * \class FlowDevice
*/
typedef FlowObject FlowDevice;

/**
 * \memberof FlowDevice
 * \brief Copies information from a FlowDevice to another.
 *
 * \param self Object on which the method will be applied
 * \param src reference Object to copy from
*/
static inline void FlowDevice_CopyFrom(FlowDevice self, FlowDevice src){ FlowObject_CopyFrom(self,src);}

#endif /* FLOW_USERS_DEVICE_TYPE_H_ */
