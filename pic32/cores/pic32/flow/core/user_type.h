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

#ifndef FLOW_USERS_USER_TYPE_H_
#define FLOW_USERS_USER_TYPE_H_

#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"

/**
 * \internal
*/
typedef enum
{
	_FlowUser_UserID,
	_FlowUser_UserName,
	_FlowUser_DisplayName,
	_FlowUser_GivenName,
	_FlowUser_Surname,
	_FlowUser_DateOfBirth,
	_FlowUser_Email,
	_FlowUser_MobilePhoneNumber,
	_FlowUser_OldPassword,
	_FlowUser_Password,
	_FlowUser_Activated,
	_FlowUser_Discoverable,
	_FlowUser_AllowEmailCommunication,
	_FlowUser_AllowDirectMarketing,
	_FlowUser_CountryCode,
	_FlowUser_Locale,
	_FlowUser_CreatedDate,
	_FlowUser_ReferType,
	_FlowUser_Refer,
	_FlowUser_DeviceRoles,
	_FlowUser_Permissions,
}_FlowUser_PropertyEnum;

/**
 * \internal
*/
typedef enum
{
	_FlowUser_rel_Activate,
	_FlowUser_rel_Alldevices,
	_FlowUser_rel_Allfavourites,
	_FlowUser_rel_Authorisation,
	_FlowUser_rel_Contacts,
	_FlowUser_rel_Datastores,
	_FlowUser_rel_Deviceregistrationkeys,
	_FlowUser_rel_Devices,
	_FlowUser_rel_Discoverableby,
	_FlowUser_rel_Firmwares,
	_FlowUser_rel_Flowconnect,
	_FlowUser_rel_Flowmessaging,
	_FlowUser_rel_Flowrcs,
	_FlowUser_rel_Flowsongs,
	_FlowUser_rel_Juke,
	_FlowUser_rel_Localcontent,
	_FlowUser_rel_Musicfavourites,
	_FlowUser_rel_Pausedactivities,
	_FlowUser_rel_Recentcontent,
	_FlowUser_rel_Recenttracks,
	_FlowUser_rel_Recommendedcontent,
	_FlowUser_rel_Recommendedreleases,
	_FlowUser_rel_Remove,
	_FlowUser_rel_Self,
	_FlowUser_rel_Settings,
	_FlowUser_rel_Siriusxm,
	_FlowUser_rel_Siriusxmfavourites,
	_FlowUser_rel_Siriusxmrecent,
	_FlowUser_rel_Sms,
	_FlowUser_rel_Socialnetworks,
	_FlowUser_rel_Storage,
	_FlowUser_rel_Storedvalueaccounts,
	_FlowUser_rel_Subscriptions,
	_FlowUser_rel_Update,
	_FlowUser_rel_Visibledevices,
	_FlowUser_rel_Vouchers,
	_FlowUser_rel_Emails,
}_FlowUser_LinkEnum;

/**
 * \class FlowUser
*/
typedef FlowObject FlowUser;

/**
 * \memberof FlowUser
 * \brief Copies information from a FlowUser to another.
 *
 * \param self Object on which the method will be applied
 * \param src reference Object to copy from
*/
static inline void FlowUser_CopyFrom(FlowUser self, FlowUser src){ FlowObject_CopyFrom(self,src);}

#endif /* FLOW_USERS_USER_TYPE_H_ */
