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

#ifndef FLOW_CORE_ITEM_H_
#define FLOW_CORE_ITEM_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/item_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowItem
 * \brief Creates a new FlowItem.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowItem FlowItem_New(FlowMemoryManager memoryManager){ return (FlowItem)FlowMemoryManager_NewObject(memoryManager, 4, 0, FlowType_Item);}
/**
 * \memberof FlowItem
 * \brief Registers meta data used for (de)serialising FlowItem to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowItem_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Item))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Item, "Item", 4, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Item, _FlowItem_Key, FlowType_ID, "Key", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Item, _FlowItem_Value, FlowType_String, "Value", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Item, _FlowItem_TypeName, FlowType_String, "TypeName", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Item, _FlowItem_UpdateID, FlowType_Integer, "UpdateID", false);
	}
}
/**
 * \memberof FlowItem
 * \brief Indicates whether the property Key is set on this object.
 * 
 * Can be used to check whether Key is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowItem_HasKey(FlowItem self) { return FlowObject_HasProperty(self, _FlowItem_Key);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowItem_GetKey(FlowItem self) { return FlowObject_GetIDProperty(self, _FlowItem_Key);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowItem_SetKey(FlowItem self, FlowID value) { FlowObject_SetIDProperty(self, _FlowItem_Key, value);}
/**
 * \memberof FlowItem
 * \brief Indicates whether the property Value is set on this object.
 * 
 * Can be used to check whether Value is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowItem_HasValue(FlowItem self) { return FlowObject_HasProperty(self, _FlowItem_Value);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
*/
static inline char *FlowItem_GetValue(FlowItem self) { return FlowObject_GetStringProperty(self, _FlowItem_Value);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowItem_SetValue(FlowItem self, char *value) { FlowObject_SetStringProperty(self, _FlowItem_Value, value);}
/**
 * \memberof FlowItem
 * \brief Indicates whether the property TypeName is set on this object.
 * 
 * Can be used to check whether TypeName is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowItem_HasTypeName(FlowItem self) { return FlowObject_HasProperty(self, _FlowItem_TypeName);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
*/
static inline char *FlowItem_GetTypeName(FlowItem self) { return FlowObject_GetStringProperty(self, _FlowItem_TypeName);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowItem_SetTypeName(FlowItem self, char *value) { FlowObject_SetStringProperty(self, _FlowItem_TypeName, value);}
/**
 * \memberof FlowItem
 * \brief Indicates whether the property UpdateID is set on this object.
 * 
 * Can be used to check whether UpdateID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowItem_HasUpdateID(FlowItem self) { return FlowObject_HasProperty(self, _FlowItem_UpdateID);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
*/
static inline int FlowItem_GetUpdateID(FlowItem self) { return FlowObject_GetIntegerProperty(self, _FlowItem_UpdateID);}
/**
 * \memberof FlowItem
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowItem_SetUpdateID(FlowItem self, int value) { FlowObject_SetIntegerProperty(self, _FlowItem_UpdateID, value);}
#endif /* FLOW_CORE_ITEM_H_ */
