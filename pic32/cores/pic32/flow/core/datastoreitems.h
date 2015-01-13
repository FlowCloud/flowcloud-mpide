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

#ifndef FLOW_USERS_DATASTOREITEMS_H_
#define FLOW_USERS_DATASTOREITEMS_H_
#include "flow/core/base_types.h"
#include "flow/core/datastoreitem.h"
#include "flow/core/datastoreitem_type.h"
#include "flow/core/datastoreitems_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/pageinfo.h"
#include "flow/core/resourcecreatedresponse_type.h"
#include "flow/core/resourcescreatedresponse_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDataStoreItems
 * \brief Creates a new FlowDataStoreItems.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDataStoreItems FlowDataStoreItems_New(FlowMemoryManager memoryManager){ return (FlowDataStoreItems)FlowMemoryManager_NewObject(memoryManager, 2, 2, FlowType_DataStoreItems);}
/**
 * \memberof FlowDataStoreItems
 * \brief Registers meta data used for (de)serialising FlowDataStoreItems to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDataStoreItems_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_DataStoreItems))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_DataStoreItems, "DataStoreItems", 2, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DataStoreItems, _FlowDataStoreItems_PageInfo, FlowType_PageInfo, "PageInfo", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_DataStoreItems, _FlowDataStoreItems_Items, "Items", "DataStoreItem", FlowType_DataStoreItem, FlowType_DataStoreItems);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DataStoreItems, _FlowDataStoreItems_rel_Add, "add");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DataStoreItems, _FlowDataStoreItems_rel_Remove, "remove");
	}
}
/**
 * \memberof FlowDataStoreItems
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItems_HasItems(FlowDataStoreItems self) { return FlowObject_HasProperty(self, _FlowDataStoreItems_Items);}
/**
 * \memberof FlowDataStoreItems
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowDataStoreItem FlowDataStoreItems_GetItem(FlowDataStoreItems self, uint index) { return (FlowDataStoreItem)FlowObject_GetArrayObjectProperty(self, _FlowDataStoreItems_Items, index);}
/**
 * \memberof FlowDataStoreItems
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowDataStoreItems_GetCount(FlowDataStoreItems self) { return FlowObject_GetArrayPropertyCount(self, _FlowDataStoreItems_Items);}
/**
 * \memberof FlowDataStoreItems
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowDataStoreItem FlowDataStoreItems_NewItem(FlowDataStoreItems self)
{
	FlowDataStoreItem result = FlowDataStoreItem_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowDataStoreItems_Items, result);
	return result;
}
/**
 * \memberof FlowDataStoreItems
 * \brief Returns the total number of items available from Server (NOTE this make return -1 when this total in unknown).
 * 
 * The value returned by this method is unrelated to the number of items already loaded in the list. But is the total available from Server
 * \param self Object on which the method will be applied
*/
static inline int FlowDataStoreItems_GetTotalCount(FlowDataStoreItems self)
{
	int result = 0;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowDataStoreItems_PageInfo);
	if (pageInfo)
		result = FlowPageInfo_GetTotalCount(pageInfo);
	else
		result = FlowObject_GetArrayPropertyCount(self, _FlowDataStoreItems_Items);
	return result;
}
/**
 * \memberof FlowDataStoreItems
 * \brief load the next page form the server into the list (NOTE removes existing items).
 * 
 * Returned whether was able to load next page in to list (NOTE this could be because there are no more item or error see \ref Errors#Flow_GetLastError ).
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItems_RetrieveNextPage(FlowDataStoreItems self)
{
	bool result = false;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowDataStoreItems_PageInfo);
	if (pageInfo)
	{
		char *url = FlowPageInfo_GetNext(pageInfo);
			if (url)
		result = FlowObject_LoadNextPage(self, url);
	}
	return result;
}
/**
 * \memberof FlowDataStoreItems
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStoreItems_AddItem is available on this object.
 * 
 * Checks whether \ref FlowDataStoreItems_AddItem is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItems_CanAddItem(FlowDataStoreItems self) { return FlowObject_HasLink(self, _FlowDataStoreItems_rel_Add);}
/**
 * \memberof FlowDataStoreItems
 * \ingroup DataStores
 * \brief Adding data store items
 *
 * 
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowResourceCreatedResponse FlowDataStoreItems_AddItem(FlowDataStoreItems self, FlowDataStoreItem data) { return (FlowResourceCreatedResponse) FlowObject_HTTPRequest(self, _FlowDataStoreItems_rel_Add, FlowHTTPMethod_Post, data, FlowType_ResourceCreatedResponse);}
/**
 * \memberof FlowDataStoreItems
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStoreItems_AddItems is available on this object.
 * 
 * Checks whether \ref FlowDataStoreItems_AddItems is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItems_CanAddItems(FlowDataStoreItems self) { return FlowObject_HasLink(self, _FlowDataStoreItems_rel_Add);}
/**
 * \memberof FlowDataStoreItems
 * \ingroup DataStores
 * \brief Adding data store items
 *
 * 
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowResourcesCreatedResponse FlowDataStoreItems_AddItems(FlowDataStoreItems self, FlowDataStoreItems data) { return (FlowResourcesCreatedResponse) FlowObject_HTTPRequest(self, _FlowDataStoreItems_rel_Add, FlowHTTPMethod_Post, data, FlowType_ResourcesCreatedResponse);}
/**
 * \memberof FlowDataStoreItems
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStoreItems_Remove is available on this object.
 * 
 * Checks whether \ref FlowDataStoreItems_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItems_CanRemove(FlowDataStoreItems self) { return FlowObject_HasLink(self, _FlowDataStoreItems_rel_Remove);}
/**
 * \memberof FlowDataStoreItems
 * \ingroup DataStores
 * \brief deleting data store items using query expression
 *
 * 
 * \param self Object on which the method will be applied
 * \param query query
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDataStoreItems_Remove(FlowDataStoreItems self, char *query)
{
	bool result = false;
	if(FlowObject_HasLink(self, _FlowDataStoreItems_rel_Remove))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDataStoreItems_rel_Remove));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "query", query);
			result = FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Delete, NULL);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
#endif /* FLOW_USERS_DATASTOREITEMS_H_ */
