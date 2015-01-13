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

#ifndef FLOW_CORE_AUTHORISATIONS_H_
#define FLOW_CORE_AUTHORISATIONS_H_
#include "flow/core/authorisation.h"
#include "flow/core/authorisation_type.h"
#include "flow/core/authorisations_type.h"
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowAuthorisations
 * \brief Creates a new FlowAuthorisations.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowAuthorisations FlowAuthorisations_New(FlowMemoryManager memoryManager){ return (FlowAuthorisations)FlowMemoryManager_NewObject(memoryManager, 1, 1, FlowType_Authorisations);}
/**
 * \memberof FlowAuthorisations
 * \brief Registers meta data used for (de)serialising FlowAuthorisations to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowAuthorisations_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Authorisations))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Authorisations, "Authorisations", 1, 1);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Authorisations, _FlowAuthorisations_Items, "Items", "Authorisation", FlowType_Authorisation, FlowType_Authorisations);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Authorisations, _FlowAuthorisations_rel_Add, "add");
	}
}
/**
 * \memberof FlowAuthorisations
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthorisations_HasItems(FlowAuthorisations self) { return FlowObject_HasProperty(self, _FlowAuthorisations_Items);}
/**
 * \memberof FlowAuthorisations
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowAuthorisation FlowAuthorisations_GetItem(FlowAuthorisations self, uint index) { return (FlowAuthorisation)FlowObject_GetArrayObjectProperty(self, _FlowAuthorisations_Items, index);}
/**
 * \memberof FlowAuthorisations
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowAuthorisations_GetCount(FlowAuthorisations self) { return FlowObject_GetArrayPropertyCount(self, _FlowAuthorisations_Items);}
/**
 * \memberof FlowAuthorisations
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowAuthorisation FlowAuthorisations_NewItem(FlowAuthorisations self)
{
	FlowAuthorisation result = FlowAuthorisation_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowAuthorisations_Items, result);
	return result;
}
/**
 * \memberof FlowAuthorisations
 * \ingroup AuthorisationGroups
 * \brief Indicates whether \ref FlowAuthorisations_Add is available on this object.
 * 
 * Checks whether \ref FlowAuthorisations_Add is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowAuthorisations_CanAdd(FlowAuthorisations self) { return FlowObject_HasLink(self, _FlowAuthorisations_rel_Add);}
/**
 * \memberof FlowAuthorisations
 * \ingroup AuthorisationGroups
 * \brief Add user to authorisation group
 *
 * Associate a user with an authorisation group using the specified credentials.
 * \param self Object on which the method will be applied
 * \param data object to save to Flow.
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline bool FlowAuthorisations_Add(FlowAuthorisations self, FlowAuthorisation data) { return FlowObject_HTTPRequestWithStatusResponse(self, _FlowAuthorisations_rel_Add, FlowHTTPMethod_Post, data);}
#endif /* FLOW_CORE_AUTHORISATIONS_H_ */
