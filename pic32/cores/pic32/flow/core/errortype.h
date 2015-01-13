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

#ifndef FLOW_ERRORTYPE_H_
#define FLOW_ERRORTYPE_H_

/**
 * \class Errors
 * \brief Type of error that can be encountered during a request.
 * \see Flow_GetLastError
 */
typedef enum
{
	//! no error
	FlowError_NoError, 										//0
	//! an internal error occured, this is a bug that should be reported to libflow developers
	FlowError_Internal, 										//1
	//! there is not enough memory to fulfill this operation
	FlowError_Memory, 											//2
	//! the requested method is not supported on this object
	FlowError_MethodUnavailable, 								//3
	//! one of the method argument was invalid
	FlowError_InvalidArgument,								//4
	//! the resource that was requested in not available
	FlowError_ResourceNotFound,								//5
	//! failure to connect to the server
	FlowError_Network, 										//6
	//! the FlowCient doesn't have the credentials to access this resource
	FlowError_Unauthorised,									//7
	//! the submitted data is in conflict with existing data on the webservice. look up the HTML documentation for more details
	FlowError_Conflict,										//8
	//! the resource you're trying to access existed but has been removed
	FlowError_Removed,											//9
	//! the server suffered an internal error
	FlowError_Server,											//10
	//! the webservice cannot fulfill the request at the moment
	FlowError_ServerBusy,										//11
	//! the timed out while waiting for this request
	FlowError_Timeout,									//12
	//! the FlowClient is not logged in, there is no current user or device
	FlowError_Anonymous,										//13
	//! failure to store data in the local filesystem
	FlowError_LocalStorage,									//14
	//! the server and client are not compatible, check that the client is up to date
	FlowError_VersionConflict,								//15
	//! the object you're trying to use has been modified concurrently, get a new copy
	FlowError_ConcurrentModification,							//16

	/* BadRequest errors */
	FlowError_BadRequest_Min,									//17
	FlowError_BadRequestInvalidFields						//17
		= FlowError_BadRequest_Min,
	FlowError_BadRequestInvalidPin,							//18
	FlowError_BadRequestInsufficientFunds,					//19
	FlowError_BadRequestProductNotFound,					//20
	FlowError_BadRequestProductNotAvailable,				//21
	FlowError_BadRequestCardNotSupported,					//22
	FlowError_BadRequestInvalidCardnumber,					//23
	FlowError_BadRequestInvalidCardExpiryDate,			//24
	FlowError_BadRequestSubscriptioninvalidForUser,		//25
	FlowError_BadRequestSubscriptionAlreadyTrialled,		//26
	FlowError_BadRequestSubscriptionCannotBeTrialled,		//27
	FlowError_BadRequestSubscriptionCannotBeRenewed,		//28
	FlowError_BadRequestDuplicateEmail,						//29
	FlowError_BadRequestAccountNotFound,					//30
	FlowError_BadRequestVoucherNotValid,					//31
	FlowError_BadRequestVoucherAlreadyBeingProcessed,		//32
	FlowError_BadRequestContentFolderLimitReached,		//33
	FlowError_BadRequest_Unknown,							//34

	//! the client is not time-synchronized with the server, \ref FlowClient_SynchronizeServerTime must be called explicitely
	FlowError_ServerTimeSync,									//35
	//! the client session token is not valid, \ref FlowClient_RenewSession must be called explicitely
	FlowError_ExpiredSession,									//36
} FlowErrorType;


#endif /* FLOW_ERRORTYPE_H_ */
