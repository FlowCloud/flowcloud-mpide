/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef _APP_CORE_H
#define _APP_CORE_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#ifdef MICROCHIP_PIC32
#include "system_config.h"
#include "system_definitions.h"
#endif
#ifdef TCPIP_IF_MRF24W
#include "driver/wifi/mrf24w/drv_wifi.h"
#include "driver/wifi/mrf24w/src/drv_wifi_easy_config.h"
#endif

#ifndef MICROCHIP_PIC32
#include "system_mapping.h"
#define SECS_PER_DAY  86400
#define SECS_PER_HOUR 3600
#define SECS_PER_MIN  60
#define ELAPSE_INTERVAL 60
#endif

#include "activitylog.h"

#include "flow/core/flow_threading.h"
#include "flow_task_priority.h"

#include "tcpip/src/system/system_command.h"

//////////////////////////////////////////////////////
//                                                  //
// Flow Starter App -- Software Version Information //
//                                                  //
#define		SOFTWARE_VERSION_STRING "1.1.0"        //
//                                                  //
//////////////////////////////////////////////////////


#define	    STARTER_APP_DEVICE_TYPE				"wifire"

#define	    MAC_ADDRESS_LENGTH					(12)


// Flow Starter App's Supported AsyncMessage Commands
//#define		SET_LED_CMD_BASE							"SET LED"
//#define		ACKNOWLEDGE_LEDS_CMD							"ACKNOWLEDGE LEDS"
//#define		CLEAR_LEDS_CMD                                                          "CLEAR LEDS"
//#define		REBOOT_CMD								"REBOOT"
//#define		REBOOT_SOFTAP_CMD							"REBOOT SOFTAP"
//#define		RENAME_DEVICE_CMD_BASE							"RENAME DEVICE"
//#define		FACTORY_RESET_CMD_BASE							"FACTORY RESET"
//#define		HOSTUSB_POWER_CMD_BASE							"USBPOWER"
//#define		CONSOLE_DISPLAY_CMD_BASE						"CONSOLE DISPLAY"
//#define		ARDUINO_COMMAND_CMD_BASE						"ARDUINO COMMAND"
//#ifndef MICROCHIP_PIC32
//#define     FLASH_LED_CMD_BASE								"FLASH LED"
//#endif

#define		ACK_BTN_PRESS_DEBOUNCE_SECONDS                  (2)
#define		CONFIG_MODE_BTN_PRESS_DEBOUNCE_SECONDS          (5)

//#define		PRESENCE_REFRESH_PERIOD_SECONDS                 (20)
//#define		PRESENCE_EXPIRY_PERIOD_SECONDS                  (30)
//
//#define		MEASUREMENTS_DATASTORE_NAME						"measurements"
//
#define CLIENTID_CHAR_LENGTH								(5)
extern char g_ClientID[CLIENTID_CHAR_LENGTH+1];

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behaviour of the application at various times.
*/

//typedef enum
//{
//   /* The app mounts the disk */
//    APP_MOUNT_DISK = 0,
//
//    /* In this state, the application waits for the initialization of the TCP/IP stack
//     * to complete. */
//    APP_TCPIP_WAIT_INIT,
//
//    /* In this state the application starts the Soft AP*/
//    APP_WIFI_SOFTAP,
//
//    /* In this state, the application opens the driver. */
//    APP_TCPIP_TRANSACT,
//
//    /* The application waits in this state for the driver to be ready
//       before sending the "hello world" message. */
//    //APP_STATE_WAIT_FOR_READY,
//
//    /* The application waits in this state for the driver to finish
//       sending the mesage. */
//    //APP_STATE_WAIT_FOR_DONE,
//
//    /* The application does nothing in the idle state. */
//    APP_STATE_IDLE,
//
//    //
//    APP_USERIO_LED_DEASSERTED,
//
//    APP_USERIO_LED_ASSERTED,
//
//    APP_TCPIP_ERROR,
//
//} APP_STATES;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

//typedef struct
//{
//	// TODO - delete?
//    /* SYS_FS File handle */
//#ifdef MICROCHIP_PIC32
//    SYS_FS_HANDLE           fileHandle;
//#endif
//
//    /* Application's current state */
//    APP_STATES              state;
//
//    /* Application data buffer */
//    //uint8_t                 data[64];
//
//    //uint32_t            nBytesWritten;
//
//    //uint32_t            nBytesRead;
//
//} APP_DATA;

