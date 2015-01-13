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

#ifndef FLOW_CORE_SETTING_H_
#define FLOW_CORE_SETTING_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/setting_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowSetting
 * \brief Creates a new FlowSetting.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowSetting FlowSetting_New(FlowMemoryManager memoryManager){ return (FlowSetting)FlowMemoryManager_NewObject(memoryManager, 2, 0, FlowType_Setting);}
/**
 * \memberof FlowSetting
 * \brief Registers meta data used for (de)serialising FlowSetting to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowSetting_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Setting))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Setting, "Setting", 2, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Setting, _FlowSetting_Key, FlowType_String, "Key", true);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Setting, _FlowSetting_Value, FlowType_String, "Value", true);
	}
}
/**
 * \memberof FlowSetting
 * \brief Indicates whether the property Key is set on this object.
 * 
 * Can be used to check whether Key is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowSetting_HasKey(FlowSetting self) { return FlowObject_HasProperty(self, _FlowSetting_Key);}
/**
 * \memberof FlowSetting
 * \param self Object on which the method will be applied
*/
static inline char *FlowSetting_GetKey(FlowSetting self) { return FlowObject_GetStringProperty(self, _FlowSetting_Key);}
/**
 * \memberof FlowSetting
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowSetting_SetKey(FlowSetting self, char *value) { FlowObject_SetStringProperty(self, _FlowSetting_Key, value);}
/**
 * \memberof FlowSetting
 * \brief Indicates whether the property Value is set on this object.
 * 
 * Can be used to check whether Value is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowSetting_HasValue(FlowSetting self) { return FlowObject_HasProperty(self, _FlowSetting_Value);}
/**
 * \memberof FlowSetting
 * \param self Object on which the method will be applied
*/
static inline char *FlowSetting_GetValue(FlowSetting self) { return FlowObject_GetStringProperty(self, _FlowSetting_Value);}
/**
 * \memberof FlowSetting
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowSetting_SetValue(FlowSetting self, char *value) { FlowObject_SetStringProperty(self, _FlowSetting_Value, value);}
#endif /* FLOW_CORE_SETTING_H_ */
