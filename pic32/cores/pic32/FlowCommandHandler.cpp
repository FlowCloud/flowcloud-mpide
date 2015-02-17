//************************************************************************
//*	FlowCommandHandler.cpp
//*		Author: Simon Pinfold
//************************************************************************

#include <FlowCommandHandler.h>
#include "flow/flow_console.h"
#include <string.h>
extern "C"
{
  #include <flow/flowcore.h>
}

CommandHandler::CommandHandler()
{
	callbackCount = 0;
}

bool CommandHandler::attach(char *command, CommandCallbackFunction callback)
{
	FlowConsole_Printf("Attaching command handler for \"%s\"\r\n", command);
	bool added = false;
	if (callbackCount < MAXCALLBACKS)
	{
		strncpy(callbacks[callbackCount].command, command, COMMAND_MAX_LENGTH);
		callbacks[callbackCount++].callback = callback;
		added = true;
	}
	return added;
}

bool CommandHandler::handleCommand(char* command, ReadableXMLNode &params, XMLNode &response)
{
	bool handled = false;
	for(int i = 0; i < callbackCount; ++i)
	{
		size_t callbackCommandLength = strlen(callbacks[i].command);
		if (strncmp(command, callbacks[i].command, callbackCommandLength) == 0
				&& strlen(command) == callbackCommandLength)
		{
			callbacks[i].callback(params, response);

			handled = true;
			break;
		}
	}
	return handled;
} 

CommandHandler FlowCommandHandler;
