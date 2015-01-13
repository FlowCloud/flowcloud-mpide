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

#ifndef FLOW_USERS_UPGRADE_H_
#define FLOW_USERS_UPGRADE_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/upgrade_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowUpgrade
 * \brief Creates a new FlowUpgrade.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowUpgrade FlowUpgrade_New(FlowMemoryManager memoryManager){ return (FlowUpgrade)FlowMemoryManager_NewObject(memoryManager, 8, 0, FlowType_Upgrade);}
/**
 * \memberof FlowUpgrade
 * \brief Registers meta data used for (de)serialising FlowUpgrade to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowUpgrade_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Upgrade))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Upgrade, "Upgrade", 8, 0);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_ID, FlowType_ID, "ID", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_InternalBuild, FlowType_String, "InternalBuild", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_BuildNumber, FlowType_Integer, "BuildNumber", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_UserVersion, FlowType_String, "UserVersion", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_Level, FlowType_Integer, "Level", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_Url, FlowType_String, "Url", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_Description, FlowType_String, "Description", false);
		FlowXMLDeserialiser_RegisterTypeProperty(FlowType_Upgrade, _FlowUpgrade_IsEnabled, FlowType_String, "IsEnabled", false);
	}
}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property ID is set on this object.
 * 
 * Can be used to check whether ID is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasID(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_ID);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline FlowID FlowUpgrade_GetID(FlowUpgrade self) { return FlowObject_GetIDProperty(self, _FlowUpgrade_ID);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetID(FlowUpgrade self, FlowID value) { FlowObject_SetIDProperty(self, _FlowUpgrade_ID, value);}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property InternalBuild is set on this object.
 * 
 * Can be used to check whether InternalBuild is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasInternalBuild(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_InternalBuild);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline char *FlowUpgrade_GetInternalBuild(FlowUpgrade self) { return FlowObject_GetStringProperty(self, _FlowUpgrade_InternalBuild);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetInternalBuild(FlowUpgrade self, char *value) { FlowObject_SetStringProperty(self, _FlowUpgrade_InternalBuild, value);}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property BuildNumber is set on this object.
 * 
 * Can be used to check whether BuildNumber is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasBuildNumber(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_BuildNumber);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline int FlowUpgrade_GetBuildNumber(FlowUpgrade self) { return FlowObject_GetIntegerProperty(self, _FlowUpgrade_BuildNumber);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetBuildNumber(FlowUpgrade self, int value) { FlowObject_SetIntegerProperty(self, _FlowUpgrade_BuildNumber, value);}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property UserVersion is set on this object.
 * 
 * Can be used to check whether UserVersion is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasUserVersion(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_UserVersion);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline char *FlowUpgrade_GetUserVersion(FlowUpgrade self) { return FlowObject_GetStringProperty(self, _FlowUpgrade_UserVersion);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetUserVersion(FlowUpgrade self, char *value) { FlowObject_SetStringProperty(self, _FlowUpgrade_UserVersion, value);}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property Level is set on this object.
 * 
 * Can be used to check whether Level is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasLevel(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_Level);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline int FlowUpgrade_GetLevel(FlowUpgrade self) { return FlowObject_GetIntegerProperty(self, _FlowUpgrade_Level);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetLevel(FlowUpgrade self, int value) { FlowObject_SetIntegerProperty(self, _FlowUpgrade_Level, value);}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property Url is set on this object.
 * 
 * Can be used to check whether Url is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasUrl(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_Url);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline char *FlowUpgrade_GetUrl(FlowUpgrade self) { return FlowObject_GetStringProperty(self, _FlowUpgrade_Url);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetUrl(FlowUpgrade self, char *value) { FlowObject_SetStringProperty(self, _FlowUpgrade_Url, value);}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property Description is set on this object.
 * 
 * Can be used to check whether Description is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasDescription(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_Description);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline char *FlowUpgrade_GetDescription(FlowUpgrade self) { return FlowObject_GetStringProperty(self, _FlowUpgrade_Description);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetDescription(FlowUpgrade self, char *value) { FlowObject_SetStringProperty(self, _FlowUpgrade_Description, value);}
/**
 * \memberof FlowUpgrade
 * \brief Indicates whether the property IsEnabled is set on this object.
 * 
 * Can be used to check whether IsEnabled is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrade_HasIsEnabled(FlowUpgrade self) { return FlowObject_HasProperty(self, _FlowUpgrade_IsEnabled);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
*/
static inline char *FlowUpgrade_GetIsEnabled(FlowUpgrade self) { return FlowObject_GetStringProperty(self, _FlowUpgrade_IsEnabled);}
/**
 * \memberof FlowUpgrade
 * \param self Object on which the method will be applied
 * \param value new value for this property
*/
static inline void  FlowUpgrade_SetIsEnabled(FlowUpgrade self, char *value) { FlowObject_SetStringProperty(self, _FlowUpgrade_IsEnabled, value);}
#endif /* FLOW_USERS_UPGRADE_H_ */
