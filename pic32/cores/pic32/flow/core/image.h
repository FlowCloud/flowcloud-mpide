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

#ifndef FLOW_CORE_IMAGE_H_
#define FLOW_CORE_IMAGE_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/image_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowImage
 * \brief Creates a new FlowImage.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowImage FlowImage_New(FlowMemoryManager memoryManager){ return (FlowImage)FlowMemoryManager_NewObject(memoryManager, 3, 0, FlowType_Image);}
/**
 * \memberof FlowImage
 * \brief Registers meta data used for (de)serialising FlowImage to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowImage_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Image))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Image, "Image", 3, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Image, _FlowImage_Height, FlowType_Integer, "Height", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Image, _FlowImage_Width, FlowType_Integer, "Width", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Image, _FlowImage_Url, FlowType_String, "Url", false);
	}
}
/**
 * \memberof FlowImage
 * \brief Indicates whether the property Height is set on this object.
 * 
 * Can be used to check whether Height is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowImage_HasHeight(FlowImage self) { return FlowObject_HasProperty(self, _FlowImage_Height);}
/**
 * \memberof FlowImage
 * \param self Object on which the method will be applied
*/
static inline int FlowImage_GetHeight(FlowImage self) { return FlowObject_GetIntegerProperty(self, _FlowImage_Height);}
/**
 * \memberof FlowImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowImage_SetHeight(FlowImage self, int value) { FlowObject_SetIntegerProperty(self, _FlowImage_Height, value);}
/**
 * \memberof FlowImage
 * \brief Indicates whether the property Width is set on this object.
 * 
 * Can be used to check whether Width is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowImage_HasWidth(FlowImage self) { return FlowObject_HasProperty(self, _FlowImage_Width);}
/**
 * \memberof FlowImage
 * \param self Object on which the method will be applied
*/
static inline int FlowImage_GetWidth(FlowImage self) { return FlowObject_GetIntegerProperty(self, _FlowImage_Width);}
/**
 * \memberof FlowImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowImage_SetWidth(FlowImage self, int value) { FlowObject_SetIntegerProperty(self, _FlowImage_Width, value);}
/**
 * \memberof FlowImage
 * \brief Indicates whether the property Url is set on this object.
 * 
 * Can be used to check whether Url is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowImage_HasUrl(FlowImage self) { return FlowObject_HasProperty(self, _FlowImage_Url);}
/**
 * \memberof FlowImage
 * \param self Object on which the method will be applied
*/
static inline char *FlowImage_GetUrl(FlowImage self) { return FlowObject_GetStringProperty(self, _FlowImage_Url);}
/**
 * \memberof FlowImage
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowImage_SetUrl(FlowImage self, char *value) { FlowObject_SetStringProperty(self, _FlowImage_Url, value);}
#endif /* FLOW_CORE_IMAGE_H_ */
