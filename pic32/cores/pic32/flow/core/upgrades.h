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

#ifndef FLOW_USERS_UPGRADES_H_
#define FLOW_USERS_UPGRADES_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/upgrade.h"
#include "flow/core/upgrades_type.h"
#include "flow/core/xml_serialisation.h"
/**
 * \memberof FlowUpgrades
 * \brief Creates a new FlowUpgrades.
 * 
 * You should use the result of this method whenever you need to submit a Object as a \a data parameter.
 * \param memoryManager Memory manager on which the method will be applied
*/
static inline FlowUpgrades FlowUpgrades_New(FlowMemoryManager memoryManager){ return (FlowUpgrades)FlowMemoryManager_NewObject(memoryManager, 1, 0, FlowType_Upgrades);}
/**
 * \memberof FlowUpgrades
 * \brief Registers meta data used for (de)serialising FlowUpgrades to XML.
 * 
 * You should this if you are going to use this type in application code.
*/
static inline void  FlowUpgrades_RegisterType()
{
	if(!FlowXMLDeserialiser_IsRegisteredType(FlowType_Upgrades))
	{
		FlowXMLDeserialiser_RegisterType(FlowType_Upgrades, "Upgrades", 1, 0);
		FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType_Upgrades, _FlowUpgrades_Items, "Items", "Item", FlowType_Upgrade, FlowType_Upgrades);
	}
}
/**
 * \memberof FlowUpgrades
 * \brief Indicates whether the property Items is set on this object.
 * 
 * Can be used to check whether Items is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowUpgrades_HasItems(FlowUpgrades self) { return FlowObject_HasProperty(self, _FlowUpgrades_Items);}
/**
 * \memberof FlowUpgrades
 * \brief Gets the item at a given position in the list.
 * 
 * \param self Object on which the method will be applied
 * \param index index of item in collection
*/
static inline FlowUpgrade FlowUpgrades_GetItem(FlowUpgrades self, uint index) { return (FlowUpgrade)FlowObject_GetArrayObjectProperty(self, _FlowUpgrades_Items, index);}
/**
 * \memberof FlowUpgrades
 * \brief Returns the number of items in the list.
 * 
 * The value returned by this method is related to the number of items already loaded in the list.
 * \param self Object on which the method will be applied
*/
static inline int FlowUpgrades_GetCount(FlowUpgrades self) { return FlowObject_GetArrayPropertyCount(self, _FlowUpgrades_Items);}
/**
 * \memberof FlowUpgrades
 * \brief Append a new item at the end of the list and returns it.
 * 
 * This is meant to be used to build up lists of items to submit.
 * \param self Object on which the method will be applied
*/
static inline FlowUpgrade FlowUpgrades_NewItem(FlowUpgrades self)
{
	FlowUpgrade result = FlowUpgrade_New(NULL);
	FlowObject_AddArrayObjectProperty(self, _FlowUpgrades_Items, result);
	return result;
}
#endif /* FLOW_USERS_UPGRADES_H_ */
