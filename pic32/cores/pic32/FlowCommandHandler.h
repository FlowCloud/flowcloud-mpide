//************************************************************************
//*	FlowCommandHandler.h
//*		Author: Simon Pinfold
//************************************************************************

//TODO: license

#ifndef FlowCommandHandler_h
#define FlowCommandHandler_h

#include "XMLNode.h"

#define COMMAND_HANDLED_OK "OK"

#define MAXCALLBACKS 50

typedef void (*CommandCallbackFunction)(XMLNode &response);

typedef struct
{
	const char *command;
	CommandCallbackFunction callback;
} CommandBinding;

/**
 * \class CommandHandler
 *
 * \brief Allows commands to be be registered for certain command strings
 *
 * This class holds a mapping between command strings and a callback function
 * for when that command string is matched as an incoming command.
 *
 */
class CommandHandler
{
public:
	CommandHandler();

	/** register a new callback for the specified command string
	  * @param command the string to trigger the callback
	  * @param callback the function to call when the command string is encountered */
	bool attach(const char *command, CommandCallbackFunction callback); 

	/** handle the command 
	  * @param command the command to handle
	  * @param response the buffer to write a response into
	  * @return true if the command was recognized, false otherwise */
	bool handleCommand(char* command, XMLNode &response);
private:
	int callbackCount;
	CommandBinding callbacks[MAXCALLBACKS];
};

/** The \ref CommandHandler used for handling command from Flow */
extern CommandHandler FlowCommandHandler;

#endif