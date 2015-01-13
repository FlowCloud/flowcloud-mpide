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

#ifndef FLOW_USERS_USERS_H_
#define FLOW_USERS_USERS_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/pageinfo.h"
#include "flow/core/resourcecreatedresponse_type.h"
#include "flow/core/user.h"
#include "flow/core/user_type.h"
#include "flow/core/users_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowUsers
 * \brief Creates a new FlowUsers.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowUsers FlowUsers_New(FlowMemoryManager memoryManager){ return (FlowUsers)FlowMemoryManager_NewObject(memoryManager, 2, 2, FlowType_Users);}
/**
 * \memberof FlowUsers
 * \brief Registers meta data used for (de)serialising FlowUsers to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowUsers_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Users))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Users, "Users", 2, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Users, _FlowUsers_PageInfo, FlowType_PageInfo, "PageInfo", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Users, _FlowUsers_Items, "Items", "User", FlowType_User, FlowType_Users);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Users, _FlowUsers_rel_Add, "add");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Users, _FlowUsers_rel_Self, "self");
	}
}
/**
 * \memberof FlowUsers
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUsers_HasItems(FlowUsers self) { return FlowObject_HasProperty(self, _FlowUsers_Items);}
/**
 * \memberof FlowUsers
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowUser FlowUsers_GetItem(FlowUsers self, uint index) { return (FlowUser)FlowObject_GetArrayObjectProperty(self, _FlowUsers_Items, index);}
/**
 * \memberof FlowUsers
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowUsers_GetCount(FlowUsers self) { return FlowObject_GetArrayPropertyCount(self, _FlowUsers_Items);}
/**
 * \memberof FlowUsers
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowUser FlowUsers_NewItem(FlowUsers self)
{
	FlowUser result = FlowUser_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowUsers_Items, result);
	return result;
}
/**
 * \memberof FlowUsers
 * \brief Returns the total number of items available from Server (NOTE this make return -1 when this total in unknown).
 * 
 * The value returned by this method is unrelated to the number of items already loaded in the list. But is the total available from Server
 * \param self Object on which the method will be applied
*/
static inline int FlowUsers_GetTotalCount(FlowUsers self)
{
	int result = 0;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowUsers_PageInfo);
	if (pageInfo)
		result = FlowPageInfo_GetTotalCount(pageInfo);
	else
		result = FlowObject_GetArrayPropertyCount(self, _FlowUsers_Items);
	return result;
}
/**
 * \memberof FlowUsers
 * \brief load the next page form the server into the list (NOTE removes existing items).
 * 
 * Returned whether was able to load next page in to list (NOTE this could be because there are no more item or error see \ref Errors#Flow_GetLastError ).
 * \param self Object on which the method will be applied
*/
static inline bool FlowUsers_RetrieveNextPage(FlowUsers self)
{
	bool result = false;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowUsers_PageInfo);
	if (pageInfo)
	{
		char *url = FlowPageInfo_GetNext(pageInfo);
			if (url)
		result = FlowObject_LoadNextPage(self, url);
	}
	return result;
}
/**
 * \memberof FlowUsers
 * \ingroup FlowUserAccountManagement
 * \brief Indicates whether \ref FlowUsers_Add is available on this object.
 * 
 * Checks whether \ref FlowUsers_Add is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUsers_CanAdd(FlowUsers self) { return FlowObject_HasLink(self, _FlowUsers_rel_Add);}
/**
 * \memberof FlowUsers
 * \ingroup FlowUserAccountManagement
 * \brief Create a new flow user
 *
 * The user needs to be activated before it can be used. The username and email address must be unique.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Conflict "FlowError_Conflict"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowResourceCreatedResponse FlowUsers_Add(FlowUsers self, FlowUser data) { return (FlowResourceCreatedResponse) FlowObject_HTTPRequest(self, _FlowUsers_rel_Add, FlowHTTPMethod_Post, data, FlowType_ResourceCreatedResponse);}
/**
 * \memberof FlowUsers
 * \ingroup Users
 * \brief Indicates whether \ref FlowUsers_RetrieveByName is available on this object.
 * 
 * Checks whether \ref FlowUsers_RetrieveByName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUsers_CanRetrieveByName(FlowUsers self) { return FlowObject_HasLink(self, _FlowUsers_rel_Self);}
/**
 * \memberof FlowUsers
 * \ingroup Users
 * \brief Search for users with a username or displayname that contains the given name
 *
 * 
 * \param self Object on which the method will be applied
 * \param name name
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowUsers_RetrieveByName(FlowUsers self, char *name, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowUsers_rel_Self))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUsers_rel_Self));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "name", name);
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
 * \memberof FlowUsers
 * \ingroup Users
 * \brief Indicates whether \ref FlowUsers_RetrieveByDisplayName is available on this object.
 * 
 * Checks whether \ref FlowUsers_RetrieveByDisplayName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUsers_CanRetrieveByDisplayName(FlowUsers self) { return FlowObject_HasLink(self, _FlowUsers_rel_Self);}
/**
 * \memberof FlowUsers
 * \ingroup Users
 * \brief Search for users with a displayname that contains the given name
 *
 * Note: the display name is an optional user friendly name for a user (many users could select the same display name).
 * \param self Object on which the method will be applied
 * \param displayname displayname
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowUsers_RetrieveByDisplayName(FlowUsers self, char *displayname, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowUsers_rel_Self))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUsers_rel_Self));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "displayname", displayname);
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
 * \memberof FlowUsers
 * \ingroup Users
 * \brief Indicates whether \ref FlowUsers_RetrieveByUserName is available on this object.
 * 
 * Checks whether \ref FlowUsers_RetrieveByUserName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUsers_CanRetrieveByUserName(FlowUsers self) { return FlowObject_HasLink(self, _FlowUsers_rel_Self);}
/**
 * \memberof FlowUsers
 * \ingroup Users
 * \brief Search for users with a username that contains the given name
 *
 * Note: the user name is unique for each flow user.
 * \param self Object on which the method will be applied
 * \param username username
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowUsers_RetrieveByUserName(FlowUsers self, char *username, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowUsers_rel_Self))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUsers_rel_Self));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "username", username);
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
 * \memberof FlowUsers
 * \brief Indicates whether \ref FlowUsers_Retrieve is available on this object.
 * 
 * Checks whether \ref FlowUsers_Retrieve is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUsers_CanRetrieve(FlowUsers self) { return FlowObject_HasLink(self, _FlowUsers_rel_Self);}
/**
 * \memberof FlowUsers
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowUsers_Retrieve(FlowUsers self, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowUsers_rel_Self))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowUsers_rel_Self));
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
#endif /* FLOW_USERS_USERS_H_ */
