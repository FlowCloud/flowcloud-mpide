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

#ifndef FLOW_CORE_LABEL_H_
#define FLOW_CORE_LABEL_H_
#include "flow/core/base_types.h"
#include "flow/core/contacts_type.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/label_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowLabel
 * \brief Creates a new FlowLabel.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowLabel FlowLabel_New(FlowMemoryManager memoryManager){ return (FlowLabel)FlowMemoryManager_NewObject(memoryManager, 2, 3, FlowType_Label);}
/**
 * \memberof FlowLabel
 * \brief Registers meta data used for (de)serialising FlowLabel to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowLabel_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Label))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Label, "Label", 2, 3);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Label, _FlowLabel_Name, FlowType_String, "Name", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Label, _FlowLabel_LabelID, FlowType_ID, "LabelID", false);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Label, _FlowLabel_rel_Contacts, "contacts");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Label, _FlowLabel_rel_Remove, "remove");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_Label, _FlowLabel_rel_Update, "update");
	}
}
/**
 * \memberof FlowLabel
 * \brief Indicates whether the property Name is set on this object.
 * 
 * Can be used to check whether Name is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowLabel_HasName(FlowLabel self) { return FlowObject_HasProperty(self, _FlowLabel_Name);}
/**
 * \memberof FlowLabel
 * \param self Object on which the method will be applied
*/
static inline char *FlowLabel_GetName(FlowLabel self) { return FlowObject_GetStringProperty(self, _FlowLabel_Name);}
/**
 * \memberof FlowLabel
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowLabel_SetName(FlowLabel self, char *value) { FlowObject_SetStringProperty(self, _FlowLabel_Name, value);}
/**
 * \memberof FlowLabel
 * \brief Indicates whether the property LabelID is set on this object.
 * 
 * Can be used to check whether LabelID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowLabel_HasLabelID(FlowLabel self) { return FlowObject_HasProperty(self, _FlowLabel_LabelID);}
/**
 * \memberof FlowLabel
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowLabel_GetLabelID(FlowLabel self) { return FlowObject_GetIDProperty(self, _FlowLabel_LabelID);}
/**
 * \memberof FlowLabel
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowLabel_SetLabelID(FlowLabel self, FlowID value) { FlowObject_SetIDProperty(self, _FlowLabel_LabelID, value);}
/**
 * \memberof FlowLabel
 * \ingroup Contacts
 * \brief Indicates whether \ref FlowLabel_RetrieveContacts is available on this object.
 * 
 * Checks whether \ref FlowLabel_RetrieveContacts is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowLabel_CanRetrieveContacts(FlowLabel self) { return FlowObject_HasLink(self, _FlowLabel_rel_Contacts);}
/**
 * \memberof FlowLabel
 * \ingroup Contacts
 * \brief Retrieve contacts for the label
 *
 * Retrieves the list of all user and device contacts for the specified label (retrieved using GetLabel).
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowContacts FlowLabel_RetrieveContacts(FlowLabel self, int pageSize)
{
	FlowContacts result = NULL;
	if(FlowObject_HasLink(self, _FlowLabel_rel_Contacts))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowLabel_rel_Contacts));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowContacts) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Contacts);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
#endif /* FLOW_CORE_LABEL_H_ */
