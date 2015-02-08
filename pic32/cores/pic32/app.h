#ifndef app_h
#define app_h

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include <Arduino.h>

#define PRESENCE_REFRESH_PERIOD_SECONDS			(20)
#define PRESENCE_EXPIRY_PERIOD_SECONDS			(30)
#define CLIENTID_CHAR_LENGTH					(5)
#define	SOFTWARE_VERSION_STRING					"1.1.0"  

typedef struct
{
	/* Uptime components*/
	uint16_t Days;
	uint8_t Hours;
	uint8_t Minutes;
	uint8_t Seconds;
} SYS_UPTIME;

#ifdef __cplusplus
extern "C"  {
#endif
	// config_store.h depends on app_core.h which depends on harmony headers
	bool ConfigStore_Config_IsValid(void);
	const char* ConfigStore_GetNetworkSSID(void);
	const char* ConfigStore_GetDeviceType(void);
	const char* ConfigStore_GetMacAddress(void);
	const char* ConfigStore_GetDeviceName(void);
	const char* ConfigStore_GetRegistrationKey(void);


#ifdef __cplusplus
}
#endif

// app_core.h which depends on harmony headers
extern "C" void SYS_Uptime (SYS_UPTIME* uptime);
extern "C" void APP_SoftwareReset(bool resetToConfigurationMode);

bool PublishDevicePresence();
void Initialise_Flow();

#endif