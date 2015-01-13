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

#ifndef FLOW_CORE_SETTINGS_H_
#define FLOW_CORE_SETTINGS_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/pageinfo.h"
#include "flow/core/setting.h"
#include "flow/core/settings_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowSettings
 * \brief Creates a new FlowSettings.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowSettings FlowSettings_New(FlowMemoryManager memoryManager){ return (FlowSettings)FlowMemoryManager_NewObject(memoryManager, 2, 4, FlowType_Settings);}
/**
 * \memberof FlowSettings
 * \brief Registers meta data used for (de)serialising FlowSettings to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowSettings_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Settings))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Settings, "Settings", 2, 4);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Settings, _FlowSettings_PageInfo, FlowType_PageInfo, "PageInfo", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Settings, _FlowSettings_Items, "Items", "Setting", FlowType_Setting, FlowType_Settings);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Settings, _FlowSettings_rel_Add, "add");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Settings, _FlowSettings_rel_Remove, "remove");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Settings, _FlowSettings_rel_Update, "update");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Settings, _FlowSettings_rel_Self, "self");
	}
}
/**
 * \memberof FlowSettings
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowSettings_HasItems(FlowSettings self) { return FlowObject_HasProperty(self, _FlowSettings_Items);}
/**
 * \memberof FlowSettings
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowSetting FlowSettings_GetItem(FlowSettings self, uint index) { return (FlowSetting)FlowObject_GetArrayObjectProperty(self, _FlowSettings_Items, index);}
/**
 * \memberof FlowSettings
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowSettings_GetCount(FlowSettings self) { return FlowObject_GetArrayPropertyCount(self, _FlowSettings_Items);}
/**
 * \memberof FlowSettings
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowSetting FlowSettings_NewItem(FlowSettings self)
{
	FlowSetting result = FlowSetting_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowSettings_Items, result);
	return result;
}
/**
 * \memberof FlowSettings
 * \brief Returns the total number of items available from Server (NOTE this make return -1 when this total in unknown).
 * 
 * The value returned by this method is unrelated to the number of items already loaded in the list. But is the total available from Server
 * \param self Object on which the method will be applied
*/
static inline int FlowSettings_GetTotalCount(FlowSettings self)
{
	int result = 0;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowSettings_PageInfo);
	if (pageInfo)
		result = FlowPageInfo_GetTotalCount(pageInfo);
	else
		result = FlowObject_GetArrayPropertyCount(self, _FlowSettings_Items);
	return result;
}
/**
 * \memberof FlowSettings
 * \brief load the next page form the server into the list (NOTE removes existing items).
 * 
 * Returned whether was able to load next page in to list (NOTE this could be because there are no more item or error see \ref Errors#Flow_GetLastError ).
 * \param self Object on which the method will be applied
*/
static inline bool FlowSettings_RetrieveNextPage(FlowSettings self)
{
	bool result = false;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowSettings_PageInfo);
	if (pageInfo)
	{
		char *url = FlowPageInfo_GetNext(pageInfo);
			if (url)
		result = FlowObject_LoadNextPage(self, url);
	}
	return result;
}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief Indicates whether \ref FlowSettings_Add is available on this object.
 * 
 * Checks whether \ref FlowSettings_Add is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowSettings_CanAdd(FlowSettings self) { return FlowObject_HasLink(self, _FlowSettings_rel_Add);}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief Create settings
 *
 * Add or update key/value store settings in the current settings list. This method is used to add device, user or device-user settings.
 * The client must be authenticated to use this call.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowSettings_Add(FlowSettings self, FlowSettings data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowSettings_rel_Add, FlowHTTPMethod_Post, data);}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief Indicates whether \ref FlowSettings_Remove is available on this object.
 * 
 * Checks whether \ref FlowSettings_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowSettings_CanRemove(FlowSettings self) { return FlowObject_HasLink(self, _FlowSettings_rel_Remove);}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief Delete setting using query expression
 *
 * Delete key-value settings that match the query. This method can be used to delete device, user or device-user settings.
 * The client must be authenticated to use this call.
 * 
 * The settings to delete are identified by a query passed into the request. A query takes the form:
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
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowSettings_Remove(FlowSettings self, char *query)
{
	bool result = false;
	if(FlowObject_HasLink(self, _FlowSettings_rel_Remove))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowSettings_rel_Remove));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "query", query);
			result = FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Delete, NULL);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief Indicates whether \ref FlowSettings_RemoveSetting is available on this object.
 * 
 * Checks whether \ref FlowSettings_RemoveSetting is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowSettings_CanRemoveSetting(FlowSettings self) { return FlowObject_HasLink(self, _FlowSettings_rel_Remove);}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief deleting key-value setting
 *
 * Delete the current key-value setting. This method can be used to delete device, user or device-user settings.
 * The client must be authenticated to use this call.
 * \param self Object on which the method will be applied
 * \param key key
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowSettings_RemoveSetting(FlowSettings self, FlowID key)
{
	bool result = false;
	if(FlowObject_HasLink(self, _FlowSettings_rel_Remove))
	{
		FlowHTTPQuery query = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowSettings_rel_Remove));
		if(query)
		{
			FlowHTTPQuery_AppendPathSuffix(query, key);
			result = FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowObject_GetMemoryManager(self), query, FlowHTTPMethod_Delete, NULL);
			FlowHTTPQuery_Free(&query);
		}
	}
	return result;
}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief Indicates whether \ref FlowSettings_Update is available on this object.
 * 
 * Checks whether \ref FlowSettings_Update is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowSettings_CanUpdate(FlowSettings self) { return FlowObject_HasLink(self, _FlowSettings_rel_Update);}
/**
 * \memberof FlowSettings
 * \ingroup KeyValueStore
 * \brief Update settings
 *
 * Update key/value store settings in the current settings list. This method is used to update device, user or device-user settings.
 * The client must be authenticated to use this call.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowSettings_Update(FlowSettings self, FlowSettings data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowSettings_rel_Update, FlowHTTPMethod_Put, data);}
#endif /* FLOW_CORE_SETTINGS_H_ */
