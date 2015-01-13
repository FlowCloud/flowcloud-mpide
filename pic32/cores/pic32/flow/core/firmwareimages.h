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

#ifndef FLOW_USERS_FIRMWAREIMAGES_H_
#define FLOW_USERS_FIRMWAREIMAGES_H_
#include "flow/core/base_types.h"
#include "flow/core/contentcontainers_type.h"
#include "flow/core/firmwareimage.h"
#include "flow/core/firmwareimage_type.h"
#include "flow/core/firmwareimages_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/pageinfo.h"
#include "flow/core/resourcecreatedresponse_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowFirmwareImages
 * \brief Creates a new FlowFirmwareImages.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowFirmwareImages FlowFirmwareImages_New(FlowMemoryManager memoryManager){ return (FlowFirmwareImages)FlowMemoryManager_NewObject(memoryManager, 2, 2, FlowType_FirmwareImages);}
/**
 * \memberof FlowFirmwareImages
 * \brief Registers meta data used for (de)serialising FlowFirmwareImages to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowFirmwareImages_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_FirmwareImages))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_FirmwareImages, "FirmwareImages", 2, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImages, _FlowFirmwareImages_PageInfo, FlowType_PageInfo, "PageInfo", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_FirmwareImages, _FlowFirmwareImages_Items, "Items", "FirmwareImage", FlowType_FirmwareImage, FlowType_FirmwareImages);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_FirmwareImages, _FlowFirmwareImages_rel_Add, "add");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_FirmwareImages, _FlowFirmwareImages_rel_Imagetype, "imagetype");
	}
}
/**
 * \memberof FlowFirmwareImages
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImages_HasItems(FlowFirmwareImages self) { return FlowObject_HasProperty(self, _FlowFirmwareImages_Items);}
/**
 * \memberof FlowFirmwareImages
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowFirmwareImage FlowFirmwareImages_GetItem(FlowFirmwareImages self, uint index) { return (FlowFirmwareImage)FlowObject_GetArrayObjectProperty(self, _FlowFirmwareImages_Items, index);}
/**
 * \memberof FlowFirmwareImages
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowFirmwareImages_GetCount(FlowFirmwareImages self) { return FlowObject_GetArrayPropertyCount(self, _FlowFirmwareImages_Items);}
/**
 * \memberof FlowFirmwareImages
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowFirmwareImage FlowFirmwareImages_NewItem(FlowFirmwareImages self)
{
	FlowFirmwareImage result = FlowFirmwareImage_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowFirmwareImages_Items, result);
	return result;
}
/**
 * \memberof FlowFirmwareImages
 * \brief Returns the total number of items available from Server (NOTE this make return -1 when this total in unknown).
 * 
 * The value returned by this method is unrelated to the number of items already loaded in the list. But is the total available from Server
 * \param self Object on which the method will be applied
*/
static inline int FlowFirmwareImages_GetTotalCount(FlowFirmwareImages self)
{
	int result = 0;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowFirmwareImages_PageInfo);
	if (pageInfo)
		result = FlowPageInfo_GetTotalCount(pageInfo);
	else
		result = FlowObject_GetArrayPropertyCount(self, _FlowFirmwareImages_Items);
	return result;
}
/**
 * \memberof FlowFirmwareImages
 * \brief load the next page form the server into the list (NOTE removes existing items).
 * 
 * Returned whether was able to load next page in to list (NOTE this could be because there are no more item or error see \ref Errors#Flow_GetLastError ).
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImages_RetrieveNextPage(FlowFirmwareImages self)
{
	bool result = false;
	FlowPageInfo pageInfo = (FlowPageInfo)FlowObject_GetObjectProperty(self, _FlowFirmwareImages_PageInfo);
	if (pageInfo)
	{
		char *url = FlowPageInfo_GetNext(pageInfo);
			if (url)
		result = FlowObject_LoadNextPage(self, url);
	}
	return result;
}
/**
 * \memberof FlowFirmwareImages
 * \ingroup Firmwares
 * \brief Indicates whether \ref FlowFirmwareImages_Add is available on this object.
 * 
 * Checks whether \ref FlowFirmwareImages_Add is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImages_CanAdd(FlowFirmwareImages self) { return FlowObject_HasLink(self, _FlowFirmwareImages_rel_Add);}
/**
 * \memberof FlowFirmwareImages
 * \ingroup Firmwares
 * \brief Add device type firmware
 *
 * Adds a firmware image for the specified device and group (as represented by an OAuth consumer key).
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowResourceCreatedResponse FlowFirmwareImages_Add(FlowFirmwareImages self, FlowFirmwareImage data) { return (FlowResourceCreatedResponse) FlowObject_HTTPRequest(self, _FlowFirmwareImages_rel_Add, FlowHTTPMethod_Post, data, FlowType_ResourceCreatedResponse);}
/**
 * \memberof FlowFirmwareImages
 * \ingroup Firmwares
 * \brief Indicates whether \ref FlowFirmwareImages_RetrieveImageTypes is available on this object.
 * 
 * Checks whether \ref FlowFirmwareImages_RetrieveImageTypes is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImages_CanRetrieveImageTypes(FlowFirmwareImages self) { return FlowObject_HasLink(self, _FlowFirmwareImages_rel_Imagetype);}
/**
 * \memberof FlowFirmwareImages
 * \ingroup Firmwares
 * \brief Retrieve firmware image types
 *
 * Retrieve all firmware image types available for the specified device.
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContentContainers FlowFirmwareImages_RetrieveImageTypes(FlowFirmwareImages self, int pageSize)
{
	FlowContentContainers result = NULL;
	if(FlowObject_HasLink(self, _FlowFirmwareImages_rel_Imagetype))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowFirmwareImages_rel_Imagetype));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowContentContainers) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_ContentContainers);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
#endif /* FLOW_USERS_FIRMWAREIMAGES_H_ */
