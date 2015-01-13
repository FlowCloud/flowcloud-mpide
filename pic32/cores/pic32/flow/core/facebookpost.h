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

#ifndef FLOW_USERS_FACEBOOKPOST_H_
#define FLOW_USERS_FACEBOOKPOST_H_
#include "flow/core/base_types.h"
#include "flow/core/facebookpost_type.h"
#include "flow/core/facebookpostaction.h"
#include "flow/core/facebookpostactions_type.h"
#include "flow/core/facebookpostlink_type.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowFacebookPost
 * \brief Creates a new FlowFacebookPost.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowFacebookPost FlowFacebookPost_New(FlowMemoryManager memoryManager){ return (FlowFacebookPost)FlowMemoryManager_NewObject(memoryManager, 3, 0, FlowType_FacebookPost);}
/**
 * \memberof FlowFacebookPost
 * \brief Registers meta data used for (de)serialising FlowFacebookPost to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowFacebookPost_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_FacebookPost))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_FacebookPost, "FacebookPost", 3, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookPost, _FlowFacebookPost_Message, FlowType_String, "Message", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_FacebookPost, _FlowFacebookPost_Link, FlowType_FacebookPostLink, "Link", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_FacebookPost, _FlowFacebookPost_Actions, "Actions", "Action", FlowType_FacebookPostAction, FlowType_FacebookPostActions);
	}
}
/**
 * \memberof FlowFacebookPost
 * \brief Indicates whether the property Message is set on this object.
 * 
 * Can be used to check whether Message is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPost_HasMessage(FlowFacebookPost self) { return FlowObject_HasProperty(self, _FlowFacebookPost_Message);}
/**
 * \memberof FlowFacebookPost
 * \param self Object on which the method will be applied
*/
static inline char *FlowFacebookPost_GetMessage(FlowFacebookPost self) { return FlowObject_GetStringProperty(self, _FlowFacebookPost_Message);}
/**
 * \memberof FlowFacebookPost
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookPost_SetMessage(FlowFacebookPost self, char *value) { FlowObject_SetStringProperty(self, _FlowFacebookPost_Message, value);}
/**
 * \memberof FlowFacebookPost
 * \brief Indicates whether the property Link is set on this object.
 * 
 * Can be used to check whether Link is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPost_HasLink(FlowFacebookPost self) { return FlowObject_HasProperty(self, _FlowFacebookPost_Link);}
/**
 * \memberof FlowFacebookPost
 * \param self Object on which the method will be applied
*/
static inline FlowFacebookPostLink FlowFacebookPost_GetLink(FlowFacebookPost self) { return (FlowFacebookPostLink)FlowObject_GetObjectProperty(self, _FlowFacebookPost_Link);}
/**
 * \memberof FlowFacebookPost
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowFacebookPost_SetLink(FlowFacebookPost self, FlowFacebookPostLink value) { FlowObject_SetObjectProperty(self, _FlowFacebookPost_Link, value);}
/**
 * \memberof FlowFacebookPost
 * \brief Indicates whether the property Actions is set on this object.
 * 
 * Can be used to check whether Actions is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowFacebookPost_HasActions(FlowFacebookPost self) { return FlowObject_HasProperty(self, _FlowFacebookPost_Actions);}
/**
 * \memberof FlowFacebookPost
 * \param self Object on which the method will be applied
*/
static inline FlowFacebookPostActions FlowFacebookPost_GetActions(FlowFacebookPost self) { return (FlowFacebookPostActions)FlowObject_GetObjectProperty(self, _FlowFacebookPost_Actions);}
#endif /* FLOW_USERS_FACEBOOKPOST_H_ */
