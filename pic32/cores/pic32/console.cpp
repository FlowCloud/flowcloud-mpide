#include "console.h"

#include <stdarg.h>
	
// allow _SYS_* .c functions to call Serial.* functions
void Serial_print(const char *str)
{
	Serial.print(str);
}
int Serial_available(void)
{
	return Serial.available();
}
int Serial_read(void)
{	
	return Serial.read();
}
void Serial_write(uint8_t c)
{
	Serial.write(c);
}


bool g_EnableConsole = false;
bool g_EnableConsoleInput = false;

extern "C" 
{

bool FlowConsole_Init(void)
{
	return true;
}

void FlowConsole_Printf(const char* format, ...)
{
	va_list arg_list;
	char buff[FLOW_CONSOLE_BUFFER_LEN];

	va_start(arg_list, format);
	vsnprintf(buff, FLOW_CONSOLE_BUFFER_LEN, format, arg_list);

	if (g_EnableConsole) 
	{
		Serial_print(buff);
	}

	va_end(arg_list);
}

void FlowConsole_Puts(const char* msg)
{
	if (g_EnableConsole) 
	{
		Serial_print(msg);
	}
}

bool FlowConsole_Ready()
{
	bool ready = false;
	if (g_EnableConsole && g_EnableConsoleInput)
	{
		ready = Serial_available() > 0;
	}
	return ready;
}

char FlowConsole_Getc()
{
	char c = '\0';
	if (g_EnableConsole && g_EnableConsoleInput)
	{
		int ci = -1;
		do {
			ci = Serial_read();
		} while (ci == -1);
		c = ci;
	}
	return c;
}

void FlowConsole_Putc(char c)
{
	if (g_EnableConsole)
	{
		Serial_write(c);
	}
}

int FlowConsole_Getline(char* buffer, int length)
{
	if (g_EnableConsole && g_EnableConsoleInput)
	{
		// Adapted from Arduino's Stream.cpp (not MPIDE's Stream.cpp as this has a bug where the null terminator can be written past the end of the buffer)

		int index = 0;
		*buffer = 0;
		while(index < length-1 )
		{
			int c = Serial_read();
			if( c <= 0 )
			{
				return 0; // timeout returns 0 !
			}
			else if( c == '\r' || c == '\n')
			{
				buffer[index] = 0; // terminate the string
				return index; // data got successfully
			}
			else
			{
				buffer[index++] = (char)c;
			}
		}
		buffer[index] = 0;
		return index;
	}
	return 0;
}

int FlowConsole_Scanf(const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);
	if (g_EnableConsole && g_EnableConsoleInput)
	{
		int i=0;
		int result;
		char buff[FLOW_CONSOLE_BUFFER_LEN];
		
		while(i < FLOW_CONSOLE_BUFFER_LEN)
		{
			buff[i] = FlowConsole_Getc();
			Serial_write(buff[i]);
			if(buff[i] == '\n' || buff[i] == '\r')
				break;
			i++;
		}
		result = vsscanf(buff, format, arg_list);
		return result;
	}
	va_end(arg_list);
	return 0;
}

//These are duplicates of the above functions for deprecation.

void SYS_CONSOLE_MESSAGE(const char * message)
{
	if (g_EnableConsole) 
	{
		Serial_print(message);
	}
}

void SYS_CONSOLE_PRINT(const char* format, ...)
{
	va_list arg_list;
	char buff[FLOW_CONSOLE_BUFFER_LEN];

	va_start(arg_list, format);
	vsnprintf(buff, FLOW_CONSOLE_BUFFER_LEN, format, arg_list);

	if (g_EnableConsole) 
	{
		Serial_print(buff);
	}

	va_end(arg_list);
}

}