#ifdef TCPIP_IF_MRF24W
// *****************************************************************************
/* Driver objects.

  Summary:
    Holds driver objects.

  Description:
    This structure contains driver objects returned by the driver init routines
    to the application. These objects are passed to the driver tasks routines.

  Remarks:
    None.
*/

typedef struct
{
    /* NVM Driver Object  */
    SYS_MODULE_OBJ              drvNVMObject;

    /* NVM Media Driver Object */
    SYS_MODULE_OBJ              drvNVMMediaObject;

    /* NVM Driver Object  */
    SYS_MODULE_OBJ              drvSPIObject;

    /* NVM Media Driver Object */
    SYS_MODULE_OBJ              drvSDCARDObject;

    /* Timer Driver Object */
    SYS_MODULE_OBJ              drvTmrObject;

    /* Timer System Object */
    SYS_MODULE_OBJ              sysTmrObject;

    /* TCP/IP Stack Object */
    SYS_MODULE_OBJ              tcpipObject;

} APP_DRV_OBJECTS;
#endif

// *****************************************************************************
/* Uptime representation.

  Summary:
    Holds information about the duration that the device has been operating since last reset.

  Description:
    This structure contains information about the duration of time that the system has been running.
	Useful for diagnostic purposes.

  Remarks:
    None.
*/

typedef struct
{
    /* Uptime components*/
    uint16_t Days;
	uint8_t Hours;
	uint8_t	Minutes;
	uint8_t	Seconds;
} SYS_UPTIME;

#ifdef TCPIP_IF_MRF24W
/* This is a container object for the SYS_MODULE_OBJ
 * returned by the driver initialization routines. */
extern APP_DRV_OBJECTS g_AppDrvObjects;
#endif

//extern const uint8_t NVM_MEDIA_DATA[];  // TODO - delete this -- not required


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/
void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_RetrieveDeviceMeasurementDataStore ( void )

  Summary:
     This routine retrieves the measurements Datastore handle so that it can be used for saving and retrieving saved Datastore items.

  Returns:
    bool, success (true) or failure (false)
*/
//bool APP_RetrieveDeviceMeasurementDataStore( void );

/*******************************************************************************
  Function:
    void APP_SignalClearSavedValues ( void )

  Summary:
     This routine signals to the AppTask to clear the values saved in the device's DataStore.
*/
//void APP_SignalClearSavedValues(void);

/*******************************************************************************
  Function:
    void APP_SignalRetrieveOwnedDevicesList ( void )

  Summary:
     This routine signals to the AppTask to update its cached owned-devices list.
*/
//void APP_SignalRetrieveOwnedDevicesList( void );


/*******************************************************************************
  Function:
    void APP_SignalRetrieveSavedValues ( void )

  Summary:
     This routine signals to the AppTask to retrieve and display the values saved in the device's DataStore.
*/
//void APP_SignalRetrieveSavedValues(void);

/*******************************************************************************
  Function:
    void APP_SignalSaveNewValue ( void )

  Summary:
     This routine signals to the AppTask to query the user for a new value to save to the device's DatatStore
     The user also has the option of notifying an owned device of the new value.
*/
//void APP_SignalSaveNewValue( void );

/*******************************************************************************
  Function:
    void APP_SignalSendAsyncMessageCommand ( void )

  Summary:
     This routine signals to the AppTask to query the user for a recipient (device owner or peer-device), the message's contents
     and to send the message.
*/
void APP_SignalSendAsyncMessageCommand( void );

/*******************************************************************************
  Function:
    bool APP_GetOwnedDeviceID(unsigned int index, char* buffer, int bufferSize)

  Summary:
     This routine returns the null-terminated DeviceID belonging to an item in the cached owned-devices list.

  Parameters:    
    index, the index of the device in the list to retrieve the deviceID of. The first item in list begins at index 1.
    buffer, pre-allocated buffer to store the deviceid
    bufferSize, size of the buffer
  Returns:
    bool, success (true) or failure (false)

  Example:
    <code>
    #define BUFFER_SIZE 128
	char myBuffer[BUFFER_SIZE];
    bool result = APP_GetOwnedDeviceID(0, myBuffer, BUFFER_SIZE);
    </code>
*/
//bool APP_GetOwnedDeviceID(unsigned int index, char* buffer, int bufferSize);


