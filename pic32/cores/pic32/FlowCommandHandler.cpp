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

bool CommandHandler::attach(const char *command, CommandCallbackFunction callback)
{
	_SYS_CONSOLE_PRINT("Attaching command handler for \"%s\"\r\n", command);
	bool added = false;
	if (callbackCount < MAXCALLBACKS)
	{
		callbacks[callbackCount].command = command;
		callbacks[callbackCount++].callback = callback;
		added = true;
	}
	return added;
}

bool CommandHandler::handleCommand(char* command, XMLNode &response)
{
	_SYS_CONSOLE_PRINT("CommandHandler::handleCommand(\"%s\", NULL)\r\n", command);
	bool handled = false;
	for(int i = 0; i < callbackCount; ++i)
	{
		size_t callbackCommandLength = strlen(callbacks[i].command);
		if (strncmp(command, callbacks[i].command, callbackCommandLength) == 0
				&& strlen(command) == callbackCommandLength)
		{
			_SYS_CONSOLE_PRINT("\tCalling command handler for \"%s\"\r\n", callbacks[i].command);
			callbacks[i].callback(response);

			handled = true;
			break;
		}
	}
	return handled;
} 

CommandHandler FlowCommandHandler;
