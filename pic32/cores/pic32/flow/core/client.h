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

#ifndef FLOW_CORE_CLIENT_H_
#define FLOW_CORE_CLIENT_H_
#include "flow/core/api_type.h"
#include "flow/core/base_types.h"
#include "flow/core/error_methods.h"
#include "flow/core/flow_memorymanager.h"
#include "flow/core/device_type.h"
#include "flow/core/externalloginrequest_type.h"
#include "flow/core/facebookloginrequest_type.h"
#include "flow/core/user_type.h"


typedef void (*FlowClient_LoginListenerCallback)(void);
typedef void (*FlowClient_LogoutListenerCallback)(void);

/**
 * \memberof FlowClient
 * \brief Provide the root \ref FlowAPI "API" object from which the webservice can be browsed.
 *
 * This method provides the starting point for getting content from the webservice.
 * \param memoryManager memory manager to track allocated memory
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
 */
FlowAPI FlowClient_GetAPI(FlowMemoryManager memoryManager);

/**
 * \memberof FlowClient
 * \brief Provide the target of a HTTP redirect from the Flow webservice.
 *
 * This method gets the redirection target of a webservice url, e.g. as provided by \ref StreamingUrl_GetUrl.
 * Typically, the redirection target will only be valid for a limited duration.
 * \param memoryManager memory manager to track allocated memory
 * \param url webservice url to get the redirection target from
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
 */
char *FlowClient_GetRedirectionTarget(FlowMemoryManager memoryManager, char *url);


/**
 * \memberof FlowClient
 * \brief Forces a session token renewal with the server.
 *
 * This method can be used when libflow failed to renew the session token automatically.
 * \param memoryManager memory manager to track allocated memory
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
 */
bool FlowClient_RenewSession(FlowMemoryManager memoryManager);

/**
 * \memberof FlowClient
 * \brief Ensures that time synchronization and session tokens are up-to-date with the server.
 *
 * This method lets you instruct libfow to resume connection, e.g. after the process it is running in was suspended or if network connection was lost.
 * \param memoryManager memory manager to track allocated memory
*/
void FlowClient_Resume(FlowMemoryManager memoryManager);

/**
 * \memberof FlowClient
 * \brief Sets the client locale that is sent to the webservice.
 *
 * All further calls to the webservice will use the locale set here.
 * This helps the webservice in providing content in the right locale, such as \ref Content.FeaturedContent "featured content". \n
 * The format of the locale should the 2-letter code for the language and the 2-letter code for the country, e.g. "en-GB".
 * \param locale locale of the client application
 */
void FlowClient_SetLocale(char *locale);

/**
 * \memberof FlowClient
 * \brief Sets the webservice the client should connect to.
 *
 * Establishes the connection to the server, synchronizes time with it and requests a session token if the client was previously identified as a device or a user with rememberMe=true.
 * \param serverUrl url of the server root API, e.g. http://ws.flowworld.com
 * \param oauthKey oauth key of your licensee
 * \param oauthSecret oauth secret of your licensee
 * \param tryAutoLogin if there is remember token, use this to login in client
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ServerBusy "FlowError_ServerBusy"
*/
bool FlowClient_ConnectToServer(const char *serverUrl, const char *oauthKey, const char *oauthSecret, bool tryAutoLogin);

/**
 * \memberof FlowClient
 * \brief Forces a time synchronization with the server.
 * 
 * This method can be used when libflow failed to synchronize time automatically.
 * \param memoryManager memory manager to track allocated memory
*/
void FlowClient_SynchronizeServerTime(FlowMemoryManager memoryManager);

/**
 * \memberof FlowClient
 * \brief Indicates if the app is logged either as a \ref User user or a \ref Device device.
 * 
 * This does not perform an HTTP request.
*/
bool FlowClient_IsLoggedIn(void);

/**
 * \memberof FlowClient
 * \brief Indicates if the app is logged either as a \ref Device device.
 * 
 * This does not perform an HTTP request.
*/
bool FlowClient_IsDeviceLoggedIn(void);
/**
 * \memberof FlowClient
 * \brief Indicates if the app is logged either as a \ref User user.
 * 
 * This does not perform an HTTP request.
*/
bool FlowClient_IsUserLoggedIn(void);
/**
 * \memberof FlowClient
 * \brief Logs out the user or device.
 * 
 * Discards any session information that was identifying the client application to the server. \n This does not perform an HTTP request.
*/
void FlowClient_Logout(void);
/**
 * \memberof FlowClient
 * \brief Logs out the current user.
 * 
 * If the user was logged in on a device, the device will stay logged-in.
*/
void FlowClient_LogoutUser(void);
/**
 * \memberof FlowClient
 * \brief Logs the client application as a given \ref User user.
 * 
 * This logs the client application as a user and manages the session token returned by the webservice.
 * All successive requests until log-out will be issued as this user.
 *
 * \param username name of the user to log in as
 * \param password password of the user
 * \param rememberMe whether libflow should automatically log-in as that user on the next startup
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
 */