/*******************************************************************************
  Function:
    bool APP_GetOwnedDeviceIdentity(unsigned int index, char* buffer, int bufferSize)

  Summary:
     This routine returns the null-terminated FlowMessaging dentity belonging to an item in the cached owned-devices list.

  Parameters:
    index, the index of the device in the list to retrieve the deviceID of. The first item in list begins at index 1.
    buffer, pre-allocated buffer to store the device identity
    bufferSize, size of the buffer

  Returns:
    bool, success (true) or failure (false)

  Example:
    <code>
    #define BUFFER_SIZE 128
	char myBuffer[BUFFER_SIZE];
    bool result = APP_GetOwnedDeviceIdentity(0, myBuffer, BUFFER_SIZE);
    </code>
*/
//bool APP_GetOwnedDeviceIdentity(unsigned int index, char* buffer, int bufferSize);

/*******************************************************************************
  Function:
    int APP_GetOwnedDevicesListCount ( void )

  Summary:
     This routine returns the number of items in the cached owned-devices list.

  Returns:
    int, number of items in the cached owned devices list.
*/
//int APP_GetOwnedDevicesListCount(void);

/*******************************************************************************
  Function:
    int APP_PromptUser ( void )

  Summary:
     This routine prompts the user for a yes/no decision via the console.

  Returns:
    bool, yes (true), no (false)
*/

bool APP_PromptUser(void);

/*******************************************************************************
  Function:
    bool APP_RetrieveSavedValues ( void )

  Summary:
     This routine retrieves and displays the saved values from the device's measurements DataStore.

  Returns:
    bool, success (true), failure (false).
*/
//bool APP_RetrieveSavedValues( void );


/*******************************************************************************
  Function:
    void APP_ClearSavedValues ( void )

  Summary:
     This routine deletes the saved values from the device's measurements DataStore.

  Returns:
    bool, success (true), failure (false).
*/
//bool APP_ClearSavedValues ( void );

/*******************************************************************************
  Function:
    void APP_ShowOwnedDevicesList ( bool showSelf )

  Summary:
     This routine displays the cached owned-devices list on the system console.

  Parameters:
    showSelf,	display this device in the list
*/

//void APP_ShowOwnedDevicesList( bool showSelf );

/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */
void APP_Tasks ( void );

/*******************************************************************************
  Function:
    void APP_SetDeviceIsOnline ( void )

  Summary:
    Indicate that the device is currently online

  Description:
    Sets state variable indicating the device is now online.
*/
//void APP_SetDeviceIsOnline(bool deviceOnline);


/*******************************************************************************
  Function:
    void SYS_Uptime (SYS_UPTIME* uptime)

  Summary:
    Return the system's up-time

  Description:
    This function returns the duration of time that the device has beebn running since last reset.
    routine.

  Precondition:
    SYS timer must be running
*/
void SYS_Uptime (SYS_UPTIME* uptime);


/*******************************************************************************
  Function:
    void SYS_StartTasks ( void )

  Summary:
    Function to start all RTOS tasks (including system-task).

  Description:
    This is the main RTOS function that starts all concurrent tasks. The function
    creates the required tasks and invokes the scheduler. The scheduler then manages
    the cooperative multi-tasking between different RTOS tasks.
    This function call is block whilst the scheduler continues to run.

  Remarks:
    This routine must be called after SYS_Initialize() routine.
*/
void SYS_StartTasks(void);

// SoftAP SSID
bool APP_GetSoftAPSSID(uint8_t *buff, uint32_t buffSize);

// Check if App is in configuration (SoftAP) or interactive mode
bool APP_IsRunningInConfigurationMode(void);
void APP_SoftwareReset(bool resetToConfigurationMode);
bool CheckForConfigurationModeRebootButtonPress(void);


#ifndef MICROCHIP_PIC32
//void APP_SignalSendAsyncMessageCommandReadComplete(void);
//void FlowRestartNeworking();
#endif

//typedef int (*flow_command_handler)(const char * cmd);
//typedef int (*AppBase_User_Setup)(const char * cmd);

typedef bool (*AppBase_ResetHandler)(bool resetToConfigurationMode);

typedef struct
{
	FlowThread_Callback AppTask;
//	flow_command_handler command_handler;
//	AppBase_User_Setup user_setup;

	_SYS_CMD_FNC CommandSet;
	_SYS_CMD_FNC CommandShow;
	AppBase_ResetHandler AppCLI_ResetHandler;
} APP_info;

extern APP_info * app_info_ptr;

int APPCORE_init(APP_info * info);


#endif /* _APP_CORE_H */
/*******************************************************************************
 End of File
 */
