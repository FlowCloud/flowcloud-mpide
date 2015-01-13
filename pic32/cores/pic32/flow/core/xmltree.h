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


#ifndef __XMLTREE_H
#define	__XMLTREE_H

#include <stdbool.h>
#include "flow/core/base_types.h"

typedef void *TreeNode;


// APIs
bool TreeNode_AddChild(TreeNode node, TreeNode child);
TreeNode TreeNode_Create(void);
bool TreeNode_DeleteSingle(TreeNode node);						// Delete this node but not any children it might have
TreeNode TreeNode_GetChild(TreeNode node, uint index);
const char *TreeNode_GetName(const TreeNode node);
TreeNode TreeNode_GetParent(const TreeNode node);
const uint8 *TreeNode_GetValue(const TreeNode node);
bool TreeNode_HasParent(const TreeNode node);
TreeNode TreeNode_Navigate(const TreeNode rootNode, char *path);
bool TreeNode_SetName(const TreeNode node, const char *name, const uint length);
bool TreeNode_SetParent(const TreeNode node, const TreeNode parent);
bool TreeNode_SetValue(const TreeNode node, const uint8 *value, const uint length);

bool Tree_Delete(TreeNode node);


TreeNode TreeNode_ParseXML(uint8* doc, uint length, bool wholeDoc);

#endif	/* __XMLTREE_H */

