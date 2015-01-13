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

/*! \file flow_messaging.h
 *  \brief libFlow  prototypes.
 */
#ifndef _FLOW_MESSAGING
#define _FLOW_MESSAGING

/* LibFlow */
#include "flow/core/base_types.h"
#include "flow/core/user_type.h"
#include "flow/flowcore.h"
#include "flow/messaging/flow_messagingevent.h"
#include "flow/messaging/flow_messagingsubscription.h"
#include "flow/messaging/flow_messagingmessage.h"

#define	FLOW_MESSAGING_TOPIC_USER_PRESENCE 		"UserPresence"
#define	FLOW_MESSAGING_TOPIC_DEVICE_PRESENCE	"DevicePresence"
#define	FLOW_MESSAGING_TOPIC_STATELESS_EVENT	"StatelessEvent"
#define	FLOW_MESSAGING_TOPIC_USER_PROFILE		"UserProfile"
#define	FLOW_MESSAGING_TOPIC_DEVICE_PROFILE		"DeviceProfile"


/**
 * \ingroup Notifications
 * @brief Notification callBack pass into \ref FlowMessaging_Subscribe. Implemented by application-layer.
 * \param[in] subscription subscription which event has been notified for
 * \param[in] event event contains content for notification
*/
typedef void (*FlowMessaging_SubscriptionEventCallBack)(FlowMessagingSubscription subscription, FlowMessagingEvent event);


/**
 * \ingroup Notifications
 * @brief Message callBack pass into \ref FlowMessaging_SetMessageReceivedListenerForDevice or \ref FlowMessaging_SetMessageReceivedListenerForUser. Implemented by application-layer.
 * \param[in] message message contains content that was received, can also be used in \ref FlowMessaging_ReplyToMessage
 */
typedef void (*FlowMessaging_MessageReceivedCallBack)(FlowMessagingMessage message);



/**
 * \ingroup Notifications
 * @brief SendMessage callback function definition.
 * \param[in] context context that was passed into \ref FlowMessaging_SendMessageToDeviceAsync or \ref FlowMessaging_SendMessageToUserAsync
 * \param[in] result whether message was successfully sent or not
 */
typedef void (*FlowMessaging_SendMessageCallBack)(void *context, bool result);


/**
 * General APIs
 *
 * \class Initialisation
 */

/**
 * \memberof Initialisation
 * \ingroup Initialisation
 * \brief Initialises SDk components
 * This function is used to initialise the various SDK components
 * \return LibFlowMessaging initialisation status
 * \retval true (SUCCESS), or false (FAILURE)
 */
bool FlowMessaging_Initialise(void);

/**
 * \memberof Initialisation
 * \ingroup Initialisation
 * \brief Shuts down Flow REST And SIP Components
 * This function is used to shutdown the Flow REST And SIP Components.
 * \return Shutdown of Flow Messaging status
 * \retval SUCCESS, FAILURE
 * \note This should be called after FlowMessaging_logout().
 * \warning No further calls to the FlowMessaging API should take place without a prior call to FlowMessaging_Init() to reinitialise the library components.
 */
bool FlowMessaging_Shutdown(void);

/**
 * Notifications
 *
 * \class Notifications
 */


/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Publishes documents/events
 * This function is used to publish documents/events to topics
 * \param[in] topic Topic to push document/event to eg FLOW_MESSAGING_TOPIC_USER_PRESENCE, FLOW_MESSAGING_TOPIC_DEVICE_PRESENCE etc.
 * \param[in] contentType MIME type of document.
 * \param[in] content Document to be published.
 * \param[in] contentLength Length of document to publish.
 * \param[in] expiryInSeconds  Publish expiry time in seconds.
 * \return Publish request status
 * \retval true (SUCCESS), or false (FAILURE)
 */
bool FlowMessaging_Publish (char *topic, char *contentType, char *content, int contentLength, uint expiryInSeconds);


/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Send reply message
 * Use this function to send a reply message back to original sender.
 * \param[in] message message to repy to
 * \param[in] contentType MIME type of reponse.
 * \param[in] response reponse message.
 * \param[in] responseLength length of reponse message.
 * \param[in] expiryInSeconds message timeout (seconds).
 * \return Message Send Status
 * \retval SUCCESS, FAILURE
 */
bool FlowMessaging_ReplyToMessage(FlowMessagingMessage message, char *contentType, char *response, uint responseLength, uint expiryInSeconds);

/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Send reply message asynchronously
 * Use this function to send a reply message back to original sender.
 * \param[in] message message to repy to
 * \param[in] contentType MIME type of reponse.
 * \param[in] response reponse message.
 * \param[in] responseLength length of reponse message.
 * \param[in] expiryInSeconds message timeout (seconds).
 */
void FlowMessaging_ReplyToMessageAsync(FlowMessagingMessage message, char *contentType, char *response, uint responseLength, uint expiryInSeconds, FlowMessaging_SendMessageCallBack callback, void *context);


/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Send message
 * This function will send a message to an specified device
 * \param[in] deviceID  Device to send message to.
 * \param[in] contentType        Null terminated message contentType.
 * \param[in] message            UTF8 text message content. Null terminated.
 * \param[in] messageLength length of message.
 * \param[in] expiryInSeconds			 Message timeout (seconds).
 * \return Message Send Status
 * \retval SUCCESS, FAILURE
 */
