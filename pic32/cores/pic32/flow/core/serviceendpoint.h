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

#ifndef FLOW_CORE_SERVICEENDPOINT_H_
#define FLOW_CORE_SERVICEENDPOINT_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/serviceendpoint_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowServiceEndpoint
 * \brief Creates a new FlowServiceEndpoint.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowServiceEndpoint FlowServiceEndpoint_New(FlowMemoryManager memoryManager){ return (FlowServiceEndpoint)FlowMemoryManager_NewObject(memoryManager, 6, 0, FlowType_ServiceEndpoint);}
/**
 * \memberof FlowServiceEndpoint
 * \brief Registers meta data used for (de)serialising FlowServiceEndpoint to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowServiceEndpoint_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_ServiceEndpoint))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_ServiceEndpoint, "ServiceEndpoint", 6, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ServiceEndpoint, _FlowServiceEndpoint_Location, FlowType_String, "Location", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ServiceEndpoint, _FlowServiceEndpoint_Secure, FlowType_String, "Secure", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ServiceEndpoint, _FlowServiceEndpoint_Username, FlowType_String, "Username", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ServiceEndpoint, _FlowServiceEndpoint_PasswordHash, FlowType_String, "PasswordHash", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ServiceEndpoint, _FlowServiceEndpoint_Password, FlowType_String, "Password", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_ServiceEndpoint, _FlowServiceEndpoint_Type, FlowType_String, "Type", true);
	}
}
/**
 * \memberof FlowServiceEndpoint
 * \brief Indicates whether the property Location is set on this object.
 * 
 * Can be used to check whether Location is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceEndpoint_HasLocation(FlowServiceEndpoint self) { return FlowObject_HasProperty(self, _FlowServiceEndpoint_Location);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
*/
static inline char *FlowServiceEndpoint_GetLocation(FlowServiceEndpoint self) { return FlowObject_GetStringProperty(self, _FlowServiceEndpoint_Location);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowServiceEndpoint_SetLocation(FlowServiceEndpoint self, char *value) { FlowObject_SetStringProperty(self, _FlowServiceEndpoint_Location, value);}
/**
 * \memberof FlowServiceEndpoint
 * \brief Indicates whether the property Secure is set on this object.
 * 
 * Can be used to check whether Secure is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceEndpoint_HasSecure(FlowServiceEndpoint self) { return FlowObject_HasProperty(self, _FlowServiceEndpoint_Secure);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
*/
static inline char *FlowServiceEndpoint_GetSecure(FlowServiceEndpoint self) { return FlowObject_GetStringProperty(self, _FlowServiceEndpoint_Secure);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowServiceEndpoint_SetSecure(FlowServiceEndpoint self, char *value) { FlowObject_SetStringProperty(self, _FlowServiceEndpoint_Secure, value);}
/**
 * \memberof FlowServiceEndpoint
 * \brief Indicates whether the property Username is set on this object.
 * 
 * Can be used to check whether Username is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceEndpoint_HasUsername(FlowServiceEndpoint self) { return FlowObject_HasProperty(self, _FlowServiceEndpoint_Username);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
*/
static inline char *FlowServiceEndpoint_GetUsername(FlowServiceEndpoint self) { return FlowObject_GetStringProperty(self, _FlowServiceEndpoint_Username);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowServiceEndpoint_SetUsername(FlowServiceEndpoint self, char *value) { FlowObject_SetStringProperty(self, _FlowServiceEndpoint_Username, value);}
/**
 * \memberof FlowServiceEndpoint
 * \brief Indicates whether the property PasswordHash is set on this object.
 * 
 * Can be used to check whether PasswordHash is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceEndpoint_HasPasswordHash(FlowServiceEndpoint self) { return FlowObject_HasProperty(self, _FlowServiceEndpoint_PasswordHash);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
*/
static inline char *FlowServiceEndpoint_GetPasswordHash(FlowServiceEndpoint self) { return FlowObject_GetStringProperty(self, _FlowServiceEndpoint_PasswordHash);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowServiceEndpoint_SetPasswordHash(FlowServiceEndpoint self, char *value) { FlowObject_SetStringProperty(self, _FlowServiceEndpoint_PasswordHash, value);}
/**
 * \memberof FlowServiceEndpoint
 * \brief Indicates whether the property Password is set on this object.
 * 
 * Can be used to check whether Password is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceEndpoint_HasPassword(FlowServiceEndpoint self) { return FlowObject_HasProperty(self, _FlowServiceEndpoint_Password);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
*/
static inline char *FlowServiceEndpoint_GetPassword(FlowServiceEndpoint self) { return FlowObject_GetStringProperty(self, _FlowServiceEndpoint_Password);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowServiceEndpoint_SetPassword(FlowServiceEndpoint self, char *value) { FlowObject_SetStringProperty(self, _FlowServiceEndpoint_Password, value);}
/**
 * \memberof FlowServiceEndpoint
 * \brief Indicates whether the property Type is set on this object.
 * 
 * Can be used to check whether Type is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowServiceEndpoint_HasType(FlowServiceEndpoint self) { return FlowObject_HasProperty(self, _FlowServiceEndpoint_Type);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
*/
static inline char *FlowServiceEndpoint_GetType(FlowServiceEndpoint self) { return FlowObject_GetStringProperty(self, _FlowServiceEndpoint_Type);}
/**
 * \memberof FlowServiceEndpoint
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowServiceEndpoint_SetType(FlowServiceEndpoint self, char *value) { FlowObject_SetStringProperty(self, _FlowServiceEndpoint_Type, value);}
#endif /* FLOW_CORE_SERVICEENDPOINT_H_ */
