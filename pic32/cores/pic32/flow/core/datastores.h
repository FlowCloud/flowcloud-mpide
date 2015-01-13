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

#ifndef FLOW_USERS_DATASTORES_H_
#define FLOW_USERS_DATASTORES_H_
#include "flow/core/base_types.h"
#include "flow/core/datastore.h"
#include "flow/core/datastores_type.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/pageinfo.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDataStores
 * \brief Creates a new FlowDataStores.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDataStores FlowDataStores_New(FlowMemoryManager memoryManager){ return (FlowDataStores)FlowMemoryManager_NewObject(memoryManager, 2, 0, FlowType_DataStores);}
/**
 * \memberof FlowDataStores
 * \brief Registers meta data used for (de)serialising FlowDataStores to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDataStores_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_DataStores))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_DataStores, "DataStores", 2, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DataStores, _FlowDataStores_PageInfo, FlowType_PageInfo, "PageInfo", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_DataStores, _FlowDataStores_Items, "Items", "DataStore", FlowType_DataStore, FlowType_DataStores);
	}
}
/**
 * \memberof FlowDataStores
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStores_HasItems(FlowDataStores self) { return FlowObject_HasProperty(self, _FlowDataStores_Items);}
/**
 * \memberof FlowDataStores
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowDataStore FlowDataStores_GetItem(FlowDataStores self, uint index) { return (FlowDataStore)FlowObject_GetArrayObjectProperty(self, _FlowDataStores_Items, index);}
/**
 * \memberof FlowDataStores
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowDataStores_GetCount(FlowDataStores self) { return FlowObject_GetArrayPropertyCount(self, _FlowDataStores_Items);}
/**
 * \memberof FlowDataStores
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowDataStore FlowDataStores_NewItem(FlowDataStores self)
{
	FlowDataStore result = FlowDataStore_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowDataStores_Items, result);
	return result;
}
/**
 * \memberof FlowDataStores
 * \brief Returns the total number of items available from Server (NOTE this make return -1 when this total in unknown).
 * 
 * The value returned by this method is unrelated to the number of items already loaded in the list. But is the total available from Server
 * \param self Object on which the method will be applied
*/
static inline int FlowDataStores_GetTotalCount(FlowDataStores self)
{
	int result = 0;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowDataStores_PageInfo);
	if (pageInfo)
		result = FlowPageInfo_GetTotalCount(pageInfo);
	else
		result = FlowObject_GetArrayPropertyCount(self, _FlowDataStores_Items);
	return result;
}
/**
 * \memberof FlowDataStores
 * \brief load the next page form the server into the list (NOTE removes existing items).
 * 
 * Returned whether was able to load next page in to list (NOTE this could be because there are no more item or error see \ref Errors#Flow_GetLastError ).
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStores_RetrieveNextPage(FlowDataStores self)
{
	bool result = false;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowDataStores_PageInfo);
	if (pageInfo)
	{
		char *url = FlowPageInfo_GetNext(pageInfo);
			if (url)
		result = FlowObject_LoadNextPage(self, url);
	}
	return result;
}
#endif /* FLOW_USERS_DATASTORES_H_ */
