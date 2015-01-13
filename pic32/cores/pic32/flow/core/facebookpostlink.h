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

#ifndef FLOW_USERS_FACEBOOKPOSTLINK_H_
#define FLOW_USERS_FACEBOOKPOSTLINK_H_
#include "flow/core/base_types.h"
#include "flow/core/facebookpostlink_type.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowFacebookPostLink
 * \brief Creates a new FlowFacebookPostLink.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowFacebookPostLink FlowFacebookPostLink_New(FlowMemoryManager memoryManager){ return (FlowFacebookPostLink)FlowMemoryManager_NewObject(memoryManager, 5, 0, FlowType_FacebookPostLink);}
/**
 * \memberof FlowFacebookPostLink
 * \brief Registers meta data used for (de)serialising FlowFacebookPostLink to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowFacebookPostLink_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_FacebookPostLink))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_FacebookPostLink, "FacebookPostLink", 5, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookPostLink, _FlowFacebookPostLink_Url, FlowType_String, "Url", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookPostLink, _FlowFacebookPostLink_Picture, FlowType_String, "Picture", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookPostLink, _FlowFacebookPostLink_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookPostLink, _FlowFacebookPostLink_Caption, FlowType_String, "Caption", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookPostLink, _FlowFacebookPostLink_Description, FlowType_String, "Description", true);
	}
}
/**
 * \memberof FlowFacebookPostLink
 * \brief Indicates whether the property Url is set on this object.
 * 
 * Can be used to check whether Url is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPostLink_HasUrl(FlowFacebookPostLink self) { return FlowObject_HasProperty(self, _FlowFacebookPostLink_Url);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowFacebookPostLink_GetUrl(FlowFacebookPostLink self) { return FlowObject_GetStringProperty(self, _FlowFacebookPostLink_Url);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookPostLink_SetUrl(FlowFacebookPostLink self, char *value) { FlowObject_SetStringProperty(self, _FlowFacebookPostLink_Url, value);}
/**
 * \memberof FlowFacebookPostLink
 * \brief Indicates whether the property Picture is set on this object.
 * 
 * Can be used to check whether Picture is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPostLink_HasPicture(FlowFacebookPostLink self) { return FlowObject_HasProperty(self, _FlowFacebookPostLink_Picture);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowFacebookPostLink_GetPicture(FlowFacebookPostLink self) { return FlowObject_GetStringProperty(self, _FlowFacebookPostLink_Picture);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookPostLink_SetPicture(FlowFacebookPostLink self, char *value) { FlowObject_SetStringProperty(self, _FlowFacebookPostLink_Picture, value);}
/**
 * \memberof FlowFacebookPostLink
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPostLink_HasName(FlowFacebookPostLink self) { return FlowObject_HasProperty(self, _FlowFacebookPostLink_Name);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowFacebookPostLink_GetName(FlowFacebookPostLink self) { return FlowObject_GetStringProperty(self, _FlowFacebookPostLink_Name);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookPostLink_SetName(FlowFacebookPostLink self, char *value) { FlowObject_SetStringProperty(self, _FlowFacebookPostLink_Name, value);}
/**
 * \memberof FlowFacebookPostLink
 * \brief Indicates whether the property Caption is set on this object.
 * 
 * Can be used to check whether Caption is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPostLink_HasCaption(FlowFacebookPostLink self) { return FlowObject_HasProperty(self, _FlowFacebookPostLink_Caption);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowFacebookPostLink_GetCaption(FlowFacebookPostLink self) { return FlowObject_GetStringProperty(self, _FlowFacebookPostLink_Caption);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookPostLink_SetCaption(FlowFacebookPostLink self, char *value) { FlowObject_SetStringProperty(self, _FlowFacebookPostLink_Caption, value);}
/**
 * \memberof FlowFacebookPostLink
 * \brief Indicates whether the property Description is set on this object.
 * 
 * Can be used to check whether Description is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPostLink_HasDescription(FlowFacebookPostLink self) { return FlowObject_HasProperty(self, _FlowFacebookPostLink_Description);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
*/
static inline char *FlowFacebookPostLink_GetDescription(FlowFacebookPostLink self) { return FlowObject_GetStringProperty(self, _FlowFacebookPostLink_Description);}
/**
 * \memberof FlowFacebookPostLink
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookPostLink_SetDescription(FlowFacebookPostLink self, char *value) { FlowObject_SetStringProperty(self, _FlowFacebookPostLink_Description, value);}
#endif /* FLOW_USERS_FACEBOOKPOSTLINK_H_ */
