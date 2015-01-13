/*******************************************************************************

  Summary:
  Simple command processor header file
    
  Description:
  This file contains a simple command processor interface file.
  It exposes the functions available to a client. 
    
*******************************************************************************/

/*******************************************************************************
File Name:	system_command.h
Copyright ?2012 released Microchip Technology Inc.  All rights
reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS?WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

#ifndef _SYSTEM_COMMAND_H_
#define _SYSTEM_COMMAND_H_

#include <stdint.h>
#include <stdbool.h>


#define         _SYS_CMD_MAX_LENGTH  255

// CMD IO devices

// a system character device handle
typedef const void* _CMDIO_DEV_HANDLE;

// message function
typedef void (*_CMDIO_DEV_MSG)(const void* cmdIoParam, const char* str);

// print function
typedef void (*_CMDIO_DEV_PRINT)(const void* cmdIoParam, const char* format, ...);

// put single char function
typedef void (*_CMDIO_DEV_PUTC)(const void* cmdIoParam, char c);

// data available
typedef bool (*_CMDIO_DEV_DATA_RDY)(const void* cmdIoParam);

// get single data
typedef char (*_CMDIO_DEV_GETC)(const void* cmdIoParam);


typedef struct
{
	// Msg function
	_CMDIO_DEV_MSG msg;
	
    // print function
    _CMDIO_DEV_PRINT print;

    // put single char function
    _CMDIO_DEV_PUTC  putc;

    // data available
    _CMDIO_DEV_DATA_RDY  isRdy;

    // get single data
    _CMDIO_DEV_GETC      getc;
}_CMDIO_DEV_API;   

typedef struct CMDIO_DEV_NODE
{
	//char name[10];				// IO device name
	//unsigned short 	 index;				// Index in cmd lists
	char*            cmdPnt;
	char*            cmdEnd; 
	char             cmdBuff[_SYS_CMD_MAX_LENGTH+1];
	const _CMDIO_DEV_API*  pCmdApi;	// Cmd IO APIs
    const void*         cmdIoParam; // channel specific parameter
	struct CMDIO_DEV_NODE* next; 
}_CMDIO_DEV_NODE;


typedef struct 
{
	int num;
	_CMDIO_DEV_NODE* head;
	_CMDIO_DEV_NODE* tail;
}_CMDIO_DEV_LST;

// Interface definitions

// command processing function
// returns 0 if it wants to end the command interpreter
typedef int (*_SYS_CMD_FNC)(_CMDIO_DEV_NODE* pCmdIO, int argc, char **argv);

typedef struct
{
    const char*     cmdStr;         // string identifying the command
    _SYS_CMD_FNC    cmdFnc;         // function to execute for this command
    const char*     cmdDescr;       // simple command description
}_SYS_CMD_DCPT;       // a simple command descriptor

typedef struct
{
    int                     nCmds;          // number of commands available in the table
    const _SYS_CMD_DCPT*    pCmd;           // pointer to an array of command descriptors
    const char*             cmdGroupName;   // name identifying the commands
    const char*             cmdMenuStr;    // help string
}_SYS_CMD_DCPT_TBL;    // table containing the supported commands       

// Interface functions

// command processor initialization function
// displays a welcome message
bool SYS_COMMAND_INIT(void);

_CMDIO_DEV_NODE* SYS_CMDIO_GET_HANDLE(short num);

_CMDIO_DEV_NODE* SYS_CMDIO_ADD(const _CMDIO_DEV_API* opApi, const void* cmdIoParam);

bool SYS_CMDIO_DELETE(_CMDIO_DEV_NODE* pDevNode);

// add user command group
bool    SYS_COMMAND_ADDGRP(const _SYS_CMD_DCPT* pCmdTbl, int nCmds, const char* groupName, const char* menuStr);

// runs and interprets the commands
// returns false when the command processor quits
bool     SYS_COMMAND_TASK(void);

#endif


