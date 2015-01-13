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
  Flow related settings

  File Name:
    flow_settings.h

  Summary:
    Flow-related configruation defines and settings.

  Description:

 *******************************************************************************/


#ifndef __FLOW_SETTINGS_H_
#define	__FLOW_SETTINGS_H_


#include <stdbool.h>
#include <stdint.h>

#define FLOW_OAUTH_KEY_LENGTH		(16)
#define FLOW_OAUTH_SECRET_LENGTH	(16)

#define FLOW_BLANK_DEVICE_NAME		"NoDeviceNameSet"
#ifdef MICROCHIP_PIC32
#define FLOW_DEFAULT_DEVICE_TYPE	"WiFire"
#else
#define FLOW_DEFAULT_DEVICE_TYPE	"ci20"
#endif
#define FLOW_DEFAULT_REST_ROOT_URL	"http://ws-uat.flowworld.com"
#define FLOW_DEFAULT_OAUTH_KEY		"Ph3bY5kkU4P6vmtT"
#define FLOW_DEFAULT_OAUTH_SECRET	"Sd1SVBfYtGfQvUCR"



#endif	/* __FLOW_SETTINGS_H_ */

