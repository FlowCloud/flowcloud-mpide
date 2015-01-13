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

#ifndef FLOW_CORE_CONTENTCONTAINER_H_
#define FLOW_CORE_CONTENTCONTAINER_H_
#include "flow/core/base_types.h"
#include "flow/core/contentcontainer_type.h"
#include "flow/core/contentcontainers_type.h"
#include "flow/core/firmwareimages_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowContentContainer
 * \brief Creates a new FlowContentContainer.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowContentContainer FlowContentContainer_New(FlowMemoryManager memoryManager){ return (FlowContentContainer)FlowMemoryManager_NewObject(memoryManager, 8, 5, FlowType_ContentContainer);}
/**
 * \memberof FlowContentContainer
 * \brief Registers meta data used for (de)serialising FlowContentContainer to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowContentContainer_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_ContentContainer))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_ContentContainer, "ContentContainer", 8, 5);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_Searchable, FlowType_Boolean, "Searchable", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_UpdateID, FlowType_Integer, "UpdateID", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_ID, FlowType_ID, "ID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_DisplayName, FlowType_String, "DisplayName", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_Description, FlowType_String, "Description", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_ItemsCount, FlowType_Integer, "ItemsCount", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ContentContainer, _FlowContentContainer_Sorted, FlowType_String, "Sorted", false);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_ContentContainer, _FlowContentContainer_rel_Ondemands, "ondemands");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_ContentContainer, _FlowContentContainer_rel_Liveradios, "liveradios");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_ContentContainer, _FlowContentContainer_rel_Similar, "similar");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_ContentContainer, _FlowContentContainer_rel_Firmwares, "firmwares");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_ContentContainer, _FlowContentContainer_rel_Imageurl, "imageurl");
	}
}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property Searchable is set on this object.
 * 
 * Can be used to check whether Searchable is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasSearchable(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_Searchable);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_GetSearchable(FlowContentContainer self) { return FlowObject_GetBooleanProperty(self, _FlowContentContainer_Searchable);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetSearchable(FlowContentContainer self, bool value) { FlowObject_SetBooleanProperty(self, _FlowContentContainer_Searchable, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property UpdateID is set on this object.
 * 
 * Can be used to check whether UpdateID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasUpdateID(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_UpdateID);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline int FlowContentContainer_GetUpdateID(FlowContentContainer self) { return FlowObject_GetIntegerProperty(self, _FlowContentContainer_UpdateID);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetUpdateID(FlowContentContainer self, int value) { FlowObject_SetIntegerProperty(self, _FlowContentContainer_UpdateID, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property ID is set on this object.
 * 
 * Can be used to check whether ID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasID(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_ID);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowContentContainer_GetID(FlowContentContainer self) { return FlowObject_GetIDProperty(self, _FlowContentContainer_ID);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetID(FlowContentContainer self, FlowID value) { FlowObject_SetIDProperty(self, _FlowContentContainer_ID, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasName(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_Name);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline char *FlowContentContainer_GetName(FlowContentContainer self) { return FlowObject_GetStringProperty(self, _FlowContentContainer_Name);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetName(FlowContentContainer self, char *value) { FlowObject_SetStringProperty(self, _FlowContentContainer_Name, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property DisplayName is set on this object.
 * 
 * Can be used to check whether DisplayName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasDisplayName(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_DisplayName);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline char *FlowContentContainer_GetDisplayName(FlowContentContainer self) { return FlowObject_GetStringProperty(self, _FlowContentContainer_DisplayName);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetDisplayName(FlowContentContainer self, char *value) { FlowObject_SetStringProperty(self, _FlowContentContainer_DisplayName, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property Description is set on this object.
 * 
 * Can be used to check whether Description is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasDescription(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_Description);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline char *FlowContentContainer_GetDescription(FlowContentContainer self) { return FlowObject_GetStringProperty(self, _FlowContentContainer_Description);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetDescription(FlowContentContainer self, char *value) { FlowObject_SetStringProperty(self, _FlowContentContainer_Description, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property ItemsCount is set on this object.
 * 
 * Can be used to check whether ItemsCount is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasItemsCount(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_ItemsCount);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline int FlowContentContainer_GetItemsCount(FlowContentContainer self) { return FlowObject_GetIntegerProperty(self, _FlowContentContainer_ItemsCount);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetItemsCount(FlowContentContainer self, int value) { FlowObject_SetIntegerProperty(self, _FlowContentContainer_ItemsCount, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property Sorted is set on this object.
 * 
 * Can be used to check whether Sorted is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasSorted(FlowContentContainer self) { return FlowObject_HasProperty(self, _FlowContentContainer_Sorted);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline char *FlowContentContainer_GetSorted(FlowContentContainer self) { return FlowObject_GetStringProperty(self, _FlowContentContainer_Sorted);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowContentContainer_SetSorted(FlowContentContainer self, char *value) { FlowObject_SetStringProperty(self, _FlowContentContainer_Sorted, value);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether \ref FlowContentContainer_RetrieveSimilar is available on this object.
 * 
 * Checks whether \ref FlowContentContainer_RetrieveSimilar is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_CanRetrieveSimilar(FlowContentContainer self) { return FlowObject_HasLink(self, _FlowContentContainer_rel_Similar);}
/**
 * \memberof FlowContentContainer
 * \brief Retrieving a list of content similar to that currently selected
 *
 * 
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContentContainers FlowContentContainer_RetrieveSimilar(FlowContentContainer self) { return (FlowContentContainers) FlowObject_HTTPRequest(self, _FlowContentContainer_rel_Similar, FlowHTTPMethod_Get, NULL, FlowType_ContentContainers);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether \ref FlowContentContainer_RetrieveFirmwares is available on this object.
 * 
 * Checks whether \ref FlowContentContainer_RetrieveFirmwares is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_CanRetrieveFirmwares(FlowContentContainer self) { return FlowObject_HasLink(self, _FlowContentContainer_rel_Firmwares);}
/**
 * \memberof FlowContentContainer
 * \brief Retrieving a list of firmware images
 *
 * 
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowFirmwareImages FlowContentContainer_RetrieveFirmwares(FlowContentContainer self) { return (FlowFirmwareImages) FlowObject_HTTPRequest(self, _FlowContentContainer_rel_Firmwares, FlowHTTPMethod_Get, NULL, FlowType_FirmwareImages);}
/**
 * \memberof FlowContentContainer
 * \brief Indicates whether the property ImageUrl is set on this object.
 * 
 * Can be used to check whether ImageUrl is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowContentContainer_HasImageUrl(FlowContentContainer self) { return FlowObject_HasLink(self, _FlowContentContainer_rel_Imageurl);}
/**
 * \memberof FlowContentContainer
 * \param self Object on which the method will be applied
*/
static inline char *FlowContentContainer_GetImageUrl(FlowContentContainer self) { return FlowObject_GetLink(self, _FlowContentContainer_rel_Imageurl);}
#endif /* FLOW_CORE_CONTENTCONTAINER_H_ */
