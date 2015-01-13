/*******************************************************************************
  Dynamic String Header

  File Name:
    dynstring.h

  Summary:
    APIs for manipulating dynamically growing C-strings.

  Description:

 *******************************************************************************/

#ifndef __DYNSTRING_H_
#define __DYNSTRING_H_

/*
 * A dynamically growing string type.
 *
 */

typedef void* StringBuilder;


// Add characters to a dynamic string
StringBuilder StringBuilder_Append(StringBuilder dynString, const char* str);

// Add an signed integer to a dynamic string
StringBuilder StringBuilder_AppendInt(StringBuilder dynString, int value);

// Clear a dynamic string
StringBuilder StringBuilder_Clear(StringBuilder dynString);

// Dispose of a dynamic string
void StringBuilder_Free(StringBuilder *dynString);

// Return a C-string representing the dynamic string content
const char* StringBuilder_GetCString(StringBuilder dynString);

//
// Return the length of the dynamic string content
//
// Returns: string length, or -1 if invalid
int StringBuilder_GetLength(StringBuilder dynString);

// Create a new dynamic string with the specified initial size
// Set 'initialSize' to 0 to use default
StringBuilder StringBuilder_New(unsigned int initialSize);


#endif // __DYNSTRING_H_
