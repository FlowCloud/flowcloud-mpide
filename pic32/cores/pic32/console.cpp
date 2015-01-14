#include "console.h"
	
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
	
static const char* _sys_excep_tbl[16] =
{
	"Int",
	"Reserved",
	"Reserved",
	"Reserved",
	"AdEL",
	"AdES",
	"IBE",
	"DBE",
	"Sys",
	"Bp",
	"RI",
	"CpU",
	"Ov",
	"Tr",
	"Reserved",
	"Reserved",
};

bool _SYS_DEBUG_INIT(int debug_port)
{
	return true;
}

void _SYS_ASSERT(int linenumber, const char* filename, const char* message)
{
	if (g_EnableConsole)
	{
		char buff[SYS_CONSOLE_BUFFER_LEN];
		snprintf(buff, SYS_CONSOLE_BUFFER_LEN, "\nSYS_ASSERT occurred in file %s on line %d. ", filename, linenumber);

		Serial_print(buff);
		Serial_print(message);
	}
	for(;;);
}

void _SYS_ERROR(int linenumber, const char* filename, const char* message)
{
	if (g_EnableConsole)
	{
		char buff[SYS_CONSOLE_BUFFER_LEN];

		snprintf(buff, SYS_CONSOLE_BUFFER_LEN, "\nSYS_ERROR occurred in file %s on line %d. ", filename, linenumber);

		Serial_print(buff);
		Serial_print(message);
	}
}

void _SYS_ERROR_PRINT(SYS_ERROR_LEVEL level, const char* format, ...)
{
	char buff[SYS_CONSOLE_BUFFER_LEN];
		va_list args;
		if( (level) <= SYSTEM_CURRENT_ERROR_LEVEL && g_EnableConsole){
				va_start( args, format );
				snprintf(buff, SYS_CONSOLE_BUFFER_LEN, "\nSYS_ERROR_PRINT issued: ");
				Serial_print(buff);
				vsnprintf(buff, SYS_CONSOLE_BUFFER_LEN, format, args);
				Serial_print(buff);
				va_end( args );
		}
}

void _SYS_PRINT(const char* format, ...)
{
	char buff[SYS_CONSOLE_BUFFER_LEN];
	va_list args;
	va_start( args, format );
		
	if (g_EnableConsole)
	{
		snprintf(buff, SYS_CONSOLE_BUFFER_LEN, "\nSYS_PRINT issued:");
			Serial_print(buff);
			vsnprintf(buff, SYS_CONSOLE_BUFFER_LEN, format, args);
			Serial_print(buff);
	}

	va_end( args );
}

bool _SYS_CONSOLE_INIT(int console_port)
{
	return true;
}

void _SYS_CONSOLE_PRINT(const char* format, ...)
{
	va_list arg_list;
	char buff[SYS_CONSOLE_BUFFER_LEN];

	va_start(arg_list, format);
	vsnprintf(buff, SYS_CONSOLE_BUFFER_LEN, format, arg_list);

	if (g_EnableConsole) 
	{
		Serial_print(buff);
	}

	va_end(arg_list);
}

void _SYS_CONSOLE_MESSAGE(const char* msg)
{
	if (g_EnableConsole) 
	{
		Serial_print(msg);
	}
}

bool _SYS_CONSOLE_DATA_RDY()
{
	bool ready = false;
	if (g_EnableConsole && g_EnableConsoleInput)
	{
		ready = Serial_available() > 0;
	}
	return ready;
}

char _SYS_CONSOLE_GETC()
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

void _SYS_CONSOLE_PUTC(char c)
{
	if (g_EnableConsole)
	{
		Serial_write(c);
	}
}

int _SYS_CONSOLE_GETLINE(char* buffer, int length)
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

int _SYS_CONSOLE_SCANF(const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);
	if (g_EnableConsole && g_EnableConsoleInput)
	{
		int i=0;
		int result;
		char buff[SYS_CONSOLE_BUFFER_LEN];
		
		while(i < SYS_CONSOLE_BUFFER_LEN)
		{
			buff[i] = _SYS_CONSOLE_GETC();
			_SYS_CONSOLE_PUTC(buff[i]);
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