bool FlowMessaging_SendMessageToDevice(FlowID deviceID, char *contentType, char *message, uint messageLength, uint expiryInSeconds);

/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Send message asynchronously
 * This function will send a message to a specified device asynchronously
 * \param[in] deviceID  Device to send message to.
 * \param[in] contentType        Null terminated message contentType.
 * \param[in] message            UTF8 text message content. Null terminated.
 * \param[in] messageLength length of message.
 * \param[in] expiryInSeconds			 Message timeout (seconds).
 * \param[in] callback			 Callback to execute async on completion.
 * \param[in] context			 Application defined context that will be passed back in callback.
 */
void FlowMessaging_SendMessageToDeviceAsync(FlowID deviceID, char *contentType, char *message, uint messageLength, uint expiryInSeconds, FlowMessaging_SendMessageCallBack callback, void *context);

/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Send message
 * This function will send a message to a specified user
 * \param[in] userID  User to send message to
 * \param[in] contentType        Null terminated message contentType.
 * \param[in] message            UTF8 text message content. Null terminated.
 * \param[in] messageLength length of message.
 * \param[in] expiryInSeconds			 Message timeout (seconds).
 * \return Message Send Status
 * \retval SUCCESS, FAILURE
 */
bool FlowMessaging_SendMessageToUser(FlowID userID, char *contentType, char *message, uint messageLength, uint expiryInSeconds);

/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Send message asynchronously
 * This function will send a message to a specified user asynchronously
 * \param[in] userID  User to send message to
 * \param[in] contentType        Null terminated message contentType.
 * \param[in] message            UTF8 text message content. Null terminated.
 * \param[in] messageLength length of message.
 * \param[in] expiryInSeconds			 Message timeout (seconds).
 * \param[in] callback			 Callback to execute async on completion.
 * \param[in] context			 Application defined context that will be passed back in callback.
 */
void FlowMessaging_SendMessageToUserAsync(FlowID userID, char *contentType, char *message, uint messageLength, uint expiryInSeconds, FlowMessaging_SendMessageCallBack callback, void *context);

/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Set callback to be fired when message is received
 * This function set callback to be fired when message is received
 * \param[in] callback  Used to notify when message is received
 */
void FlowMessaging_SetMessageReceivedListenerForDevice(FlowMessaging_MessageReceivedCallBack callback);

/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Set callback to be fired when message is received
 * This function set callback to be fired when message is received
 * \param[in] callback  Used to notify when message is received
 */
void FlowMessaging_SetMessageReceivedListenerForUser(FlowMessaging_MessageReceivedCallBack callback);


/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Subscribe to notifications
 * This function is used to subscribe to notifications on a particular topic e.g. user-presence, device-presence etc
 * \param[in] topic Topic to listen to notification on eg FLOW_MESSAGING_TOPIC_USER_PRESENCE, FLOW_MESSAGING_TOPIC_DEVICE_PRESENCE etc.
 * \param[in] deviceID  .
 * \param[in] userID  .
 * \param[in] eventCallBack  Callback function pointer called on receipt of an incoming notification.
 * \return Subscribe request statusFlow
 * \retval \ref FlowMessagingSubscription (SUCCESS), or NULL (FAILURE)
 */
FlowMessagingSubscription FlowMessaging_Subscribe(char *topic, FlowID deviceID, FlowID userID, FlowMessaging_SubscriptionEventCallBack eventCallBack);

/**
 * \memberof Notifications
 * \ingroup Notifications
 * \brief Unsubscribe from notifications
 * This function is used to unsubscribe from notifications e.g. user-presence, device-presence etc
 * \param[in] subscription  Subscription to unsubscribe from, returned from \ref FlowMessaging_Subscribe.
 * \return Unsubscribe request status
 * \retval true (SUCCESS), or false (FAILURE)
 */
bool FlowMessaging_Unsubscribe(FlowMessagingSubscription *subscription);


/* Library version */
/**
 * \memberof Initialisation
 * \ingroup Initialisation
 * \brief Get LibFlow major version number
 * This function is used to return the major version number for this version of LibFlow
 * \return Major version number
 * \retval uint
 */
uint FlowMessaging_GetVersionMajor(void);

/**
 * \memberof Initialisation
 * \ingroup Initialisation
 * \brief Get LibFlow minor version number
 * This function is used to return the minor version number for this version of LibFlow
 * \return Minor version number
 * \retval uint
 */
uint FlowMessaging_GetVersionMinor(void);

/**
 * \memberof Initialisation
 * \ingroup Initialisation
 * \brief Get LibFlow build number of this version
 * This function is used to return the build number for this version of LibFlow
 * \return Build number
 * \retval uint
 */
uint FlowMessaging_GetVersionBuild(void);

/**
 * \memberof Initialisation
 * \ingroup Initialisation
 * \brief Get LibFlow release-date of this version
 * This function is used to return the release-date for this version of LibFlow
 * \return Version date
 * \retval char *
 */
char *FlowMessaging_GetVersionDate(void);


#endif
