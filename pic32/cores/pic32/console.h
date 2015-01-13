#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>

#if (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

extern bool g_EnableConsole;
extern bool g_EnableConsoleInput;

// required for the C implementation of _SYS_* to call the C++ functions on Serial
void Serial_print(const char *str);
int Serial_available(void);
int Serial_read(void);
void Serial_write(uint8_t);


#ifdef __cplusplus
extern "C" {
#endif

#define SYS_CONSOLE_BUFFER_LEN 1024

typedef enum 
{
    /* Errors that have the potential to cause a system crash. */
    SYS_ERROR_FATAL     = 0,

    /* Errors that have the potential to cause incorrect behavior. */
    SYS_ERROR_ERROR     = 1,

    /* Warnings about potentially unexpected behavior or side effects. */
    SYS_ERROR_WARNING   = 2,

    /* Information helpful to understanding potential errors and warnings. */
    SYS_ERROR_INFO      = 3,

    /* Verbose information helpful during debugging and testing. */
    SYS_ERROR_DEBUG     = 4

} SYS_ERROR_LEVEL;

#define SYSTEM_CURRENT_ERROR_LEVEL SYS_ERROR_WARNING

bool _SYS_DEBUG_INIT(int debug_port);

void _SYS_ASSERT(int linenumber, const char* filename, const char* message);

void _SYS_ERROR(int linenumber, const char* filename, const char* message);

void _SYS_ERROR_PRINT(SYS_ERROR_LEVEL level, const char* format, ...);

void _SYS_PRINT(const char* format, ...);

bool _SYS_CONSOLE_INIT(int console_port);

void _SYS_CONSOLE_PRINT(const char* format, ...);

void _SYS_CONSOLE_MESSAGE(const char* msg);

bool _SYS_CONSOLE_DATA_RDY();

char _SYS_CONSOLE_GETC();

void _SYS_CONSOLE_PUTC(char c);

int _SYS_CONSOLE_GETLINE(char* line, int bufferLen);

int _SYS_CONSOLE_SCANF(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif