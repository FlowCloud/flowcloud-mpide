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

#ifndef FLOW_USERS_CONTACTS_H_
#define FLOW_USERS_CONTACTS_H_
#include "flow/core/base_types.h"
#include "flow/core/contact.h"
#include "flow/core/contactrequests_type.h"
#include "flow/core/contacts_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/labels_type.h"
#include "flow/core/pageinfo.h"
#include "flow/core/users_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowContacts
 * \brief Creates a new FlowContacts.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowContacts FlowContacts_New(FlowMemoryManager memoryManager){ return (FlowContacts)FlowMemoryManager_NewObject(memoryManager, 2, 8, FlowType_Contacts);}
/**
 * \memberof FlowContacts
 * \brief Registers meta data used for (de)serialising FlowContacts to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowContacts_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Contacts))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Contacts, "Contacts", 2, 8);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Contacts, _FlowContacts_PageInfo, FlowType_PageInfo, "PageInfo", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Contacts, _FlowContacts_Items, "Items", "Contact", FlowType_Contact, FlowType_Contacts);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Add, "add");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Blocked, "blocked");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Devices, "devices");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Friends, "friends");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Labels, "labels");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Notfriends, "notfriends");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Requests, "requests");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Contacts, _FlowContacts_rel_Users, "users");
	}
}
/**
 * \memberof FlowContacts
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_HasItems(FlowContacts self) { return FlowObject_HasProperty(self, _FlowContacts_Items);}
/**
 * \memberof FlowContacts
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowContact FlowContacts_GetItem(FlowContacts self, uint index) { return (FlowContact)FlowObject_GetArrayObjectProperty(self, _FlowContacts_Items, index);}
/**
 * \memberof FlowContacts
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowContacts_GetCount(FlowContacts self) { return FlowObject_GetArrayPropertyCount(self, _FlowContacts_Items);}
/**
 * \memberof FlowContacts
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowContact FlowContacts_NewItem(FlowContacts self)
{
	FlowContact result = FlowContact_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowContacts_Items, result);
	return result;
}
/**
 * \memberof FlowContacts
 * \brief Returns the total number of items available from Server (NOTE this make return -1 when this total in unknown).
 * 
 * The value returned by this method is unrelated to the number of items already loaded in the list. But is the total available from Server
 * \param self Object on which the method will be applied
*/
static inline int FlowContacts_GetTotalCount(FlowContacts self)
{
	int result = 0;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowContacts_PageInfo);
	if (pageInfo)
		result = FlowPageInfo_GetTotalCount(pageInfo);
	else
		result = FlowObject_GetArrayPropertyCount(self, _FlowContacts_Items);
	return result;
}
/**
 * \memberof FlowContacts
 * \brief load the next page form the server into the list (NOTE removes existing items).
 * 
 * Returned whether was able to load next page in to list (NOTE this could be because there are no more item or error see \ref Errors#Flow_GetLastError ).
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_RetrieveNextPage(FlowContacts self)
{
	bool result = false;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowContacts_PageInfo);
	if (pageInfo)
	{
		char *url = FlowPageInfo_GetNext(pageInfo);
			if (url)
		result = FlowObject_LoadNextPage(self, url);
	}
	return result;
}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowContacts_AddContacts is available on this object.
 * 
 * Checks whether \ref FlowContacts_AddContacts is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanAddContacts(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Add);}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Add contacts
 *
 * Add user and device contacts for the current user. Each user contact can be specified by UserName or UserID. DisplayName and Labels are optional.
 * If the user contact is added as a 'friend' then a friend reqeuest is sent to the requested friend.
 * For a non-friend request if the requested user is not 'discoverable' then a contact request is sent to the requested contact.
 * If the requested user is already 'Discoverable' (e.g. Public discoverable level) then the user 'Discoverable' status is saved to ensure the contact can still be used if the other user changes their default discoverable level later.
 * 
 * Requested users can use the 'Get contact requests' API to check for any contact requests. New user contacts are stored in the contact list. For friends the contact status indicates the current friend status.
 * 
 * Each device contact is specified by DeviceID. DisplayName and Labels are optional.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowContacts_AddContacts(FlowContacts self, FlowContacts data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowContacts_rel_Add, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowContacts
 * \ingroup Blockedusers
 * \brief Indicates whether \ref FlowContacts_RetrieveBlockedUsers is available on this object.
 * 
 * Checks whether \ref FlowContacts_RetrieveBlockedUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanRetrieveBlockedUsers(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Blocked);}
/**
 * \memberof FlowContacts
 * \ingroup Blockedusers
 * \brief Retrieve blocked users
 *
 * Retrieves the list of users who have been blocked by the current user. The user must be authenticated to use this call.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowContacts_RetrieveBlockedUsers(FlowContacts self, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowContacts_rel_Blocked))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowContacts_rel_Blocked));
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
 * \memberof FlowContacts
 * \ingroup Blockedusers
 * \brief Indicates whether \ref FlowContacts_AddBlockedUsers is available on this object.
 * 
 * Checks whether \ref FlowContacts_AddBlockedUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanAddBlockedUsers(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Blocked);}
/**
 * \memberof FlowContacts
 * \ingroup Blockedusers
 * \brief Add blocked users
 *
 * Add users to the blocked user list for the current user. A blocked user can not send a contact request to a user that has blocked them. Users can be blocked using the <b>blockedusers</b> link in <b>Contacts</b> for a User.<h3>Request</h3>The Request body must be of type <b>Users</b> where each <b>User</b> must have the UserName or UserID field.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowContacts_AddBlockedUsers(FlowContacts self, FlowUsers data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowContacts_rel_Blocked, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowContacts_RetrieveDevices is available on this object.
 * 
 * Checks whether \ref FlowContacts_RetrieveDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanRetrieveDevices(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Devices);}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Retrieve device contacts
 *
 * Retrieves the list of device contacts created by the current user. The GetLabels API can be used on the response to get the labels used by device contacts.
 * 
 * Note: the Users list in each device contact indicates which other users have made the device visible to the current user. The Users list is typically empty for any devices owned or associated with the user.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContacts FlowContacts_RetrieveDevices(FlowContacts self, int pageSize)
{
	FlowContacts result = NULL;
	if(FlowObject_HasLink(self, _FlowContacts_rel_Devices))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowContacts_rel_Devices));
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
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowContacts_RetrieveFriends is available on this object.
 * 
 * Checks whether \ref FlowContacts_RetrieveFriends is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanRetrieveFriends(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Friends);}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Retrieve friend contacts
 *
 * Retrieves the list of friend contacts where each 'friend' is a user contact with IsFriend = true. This includes all requested and accepted friends, and also includes any friends that have deleted their corresponding contact.
 * 
 * The GetLabels API can be used on the response to get the labels used by any friend contacts.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContacts FlowContacts_RetrieveFriends(FlowContacts self, int pageSize)
{
	FlowContacts result = NULL;
	if(FlowObject_HasLink(self, _FlowContacts_rel_Friends))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowContacts_rel_Friends));
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
 * \memberof FlowContacts
 * \ingroup Labels
 * \brief Indicates whether \ref FlowContacts_RetrieveLabels is available on this object.
 * 
 * Checks whether \ref FlowContacts_RetrieveLabels is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanRetrieveLabels(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Labels);}
/**
 * \memberof FlowContacts
 * \ingroup Labels
 * \brief Retrieve contact labels
 *
 * Retrieves the list of all contact labels for the contact list. This can be used on the response from GetContacts and for each of the special contact type requests (e.g. GetUsers and GetFriends).
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowLabels FlowContacts_RetrieveLabels(FlowContacts self, int pageSize)
{
	FlowLabels result = NULL;
	if(FlowObject_HasLink(self, _FlowContacts_rel_Labels))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowContacts_rel_Labels));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowLabels) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Labels);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowContacts_RetrieveNotFriends is available on this object.
 * 
 * Checks whether \ref FlowContacts_RetrieveNotFriends is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanRetrieveNotFriends(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Notfriends);}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Retrieve not friend contacts
 *
 * Retrieves the list of not friend contacts where each 'friend' is a user contact with IsFriend = false. The GetLabels API can be used on the response to get the labels used by any not friend user contacts.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContacts FlowContacts_RetrieveNotFriends(FlowContacts self, int pageSize)
{
	FlowContacts result = NULL;
	if(FlowObject_HasLink(self, _FlowContacts_rel_Notfriends))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowContacts_rel_Notfriends));
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
 * \memberof FlowContacts
 * \ingroup Contactrequests
 * \brief Indicates whether \ref FlowContacts_RetrieveContactRequests is available on this object.
 * 
 * Checks whether \ref FlowContacts_RetrieveContactRequests is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanRetrieveContactRequests(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Requests);}
/**
 * \memberof FlowContacts
 * \ingroup Contactrequests
 * \brief Contact requests
 *
 * Retrieves the list of contact requests received by the current user. The 'FriendRequest' field indicates if each contact request is for a friend or non-friend contact.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContactRequests FlowContacts_RetrieveContactRequests(FlowContacts self, int pageSize)
{
	FlowContactRequests result = NULL;
	if(FlowObject_HasLink(self, _FlowContacts_rel_Requests))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowContacts_rel_Requests));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowContactRequests) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_ContactRequests);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowContacts_RetrieveUsers is available on this object.
 * 
 * Checks whether \ref FlowContacts_RetrieveUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContacts_CanRetrieveUsers(FlowContacts self) { return FlowObject_HasLink(self, _FlowContacts_rel_Users);}
/**
 * \memberof FlowContacts
 * \ingroup Contacts
 * \brief Retrieve user contacts
 *
 * Retrieves the list of user contacts. This includes both friends and not friends. The GetLabels API can be used on the response to get the labels used by user contacts.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContacts FlowContacts_RetrieveUsers(FlowContacts self, int pageSize)
{
	FlowContacts result = NULL;
	if(FlowObject_HasLink(self, _FlowContacts_rel_Users))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowContacts_rel_Users));
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
#endif /* FLOW_USERS_CONTACTS_H_ */
