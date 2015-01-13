/*****************************************************************************
        Copyright 2014 by Imagination Technologies.
                  All rights reserved.
                  No part of this software, either material or conceptual
                  may be copied or distributed, transmitted, transcribed,
                  stored in a retrieval system or translated into any
                  human or computer language in any form by any means,
                  electronic, mechanical, manual or otherwise, or
                  disclosed to third parties without the express written
                  permission of:
                        Imagination Technologies, Home Park Estate,
                        Kings Langley, Hertfordshire, WD4 8LZ, U.K.

*****************************************************************************/


/*******************************************************************************
  Configuration Store Header

  File Name:
    config_store.h

  Summary:
    APIs for storing and reading configuration information from non-volatile memory.

  Description:

 *******************************************************************************/

#ifndef __CONFIG_STORE_H_
#define __CONFIG_STORE_H_

#include <stdbool.h>
#include <stdint.h>

#include "app_core.h"
#include "flow_settings.h"
#include "activitylog.h"
#include "flow/core/base_types.h"

#define	CONFIG_STORE_DEFAULT_FIELD_LENGTH					(32)

/* Configuration Memory Base Address*/
#define CONFIG_STORE_BASE_ADDRESS							0xBD1F0000

// Versioning
#define	CONFIGSTORE_CONFIG_MEM_FORMAT_VERSION				(1)
#define	CONFIGSTORE_LOGGINGSETTINGS_MEM_FORMAT_VERSION		(1)

#define	IPV4_ADDRESS_LENGTH									(15)
#define FLOW_ROOT_URL_LENGTH								(48)



//
// Device Config settings
//
typedef enum
{
	WiFiEncryptionType_WEP = 0,
	WiFiEncryptionType_WPA,
	WiFiEncryptionType_WPA2,
	WiFiEncryptionType_Open,
	WiFiEncryptionType_Max
} WiFiEncryptionType;

typedef enum
{
	AddressScheme_Dhcp = 0,
	AddressScheme_StaticIP,
	AddressScheme_Max
} AddressScheme;


#define DEFAULT_LOGGING_ENABLED_SETTING		(true)
#define DEFAULT_LOGGING_LEVEL				(FlowActivityLogLevel_Information)
#define DEFAULT_LOGGING_CATEGORIES			(1<<FlowActivityLogCategory_HardwareBoot | 1<<FlowActivityLogCategory_Startup | 1<<FlowActivityLogCategory_Shutdown)



/*
 * Non-volatile storage; data structure definitions
 * - ConfigStruct
 * - LoggingSettingsStruct
 */

#define NVM_STRUCTURE_SPACING_BYTES			(32)			// Todo, could improve this to make it more intelligent (i.e. word/row-aligned)?

// Format of configuration memory
//
// Notes:
//			- startInConfigurationMode:	== 0xFFFF -> boot into configuration mode
//										!= 0xFFFF -> boot into interactive mode
//
//			- checkbyte will be XOR of magic number through to padding field
//
//
#define	CONFIGSETTINGS_PAGEOFFSET			(0)
typedef struct
{
	// Memory Format Information
	uint8_t				Magic[8];
	uint32_t			MemFormatVer;

	// Device Information
	uint64_t			CpuSerialNumber;
	char				DeviceName[CONFIG_STORE_DEFAULT_FIELD_LENGTH+1];		// Null terminated
	char				DeviceType[CONFIG_STORE_DEFAULT_FIELD_LENGTH+1];		//  "       "
	char				MacAddress[MAC_ADDRESS_LENGTH+1];						//  "       "
	char				RegistrationKey[CONFIG_STORE_DEFAULT_FIELD_LENGTH+1];	//  "       "

	// SoftAP Information
	char				SoftAPSSID[CONFIG_STORE_DEFAULT_FIELD_LENGTH+1];		//  "       "
	char				SoftAPPassword[CONFIG_STORE_DEFAULT_FIELD_LENGTH+1];	//  "       "

	// Network Configuration
	WiFiEncryptionType	Encryption;
	char				NetworkSSID[CONFIG_STORE_DEFAULT_FIELD_LENGTH+1];		//  "       "
	char				NetworkPassword[CONFIG_STORE_DEFAULT_FIELD_LENGTH+1];	//  "       "
	AddressScheme		AddressingScheme;
	
	// StaticIP configuration
	char				StatDNS[IPV4_ADDRESS_LENGTH+1];							//  "       "
	char				StatIP[IPV4_ADDRESS_LENGTH+1];							//  "       "
	char				StatNetmask[IPV4_ADDRESS_LENGTH+1];						//  "       "
	char				StatGateway[IPV4_ADDRESS_LENGTH+1];						//  "       "
	
	// Flow Settings
	char				RestRootURL[FLOW_ROOT_URL_LENGTH+1];					//  "       "
	char				FlowOauthKey[FLOW_OAUTH_KEY_LENGTH+1];					//  "       "
	char				FlowOauthSecret[FLOW_OAUTH_SECRET_LENGTH+1];			//  "       "


	// Device Control
	uint8_t				StartInConfigurationMode;
	uint8_t				NetworkConfigConfigured;

	// Housekeeping
	uint16_t			Padding;
	uint8_t				Checkbyte;												// Note: Must always be last field in structure

} ConfigStruct;


#define	LOGGINGSETTINGS_PAGEOFFSET			(sizeof(ConfigStruct) + NVM_STRUCTURE_SPACING_BYTES)
typedef struct
{
	// Memory Format Information
	uint8_t					Magic[8];
	uint32_t				MemFormatVer;

	// Logging Configuration
	uint32_t				LoggingEnabled;		// Note: could reduce size to uint8 (if other settings are changed in the future)
	FlowActivityLogLevel	LoggingLevel;
	uint16_t				LoggingCategories;

	// Housekeeping
	uint16_t				Padding;
	uint8_t					Checkbyte;												// Note: Must always be last field in structure

} LoggingSettingsStruct;

