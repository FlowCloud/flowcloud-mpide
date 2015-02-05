#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stdint.h>
#include "flow/flow_console.h"

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

#define FLOW_CONSOLE_BUFFER_LEN 1024

#endif