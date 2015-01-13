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

/*! \file xml_serialisation.h
 *  \brief LibFlowCore .
 */


#ifndef XML_SERIALISATION_H_
#define XML_SERIALISATION_H_

#include "flow/core/base_types.h"
#include "flow/core/flow_object.h"

bool FlowXMLDeserialiser_Initialise(void);

bool FlowXMLDeserialiser_IsRegisteredType(FlowType type);

void FlowXMLDeserialiser_RegisterType(FlowType type, char *rootElement, uint8 propertyCount, uint8  linkCount);
void FlowXMLDeserialiser_RegisterTypeProperty(FlowType type, uint8 propertyIndex, FlowType propertyType, char *name, bool isElement);
void FlowXMLDeserialiser_RegisterTypeArrayProperty(FlowType type, uint8 propertyIndex, char *name, char *childName, FlowType childType, FlowType implementedByType);
void FlowXMLDeserialiser_RegisterTypeLink(FlowType type, uint8 linkIndex, char *name);

void FlowXMLDeserialiser_RegisterEnum(FlowType type, char *rootElement, uint8 valueCount);
void FlowXMLDeserialiser_RegisterEnumValue(FlowType type, uint8 index, char *name);

bool FlowXMLDeserialiser_Shutdown(void);


#endif /* XML_SERIALISATION_H_ */
