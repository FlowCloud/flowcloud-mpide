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

#ifndef APP_ACTIVITYLOG_H_
#define APP_ACTIVITYLOG_H_

#include <stdbool.h>
#include <stdarg.h>
#include "flow/core/base_types.h"
#include "flow/core/flow_activitylog.h"
#include "flow/messaging/flow_messagingerrors.h"
#ifndef MICROCHIP_PIC32
#include "system_mapping.h"
#endif
#define ACTIVITYLOG_MESSAGE_LENGTH		(120)

typedef struct
{
	uint32	Timestamp;			// Epoch seconds since Jan 1 1970
	uint8	Category;
	uint8	LogLevel;
	uint16	ErrorCode;
	char	Message[ACTIVITYLOG_MESSAGE_LENGTH];	// null terminated
} ActivityLog;

typedef struct
{
	int			RequestCount;		// maximum ActivityLog records to read
	int			NextIndex;			// next index to read (modified by read), -1 = start from first
	bool		ReadDescending;		// true = descending: read newest first, false = ascending: read oldest first
	ActivityLog	*ReadLog;			// must have enough room for requestCount records
} ActivityLogRequest;

/**
 * \brief Initializes the activity log.
 *
 */
bool Flow_ActivityLogInit(void);

/**
 * \brief Erase the activity log.
 */
bool Flow_ActivityLogErase(void);

/**
 * \brief Set ActivityLog system-debug logging mode.
 */
void Flow_ActivityLogSystemMode(FlowActivityLogCategory category);

/**
 * \brief Logs an activity message. Activity messages are stored if logging is enabled for the level and category.
 *
 * @param level importance ofs the message
 * @param category of the message
 * @param szMessage printf-formatted message
 *
 * @return true if message was stored in the activity log
 */
void Flow_ActivityLogWrite(FlowActivityLogLevel level, FlowActivityLogCategory category, int errorCode, char *szMessage, ...);

/**
 * \brief Read activity log entries
 *
 * @param request specifies the activity log records to be copied into readLog buffer
 *
 * @return number of records copied into readLog
 */
int Flow_ActivityLogRead(ActivityLogRequest *request);

/**
 * Dump the activity log to output debug console
 *
 * @param readDescending = true read newest first, false read oldest first
 * @param readCount = maximum entries to dump, 0 = dump all
 *
 * @return actual number of log entries dumped
 */
int Flow_ActivityLogDump(bool readDescending, int readCount);

/**
 * \brief Write activity log record to output debug console
 *
 * @param activityLog record to print
 */
void Flow_ActivityLogPrint(const ActivityLog *activityLog);


#endif /* APP_ACTIVITYLOG_H_ */