bool FlowClient_LoginAsUser(char *username, char *password, bool rememberMe);
/**
 * \memberof FlowClient
 * \brief Logs the client application as a given \ref Device device.
 * 
 * 
 * Logs the application as a device permanently (or until \ref FlowClient_Logout is called). \n
 * If the information on the device stored by the server is outdated, it will be updated (e.g. software version, device name). \n
 * If the device has never been registered with the server before, it will be done automatically. \n
 * If the device is already logged-in to the server, no update or registration will be performed. \n
 * \n
 * The device will be automatically logged-in on the next application start-up.
 * \param hardwareType type of the device, e.g. "MiniMorph"
 * \param macAddress mac address of the device, e.g. "001122334455"
 * \param serialNumber serial number of the device, may be empty
 * \param deviceID used when macAddress is not available, to generate use \ref FlowAPI#FlowAPI_GenerateUUID
 * \param softwareVersion software version of the client application running on the device
 * \param deviceName friendly name of the device that the user can identify
 * \param registrationKey required by some licensees to register a device (and at the same time associate with a user)
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
*/
bool FlowClient_LoginAsDevice(char *hardwareType, char *macAddress, char *serialNumber, char *deviceID, char *softwareVersion, char *deviceName, FlowToken registrationKey);
/**
 * \memberof FlowClient
 * \brief Logs a user on a specific device.
 *
 *
 * \param username name of the user to log in as
 * \param password password of the user
 * \param rememberMe whether libflow should automatically log-in as that user on that device on the next startup
 * \note You may only call this method after calling \ref FlowClient_LoginAsDevice to identify the device on which the user is trying to connect. \n
 * \note Calling \ref FlowClient_LoginAsDevice on the next start-up will log the user out.
 * If you want to keep the user logged-in, first check against \ref FlowClient_GetLoggedInUser before calling \ref FlowClient_LoginAsDevice.
 * \note <BR />
 * \note If not successful, call \ref Errors#Flow_GetLastError "Flow_GetLastError" for error. Possible errors are:
 *   - \ref FlowError#FlowError_BadRequestInvalidFields "FlowError_BadRequestInvalidFields"
 *   - \ref FlowError#FlowError_Network "FlowError_Network"
 *   - \ref FlowError#FlowError_ResourceNotFound "FlowError_ResourceNotFound"
 *   - \ref FlowError#FlowError_Unauthorised "FlowError_Unauthorised"
*/
bool FlowClient_LoginAsUserOnCurrentDevice(char *username, char *password, bool rememberMe);

/**
 * \memberof FlowClient
 * \brief Returns the user currently logged in.
 * 
 * This method uses an HTTP request to provide up-to-date \ref User details.
 * \param memoryManager memory manager to track allocated memory
 * \exception FlowError_Anonymous if the client is not logged in as a user
 *
*/
FlowUser FlowClient_GetLoggedInUser(FlowMemoryManager memoryManager);
/**
 * \memberof FlowClient
 * \brief Returns the device currently logged in.
 * 
 * This method uses an HTTP request to provide up-to-date \ref Device details.
 * \param memoryManager memory manager to track allocated memory
 * \exception FlowError_Anonymous if the client is not logged in as a device
*/
FlowDevice FlowClient_GetLoggedInDevice(FlowMemoryManager memoryManager);

FlowFacebookLoginRequest FlowClient_StartFacebookLogin(FlowMemoryManager memoryManager, FlowExternalLoginRequest loginRequest);

void FlowClient_CompleteFacebookLogin(FlowMemoryManager memoryManager, FlowFacebookLoginRequest request, char *fbAccessToken, FlowDatetime fbAccessTokenExpiry, bool remember);


/**
 * \memberof FlowClient
 * \brief Allow for modules to be notified via callback function when device login has occurred
 * Allow for modules to be notified via callback function when device login has occurred
 * \param callback Callback function
*/
void FlowClient_RegisterDeviceLoginListener(FlowClient_LoginListenerCallback callback);

/**
 * \memberof FlowClient
 * \brief Allow for modules to be notified via callback function when device logout has occurred
 * Allow for modules to be notified via callback function when device logout has occurred
 * \param callback Callback function
*/
void FlowClient_RegisterDeviceLogoutListener(FlowClient_LogoutListenerCallback callback);

/**
 * \memberof FlowClient
 * \brief Allow for modules to be notified via callback function when user login has occurred
 * Allow for modules to be notified via callback function when user login has occurred
 * \param callback Callback function
*/
void FlowClient_RegisterUserLoginListener(FlowClient_LoginListenerCallback callback);

/**
 * \memberof FlowClient
 * \brief Allow for modules to be notified via callback function when user logout has occurred
 * Allow for modules to be notified via callback function when user logout has occurred
 * \param callback Callback function
*/
void FlowClient_RegisterUserLogoutListener(FlowClient_LogoutListenerCallback callback);

		
#endif /* FLOW_CORE_CLIENT_H_ */
