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

#ifndef FLOW_USERS_DATASTOREITEM_H_
#define FLOW_USERS_DATASTOREITEM_H_
#include "flow/core/base_types.h"
#include "flow/core/datastoreitem_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDataStoreItem
 * \brief Creates a new FlowDataStoreItem.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDataStoreItem FlowDataStoreItem_New(FlowMemoryManager memoryManager){ return (FlowDataStoreItem)FlowMemoryManager_NewObject(memoryManager, 1, 3, FlowType_DataStoreItem);}
/**
 * \memberof FlowDataStoreItem
 * \brief Registers meta data used for (de)serialising FlowDataStoreItem to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDataStoreItem_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_DataStoreItem))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_DataStoreItem, "DataStoreItem", 1, 3);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DataStoreItem, _FlowDataStoreItem_Content, FlowType_RawString, "Content", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DataStoreItem, _FlowDataStoreItem_rel_Remove, "remove");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DataStoreItem, _FlowDataStoreItem_rel_Self, "self");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_DataStoreItem, _FlowDataStoreItem_rel_Update, "update");
	}
}
/**
 * \memberof FlowDataStoreItem
 * \brief Indicates whether the property Content is set on this object.
 * 
 * Can be used to check whether Content is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItem_HasContent(FlowDataStoreItem self) { return FlowObject_HasProperty(self, _FlowDataStoreItem_Content);}
/**
 * \memberof FlowDataStoreItem
 * \param self Object on which the method will be applied
*/
static inline char *FlowDataStoreItem_GetContent(FlowDataStoreItem self) { return FlowObject_GetStringProperty(self, _FlowDataStoreItem_Content);}
/**
 * \memberof FlowDataStoreItem
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDataStoreItem_SetContent(FlowDataStoreItem self, char *value) { FlowObject_SetStringProperty(self, _FlowDataStoreItem_Content, value);}
/**
 * \memberof FlowDataStoreItem
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStoreItem_Remove is available on this object.
 * 
 * Checks whether \ref FlowDataStoreItem_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItem_CanRemove(FlowDataStoreItem self) { return FlowObject_HasLink(self, _FlowDataStoreItem_rel_Remove);}
/**
 * \memberof FlowDataStoreItem
 * \ingroup DataStores
 * \brief Removing a data store item
 *
 * 
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDataStoreItem_Remove(FlowDataStoreItem self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowDataStoreItem_rel_Remove, FlowHTTPMethod_Delete, NULL);}
/**
 * \memberof FlowDataStoreItem
 * \brief Indicates whether \ref FlowDataStoreItem_RetrieveDetails is available on this object.
 * 
 * Checks whether \ref FlowDataStoreItem_RetrieveDetails is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItem_CanRetrieveDetails(FlowDataStoreItem self) { return FlowObject_HasLink(self, _FlowDataStoreItem_rel_Self);}
/**
 * \memberof FlowDataStoreItem
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowDataStoreItem FlowDataStoreItem_RetrieveDetails(FlowDataStoreItem self) { return (FlowDataStoreItem) FlowObject_HTTPRequest(self, _FlowDataStoreItem_rel_Self, FlowHTTPMethod_Get, NULL, FlowType_DataStoreItem);}
/**
 * \memberof FlowDataStoreItem
 * \ingroup DataStores
 * \brief Indicates whether \ref FlowDataStoreItem_Update is available on this object.
 * 
 * Checks whether \ref FlowDataStoreItem_Update is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDataStoreItem_CanUpdate(FlowDataStoreItem self) { return FlowObject_HasLink(self, _FlowDataStoreItem_rel_Update);}
/**
 * \memberof FlowDataStoreItem
 * \ingroup DataStores
 * \brief Updating a data store item
 *
 * 
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowDataStoreItem_Update(FlowDataStoreItem self, FlowDataStoreItem data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowDataStoreItem_rel_Update, FlowHTTPMethod_Put, data);}
#endif /* FLOW_USERS_DATASTOREITEM_H_ */
