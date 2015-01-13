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

/*! \file user_helpers.h
 *  \brief LibFlowCore .
 */


#ifndef USER_HELPERS_H_
#define USER_HELPERS_H_

#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"


bool FlowUsers_CreateUser(FlowMemoryManager memoryManager, char *username, char *email, char *password, bool allowEmailCommunication, bool allowDirectMarketing, char *locale);

/**
 * \memberof FlowUsers
 * \brief Retrieve user based on identity (either username or userID)
 * \param[in] memoryManager Memory manager to collect allocated memory.
 * \param[in] id identity of user (either username or userID)
 * \return User
 * \retval FlowUser
 */
FlowUser FlowUsers_RetrieveUser (FlowMemoryManager memoryManager, char *id);

/**
 * \memberof DirectoryServices
 * \ingroup DirectoryServices
 * \brief &nbsp; Search for a user by username
 * <p>&nbsp; <b> Description </b> <br/>
 * &nbsp; This function is used to search for a user by userName and returns discoverable users
 * \param[in] memoryManager Memory manager to collect allocated memory.
 * \param[in] filter . search discoverable  users by username (e.g. 'r\%' to search for users with names beginning with 'r'). If no filtering is required, filter should be an empty string (not NULL).
 * \return Returns discoverable users
 * \retval FlowUsers
 * \note Callers of this API should make sure to later call FlowMessaging_FreeMemory() to free the resources dynamically allocated for storing these search results(FlowUsers)
 */
FlowUsers FlowUsers_SearchUsers (FlowMemoryManager memoryManager, char *filter);


/**
 * \memberof DirectoryServices
 * \ingroup DirectoryServices
 * \brief &nbsp; Retrieve list of devices associated with a user
 * <p>&nbsp; <b> Description </b> <br/>
 * &nbsp; This function is used to return a list of all visibile devices associated with a particular user
 * \param[in] memoryManager Memory manager to collect allocated memory.
 * \param[in] id UserID of the user, the devices must be associated with.
 * \return Visible devices associated with a user
 * \retval FlowDevices
 * \note Only devices with their visibility set will be returned by this API.
 * \note Callers of this API should make sure to later call free() on the returned FlowDevices at conclusion of its use.
 */
FlowDevices FlowUser_RetrieveUserDevices (FlowMemoryManager memoryManager, char *id);


///**
// * \memberof DirectoryServices
// * \ingroup DirectoryServices
// * \brief &nbsp; Get display name of a device or user
// * <p>&nbsp; <b> Description </b> <br/>
// * &nbsp; This function is used to retrieve the display name for a given entity i.e. a user or device.
// * \param[in] id  	    The id of the user/device of whom the AoR is to be returned.
// * \param[out] displayName  Display name for that entity. Null terminated string.
// * \param[out] length       Length of display name string.
// * \return Whether displayName is properly retrieved
// * \retval true (SUCCESS), or false (FAILURE)
// * \note Callers of this API should make sure to later call free() on the returned displayName at conclusion of its use.
// */
//bool FlowMessaging_GetDisplayName (char *id, char **displayName, int *length);


///**
// * \memberof DirectoryServices
// * \ingroup DirectoryServices
// * \brief &nbsp; Determines if an entity is a device
// * <p>&nbsp; <b> Description </b> <br/>
// *  &nbsp; This function is used to determine if an entity is a device
// * \param[in] entity  The entity to inspect.
// * \return Whether given entity is a device
// * \retval true (SUCCESS), or false (FAILURE)
// */
//bool FlowIsDevice (FlowObject entity);
//
///**
// * \memberof DirectoryServices
// * \ingroup DirectoryServices
// * \brief &nbsp; Determines if an entity is a user
// * <p>&nbsp; <b> Description </b> <br/>
// * &nbsp; This function is used to determine if an entity is a user
// * \param[in] entity  The entity to inspect.
// * \return Whether given entity is a user
// * \retval true (SUCCESS), or false (FAILURE)
// */
//bool FlowIsUser (FlowObject entity);
//

//
///**
// * \memberof DirectoryServices
// * \ingroup DirectoryServices
// * \brief &nbsp; Get device type of a device
// * <p>&nbsp; <b> Description </b> <br/>
// * &nbsp; This function is used to retrieve the device type for a given entity and only makes sense for a device
// * \param[in] id           The id of the user/device of whom the AoR is to be returned.
// * \param[out] deviceType  Device type for that entity. Will return with a null-terminated string.
// * \param[out] length      Length of device type string.
// * \return Whether device type is properly retrieved
// * \retval true (SUCCESS), or false (FAILURE)
// * \note If the entity represents a user then a null string is returned.
// * \note Callers of this API should make sure to later call free() on the returned deviceType at conclusion of its use.
// */
//bool FlowMessaging_GetDeviceType (char *id, char **deviceType, int *length);


#endif /* USER_HELPERS_H_ */
