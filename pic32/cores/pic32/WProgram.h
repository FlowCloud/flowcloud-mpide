//************************************************************************
#ifndef WProgram_h
#define WProgram_h
#ifdef _FLOWCLOUD_
#include <console.h>


/*****************************************************************************
 FlowCloud objects.

  Summary:
    Contains FlowCloud-related data.

  Description:
    These variables keep track of FlowCloud related data that does not change during a session.
*/
#define CLIENTID_CHAR_LENGTH                (5)

extern char *g_DeviceAoR;
extern char g_ClientID[CLIENTID_CHAR_LENGTH+1];
extern char *g_OwnerAoR;
extern char *g_OwnerID;
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <pins_arduino.h>

#ifndef Wiring_h
	#include "wiring.h"
#endif

#ifdef __cplusplus
#include "WCharacter.h"
#include "WString.h"

#ifndef HardwareSerial_h
	#include "HardwareSerial.h"
#endif

//Compatability changes
#if defined(__PIC32MX__)
  #if defined F
    #undef F
  #endif
  #define F(X) (X)
#endif

uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);

#define word(...) makeWord(__VA_ARGS__)

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned int);
long map(long, long, long, long, long);

#endif	// __cplusplus

#endif	// Wprogram_h
