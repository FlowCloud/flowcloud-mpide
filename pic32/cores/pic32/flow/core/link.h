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

#ifndef FLOW_CORE_LINK_H_
#define FLOW_CORE_LINK_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/link_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowLink
 * \brief Creates a new FlowLink.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowLink FlowLink_New(FlowMemoryManager memoryManager){ return (FlowLink)FlowMemoryManager_NewObject(memoryManager, 4, 0, FlowType_Link);}
/**
 * \memberof FlowLink
 * \brief Registers meta data used for (de)serialising FlowLink to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowLink_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Link))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Link, "Link", 4, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Link, _FlowLink_rel, FlowType_String, "rel", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Link, _FlowLink_href, FlowType_String, "href", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Link, _FlowLink_type, FlowType_String, "type", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Link, _FlowLink_resolution, FlowType_String, "resolution", false);
	}
}
/**
 * \memberof FlowLink
 * \brief Indicates whether the property rel is set on this object.
 * 
 * Can be used to check whether rel is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowLink_Hasrel(FlowLink self) { return FlowObject_HasProperty(self, _FlowLink_rel);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowLink_Getrel(FlowLink self) { return FlowObject_GetStringProperty(self, _FlowLink_rel);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowLink_Setrel(FlowLink self, char *value) { FlowObject_SetStringProperty(self, _FlowLink_rel, value);}
/**
 * \memberof FlowLink
 * \brief Indicates whether the property href is set on this object.
 * 
 * Can be used to check whether href is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowLink_Hashref(FlowLink self) { return FlowObject_HasProperty(self, _FlowLink_href);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowLink_Gethref(FlowLink self) { return FlowObject_GetStringProperty(self, _FlowLink_href);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowLink_Sethref(FlowLink self, char *value) { FlowObject_SetStringProperty(self, _FlowLink_href, value);}
/**
 * \memberof FlowLink
 * \brief Indicates whether the property type is set on this object.
 * 
 * Can be used to check whether type is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowLink_Hastype(FlowLink self) { return FlowObject_HasProperty(self, _FlowLink_type);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowLink_Gettype(FlowLink self) { return FlowObject_GetStringProperty(self, _FlowLink_type);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowLink_Settype(FlowLink self, char *value) { FlowObject_SetStringProperty(self, _FlowLink_type, value);}
/**
 * \memberof FlowLink
 * \brief Indicates whether the property resolution is set on this object.
 * 
 * Can be used to check whether resolution is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowLink_Hasresolution(FlowLink self) { return FlowObject_HasProperty(self, _FlowLink_resolution);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowLink_Getresolution(FlowLink self) { return FlowObject_GetStringProperty(self, _FlowLink_resolution);}
/**
 * \memberof FlowLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowLink_Setresolution(FlowLink self, char *value) { FlowObject_SetStringProperty(self, _FlowLink_resolution, value);}
#endif /* FLOW_CORE_LINK_H_ */
