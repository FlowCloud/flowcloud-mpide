/*******************************************************************************
  MRF24W Driver Customization

  Summary:
    Module for Microchip TCP/IP Stack
    
  Description:
    -Provides access to MRF24W WiFi controller
    -Reference: MRF24W Data sheet, IEEE 802.11 Standard
*******************************************************************************/

/*******************************************************************************
File Name: drv_wifi_config.h
Copyright 2012 released Microchip Technology Inc.  All rights
reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS?WITHOUT WARRANTY OF ANY KIND,
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

#ifndef __WF_CONFIG_H_
#define __WF_CONFIG_H_

#define WIFI_EASY_CONFIG_DEMO

#define WIFI_EASY_CONFIG_DEMO_VERSION_NUMBER  "1.0"


/************************************************************************
 * Select a default network mode for Console Demo.                      *
 *                                                                      *
 * Flow Starter App:                                                    *
 *      DRV_WIFI_NETWORK_TYPE_INFRASTRUCTURE                            *
 *		DRV_WIFI_NETWORK_TYPE_SOFT_AP                                   *
 ************************************************************************/
//#define WF_DEFAULT_NETWORK_TYPE     DRV_WIFI_NETWORK_TYPE_INFRASTRUCTURE
//#define WF_DEFAULT_NETWORK_TYPE     DRV_WIFI_NETWORK_TYPE_SOFT_AP
#define DYNAMIC_WIFI_MODE_SWITCH			(1)
#if! DYNAMIC_WIFI_MODE_SWITCH
	#define WF_DEFAULT_NETWORK_TYPE					DRV_WIFI_NETWORK_TYPE_INFRASTRUCTURE
	#define WF_DEFAULT_WIFI_SECURITY_MODE			DRV_WIFI_SECURITY_WPA2_WITH_PASS_PHRASE
#else
	extern DrvWifiNetworkType g_CurrentNetworkType;
	#define WF_DEFAULT_NETWORK_TYPE				(g_CurrentNetworkType)

	extern DrvWifiSecurityType g_CurrentSecurityMode;
	#define WF_DEFAULT_WIFI_SECURITY_MODE		(g_CurrentSecurityMode)
#endif

/************************************************************************************************************************************
 * Configure network for Infrastructure mode                                                                                        *
 *                                                                                                                                  *
 * Available security configuration:                                                                                                *
 * DRV_WIFI_SECURITY_OPEN                      : No security                                                                              *
 * DRV_WIFI_SECURITY_WEP_40                    : WEP Encryption using 40 bit keys                                                         *
 * DRV_WIFI_SECURITY_WEP_104                   : WEP Encryption using 104 bit keys                                                        *
 * DRV_WIFI_SECURITY_WPA_WITH_PASS_PHRASE      : WPA-PSK Personal where passphrase is given to MRF24W and it calculates the binary key    *
 * DRV_WIFI_SECURITY_WPA2_WITH_PASS_PHRASE     : WPA2-PSK Personal where passphrase is given to MRF24W and it calculates the binary key   *
 * DRV_WIFI_SECURITY_WPA_AUTO_WITH_PASS_PHRASE : WPA-PSK Personal or WPA2-PSK Personal where passphrase is given to MRF24W and it         *
 *                                             calculates the binary key and connects at highest level AP supports (WPA or WPA2)    *
 * DRV_WIFI_SECURITY_WPS_PUSH_BUTTON           : WPS push button method - for MRF24WG only                                                *
 * DRV_WIFI_SECURITY_WPS_PIN                   : WPS PIN method - for MRF24WG only                                                        *
 ************************************************************************************************************************************/
	#if! DYNAMIC_WIFI_MODE_SWITCH
	#define WF_DEFAULT_WIFI_SECURITY_MODE               DRV_WIFI_SECURITY_WPA2_WITH_PASS_PHRASE
	#endif

    #define WF_DEFAULT_SSID_NAME                        "WiFire"			 /* Set the SSID of the network we want to join. For WPS Push button set to "" */
    #define WF_DEFAULT_LIST_RETRY_COUNT                 (DRV_WIFI_RETRY_FOREVER) /* Number (1..255) of times to try to connect to the SSID when using Infrastructure network type */
    #define WF_DEFAULT_CHANNEL_LIST                     {}                       /* Channel list for Domain - use default in module */
	#define WF_DEFAULT_CHANNEL_LIST_SIZE				(0)						 /* Set network channel list size */
    #define WF_DEFAULT_PS_POLL                          DRV_WIFI_DISABLED        /* DRV_WIFI_ENABLED or DRV_WIFI_DISABLED */	

	#if (WF_DEFAULT_NETWORK_TYPE == DRV_WIFI_NETWORK_TYPE_INFRASTRUCTURE)

	#endif

