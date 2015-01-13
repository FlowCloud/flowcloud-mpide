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

#ifndef FLOW_USERS_DEVICESETTINGS_H_
#define FLOW_USERS_DEVICESETTINGS_H_
#include "flow/core/base_types.h"
#include "flow/core/flow_httpmethod.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_memorymanager_methods.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_object_methods.h"
#include "flow/core/http_query.h"
#include "flow/core/settings_type.h"
/**
 * \memberof FlowDeviceSettings
 * \ingroup DeviceSettings
 * \brief Indicates whether \ref FlowDeviceSettings_RetrieveDetailsByQuery is available on this object.
 * 
 * Checks whether \ref FlowDeviceSettings_RetrieveDetailsByQuery is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceSettings_CanRetrieveDetailsByQuery(FlowSettings self) { return FlowObject_HasLink(self, _FlowSettings_rel_Self);}
/**
 * \memberof FlowDeviceSettings
 * \ingroup DeviceSettings
 * \brief Retrieve all device settings that match the query
 *
 * Retrieve subset of settings for the specified device. The device must be authenticated to use this API.
 * 
 * To obtain a subset of key/value settings a query takes the form:
 * \@Key {operator} {key pattern}
 * 
 * The supported query operators are:
 * | Operator | Description |
 * | :------: | :---------- |
 * | CONTAINS | key contains a value. e.g. \@Key CONTAINS 'ui'|
 * | LIKE | key like a value (including multiple wildcards, represented by the % character). e.g. \@Key LIKE 'myapp.ui.%''|
 * | IN | key in a list of possible values. e.g. \@Key IN ('pattern1', 'pattern2')|
 * | == | key equals specific value. e.g. \@Key == 'myapp.ui.theme'|
 * | != | key is not equal to specific value. e.g. \@Key != 'example' |
 * | > | key greater than specific value. e.g. \@Key > 12345 |
 * | >= | key greater than or equal to specific value. e.g. \@Key >= 12345 |
 * | < | key less than specific value. e.g. \@Key < 12345 |
 * | <= | key less than or equal tospecific value. e.g. \@Key <= 12345 |
 * \param self Object on which the method will be applied
 * \param query query
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowDeviceSettings_RetrieveDetailsByQuery(FlowSettings self, char *query, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowSettings_rel_Self))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowSettings_rel_Self));
		if(httpQuery)
		{
			FlowHTTPQuery_SetQueryParameter(httpQuery, "query", query);
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowSettings) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Settings);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
/**
 * \memberof FlowDeviceSettings
 * \brief Indicates whether \ref FlowDeviceSettings_RetrieveDetails is available on this object.
 * 
 * Checks whether \ref FlowDeviceSettings_RetrieveDetails is available on this object without making an HTTP call.
 * \param self Object on which the method will be applied
*/
static inline bool FlowDeviceSettings_CanRetrieveDetails(FlowSettings self) { return FlowObject_HasLink(self, _FlowSettings_rel_Self);}
/**
 * \memberof FlowDeviceSettings
 * \param self Object on which the method will be applied
 * \param pageSize number of items to return per page
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
static inline FlowSettings FlowDeviceSettings_RetrieveDetails(FlowSettings self, int pageSize)
{
	FlowSettings result = NULL;
	if(FlowObject_HasLink(self, _FlowSettings_rel_Self))
	{
		FlowHTTPQuery httpQuery = FlowHTTPQuery_NewFromUrl(FlowObject_GetLink(self, _FlowSettings_rel_Self));
		if(httpQuery)
		{
			char paramPageSize[32];
			sprintf(paramPageSize, "%d", pageSize);
			FlowHTTPQuery_SetQueryParameter(httpQuery, "pageSize", paramPageSize);
			result = (FlowSettings) FlowHTTPQuery_HTTPRequest(FlowObject_GetMemoryManager(self), httpQuery, FlowHTTPMethod_Get, NULL, FlowType_Settings);
			FlowHTTPQuery_Free(&httpQuery);
		}
	}
	return result;
}
#endif /* FLOW_USERS_DEVICESETTINGS_H_ */
