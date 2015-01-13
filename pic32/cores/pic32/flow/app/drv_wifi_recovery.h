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

#ifndef _DRV_WIFI_RECOVERY_H
#define _DRV_WIFI_RECOVERY_H

typedef void (*Wifi_FailedCallback)(bool configError);

void Wifi_SetFailedCallback(Wifi_FailedCallback callback);
void Wifi_SetConfigurationConfirmed(bool isConfirmed);

bool WiFi_InitComplete(void);

#endif /* _DRV_WIFI_RECOVERY_H */
