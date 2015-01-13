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

#ifndef FLOW_CORE_USERGRANT_H_
#define FLOW_CORE_USERGRANT_H_
#include "flow/core/accessright_type.h"
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/usergrant_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowUserGrant
 * \brief Creates a new FlowUserGrant.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowUserGrant FlowUserGrant_New(FlowMemoryManager memoryManager){ return (FlowUserGrant)FlowMemoryManager_NewObject(memoryManager, 2, 3, FlowType_UserGrant);}
/**
 * \memberof FlowUserGrant
 * \brief Registers meta data used for (de)serialising FlowUserGrant to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowUserGrant_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_UserGrant))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_UserGrant, "UserGrant", 2, 3);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_UserGrant, _FlowUserGrant_UserID, FlowType_ID, "UserID", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_UserGrant, _FlowUserGrant_Access, FlowType_AccessRight, "Access", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_UserGrant, _FlowUserGrant_rel_Remove, "remove");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_UserGrant, _FlowUserGrant_rel_Self, "self");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_UserGrant, _FlowUserGrant_rel_Update, "update");
	}
}
/**
 * \memberof FlowUserGrant
 * \brief Indicates whether the property UserID is set on this object.
 * 
 * Can be used to check whether UserID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUserGrant_HasUserID(FlowUserGrant self) { return FlowObject_HasProperty(self, _FlowUserGrant_UserID);}
/**
 * \memberof FlowUserGrant
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowUserGrant_GetUserID(FlowUserGrant self) { return FlowObject_GetIDProperty(self, _FlowUserGrant_UserID);}
/**
 * \memberof FlowUserGrant
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUserGrant_SetUserID(FlowUserGrant self, FlowID value) { FlowObject_SetIDProperty(self, _FlowUserGrant_UserID, value);}
/**
 * \memberof FlowUserGrant
 * \brief Indicates whether the property Access is set on this object.
 * 
 * Can be used to check whether Access is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUserGrant_HasAccess(FlowUserGrant self) { return FlowObject_HasProperty(self, _FlowUserGrant_Access);}
/**
 * \memberof FlowUserGrant
 * \param self Object on which the method will be applied
*/
static inline FlowAccessRight FlowUserGrant_GetAccess(FlowUserGrant self) { return (FlowAccessRight)FlowObject_GetIntegerProperty(self, _FlowUserGrant_Access);}
/**
 * \memberof FlowUserGrant
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUserGrant_SetAccess(FlowUserGrant self, FlowAccessRight value) { FlowObject_SetIntegerProperty(self, _FlowUserGrant_Access, value);}
/**
 * \memberof FlowUserGrant
 * \brief Indicates whether \ref FlowUserGrant_Remove is available on this object.
 * 
 * Checks whether \ref FlowUserGrant_Remove is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUserGrant_CanRemove(FlowUserGrant self) { return FlowObject_HasLink(self, _FlowUserGrant_rel_Remove);}
/**
 * \memberof FlowUserGrant
 * \brief Removing/revoking a user granted access right
 *
 * 
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUserGrant_Remove(FlowUserGrant self) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowUserGrant_rel_Remove, FlowHTTPMethod_Delete, NULL);}
/**
 * \memberof FlowUserGrant
 * \brief Indicates whether \ref FlowUserGrant_RetrieveDetails is available on this object.
 * 
 * Checks whether \ref FlowUserGrant_RetrieveDetails is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUserGrant_CanRetrieveDetails(FlowUserGrant self) { return FlowObject_HasLink(self, _FlowUserGrant_rel_Self);}
/**
 * \memberof FlowUserGrant
 * \param self Object on which the method will be applied
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowUserGrant FlowUserGrant_RetrieveDetails(FlowUserGrant self) { return (FlowUserGrant) FlowObject_HTTPRequest(self, _FlowUserGrant_rel_Self, FlowHTTPMethod_Get, NULL, FlowType_UserGrant);}
/**
 * \memberof FlowUserGrant
 * \brief Indicates whether \ref FlowUserGrant_Update is available on this object.
 * 
 * Checks whether \ref FlowUserGrant_Update is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUserGrant_CanUpdate(FlowUserGrant self) { return FlowObject_HasLink(self, _FlowUserGrant_rel_Update);}
/**
 * \memberof FlowUserGrant
 * \brief Updating a user granted access right
 *
 * 
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowUserGrant_Update(FlowUserGrant self, FlowUserGrant data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowUserGrant_rel_Update, FlowHTTPMethod_Put, data);}
#endif /* FLOW_CORE_USERGRANT_H_ */
