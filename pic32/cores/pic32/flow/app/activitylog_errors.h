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

#ifndef ACTIVITYLOG_ERRORS_H_
#define ACTIVITYLOG_ERRORS_H_

#include "flow/messaging/flow_messagingerrors.h"


// FlowMessaging error codes used by flow_activitylog
typedef enum
{
	ActivityLogErrorCode_none = FLOWMESSAGINGERRORCODE_APP,		// 100
	ActivityLogErrorCode_wifiNoConnect,							// 101 - no connect after timeout (WiFi is off or SSID is wrong)
	ActivityLogErrorCode_wifiConnectFailed,						// 102 - connect failed (generic problem)
	ActivityLogErrorCode_wifiAuth,								// 103 - authenticate failed (wrong password)
	ActivityLogErrorCode_wifiSecurity,							// 104 - wrong security settings (wpa, wpa2 etc.)
	ActivityLogErrorCode_wifiLost,								// 105 - Beacon lost
	ActivityLogErrorCode_ipAddress,								// 106 - IP address timeout, DHCP failed
	ActivityLogErrorCode_badConfig,								// 107 - bad configuration
	ActivityLogErrorCode_wifiUnspecified,						// 108 - unspecified WiFi error (possibly device not allowed in whitelist?)
	ActivityLogErrorCode_wifiOutOfRx							// 109 - WiFi driver unrecoverable 'Out of Rx' error

} ActivityLogErrorCode;


#endif /* ACTIVITYLOG_ERRORS_H_ */