// WARNING: must be after the last config setting
#define	CONFIG_STORE_SETTING_END		(sizeof(LoggingSettingsStruct) + LOGGINGSETTINGS_PAGEOFFSET)

// TODO - delete...
typedef struct
{
	int							Index;
	uint32						Timestamp;			// timestamp for newest log entry read (to prevent wrap-around on read previous)
	FlowActivityLogCategory	Category;
	FlowActivityLogLevel		LoggingLevel;
} ActivityLogContext;

#define ACTIVITYLOG_PAGEOFFSET			2048									// reserve first 2KB in NV flash for config settings


///////////////////
// External APIs //
///////////////////
bool ConfigStore_Initialize(void);
bool ConfigStore_DeInitialize(void);

//
// [Device Config]
//
bool ConfigStore_Config_Erase(void);
bool ConfigStore_Config_Read(void);
bool ConfigStore_Config_ResetToDefaults(void);
bool ConfigStore_Config_IsValid(void);
bool ConfigStore_Config_IsMagicValid(void);
bool ConfigStore_Config_UpdateCheckbyte(void);
bool ConfigStore_Config_Write(void);

// APIs
bool ConfigStore_SoftAPSSIDValid(void);
bool ConfigStore_StartInConfigMode(void);
bool ConfigStore_GetNetworkConfigConfirmed(void);
bool ConfigStore_GetNetworkConfigSet(void);

AddressScheme ConfigStore_GetAddressingScheme(void);
const char* ConfigStore_GetAddressingSchemeName(AddressScheme addressingScheme);
const char* ConfigStore_GetDeviceName(void);
const char* ConfigStore_GetDeviceType(void);
const char* ConfigStore_GetEncryptionName(WiFiEncryptionType encryption);
WiFiEncryptionType  ConfigStore_GetEncryptionType(void);
const char* ConfigStore_GetMacAddress(void);
const char* ConfigStore_GetNetworkSSID(void);
const char* ConfigStore_GetFlowKeyValue(const char *keyName, size_t *valueLength);
const char* ConfigStore_GetFlowOauthKey(void);
const char* ConfigStore_GetFlowOauthSecret(void);
const char* ConfigStore_GetNetworkPassword(void);
const char* ConfigStore_GetRegistrationKey(void);
const char* ConfigStore_GetRestRootURL(void);
uint64_t ConfigStore_GetSerialNumber(void);
const char* ConfigStore_GetSoftAPSSID(void);
const char* ConfigStore_GetSoftAPPassword(void);
const char* ConfigStore_GetStaticDNS(void);
const char* ConfigStore_GetStaticGateway(void);
const char* ConfigStore_GetStaticNetmask(void);
const char* ConfigStore_GetStaticIP(void);


bool ConfigStore_SetAddressingScheme(const AddressScheme addressingScheme);
bool ConfigStore_SetDeviceName(const char* value);
bool ConfigStore_SetDeviceType(const char* value);
bool ConfigStore_SetFlowOauthKey(const char* value);
bool ConfigStore_SetFlowOauthSecret(const char* value);
bool ConfigStore_SetMacAddress(const char* value);
bool ConfigStore_SetNetworkConfigConfirmed(bool isSet);
bool ConfigStore_SetNetworkConfigSet(bool isSet);
bool ConfigStore_SetNetworkEncryption(WiFiEncryptionType encryption);
bool ConfigStore_SetNetworkPassword(const char* value);
bool ConfigStore_SetNetworkSSID(const char* value);
bool ConfigStore_SetRegistrationKey(const char* value);
bool ConfigStore_SetResetToConfigurationMode(bool value);
bool ConfigStore_SetRestRootURL(const char* value);
bool ConfigStore_SetSoftAPPassword(const char* value);
bool ConfigStore_SetStaticDNS(const char* value);
bool ConfigStore_SetStaticGateway(const char* value);
bool ConfigStore_SetStaticIP(const char* value);
bool ConfigStore_SetStaticNetmask(const char* value);

//
// [Logging Settings]
//
bool ConfigStore_LoggingSettings_Erase(void);
bool ConfigStore_LoggingSettings_Read(void);
bool ConfigStore_LoggingSettings_ResetToDefaults(void);
bool ConfigStore_LoggingSettings_IsValid(void);
bool ConfigStore_LoggingSettings_IsMagicValid(void);
bool ConfigStore_LoggingSettings_UpdateCheckbyte(void);
bool ConfigStore_LoggingSettings_Write(void);

// APIs
uint16_t ConfigStore_GetLoggingCategories(void);
const char* ConfigStore_GetLoggingCategoryName(FlowActivityLogCategory category);
bool ConfigStore_GetLoggingEnabled(void);
FlowActivityLogLevel ConfigStore_GetLoggingLevel(void);
const char* ConfigStore_GetLoggingLevelName(FlowActivityLogLevel level);

bool ConfigStore_SetLoggingEnabled(bool value);
bool ConfigStore_SetLoggingLevel(FlowActivityLogLevel value);
bool ConfigStore_SetLoggingCategories(uint16_t value);

//
// [Activity Log]
//
bool ConfigStore_ActivityLogInitialise(void);
bool ConfigStore_ActivityLogErase(void);
bool ConfigStore_ActivityLogAppend(const ActivityLog *appendLog);
int ConfigStore_ActivityLogRead(ActivityLogRequest *request);

//
//Network-Manager
//
#ifndef MICROCHIP_PIC32
void FlowWriteNetworkConfigFile();
#endif
#endif // __CONFIG_STORE_H_
