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
  User Interface Control Headers

  File Name:
    ui_control.h

  Summary:
    APIs for manipulating the user interface behaviour of the Flow Starter App

  Description:

 *******************************************************************************/

#ifndef __UI_CONTROL_H_
#define __UI_CONTROL_H_
#ifdef MICROCHIP_PIC32
#include "bsp_config.h"
#endif

#ifndef MICROCHIP_PIC32
#include <stdbool.h>
#include <stdint.h>
#endif


#define MAX_LEDS			(4)

typedef enum
{
	UILEDState_Off = 0,
	UILEDState_On
} UILEDState;

typedef enum
{
	UILEDMode_Manual = 0,					// Manually controlled (the ui controller module will not modify the LED's state)
	UILEDMode_Off,
	UILEDMode_On,
	UILEDMode_FlashStartOn,
	UILEDMode_FlashStartOff,
	UILEDMode_Max,
} UILEDMode;


typedef enum
{
	AppUIState_None = 0,
	AppUIState_SoftApHardwareError,
	AppUIState_SoftApNotConnected,
	AppUIState_SoftApConnected,
	AppUIState_SoftApNotConfigured,
	AppUIState_SoftApConfigured,
	AppUIState_InteractiveConnectingToNetwork,
	AppUIState_InteractiveConnectedToNetwork,
	AppUIState_InteractiveConnectingToFlow,
	AppUIState_InteractiveConnectedToFlow,
	AppUIState_InteractiveHardwareError,
	AppUIState_Max

} AppUIState;


void UIControl_UIStep(void);


// APIs
bool UIControl_SetUIState(AppUIState newState);
bool UIControl_SetLEDMode(uint8_t led, UILEDMode newMode);
bool UIControl_SetLEDState(uint8_t led, UILEDState newState);

#endif	// __UI_CONTROL_H_