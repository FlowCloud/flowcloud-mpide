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

/*! \file flow_messagingsubscription.h
 *  \brief LibFlowCore .
 */


#ifndef FLOW_MESSAGINGSUBSCRIPTION_H_
#define FLOW_MESSAGINGSUBSCRIPTION_H_

/**
 * \class FlowMessagingSubscription
*/
typedef struct FlowMessagingSubscriptionImpl *FlowMessagingSubscription;


/**
 * \memberof FlowMessagingSubscription
 * \ingroup Notifications
 * \brief &nbsp; Get topic associated with subscription
 * <p>&nbsp; <b> Description </b> <br/>
 * &nbsp; This function returns the MIME type of the content for an event
 * \param[in]  subscription   Pointer to the subscription returned by \ref Notifications#FlowMessaging_Subscribe.
 * \retval  content type
 */
char *FlowMessagingSubscription_GetTopic(FlowMessagingSubscription subscription);

/**
 * \memberof FlowMessagingSubscription
 * \ingroup Notifications
 * \brief &nbsp; Get user's ID for this subscription
 * <p>&nbsp; <b> Description </b> <br/>
 * &nbsp;This function returns the user's ID for an subscription
 * \param[in]  subscription   Pointer to the subscription returned by \ref Notifications#FlowMessaging_Subscribe.
 */
char *FlowMessagingSubscription_GetUserID(FlowMessagingSubscription subscription);

/**
 * \memberof FlowMessagingSubscription
 * \ingroup Notifications
 * \brief &nbsp; Get sender's ID for an event
 * <p>&nbsp; <b> Description </b> <br/>
 * &nbsp;This function returns the sender's ID for an event
 * \param[in]  subscription   Pointer to the subscription returned by \ref Notifications#FlowMessaging_Subscribe.
 */
char *FlowMessagingSubscription_GetDeviceID(FlowMessagingSubscription subscription);

#endif /* FLOW_MESSAGINGSUBSCRIPTION_H_ */
