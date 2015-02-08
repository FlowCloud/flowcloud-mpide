//************************************************************************
//*	main.c
//*	
//*	Arduino core files for PIC32
//*		Copyright (c) 2010, 2011 by Mark Sproul
//*	
//*	
//************************************************************************
//*	this code is based on code Copyright (c) 2005-2006 David A. Mellis
//*	
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.//*	See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
//*	
//*	
//************************************************************************
//*	Edit History
//************************************************************************
//*	Oct 12,	2010	Got MPLAB X working on MacOSX 1.6 for the first time
//* Dec 12, 2011 <GeneApperson> added call to _scheduleTask() before call
//*					to loop().
//* Feb 09, 2015	Added support for FlowCloud on Arduino
//************************************************************************

//!!! This section is a read only section !!!

#define OPT_SYSTEM_INTERNAL

#include <System_Defs.h>

#if (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

extern "C" {
void __use_isr_install(void);
__attribute__((section(".comment"))) void (*__use_force_isr_install)(void) = &__use_isr_install;
}


#ifdef _FLOWCLOUD_

#include "app.h"
#include "console.h"
#include "flow/flow_console.h"

#include <flow/core/flow_threading.h>
#include <flow/core/flow_timer.h>
#include <flow/app/system_command.h>
extern "C" 
{
	#include <flow/core/flow_memalloc.h>
	#include <flow/core/flow_time.h>
}

void * operator new(size_t n)
{
	return Flow_MemAlloc(n);
}
void operator delete(void * p) throw()
{
	Flow_MemSafeFree(p);
}

extern "C" {

	//************************************************************************
	// Interrupts required by APPCORE. These cannot be defined in a static library
	//************************************************************************

	void APPCORE_InterruptHandler_MRF24W_Ext4(void);
	void APPCORE_InterruptHandler_ETHMAC(void);
	void APPCORE_InterruptHandler_TMR2(void);
	void APPCORE_InterruptHandler_NVM(void);

	void __attribute__((nomips16, vector(_EXTERNAL_4_VECTOR),interrupt(IPL3SRS))) _InterruptHandler_MRF24W_Ext4(void)
	{
	     APPCORE_InterruptHandler_MRF24W_Ext4();
	}

	void __attribute__((nomips16, vector(_ETHERNET_VECTOR),interrupt(IPL5SRS))) _InterruptHandler_ETHMAC(void)
	{
	    APPCORE_InterruptHandler_ETHMAC();
	}

	void __attribute__((nomips16, vector(_TIMER_2_VECTOR),interrupt(IPL4))) _InterruptHandler_TMR2(void)
	{
	    APPCORE_InterruptHandler_TMR2();
	}

	void __attribute__((nomips16, vector(_FLASH_CONTROL_VECTOR),interrupt(IPL4SRS))) _InterruptHandler_NVM(void)
	{
	    APPCORE_InterruptHandler_NVM();
	}

	//************************************************************************
	// definitions for required functions from libappbase that themselves have
	// dependencies we can't meet (i.e. harmony drivers)
	//************************************************************************

	typedef bool (*AppBase_ResetHandler)(bool resetToConfigurationMode);

	typedef struct
	{
		FlowThread_Callback AppTask;
		_SYS_CMD_FNC CommandSet;
		_SYS_CMD_FNC CommandShow;
		AppBase_ResetHandler AppCLI_ResetHandler;
	} APP_info;

	int APPCORE_init(APP_info * info);

	// assuming configUSE_16_BIT_TICKS == 0
	void vTaskDelay( const uint32_t xTicksToDelay );

	//************************************************************************
	// Implement required functions for libappbase
	//************************************************************************

	extern "C" void APP_SoftwareReset(bool);

	bool SoftwareReset(bool resetToConfigurationMode)
	{
		APP_SoftwareReset(resetToConfigurationMode);
		return false;
	}

	//************************************************************************
	// Intercept UI task's access to the LEDs to Arduino can have full controll
	//************************************************************************

	bool g_EnableUIControlLED = false;

	typedef enum
	{
		UILEDState_Off = 0,
		UILEDState_On
	} UILEDState;

	typedef enum
	{
		UILEDMode_Manual = 0,
		UILEDMode_Off,
		UILEDMode_On,
		UILEDMode_FlashStartOn,
		UILEDMode_FlashStartOff,
		UILEDMode_Max,
	} UILEDMode;

	bool __real_UIControl_SetLEDMode(uint8_t led, UILEDMode newMode);
	bool __real_UIControl_SetLEDState(uint8_t led, UILEDState newMode);
	void __real_UIControl_UIStep(void);

	bool __wrap_UIControl_SetLEDMode(uint8_t led, UILEDMode newMode)
	{
		bool result = false;
		if (g_EnableUIControlLED)
		{
			result = __real_UIControl_SetLEDMode(led, newMode);
		}
		return result;
	}

	bool __wrap_UIControl_SetLEDState(uint8_t led, UILEDState newMode)
	{
		bool result = false;
		if (g_EnableUIControlLED)
		{
			result = __real_UIControl_SetLEDState(led, newMode);
		}
		return result;
	}

	void __wrap_UIControl_UIStep(void)
	{
		if (g_EnableUIControlLED)
		{
			__real_UIControl_UIStep();
		}
	}



}

void Arduino_AppTask(FlowThread thread, void *taskParameters)
{
	FlowConsole_Printf("Initialising Flow connection\r\n");
	Initialise_Flow();

	FlowConsole_Printf("\n\r\n\r----------------------------------------------");
	FlowConsole_Printf("\n\rFlow booting completed. Running Arduino sketch...\n\r");
	FlowConsole_Printf("\n\r\n\r\n\r");
	delay(20);

	Serial.end();
	g_EnableConsole = false;
	g_EnableConsoleInput = false;
	g_EnableUIControlLED = false;

	delay(10);

	digitalWrite(PIN_LED1, LOW);
	digitalWrite(PIN_LED2, LOW);
	digitalWrite(PIN_LED3, LOW);
	digitalWrite(PIN_LED4, LOW);

	// call init a second time to reset millis()
	init();
	setup();
	
	for (;;)
	{
		//_scheduleTask();
		vTaskDelay(1);
		loop();
	}
}

static APP_info info =
{
	Arduino_AppTask,
	NULL,
	NULL,
	SoftwareReset
};

int main(void)
{
	digitalWrite(PIN_LED1, HIGH);
	digitalWrite(PIN_LED2, LOW);
	digitalWrite(PIN_LED3, HIGH);
	digitalWrite(PIN_LED4, LOW);

	init();
	Serial.begin(115200);
	g_EnableConsole = true;
	g_EnableConsoleInput = true;

	FlowConsole_Printf("System booting - Initialising appcore\r\n");

	g_EnableUIControlLED = true;
	return APPCORE_init(&info);
}

#else

int main(void)
{
	init();

	setup();

	while (1)
	{
		_scheduleTask();
		loop();
	}
	return 0;
}

#endif