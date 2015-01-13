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

#ifndef FLOW_CORE_BADREQUESTRESPONSE_H_
#define FLOW_CORE_BADREQUESTRESPONSE_H_
#include "flow/core/badrequestresponse_type.h"
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/strings_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowBadRequestResponse
 * \brief Creates a new FlowBadRequestResponse.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowBadRequestResponse FlowBadRequestResponse_New(FlowMemoryManager memoryManager){ return (FlowBadRequestResponse)FlowMemoryManager_NewObject(memoryManager, 5, 0, FlowType_BadRequestResponse);}
/**
 * \memberof FlowBadRequestResponse
 * \brief Registers meta data used for (de)serialising FlowBadRequestResponse to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowBadRequestResponse_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_BadRequestResponse))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_BadRequestResponse, "BadRequestResponse", 5, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_BadRequestResponse, _FlowBadRequestResponse_ErrorCode, FlowType_Integer, "ErrorCode", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_BadRequestResponse, _FlowBadRequestResponse_ErrorMessage, FlowType_String, "ErrorMessage", true);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_BadRequestResponse, _FlowBadRequestResponse_InvalidFields, "InvalidFields", "Field", FlowType_String, FlowType_Strings);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_BadRequestResponse, _FlowBadRequestResponse_PINAttemptsLeft, FlowType_Integer, "PINAttemptsLeft", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_BadRequestResponse, _FlowBadRequestResponse_ExternalErrorCode, FlowType_String, "ExternalErrorCode", true);
	}
}
/**
 * \memberof FlowBadRequestResponse
 * \brief Indicates whether the property ErrorCode is set on this object.
 * 
 * Can be used to check whether ErrorCode is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowBadRequestResponse_HasErrorCode(FlowBadRequestResponse self) { return FlowObject_HasProperty(self, _FlowBadRequestResponse_ErrorCode);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
*/
static inline int FlowBadRequestResponse_GetErrorCode(FlowBadRequestResponse self) { return FlowObject_GetIntegerProperty(self, _FlowBadRequestResponse_ErrorCode);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowBadRequestResponse_SetErrorCode(FlowBadRequestResponse self, int value) { FlowObject_SetIntegerProperty(self, _FlowBadRequestResponse_ErrorCode, value);}
/**
 * \memberof FlowBadRequestResponse
 * \brief Indicates whether the property ErrorMessage is set on this object.
 * 
 * Can be used to check whether ErrorMessage is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowBadRequestResponse_HasErrorMessage(FlowBadRequestResponse self) { return FlowObject_HasProperty(self, _FlowBadRequestResponse_ErrorMessage);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
*/
static inline char *FlowBadRequestResponse_GetErrorMessage(FlowBadRequestResponse self) { return FlowObject_GetStringProperty(self, _FlowBadRequestResponse_ErrorMessage);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowBadRequestResponse_SetErrorMessage(FlowBadRequestResponse self, char *value) { FlowObject_SetStringProperty(self, _FlowBadRequestResponse_ErrorMessage, value);}
/**
 * \memberof FlowBadRequestResponse
 * \brief Indicates whether the property InvalidFields is set on this object.
 * 
 * Can be used to check whether InvalidFields is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowBadRequestResponse_HasInvalidFields(FlowBadRequestResponse self) { return FlowObject_HasProperty(self, _FlowBadRequestResponse_InvalidFields);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
*/
static inline FlowStrings FlowBadRequestResponse_GetInvalidFields(FlowBadRequestResponse self) { return (FlowStrings)FlowObject_GetObjectProperty(self, _FlowBadRequestResponse_InvalidFields);}
/**
 * \memberof FlowBadRequestResponse
 * \brief Indicates whether the property PINAttemptsLeft is set on this object.
 * 
 * Can be used to check whether PINAttemptsLeft is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowBadRequestResponse_HasPINAttemptsLeft(FlowBadRequestResponse self) { return FlowObject_HasProperty(self, _FlowBadRequestResponse_PINAttemptsLeft);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
*/
static inline int FlowBadRequestResponse_GetPINAttemptsLeft(FlowBadRequestResponse self) { return FlowObject_GetIntegerProperty(self, _FlowBadRequestResponse_PINAttemptsLeft);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowBadRequestResponse_SetPINAttemptsLeft(FlowBadRequestResponse self, int value) { FlowObject_SetIntegerProperty(self, _FlowBadRequestResponse_PINAttemptsLeft, value);}
/**
 * \memberof FlowBadRequestResponse
 * \brief Indicates whether the property ExternalErrorCode is set on this object.
 * 
 * Can be used to check whether ExternalErrorCode is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowBadRequestResponse_HasExternalErrorCode(FlowBadRequestResponse self) { return FlowObject_HasProperty(self, _FlowBadRequestResponse_ExternalErrorCode);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
*/
static inline char *FlowBadRequestResponse_GetExternalErrorCode(FlowBadRequestResponse self) { return FlowObject_GetStringProperty(self, _FlowBadRequestResponse_ExternalErrorCode);}
/**
 * \memberof FlowBadRequestResponse
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowBadRequestResponse_SetExternalErrorCode(FlowBadRequestResponse self, char *value) { FlowObject_SetStringProperty(self, _FlowBadRequestResponse_ExternalErrorCode, value);}
#endif /* FLOW_CORE_BADREQUESTRESPONSE_H_ */
