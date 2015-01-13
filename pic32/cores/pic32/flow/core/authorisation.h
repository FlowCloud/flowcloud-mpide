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

#ifndef FLOW_CORE_AUTHORISATION_H_
#define FLOW_CORE_AUTHORISATION_H_
#include "flow/core/authorisation_type.h"
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowAuthorisation
 * \brief Creates a new FlowAuthorisation.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowAuthorisation FlowAuthorisation_New(FlowMemoryManager memoryManager){ return (FlowAuthorisation)FlowMemoryManager_NewObject(memoryManager, 4, 0, FlowType_Authorisation);}
/**
 * \memberof FlowAuthorisation
 * \brief Registers meta data used for (de)serialising FlowAuthorisation to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowAuthorisation_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Authorisation))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Authorisation, "Authorisation", 4, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Authorisation, _FlowAuthorisation_Name, FlowType_String, "Name", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Authorisation, _FlowAuthorisation_ConsumerKey, FlowType_Token, "ConsumerKey", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Authorisation, _FlowAuthorisation_ConsumerSecret, FlowType_Token, "ConsumerSecret", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Authorisation, _FlowAuthorisation_GroupType, FlowType_Token, "GroupType", true);
	}
}
/**
 * \memberof FlowAuthorisation
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthorisation_HasName(FlowAuthorisation self) { return FlowObject_HasProperty(self, _FlowAuthorisation_Name);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
*/
static inline char *FlowAuthorisation_GetName(FlowAuthorisation self) { return FlowObject_GetStringProperty(self, _FlowAuthorisation_Name);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthorisation_SetName(FlowAuthorisation self, char *value) { FlowObject_SetStringProperty(self, _FlowAuthorisation_Name, value);}
/**
 * \memberof FlowAuthorisation
 * \brief Indicates whether the property ConsumerKey is set on this object.
 * 
 * Can be used to check whether ConsumerKey is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthorisation_HasConsumerKey(FlowAuthorisation self) { return FlowObject_HasProperty(self, _FlowAuthorisation_ConsumerKey);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowAuthorisation_GetConsumerKey(FlowAuthorisation self) { return FlowObject_GetTokenProperty(self, _FlowAuthorisation_ConsumerKey);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthorisation_SetConsumerKey(FlowAuthorisation self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowAuthorisation_ConsumerKey, value);}
/**
 * \memberof FlowAuthorisation
 * \brief Indicates whether the property ConsumerSecret is set on this object.
 * 
 * Can be used to check whether ConsumerSecret is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthorisation_HasConsumerSecret(FlowAuthorisation self) { return FlowObject_HasProperty(self, _FlowAuthorisation_ConsumerSecret);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowAuthorisation_GetConsumerSecret(FlowAuthorisation self) { return FlowObject_GetTokenProperty(self, _FlowAuthorisation_ConsumerSecret);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthorisation_SetConsumerSecret(FlowAuthorisation self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowAuthorisation_ConsumerSecret, value);}
/**
 * \memberof FlowAuthorisation
 * \brief Indicates whether the property GroupType is set on this object.
 * 
 * Can be used to check whether GroupType is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthorisation_HasGroupType(FlowAuthorisation self) { return FlowObject_HasProperty(self, _FlowAuthorisation_GroupType);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
*/
static inline FlowToken FlowAuthorisation_GetGroupType(FlowAuthorisation self) { return FlowObject_GetTokenProperty(self, _FlowAuthorisation_GroupType);}
/**
 * \memberof FlowAuthorisation
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowAuthorisation_SetGroupType(FlowAuthorisation self, FlowToken value) { FlowObject_SetTokenProperty(self, _FlowAuthorisation_GroupType, value);}
#endif /* FLOW_CORE_AUTHORISATION_H_ */
