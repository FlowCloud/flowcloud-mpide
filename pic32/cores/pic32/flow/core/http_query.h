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

#ifndef FLOW_HTTP_QUERY_PRIVATE_H_
#define FLOW_HTTP_QUERY_PRIVATE_H_

#include "flow/core/base_types.h"
#include "flow/core/flow_object.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/flow_httpmethod.h"

typedef struct _FlowHTTPQuery *FlowHTTPQuery;


/**
 * Append a suffix to the url, e.g. for suffix "email@company.com", "/email@company.com"
 *  will be appended to the base url and encoded properly
 * @param self
 * @param suffix
 */
bool FlowHTTPQuery_AppendPathSuffix(FlowHTTPQuery self, const char *suffix);
bool FlowHTTPQuery_AppendPathSuffixBoolean(FlowHTTPQuery self, bool value);
bool FlowHTTPQuery_AppendPathSuffixChar(FlowHTTPQuery self, char value);
bool FlowHTTPQuery_AppendPathSuffixInt(FlowHTTPQuery self, int value);

/**
 * Constructs a new url from the query parameters and base url
 *
 * @param self the query parameters handle
 * @return a newly-allocated null-terminated string of the result URL
 */
char *FlowHTTPQuery_GenerateUrl(FlowHTTPQuery self);

/**
 * Returns a dynamically-allocated string containing the value for self query parameter
 *
 * @param self
 * @param param
 * @return
 */
char *FlowHTTPQuery_GetQueryParameter(FlowHTTPQuery self, char *param);


FlowObject FlowHTTPQuery_HTTPRequest(FlowMemoryManager memoryManager, FlowHTTPQuery query,FlowHTTPMethod method,FlowObject data, FlowType returnType);
bool FlowHTTPQuery_HTTPRequestWithStatusResponse(FlowMemoryManager memoryManager, FlowHTTPQuery query, FlowHTTPMethod method,FlowObject data);

FlowHTTPQuery FlowHTTPQuery_New(void);
FlowHTTPQuery FlowHTTPQuery_NewFromUrl(const char *url);

void FlowHTTPQuery_SetBaseUrl(FlowHTTPQuery self, const char *szBaseUrl);

void FlowHTTPQuery_SetQueryParameter(FlowHTTPQuery self, char *param, const char *paramValue);

void FlowHTTPQuery_Free(FlowHTTPQuery *self);


#endif /* FLOW_HTTP_QUERY_PRIVATE_H_ */
