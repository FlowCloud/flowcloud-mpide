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

#ifndef FLOW_CORE_API_H_
#define FLOW_CORE_API_H_
#include "flow/core/api_type.h"
#include "flow/core/authenticationmethods_type.h"
#include "flow/core/authenticationtokencreatedresponse_type.h"
#include "flow/core/base_types.h"
#include "flow/core/device_type.h"
#include "flow/core/devices_type.h"
#include "flow/core/eventlog_type.h"
#include "flow/core/eventlogs_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/resourcecreatedresponse_type.h"
#include "flow/core/settings_type.h"
#include "flow/core/time_type.h"
#include "flow/core/tokencredentials_type.h"
#include "flow/core/user_type.h"
#include "flow/core/users_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowAPI
 * \brief Creates a new FlowAPI.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowAPI FlowAPI_New(FlowMemoryManager memoryManager){ return (FlowAPI)FlowMemoryManager_NewObject(memoryManager, 1, 19, FlowType_API);}
/**
 * \memberof FlowAPI
 * \brief Registers meta data used for (de)serialising FlowAPI to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowAPI_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_API))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_API, "API", 1, 19);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_API, _FlowAPI_DetectedCountry, FlowType_ID, "DetectedCountry", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Devices, "devices");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Users, "users");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Authenticate, "authenticate");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Authenticationmethods, "authenticationmethods");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Music, "music");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Merchants, "merchants");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Paymentproviders, "paymentproviders");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Subscriptionplans, "subscriptionplans");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Categories, "categories");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Content, "content");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Featuredcontent, "featuredcontent");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Activities, "activities");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Listeningactivities, "listeningactivities");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Pausedactivities, "pausedactivities");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Settings, "settings");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Time, "time");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Eventlogs, "eventlogs");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Uuid, "uuid");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_API, _FlowAPI_rel_Siriusxm, "siriusxm");
	}
}
/**
 * \memberof FlowAPI
 * \brief Indicates whether the property DetectedCountry is set on this object.
 * 
 * Can be used to check whether DetectedCountry is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_HasDetectedCountry(FlowAPI self) { return FlowObject_HasProperty(self, _FlowAPI_DetectedCountry);}
/**
 * \memberof FlowAPI
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowAPI_GetDetectedCountry(FlowAPI self) { return FlowObject_GetIDProperty(self, _FlowAPI_DetectedCountry);}
/**
 * \memberof FlowAPI
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAPI_SetDetectedCountry(FlowAPI self, FlowID value) { FlowObject_SetIDProperty(self, _FlowAPI_DetectedCountry, value);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Indicates whether \ref FlowAPI_RetrieveDevice is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveDevice is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveDevice(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Devices);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Retrieve specified device
 *
 * Retrieve the details of the specified device.
 * 
 * The device information retrieved depends on the current client. Full device information is retrieved if the current client is the device or registered device owner.
 * An associated user (with a DeviceRole, but device is not in the session token) will retrieve less information from the device.
 * If a device that has been made visible to a user, but the user is not associated with the device then only 'anonymous' information is retrieved
 * \param self Object on which the method will be applied
 * \param deviceID Identifier of device to retrieve
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevice FlowAPI_RetrieveDevice(FlowAPI self, FlowID deviceID)
{
	FlowDevice result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Devices))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Devices));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, deviceID);
			result = (FlowDevice) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Get, NULL, FlowType_Device);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Indicates whether \ref FlowAPI_RetrieveDevices is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveDevices is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveDevices(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Devices);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Retrieve devices entry point
 *
 * Retrieve the devices resource entry point.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDevices FlowAPI_RetrieveDevices(FlowAPI self) { return (FlowDevices) FlowObject_HTTPRequest(self, _FlowAPI_rel_Devices, FlowHTTPMethod_Get, NULL, FlowType_Devices);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Indicates whether \ref FlowAPI_RetrieveUser is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveUser is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveUser(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Users);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Retrieve details for the specified user
 *
 * The user parameter can be the userID (Guid), username or a session token (for a logged in user or an owned device). The client must be authenticated to use this API. Note: less information is retrieved if the current user client is not the same as the current userID. If the current user is a friend (from Contacts service) then links are provided to support shared favourites etc.
 * \param self Object on which the method will be applied
 * \param userID Identifier of user to retrieve
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUser FlowAPI_RetrieveUser(FlowAPI self, FlowID userID)
{
	FlowUser result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Users))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Users));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, userID);
			result = (FlowUser) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Get, NULL, FlowType_User);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowAPI
 * \ingroup Users
 * \brief Indicates whether \ref FlowAPI_RetrieveUsersByName is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveUsersByName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveUsersByName(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Users);}
/**
 * \memberof FlowAPI
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
static inline FlowUsers FlowAPI_RetrieveUsersByName(FlowAPI self, char *name, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Users))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Users));
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
 * \memberof FlowAPI
 * \ingroup Users
 * \brief Indicates whether \ref FlowAPI_RetrieveUsersByDisplayName is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveUsersByDisplayName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveUsersByDisplayName(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Users);}
/**
 * \memberof FlowAPI
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
static inline FlowUsers FlowAPI_RetrieveUsersByDisplayName(FlowAPI self, char *displayname, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Users))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Users));
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
 * \memberof FlowAPI
 * \ingroup Users
 * \brief Indicates whether \ref FlowAPI_RetrieveUsersByUserName is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveUsersByUserName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveUsersByUserName(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Users);}
/**
 * \memberof FlowAPI
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
static inline FlowUsers FlowAPI_RetrieveUsersByUserName(FlowAPI self, char *username, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Users))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Users));
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
 * \memberof FlowAPI
 * \ingroup API
 * \brief Indicates whether \ref FlowAPI_RetrieveUsers is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveUsers(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Users);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Retrieve the entry point to add a user
 *
 * Retrieve the users resource entry point. The users resource can be used to add a user.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUsers FlowAPI_RetrieveUsers(FlowAPI self, int pageSize)
{
	FlowUsers result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Users))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Users));
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
 * \memberof FlowAPI
 * \ingroup FlowAuthentication
 * \brief Indicates whether \ref FlowAPI_Authenticate is available on this object.
 * 
 * Checks whether \ref FlowAPI_Authenticate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanAuthenticate(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Authenticate);}
/**
 * \memberof FlowAPI
 * \ingroup FlowAuthentication
 * \brief Create a session token
 *
 * Creates a session authentication token based on the supplied credentials and optionally returns a new Remember-Me token.
 * 
 * Device authentication - A device remember-me token is used to authenticate a device. If the device has a registered user (owner) then the session token provides authentication for the user as well (for example to allow access to user favourites etc.).
 * 
 * User authentication - Username and password (or a remember-me token with user credentials) is used to authenticate a user. This allows access to user favourites etc. and also grants access to API functions that require the user to be logged in.
 * If a device remember-me token also supplied with the username and password then the same session token can be used to access both user and device API functions.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthenticationTokenCreatedResponse FlowAPI_Authenticate(FlowAPI self, FlowTokenCredentials data) { return (FlowAuthenticationTokenCreatedResponse) FlowObject_HTTPRequest(self, _FlowAPI_rel_Authenticate, FlowHTTPMethod_Post, data, FlowType_AuthenticationTokenCreatedResponse);}
/**
 * \memberof FlowAPI
 * \brief Indicates whether \ref FlowAPI_RetrieveAuthenticationMethods is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveAuthenticationMethods is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveAuthenticationMethods(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Authenticationmethods);}
/**
 * \memberof FlowAPI
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowAuthenticationMethods FlowAPI_RetrieveAuthenticationMethods(FlowAPI self) { return (FlowAuthenticationMethods) FlowObject_HTTPRequest(self, _FlowAPI_rel_Authenticationmethods, FlowHTTPMethod_Get, NULL, FlowType_AuthenticationMethods);}
/**
 * \memberof FlowAPI
 * \brief Indicates whether \ref FlowAPI_RetrieveSettingsByQuery is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveSettingsByQuery is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveSettingsByQuery(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Settings);}
/**
 * \memberof FlowAPI
 * \param self Object on which the method will be applied
 * \param query query
 * \param pageSize pageSize
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowAPI_RetrieveSettingsByQuery(FlowAPI self, char *query, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Settings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Settings));
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
 * \memberof FlowAPI
 * \ingroup API
 * \brief Indicates whether \ref FlowAPI_RetrieveSettings is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveSettings is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveSettings(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Settings);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Retrieve licensee specific settings. These are read only.
 *
 * Retrieve key/value settings for the current licensee.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowAPI_RetrieveSettings(FlowAPI self, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowAPI_rel_Settings))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowAPI_rel_Settings));
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
 * \memberof FlowAPI
 * \ingroup API
 * \brief Indicates whether \ref FlowAPI_RetrieveTime is available on this object.
 * 
 * Checks whether \ref FlowAPI_RetrieveTime is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanRetrieveTime(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Time);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Retrieve current server time
 *
 * Retrieve the current server utc time and acquire links for retrieving a list of countries and a list of time zones.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowTime FlowAPI_RetrieveTime(FlowAPI self) { return (FlowTime) FlowObject_HTTPRequest(self, _FlowAPI_rel_Time, FlowHTTPMethod_Get, NULL, FlowType_Time);}
/**
 * \memberof FlowAPI
 * \ingroup EventLogs
 * \brief Indicates whether \ref FlowAPI_SaveEventLog is available on this object.
 * 
 * Checks whether \ref FlowAPI_SaveEventLog is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanSaveEventLog(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Eventlogs);}
/**
 * \memberof FlowAPI
 * \ingroup EventLogs
 * \brief Create an event log entry
 *
 * Creates a new event log entry. This can be used to report application problems.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowAPI_SaveEventLog(FlowAPI self, FlowEventLog data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowAPI_rel_Eventlogs, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowAPI
 * \ingroup EventLogs
 * \brief Indicates whether \ref FlowAPI_SaveEventLogs is available on this object.
 * 
 * Checks whether \ref FlowAPI_SaveEventLogs is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanSaveEventLogs(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Eventlogs);}
/**
 * \memberof FlowAPI
 * \ingroup EventLogs
 * \brief Create event log entries
 *
 * Create multiple new event log entries. This can be used to report application problems.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowAPI_SaveEventLogs(FlowAPI self, FlowEventLogs data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowAPI_rel_Eventlogs, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Indicates whether \ref FlowAPI_GenerateUUID is available on this object.
 * 
 * Checks whether \ref FlowAPI_GenerateUUID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAPI_CanGenerateUUID(FlowAPI self) { return FlowObject_HasLink(self, _FlowAPI_rel_Uuid);}
/**
 * \memberof FlowAPI
 * \ingroup API
 * \brief Generate a new universally unique identifier(UUID)
 *
 * Generate a new universally unique identifier(UUID)
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowResourceCreatedResponse FlowAPI_GenerateUUID(FlowAPI self) { return (FlowResourceCreatedResponse) FlowObject_HTTPRequest(self, _FlowAPI_rel_Uuid, FlowHTTPMethod_Post, NULL, FlowType_ResourceCreatedResponse);}
#endif /* FLOW_CORE_API_H_ */
