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

#ifndef FLOW_USERS_FIRMWAREIMAGE_H_
#define FLOW_USERS_FIRMWAREIMAGE_H_
#include "flow/core/base_types.h"
#include "flow/core/firmwareimage_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowFirmwareImage
 * \brief Creates a new FlowFirmwareImage.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowFirmwareImage FlowFirmwareImage_New(FlowMemoryManager memoryManager){ return (FlowFirmwareImage)FlowMemoryManager_NewObject(memoryManager, 11, 2, FlowType_FirmwareImage);}
/**
 * \memberof FlowFirmwareImage
 * \brief Registers meta data used for (de)serialising FlowFirmwareImage to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowFirmwareImage_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_FirmwareImage))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_FirmwareImage, "FirmwareImage", 11, 2);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_FirmwareID, FlowType_ID, "FirmwareID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_Version, FlowType_String, "Version", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_FirmwareImageUrl, FlowType_String, "FirmwareImageUrl", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_Description, FlowType_String, "Description", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_SubmittedBy, FlowType_String, "SubmittedBy", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_PublishedDate, FlowType_Datetime, "PublishedDate", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_IsPrivate, FlowType_Boolean, "IsPrivate", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_ImageType, FlowType_String, "ImageType", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_DeviceType, FlowType_ID, "DeviceType", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FirmwareImage, _FlowFirmwareImage_Authorisation, FlowType_String, "Authorisation", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_FirmwareImage, _FlowFirmwareImage_rel_Remove, "remove");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_FirmwareImage, _FlowFirmwareImage_rel_Update, "update");
	}
}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property FirmwareID is set on this object.
 * 
 * Can be used to check whether FirmwareID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasFirmwareID(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_FirmwareID);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowFirmwareImage_GetFirmwareID(FlowFirmwareImage self) { return FlowObject_GetIDProperty(self, _FlowFirmwareImage_FirmwareID);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetFirmwareID(FlowFirmwareImage self, FlowID value) { FlowObject_SetIDProperty(self, _FlowFirmwareImage_FirmwareID, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasName(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_Name);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowFirmwareImage_GetName(FlowFirmwareImage self) { return FlowObject_GetStringProperty(self, _FlowFirmwareImage_Name);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetName(FlowFirmwareImage self, char *value) { FlowObject_SetStringProperty(self, _FlowFirmwareImage_Name, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property Version is set on this object.
 * 
 * Can be used to check whether Version is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasVersion(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_Version);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowFirmwareImage_GetVersion(FlowFirmwareImage self) { return FlowObject_GetStringProperty(self, _FlowFirmwareImage_Version);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetVersion(FlowFirmwareImage self, char *value) { FlowObject_SetStringProperty(self, _FlowFirmwareImage_Version, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property FirmwareImageUrl is set on this object.
 * 
 * Can be used to check whether FirmwareImageUrl is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasFirmwareImageUrl(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_FirmwareImageUrl);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowFirmwareImage_GetFirmwareImageUrl(FlowFirmwareImage self) { return FlowObject_GetStringProperty(self, _FlowFirmwareImage_FirmwareImageUrl);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetFirmwareImageUrl(FlowFirmwareImage self, char *value) { FlowObject_SetStringProperty(self, _FlowFirmwareImage_FirmwareImageUrl, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property Description is set on this object.
 * 
 * Can be used to check whether Description is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasDescription(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_Description);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowFirmwareImage_GetDescription(FlowFirmwareImage self) { return FlowObject_GetStringProperty(self, _FlowFirmwareImage_Description);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetDescription(FlowFirmwareImage self, char *value) { FlowObject_SetStringProperty(self, _FlowFirmwareImage_Description, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property SubmittedBy is set on this object.
 * 
 * Can be used to check whether SubmittedBy is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasSubmittedBy(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_SubmittedBy);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowFirmwareImage_GetSubmittedBy(FlowFirmwareImage self) { return FlowObject_GetStringProperty(self, _FlowFirmwareImage_SubmittedBy);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetSubmittedBy(FlowFirmwareImage self, char *value) { FlowObject_SetStringProperty(self, _FlowFirmwareImage_SubmittedBy, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property PublishedDate is set on this object.
 * 
 * Can be used to check whether PublishedDate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasPublishedDate(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_PublishedDate);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline FlowDatetime FlowFirmwareImage_GetPublishedDate(FlowFirmwareImage self) { return FlowObject_GetDateTimeProperty(self, _FlowFirmwareImage_PublishedDate);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetPublishedDate(FlowFirmwareImage self, FlowDatetime value) { FlowObject_SetDateTimeProperty(self, _FlowFirmwareImage_PublishedDate, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property IsPrivate is set on this object.
 * 
 * Can be used to check whether IsPrivate is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasIsPrivate(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_IsPrivate);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_GetIsPrivate(FlowFirmwareImage self) { return FlowObject_GetBooleanProperty(self, _FlowFirmwareImage_IsPrivate);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetIsPrivate(FlowFirmwareImage self, bool value) { FlowObject_SetBooleanProperty(self, _FlowFirmwareImage_IsPrivate, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property ImageType is set on this object.
 * 
 * Can be used to check whether ImageType is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasImageType(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_ImageType);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowFirmwareImage_GetImageType(FlowFirmwareImage self) { return FlowObject_GetStringProperty(self, _FlowFirmwareImage_ImageType);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetImageType(FlowFirmwareImage self, char *value) { FlowObject_SetStringProperty(self, _FlowFirmwareImage_ImageType, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property DeviceType is set on this object.
 * 
 * Can be used to check whether DeviceType is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasDeviceType(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_DeviceType);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowFirmwareImage_GetDeviceType(FlowFirmwareImage self) { return FlowObject_GetIDProperty(self, _FlowFirmwareImage_DeviceType);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetDeviceType(FlowFirmwareImage self, FlowID value) { FlowObject_SetIDProperty(self, _FlowFirmwareImage_DeviceType, value);}
/**
 * \memberof FlowFirmwareImage
 * \brief Indicates whether the property Authorisation is set on this object.
 * 
 * Can be used to check whether Authorisation is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_HasAuthorisation(FlowFirmwareImage self) { return FlowObject_HasProperty(self, _FlowFirmwareImage_Authorisation);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowFirmwareImage_GetAuthorisation(FlowFirmwareImage self) { return FlowObject_GetStringProperty(self, _FlowFirmwareImage_Authorisation);}
/**
 * \memberof FlowFirmwareImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFirmwareImage_SetAuthorisation(FlowFirmwareImage self, char *value) { FlowObject_SetStringProperty(self, _FlowFirmwareImage_Authorisation, value);}
/**
 * \memberof FlowFirmwareImage
 * \ingroup Firmwares
 * \brief Indicates whether \ref FlowFirmwareImage_Remove is available on this object.
 * 
 * Checks whether \ref FlowFirmwareImage_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_CanRemove(FlowFirmwareImage self) { return FlowObject_HasLink(self, _FlowFirmwareImage_rel_Remove);}
/**
 * \memberof FlowFirmwareImage
 * \ingroup Firmwares
 * \brief Delete firmware image
 *
 * Deletes the specified firmware image.
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowFirmwareImage_Remove(FlowFirmwareImage self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowFirmwareImage_rel_Remove, FlowHTTPMethod_Delete, NULL);}
/**
 * \memberof FlowFirmwareImage
 * \ingroup Firmwares
 * \brief Indicates whether \ref FlowFirmwareImage_Update is available on this object.
 * 
 * Checks whether \ref FlowFirmwareImage_Update is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFirmwareImage_CanUpdate(FlowFirmwareImage self) { return FlowObject_HasLink(self, _FlowFirmwareImage_rel_Update);}
/**
 * \memberof FlowFirmwareImage
 * \ingroup Firmwares
 * \brief Update firmware image details
 *
 * Updates the details of the specified firmware image.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowFirmwareImage_Update(FlowFirmwareImage self, FlowFirmwareImage data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowFirmwareImage_rel_Update, FlowHTTPMethod_Put, data);}
#endif /* FLOW_USERS_FIRMWAREIMAGE_H_ */
