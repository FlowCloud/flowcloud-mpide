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

#ifndef FLOW_USERS_DEVICETYPE_H_
#define FLOW_USERS_DEVICETYPE_H_
#include "flow/core/base_types.h"
#include "flow/core/devicetype_type.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowDeviceType
 * \brief Creates a new FlowDeviceType.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowDeviceType FlowDeviceType_New(FlowMemoryManager memoryManager){ return (FlowDeviceType)FlowMemoryManager_NewObject(memoryManager, 3, 0, FlowType_DeviceType);}
/**
 * \memberof FlowDeviceType
 * \brief Registers meta data used for (de)serialising FlowDeviceType to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowDeviceType_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_DeviceType))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_DeviceType, "DeviceType", 3, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceType, _FlowDeviceType_DeviceTypeID, FlowType_ID, "DeviceTypeID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceType, _FlowDeviceType_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_DeviceType, _FlowDeviceType_DeviceCategoryID, FlowType_ID, "DeviceCategoryID", true);
	}
}
/**
 * \memberof FlowDeviceType
 * \brief Indicates whether the property DeviceTypeID is set on this object.
 * 
 * Can be used to check whether DeviceTypeID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceType_HasDeviceTypeID(FlowDeviceType self) { return FlowObject_HasProperty(self, _FlowDeviceType_DeviceTypeID);}
/**
 * \memberof FlowDeviceType
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowDeviceType_GetDeviceTypeID(FlowDeviceType self) { return FlowObject_GetIDProperty(self, _FlowDeviceType_DeviceTypeID);}
/**
 * \memberof FlowDeviceType
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceType_SetDeviceTypeID(FlowDeviceType self, FlowID value) { FlowObject_SetIDProperty(self, _FlowDeviceType_DeviceTypeID, value);}
/**
 * \memberof FlowDeviceType
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceType_HasName(FlowDeviceType self) { return FlowObject_HasProperty(self, _FlowDeviceType_Name);}
/**
 * \memberof FlowDeviceType
 * \param self Object on which the method will be applied
*/
static inline char *FlowDeviceType_GetName(FlowDeviceType self) { return FlowObject_GetStringProperty(self, _FlowDeviceType_Name);}
/**
 * \memberof FlowDeviceType
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceType_SetName(FlowDeviceType self, char *value) { FlowObject_SetStringProperty(self, _FlowDeviceType_Name, value);}
/**
 * \memberof FlowDeviceType
 * \brief Indicates whether the property DeviceCategoryID is set on this object.
 * 
 * Can be used to check whether DeviceCategoryID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceType_HasDeviceCategoryID(FlowDeviceType self) { return FlowObject_HasProperty(self, _FlowDeviceType_DeviceCategoryID);}
/**
 * \memberof FlowDeviceType
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowDeviceType_GetDeviceCategoryID(FlowDeviceType self) { return FlowObject_GetIDProperty(self, _FlowDeviceType_DeviceCategoryID);}
/**
 * \memberof FlowDeviceType
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowDeviceType_SetDeviceCategoryID(FlowDeviceType self, FlowID value) { FlowObject_SetIDProperty(self, _FlowDeviceType_DeviceCategoryID, value);}
#endif /* FLOW_USERS_DEVICETYPE_H_ */
