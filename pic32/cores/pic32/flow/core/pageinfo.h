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

#ifndef FLOW_CORE_PAGEINFO_H_
#define FLOW_CORE_PAGEINFO_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/pageinfo_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowPageInfo
 * \brief Creates a new FlowPageInfo.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowPageInfo FlowPageInfo_New(FlowMemoryManager memoryManager){ return (FlowPageInfo)FlowMemoryManager_NewObject(memoryManager, 4, 4, FlowType_PageInfo);}
/**
 * \memberof FlowPageInfo
 * \brief Registers meta data used for (de)serialising FlowPageInfo to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowPageInfo_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_PageInfo))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_PageInfo, "PageInfo", 4, 4);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PageInfo, _FlowPageInfo_TotalCount, FlowType_Integer, "TotalCount", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PageInfo, _FlowPageInfo_ItemsCount, FlowType_Integer, "ItemsCount", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PageInfo, _FlowPageInfo_StartIndex, FlowType_Integer, "StartIndex", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_PageInfo, _FlowPageInfo_AlphaIndex, FlowType_String, "AlphaIndex", true);
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_PageInfo, _FlowPageInfo_rel_First, "first");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_PageInfo, _FlowPageInfo_rel_Last, "last");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_PageInfo, _FlowPageInfo_rel_Next, "next");
		FlowXMLDeserialiser_RegisterTypeLink(FlowType_PageInfo, _FlowPageInfo_rel_Previous, "previous");
	}
}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property TotalCount is set on this object.
 * 
 * Can be used to check whether TotalCount is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasTotalCount(FlowPageInfo self) { return FlowObject_HasProperty(self, _FlowPageInfo_TotalCount);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline int FlowPageInfo_GetTotalCount(FlowPageInfo self) { return FlowObject_GetIntegerProperty(self, _FlowPageInfo_TotalCount);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPageInfo_SetTotalCount(FlowPageInfo self, int value) { FlowObject_SetIntegerProperty(self, _FlowPageInfo_TotalCount, value);}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property ItemsCount is set on this object.
 * 
 * Can be used to check whether ItemsCount is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasItemsCount(FlowPageInfo self) { return FlowObject_HasProperty(self, _FlowPageInfo_ItemsCount);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline int FlowPageInfo_GetItemsCount(FlowPageInfo self) { return FlowObject_GetIntegerProperty(self, _FlowPageInfo_ItemsCount);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPageInfo_SetItemsCount(FlowPageInfo self, int value) { FlowObject_SetIntegerProperty(self, _FlowPageInfo_ItemsCount, value);}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property StartIndex is set on this object.
 * 
 * Can be used to check whether StartIndex is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasStartIndex(FlowPageInfo self) { return FlowObject_HasProperty(self, _FlowPageInfo_StartIndex);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline int FlowPageInfo_GetStartIndex(FlowPageInfo self) { return FlowObject_GetIntegerProperty(self, _FlowPageInfo_StartIndex);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPageInfo_SetStartIndex(FlowPageInfo self, int value) { FlowObject_SetIntegerProperty(self, _FlowPageInfo_StartIndex, value);}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property AlphaIndex is set on this object.
 * 
 * Can be used to check whether AlphaIndex is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasAlphaIndex(FlowPageInfo self) { return FlowObject_HasProperty(self, _FlowPageInfo_AlphaIndex);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline char *FlowPageInfo_GetAlphaIndex(FlowPageInfo self) { return FlowObject_GetStringProperty(self, _FlowPageInfo_AlphaIndex);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowPageInfo_SetAlphaIndex(FlowPageInfo self, char *value) { FlowObject_SetStringProperty(self, _FlowPageInfo_AlphaIndex, value);}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property First is set on this object.
 * 
 * Can be used to check whether First is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasFirst(FlowPageInfo self) { return FlowObject_HasLink(self, _FlowPageInfo_rel_First);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline char *FlowPageInfo_GetFirst(FlowPageInfo self) { return FlowObject_GetLink(self, _FlowPageInfo_rel_First);}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property Last is set on this object.
 * 
 * Can be used to check whether Last is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasLast(FlowPageInfo self) { return FlowObject_HasLink(self, _FlowPageInfo_rel_Last);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline char *FlowPageInfo_GetLast(FlowPageInfo self) { return FlowObject_GetLink(self, _FlowPageInfo_rel_Last);}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property Next is set on this object.
 * 
 * Can be used to check whether Next is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasNext(FlowPageInfo self) { return FlowObject_HasLink(self, _FlowPageInfo_rel_Next);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline char *FlowPageInfo_GetNext(FlowPageInfo self) { return FlowObject_GetLink(self, _FlowPageInfo_rel_Next);}
/**
 * \memberof FlowPageInfo
 * \brief Indicates whether the property Previous is set on this object.
 * 
 * Can be used to check whether Previous is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowPageInfo_HasPrevious(FlowPageInfo self) { return FlowObject_HasLink(self, _FlowPageInfo_rel_Previous);}
/**
 * \memberof FlowPageInfo
 * \param self Object on which the method will be applied
*/
static inline char *FlowPageInfo_GetPrevious(FlowPageInfo self) { return FlowObject_GetLink(self, _FlowPageInfo_rel_Previous);}
#endif /* FLOW_CORE_PAGEINFO_H_ */
