
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

#include "FlowCommandHandler.h"

#include "flow/flow_console.h"

extern "C" {
	#include <flow/app/string_builder.h>
	#include <flow/app/device_serial.h>

	// XML parser and treebuilder
	#include <flow/core/xmlparser.h>
	#include <flow/core/xmltree.h>

	#include <flow/flowcore.h>
	#include <flow/flowmessaging.h>

	#include <flow/core/flow_time.h>
	#include <flow/core/flow_timer.h>
	#include <flow/core/flow_task_scheduler.h>
}

typedef struct
{
	char*	DeviceID;
	char*	DeviceName;
	char*	DeviceMACAddress;
	char*	DeviceIdentity;
	bool	IsThisDevice;
} OwnedDevice;


static bool _DeviceIsOnline = false;
static FlowSemaphore _DeviceOnlineStatusLock = NULL;

void APP_SetDeviceIsOnline(bool deviceOnline)
{
	if (_DeviceOnlineStatusLock)
		FlowSemaphore_Wait(_DeviceOnlineStatusLock, 1);

	_DeviceIsOnline = deviceOnline;
	//_ForcePresencePublish = true;

	if (_DeviceOnlineStatusLock)
		FlowSemaphore_Release(_DeviceOnlineStatusLock, 1);
}

void MessageReceived (FlowMessagingMessage message)
{
	char *content =  FlowMessagingMessage_GetContent(message);
	int contentLength =  FlowMessagingMessage_GetContentLength(message);
	char *otherCommandsResponse = NULL;
	// Setup xml parser to buld tree to navigate
	// run the parser, find what type of command it was
	TreeNode rootNode = TreeNode_ParseXML((uint8_t*) content, contentLength, true);
	if (rootNode)
	{
		// Check whether the command was for us
		TreeNode node = TreeNode_Navigate(rootNode, "command/to");
		char* cmdTo = (char*) TreeNode_GetValue(node);
		if (node && strcmp(g_DeviceAoR, cmdTo) == 0)
		{			
			char *cmdFrom = NULL, *cmdRequestID = NULL, *cmdRequestClientID = NULL, *cmdDetails = NULL;
			TreeNode cmdParams = NULL;

			node = TreeNode_Navigate(rootNode, "command/from");
			if(node)
				cmdFrom = (char*) TreeNode_GetValue(node);

			node = TreeNode_Navigate(rootNode, "command/requestid");
			if(node)
				cmdRequestID = (char*) TreeNode_GetValue(node);

			node = TreeNode_Navigate(rootNode, "command/clientid");
			if(node)
				cmdRequestClientID = (char*) TreeNode_GetValue(node);

			node = TreeNode_Navigate(rootNode, "command/details");
			if (!node) 
				node = TreeNode_Navigate(rootNode, "command/commandtype"); // allow commandtype instead of details as the name
			if(node)
				cmdDetails = (char*) TreeNode_GetValue(node);

			cmdParams = TreeNode_Navigate(rootNode, "command/commandparams");
			
			if (cmdTo && cmdFrom && cmdRequestID && cmdRequestClientID && cmdDetails)
			{
				XMLNode response("response");
				{
					XMLNode &sent = response.addChild("sent");
					sent.addAttribute("type", "datetime");
					#define DATETIME_FIELD_LENGTH 32
					char datetimeStr[DATETIME_FIELD_LENGTH];
					time_t currentDateTimeSeconds;
					Flow_GetTime(&currentDateTimeSeconds);
					struct tm *currentDateTimeUTC = gmtime(&currentDateTimeSeconds);
					strftime(datetimeStr, DATETIME_FIELD_LENGTH, "%Y-%m-%dT%H:%M:%SZ", currentDateTimeUTC);
					sent.setContent(datetimeStr);

					XMLNode &to = response.addChild("to");
					to.setContent(cmdFrom);

					XMLNode &from = response.addChild("from");
					from.setContent(g_DeviceAoR);

					XMLNode &requestclientid = response.addChild("requestclientid");
					requestclientid.addAttribute("type", "integer");
					requestclientid.setContent(cmdRequestClientID);

					XMLNode &clientid = response.addChild("clientid");
					clientid.addAttribute("type", "integer");
					clientid.setContent(cmdRequestID);
				}

				XMLNode &responsecode = response.addChild("responsecode");

				XMLNode &responseparams = response.addChild("responseparams");

				ReadableXMLNode *paramsNode;
				if (cmdParams && TreeNode_GetChild(cmdParams, 0))
				{
					paramsNode = new ReadableXMLNode(TreeNode_GetChild(cmdParams, 0));
				} 
				else
				{
					paramsNode = new ReadableXMLNode("commandparams");
				}

				if (FlowCommandHandler.handleCommand(cmdDetails, *paramsNode, responseparams))
				{
					responsecode.setContent("OK");
				} 
				else 
				{
					responsecode.setContent("UNKNOWN_COMMAND");
				}

				delete paramsNode;

				StringBuilder responseStringBuilder = StringBuilder_New(512);
				responseStringBuilder = StringBuilder_Append(responseStringBuilder, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
				response.appendTo(responseStringBuilder);

				if(!FlowMessaging_ReplyToMessage(message, "text/plain", (char *)StringBuilder_GetCString(responseStringBuilder), StringBuilder_GetLength(responseStringBuilder), 60))
					FlowConsole_Printf("Error: Sending command response failed...");

				StringBuilder_Free(&responseStringBuilder);
			}

		}
	}
	// else, not a command for us

	// Fell the tree
	Tree_Delete(rootNode);
	rootNode = NULL;
}


bool SetupFlowSubscriptions (void)
{

	bool result = true;

	/* Register own asynchronous-message callback to receive incoming commands */
	FlowMessaging_SetMessageReceivedListenerForDevice(MessageReceived);

	// Test code -- not required for Flow Starter App
	//	/* Register own device-presence callback to receive own presence updates */
	//	if (!FlowMessaging_subscribe(profile, g_DeviceAoR, FLOW_MESSAGING_EVENTCATEGORY_DEVICE_PRESENCE, (char *) "", 3600, flowEventCallback))
	//	{
	//		FlowConsole_Printf("\n\rError: Subscription to own device-presence failed");
	//		result = false;
	//	}

	return result;
}

bool PublishDevicePresence(void)
{
	bool result = false;


	if (g_DeviceAoR && ConfigStore_Config_IsValid())
	{
		StringBuilder doc = StringBuilder_New(256);

		// Presence-doc Header
		doc = StringBuilder_Append(doc, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
		doc = StringBuilder_Append(doc, "<presence xmlns=\"urn:ietf:params:xml:ns:pidf\" xmlns:wifire_starterapp=\"com.imgtec.flow\" entity=\"");
		doc = StringBuilder_Append(doc, g_DeviceAoR);
		doc = StringBuilder_Append(doc, "\">");

		// Standard tuple
		doc = StringBuilder_Append(doc, "<tuple id=\"standard\"><status><basic>");
		if (_DeviceIsOnline)
			doc = StringBuilder_Append(doc, "open");
		else
			doc = StringBuilder_Append(doc, "closed");
		doc = StringBuilder_Append(doc, "</basic></status></tuple>");

		// Presence-info tuple
		doc = StringBuilder_Append(doc, "<tuple id=\"presence-info\">");
		doc = StringBuilder_Append(doc, "<wifire_starterapp:pres-info>");
		
		doc = StringBuilder_Append(doc, "<datetime>");
		#define DATETIME_FIELD_LENGTH 32
		char datetimeStr[DATETIME_FIELD_LENGTH];
		time_t currentDateTimeSeconds;
		Flow_GetTime(&currentDateTimeSeconds);
		struct tm *currentDateTimeUTC = gmtime(&currentDateTimeSeconds);
		strftime(datetimeStr, DATETIME_FIELD_LENGTH, "%Y-%m-%dT%H:%M:%SZ", currentDateTimeUTC);
		doc = StringBuilder_Append(doc, datetimeStr);
		doc = StringBuilder_Append(doc, "</datetime>");

		doc = StringBuilder_Append(doc, "</wifire_starterapp:pres-info>");
		doc = StringBuilder_Append(doc, "</tuple>");


		// Network-status tuple
		doc = StringBuilder_Append(doc, "<tuple id=\"network-status\"><wifire_starterapp:net-status>");
		doc = StringBuilder_Append(doc, "<wifire_starterapp:ssid>");
		doc = StringBuilder_Append(doc, ConfigStore_GetNetworkSSID());
		doc = StringBuilder_Append(doc, "</wifire_starterapp:ssid>");

		doc = StringBuilder_Append(doc, "<wifire_starterapp:state>");
		if (_DeviceIsOnline)
			doc = StringBuilder_Append(doc, "connected");
		else
			doc = StringBuilder_Append(doc, "disconnected");

		doc = StringBuilder_Append(doc, "</wifire_starterapp:state>");

		doc = StringBuilder_Append(doc, "<wifire_starterapp:rssi_dbm>-100</wifire_starterapp:rssi_dbm>");		// Todo return correct signal strength value
		doc = StringBuilder_Append(doc, "</wifire_starterapp:net-status></tuple>");

		// Board-health tuple
		SYS_UPTIME uptime;
		SYS_Uptime(&uptime);
		char uptimeBuf[32];
		memset(uptimeBuf, 0, 32);
		snprintf(uptimeBuf, 32, "%dd:%02dh%02dm%02ds", uptime.Days, uptime.Hours, uptime.Minutes, uptime.Seconds);

		doc = StringBuilder_Append(doc, "<tuple id=\"board-health\">");
		doc = StringBuilder_Append(doc, "<wifire_starterapp:mrf24w-status>");
		doc = StringBuilder_Append(doc, "<wifire_starterapp:status>ok</wifire_starterapp:status>");
		doc = StringBuilder_Append(doc, "</wifire_starterapp:mrf24w-status>");
		doc = StringBuilder_Append(doc, "<wifire_starterapp:wifire-status>");
		doc = StringBuilder_Append(doc, "<wifire_starterapp:status>ok</wifire_starterapp:status>");
		doc = StringBuilder_Append(doc, "<wifire_starterapp:uptime>");
		doc = StringBuilder_Append(doc, uptimeBuf);
		doc = StringBuilder_Append(doc, "</wifire_starterapp:uptime>");
		doc = StringBuilder_Append(doc, "</wifire_starterapp:wifire-status>");		
		doc = StringBuilder_Append(doc, "</tuple>");

		// Presence-doc Footer
		doc = StringBuilder_Append(doc, "</presence>");

		if (doc && FlowMessaging_Publish(FLOW_MESSAGING_TOPIC_DEVICE_PRESENCE, NULL, (char *)StringBuilder_GetCString(doc), StringBuilder_GetLength(doc), PRESENCE_EXPIRY_PERIOD_SECONDS))
		{
			result = true;
		}

		StringBuilder_Free(&doc);		
	}

	return result;
}

void UpdatePresence(FlowTaskID taskID, void *context)
{
	if (!PublishDevicePresence())
		FlowConsole_Printf("\r\nError: Presence update failed\r\n");
}

void Initialise_Flow()
{

	_DeviceOnlineStatusLock = FlowSemaphore_New(1, 0);
	if (!_DeviceOnlineStatusLock)
	{
		FlowConsole_Printf("Warning: OnlineStatus semaphore could not be initialised. Continuing without sempahore.\n\r");
	}

	/* Create device */
	#define serialNumberBufferLen	(17)
	char deviceSerialNumber[serialNumberBufferLen];
	DeviceSerial_GetCpuSerialNumberHexString (deviceSerialNumber, serialNumberBufferLen);

	FlowMemoryManager memoryManager = FlowMemoryManager_New();
	FlowDevice device = NULL;
	if (FlowClient_LoginAsDevice((char*)ConfigStore_GetDeviceType(), (char*)ConfigStore_GetMacAddress(), deviceSerialNumber, NULL, SOFTWARE_VERSION_STRING, (char*)ConfigStore_GetDeviceName(), (char*)ConfigStore_GetRegistrationKey()))
	{
		bool gotDeviceAoR = false;
		device = FlowClient_GetLoggedInDevice(memoryManager);
		if (device)
		{
			FlowService service = FlowDevice_RetrieveFlowMessagingServiceInfo(device);
			if (service)
			{
				FlowServiceSettings serviceSettings = FlowService_RetrieveServiceSettings(service);
				if (serviceSettings)
				{
					g_DeviceAoR = FlowString_Duplicate(FlowServiceSettings_GetIdentity(serviceSettings));
					gotDeviceAoR = true;
				}
			}
		}

		if (gotDeviceAoR)
			FlowConsole_Printf("\n\rLogged-in device's Flow Messaging identity: '%s'\n\r\n\r", g_DeviceAoR);
		else
			FlowConsole_Printf("\n\rFailed to retrieve device's Flow Messaging identity\n\r\n\r");

		APP_SetDeviceIsOnline(true);
		//Flow_ActivityLogWrite(FlowActivityLogLevel_Information, FlowActivityLogCategory_Startup, ActivityLogErrorCode_none, "Device registered successfully");
	}
	else
	{
		FlowConsole_Printf("Device registration failed...\n\r");
		FlowErrorType errorType = Flow_GetLastError();
		if (errorType >= FlowError_BadRequest_Min && errorType <= FlowError_BadRequest_Unknown)
			errorType = FlowError_InvalidArgument;
		if (errorType == FlowError_InvalidArgument || errorType == FlowError_MethodUnavailable || errorType == FlowError_Unauthorised)
		{
				FlowNVS_Set("core.remembermetoken", NULL, 0);
				APP_SoftwareReset(true);
		}
		while (1)
		{
			FlowThread_SleepMilliseconds(NULL, 1000);
		}
	}

	if (device)
	{
		FlowUser owner = FlowDevice_RetrieveOwner(device);
		if (owner)
		{
			if (FlowUser_HasUserID(owner))
			{
				g_OwnerID = FlowString_Duplicate(FlowUser_GetUserID(owner));
			}

			FlowService service = FlowUser_RetrieveFlowMessagingServiceInfo(owner);
			if (service)
			{
				FlowServiceIdentity serviceIdentity = FlowService_RetrieveServiceIdentity(service);
				if (serviceIdentity)
				{
					g_OwnerAoR = FlowString_Duplicate(FlowServiceIdentity_GetIdentity(serviceIdentity));
				}
			}
		}
	}

	FlowMemoryManager_Free(&memoryManager);

	if (!SetupFlowSubscriptions())
		FlowConsole_Printf("\r\nError: Subscribe failed\r\n");

	if (!PublishDevicePresence())
		FlowConsole_Printf("\r\nError: Presence update failed\r\n");

	// Generate a random clientID
	{
		uint16_t clientID = 0;
		time_t currentTime;
		Flow_GetTime(&currentTime);
		uint8_t* mac = (uint8_t*) ConfigStore_GetMacAddress();
		clientID = ((uint16_t)(currentTime & 0xFFFF));
		if (mac)
		{
			unsigned int index;
			for(index = 0; index < 12; index++)
				clientID ^= mac[index];
		}
		sprintf((char*) g_ClientID, "%d" , clientID);
		g_ClientID[CLIENTID_CHAR_LENGTH] = '\0';
	}

	FlowScheduler_ScheduleTask(UpdatePresence, NULL, 20, true);

}

