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

#ifndef FLOW_USERS_DATASTORE_H_
#define FLOW_USERS_DATASTORE_H_
#include "flow/core/base_types.h"
#include "flow/core/datastore_type.h"
#include "flow/core/datastoreitems_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/usergrants_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDataStore
 * \brief Creates a new FlowDataStore.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDataStore FlowDataStore_New(FlowMemoryManager memoryManager){ return (FlowDataStore)FlowMemoryManager_NewObject(memoryManager, 1, 2, FlowType_DataStore);}
/**
 * \memberof FlowDataStore
 * \brief Registers meta data used for (de)serialising FlowDataStore to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDataStore_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_DataStore))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_DataStore, "DataStore", 1, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DataStore, _FlowDataStore_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DataStore, _FlowDataStore_rel_Access, "access");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DataStore, _FlowDataStore_rel_Items, "items");
	}
}
/**
 * \memberof FlowDataStore
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStore_HasName(FlowDataStore self) { return FlowObject_HasProperty(self, _FlowDataStore_Name);}
/**
 * \memberof FlowDataStore
 * \param self Object on which the method will be applied
*/
static inline char *FlowDataStore_GetName(FlowDataStore self) { return FlowObject_GetStringProperty(self, _FlowDataStore_Name);}
/**
 * \memberof FlowDataStore
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDataStore_SetName(FlowDataStore self, char *value) { FlowObject_SetStringProperty(self, _FlowDataStore_Name, value);}
/**
 * \memberof FlowDataStore
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStore_RetrieveGrantedUsers is available on this object.
 * 
 * Checks whether \ref FlowDataStore_RetrieveGrantedUsers is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStore_CanRetrieveGrantedUsers(FlowDataStore self) { return FlowObject_HasLink(self, _FlowDataStore_rel_Access);}
/**
 * \memberof FlowDataStore
 * \ingroup DataStores
 * \brief Retrieve users who have been granted access
 *
 * Retrieve users who have been granted access to data store
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUserGrants FlowDataStore_RetrieveGrantedUsers(FlowDataStore self) { return (FlowUserGrants) FlowObject_HTTPRequest(self, _FlowDataStore_rel_Access, FlowHTTPMethod_Get, NULL, FlowType_UserGrants);}
/**
 * \memberof FlowDataStore
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStore_RetrieveItemsByQuery is available on this object.
 * 
 * Checks whether \ref FlowDataStore_RetrieveItemsByQuery is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStore_CanRetrieveItemsByQuery(FlowDataStore self) { return FlowObject_HasLink(self, _FlowDataStore_rel_Items);}
/**
 * \memberof FlowDataStore
 * \ingroup DataStores
 * \brief Retrieve a subset stored items
 *
 * Retrieve a subset stored items.
 * A query takes the form:
 * 
 * \@FieldName {operator} {value}
 * 
 * Or for nested objects
 * 
 * \@FieldName1.FieldName2 {operator} {value}
 * 
 * Also boolean logic (NOT, AND , OR) can aso be applied
 * 
 * \@FieldName1 {operator} {value} AND \@FieldName2 {operator} {value}
 * The supported query operators are:
 * | Operator | Description |
 * | :------: | :---------- |
 * | CONTAINS | field contains a value. e.g. \@FieldName CONTAINS 'ex' |
 * | LIKE | field like a value (including multiple wildcards, represented by the % character). e.g. \@FieldName LIKE 'exam%' |
 * | IN | field in a list of possible values. e.g \@FieldName IN ('pattern1', 'pattern2') |
 * | == | field equals specific value. e.g. \@FieldName == 'example' |
 * | != | field is not equal to specific value. e.g. \@FieldName != 'example' |
 * | > | field greater than specific value. e.g. \@FieldName > 12345 |
 * | >= | field greater than or equal to specific value. e.g. \@FieldName >= 12345 |
 * | < | field less than specific value. e.g. \@FieldName < 12345 |
 * | <= | field less than or equal tospecific value. e.g. \@FieldName <= 12345 |
 * \param self Object on which the method will be applied
 * \param query query
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDataStoreItems FlowDataStore_RetrieveItemsByQuery(FlowDataStore self, char *query, int pageSize)
{
	FlowDataStoreItems result = NULL;
	if(FlowObject_HasLink(self, _FlowDataStore_rel_Items))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDataStore_rel_Items));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "query", query);
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowDataStoreItems) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_DataStoreItems);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowDataStore
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStore_RetrieveItems is available on this object.
 * 
 * Checks whether \ref FlowDataStore_RetrieveItems is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStore_CanRetrieveItems(FlowDataStore self) { return FlowObject_HasLink(self, _FlowDataStore_rel_Items);}
/**
 * \memberof FlowDataStore
 * \ingroup DataStores
 * \brief Retrieve stored items
 *
 * 
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDataStoreItems FlowDataStore_RetrieveItems(FlowDataStore self, int pageSize)
{
	FlowDataStoreItems result = NULL;
	if(FlowObject_HasLink(self, _FlowDataStore_rel_Items))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowDataStore_rel_Items));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowDataStoreItems) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_DataStoreItems);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
#endif /* FLOW_USERS_DATASTORE_H_ */