/************************************************************************************
 * Configure network for SoftAP mode                                                *
 *                                                                                  *
 * Available security configuration:                                                *
 *      DRV_WIFI_SECURITY_OPEN                : No security                         *
 *      DRV_WIFI_SECURITY_WEP_40              : WEP Encryption using 40 bit keys    *
 *      DRV_WIFI_SECURITY_WEP_104             : WEP Encryption using 104 bit keys   *
 ************************************************************************************/

	#define USE_DEFAULT_SOFTAP_SSID				0							/* Revert back to default SoftAP SSID */
	#define WF_DEFAULT_SSID_NAME_PREFIX			"WiFire_"					/* Set SoftAP ssid base string (prefix) */
    #define WF_DEFAULT_SOFTAP_SSID_NAME         "MCHPSoftAP"                /* Set SoftAP ssid    */
    #define WF_DEFAULT_SOFTAP_WIFI_SECURITY_MODE	    DRV_WIFI_SECURITY_WEP_40					/* Set SoftAP security */
    #define WF_DEFAULT_SOFTAP_CHANNEL_LIST             {6}                     /* Set SoftAP network channel */
	#define WF_DEFAULT_SOFTAP_CHANNEL_LIST_SIZE        (1)                     /* Set SoftAP network channel list size */
    #define SOFTAP_CHECK_LINK_STATUS            DRV_WIFI_DISABLED           /* DRV_WIFI_ENABLED to use with SOFTAP_LINK_FAILURE_THRESHOLD */
    #define SOFTAP_LINK_FAILURE_THRESHOLD       40
	#define WF_DEFAULT_CHANNEL_LIST                     {}                       /* Channel list for Domain - use default in module */
	#define WF_DEFAULT_PS_POLL                          DRV_WIFI_DISABLED        /* DRV_WIFI_ENABLED or DRV_WIFI_DISABLED */
	#define WF_DEFAULT_LIST_RETRY_COUNT                 (DRV_WIFI_RETRY_FOREVER) /* Number (1..255) of times to try to connect to the SSID when using Infrastructure network type */

	#if (WF_DEFAULT_NETWORK_TYPE == DRV_WIFI_NETWORK_TYPE_SOFT_AP)

	#endif



 /*----------------------------------------------------------------------*
 * For WPS Push-Button demo, press the button of AP (Registrar) first   *
 * before running this demo. Input this pin number on AP (Registrar),   *
 * and activate Registrar first before connection attempt. Also note    *
 * that this 8 digit is not randomly generated. Last digit is the       *
 * checksum of first 7 digits. The checksum must be correct, otherwise  *
 * MRF24WG module will reject the pin code.                             *
 *----------------------------------------------------------------------*/
#define WF_DEFAULT_WPS_PIN    "12390212"

/*------------------------------------------------------------------------------------------*
 * Warning !!! Please note that :                                                           *
 * RF Module FW has a built-in connection manager, and it is enabled by default.            *
 * So if you want to run your own connection manager in host stack application side,        *
 * then you should disable the module connection manager to avoid some possible conflict    *
 * between the two.  These two APIs can be affected if you do not disable it.               *
 *   A) DRV_WIFI_Disconnect()                                                               *
 *   B) DRV_WIFI_Scan()                                                                     *
 * If some conflict occurs then these APIs will return failure.                             *
 *                                                                                          *
 * Note: This feature is current available with Infrastructure mode only.                   *
 *------------------------------------------------------------------------------------------*/
#define WF_MODULE_CONNECTION_MANAGER       DRV_WIFI_ENABLED


/*----------------------------------------------------------------------------------------------------------*
 * By default the module HW has 2 hardware multicast filters. If that is not enough on your application,    *
 * then you can choose this option to extend it to max 16.  As the macro name indicates this forces         *
 * the module FW to use software to run the filters instead of hardware.  Downside of this option           *
 * is the performance can degrade when there are so many multicast packets on air and the filtering is      *
 * done in SW.                                                                                              *
 *----------------------------------------------------------------------------------------------------------*/
#define WF_SOFTWARE_MULTICAST_FILTER            DRV_WIFI_ENABLED

