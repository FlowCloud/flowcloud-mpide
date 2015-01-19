//************************************************************************
//*	FlowCommandHandler.cpp
//*		Author: Simon Pinfold
//************************************************************************

//TODO: license

#include <FlowCommandHandler.h>
#include <string.h>

CommandHandler::CommandHandler()
{
	callbackCount = 0;
}

extern "C"
{
  void _SYS_CONSOLE_PRINT(const char* format, ...);
  #include <flow/flowcore.h>
}

bool CommandHandler::attach(char *command, CommandCallbackFunction callback)
{
	_SYS_CONSOLE_PRINT("Attaching command handler for \"%s\"\r\n", command);
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
	_SYS_CONSOLE_PRINT("CommandHandler::handleCommand(\"%s\", %p)\r\n", command, &response);
	bool handled = false;
	for(int i = 0; i < callbackCount; ++i)
	{
		size_t callbackCommandLength = strlen(callbacks[i].command);
		if (strncmp(command, callbacks[i].command, callbackCommandLength) == 0
				&& strlen(command) == callbackCommandLength)
		{
			_SYS_CONSOLE_PRINT("\tCalling command handler for \"%s\"\r\n", callbacks[i].command);
			callbacks[i].callback(params, response);

			handled = true;
			break;
		}
	}
	return handled;
} 

CommandHandler FlowCommandHandler;