/*----------------------------------------------------------------------------------------------------------*
 * This option allows a host stack to save and store acquired credentials through WPS process, and reuse    *
 * them to reconnect to same AP later on.  WPS process takes a relatively long time to get through.         *
 * So storing the credentials in non-volatile memory  and reusing it for reconnect is always good idea.     *
 * But this is not hard requirement, so we will let our customers decide whether to use this option or not. *
 * In order to save memory space in a host application side, we disable this option by default              *
 *----------------------------------------------------------------------------------------------------------*/
	#if (WF_DEFAULT_WIFI_SECURITY_MODE == DRV_WIFI_SECURITY_WPS_PUSH_BUTTON) || \
		(WF_DEFAULT_WIFI_SECURITY_MODE == DRV_WIFI_SECURITY_WPS_PIN)
		#define WF_SAVE_WPS_CREDENTIALS             DRV_WIFI_DISABLED
	#endif

#define WF_GRATUITOUS_ARP    DRV_WIFI_DISABLED

/*----------------------------------------------------------------------------------*
 * Default WEP keys used in DRV_WIFI_SECURITY_WEP_40 and DRV_WIFI_SECURITY_WEP_104  *
 * security mode.                                                                   *
 *----------------------------------------------------------------------------------*/

#define WF_DEFAULT_WEP_PHRASE           "WEP Phrase"

// string 4 40-bit WEP keys -- corresponding to passphrase of "WEP Phrase"
#define WF_DEFAULT_WEP_KEYS_40 "\
\x5a\xfb\x6c\x8e\x77\
\xc1\x04\x49\xfd\x4e\
\x43\x18\x2b\x33\x88\
\xb0\x73\x69\xf4\x78"
// Do not indent above string as it will inject spaces


// string containing 4 104-bit WEP keys -- corresponding to passphrase of "WEP Phrase"
#define WF_DEFAULT_WEP_KEYS_104 "\
\x90\xe9\x67\x80\xc7\x39\x40\x9d\xa5\x00\x34\xfc\xaa\
\x77\x4a\x69\x45\xa4\x3d\x66\x63\xfe\x5b\x1d\xb9\xfd\
\x82\x29\x87\x4c\x9b\xdc\x6d\xdf\x87\xd1\xcf\x17\x41\
\xcc\xd7\x62\xde\x92\xad\xba\x3b\x62\x2f\x7f\xbe\xfb"
// Do not indent above string as it will inject spaces 



/*----------------------------------------------------------------------*
 * Default PSK passphrase used in WPA and WPA2                          *
 *----------------------------------------------------------------------*/
#if ((WF_DEFAULT_WIFI_SECURITY_MODE == DRV_WIFI_SECURITY_WPA_WITH_PASS_PHRASE)      \
                            ||                                                      \
    (WF_DEFAULT_WIFI_SECURITY_MODE == DRV_WIFI_SECURITY_WPA2_WITH_PASS_PHRASE)      \
                            ||                                                      \
    (WF_DEFAULT_WIFI_SECURITY_MODE == DRV_WIFI_SECURITY_WPA_AUTO_WITH_PASS_PHRASE))

#define WF_DEFAULT_PSK_PHRASE               "ParagonLaptop"

#endif  /* WPA and WPA2 PSK Passphrase */

//#define WF_UPDATE_FIRMWARE_UART           // when you update wifi firmware by uart, please enable this line
//#define WF_UPDATE_FIRMWARE_TCPCLIENT      // when you update wifi firmware by tcpip client, please enable this line. The target file is A3Patchxxx.txt

//#define WF_SAVE_CONFIG_TO_MEMORY   //If define this macro, system will save configure data into MEMORY
#if defined (WF_SAVE_CONFIG_TO_MEMORY)
 #define WF_MEMORY_INSIDE_FLASH
 //#define WF_MEMORY_EXTERN_EEPROM

 #if defined(WF_MEMORY_INSIDE_FLASH) && defined(WF_MEMORY_EXTERN_EEPROM)
  #error "we cannot define the WF_MEMORY_INSIDE_FLASH and WF_MEMORY_EXTERN_EEPROM at same time"
 #endif
#endif


#if (WF_DEFAULT_NETWORK_TYPE != DRV_WIFI_NETWORK_TYPE_INFRASTRUCTURE)
    #if WF_MODULE_CONNECTION_MANAGER == DRV_WIFI_DISABLED
        #error "WF_MODULE_CONNECTION_MANAGER must be enabled if not in infrastructure mode"
    #endif
#endif


#endif /* __WF_CONFIG_H_ */


