#ifndef __HTTP_HEADER_H_
#define __HTTP_HEADER_H_


/****************************************************************************
  Section:
    HTTP Definitions
 */



//Supported Methods
typedef enum
{
	HTTP_METHOD_UNKNOWN = 0u,      // UNKNOWN command
    HTTP_METHOD_GET,               // GET command is being processed
    HTTP_METHOD_POST,              // POST command is being processed

} HTTP_METHOD;

// Name-Value pair
typedef struct
{
	uint8_t*		name;
	uint8_t*		value;
} nameValue;


// Doubly-linked list
struct listType;
typedef struct
{
	void*				node;
	struct listType*	last;
	struct listType*	next;
} listType;


typedef struct
{
	HTTP_METHOD		method;
	uint8_t*		url;
	listType*		headers;
	listType*		queryString;
	HTTP_STATUS		status;
	int32_t			endpointID;

	void*			postBody;
	uint32_t		postBodyLength;
} HTTP_REQUEST_INFO;

typedef struct
{
	void*			body;
	uint16_t		length;
} HTTP_RESPONSE_INFO;



// File type definitions
typedef enum
{
    HTTP_CONTENTTYPE_TXT = 0u,				// File is a text document
    HTTP_CONTENTTYPE_HTM,					// File is HTML (extension .htm)
    HTTP_CONTENTTYPE_HTML,					// File is HTML (extension .html)
    HTTP_CONTENTTYPE_CGI,					// File is HTML (extension .cgi)
    HTTP_CONTENTTYPE_XML,					// File is XML (extension .xml)
    HTTP_CONTENTTYPE_CSS,					// File is stylesheet (extension .css)
    HTTP_CONTENTTYPE_GIF,					// File is GIF image (extension .gif)
    HTTP_CONTENTTYPE_PNG,					// File is PNG image (extension .png)
    HTTP_CONTENTTYPE_JPG,					// File is JPG image (extension .jpg)
    HTTP_CONTENTTYPE_JAVA,					// File is java (extension .java)
    HTTP_CONTENTTYPE_WAV,					// File is audio (extension .wav)

	HTTP_CONTENTTYPE_FLOW_DEVICEINFO,		// Flow DeviceInfo
	HTTP_CONTENTTYPE_FLOW_NETWORKCONFIG,	// Flow Network-config
	HTTP_CONTENTTYPE_FLOW_ACTIVITYLOG,		// Flow Device Activity Log
	HTTP_CONTENTTYPE_FLOW_LOGGINGCONFIG,	// Flow Logging Config

    HTTP_CONTENTTYPE_UNKNOWN				// File type is unknown

} HTTP_CONTENTTYPE_TYPE;




#define AsNameValuePtr(arg)	((nameValue*)arg)

/****************************************************************************
  Section:
    Function Prototypes
 */



/*****************************************************************************
  Function:
    HTTP_REQUEST_INFO* TCPIP_HTTP_CurrentConnectionRequestInfoGet(HTTP_CONN_HANDLE connHandle);

  Summary:
    Gets information about an HTTP request.

  Description:
    This function returns the a pointer to a structure containing HTTP request context information.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Return Values:
    a poiunter to a HTTP_REQUEST_INFO structure.

  Example:
  <code>
    HTTP_REQUEST_INFO* currRequest =  TCPIP_HTTP_CurrentConnectionRequestInfoGet(connHandle);
  </code>

  Remarks:
    None.
 */
HTTP_REQUEST_INFO*		TCPIP_HTTP_CurrentConnectionRequestInfoGet(HTTP_CONN_HANDLE connHandle);


#endif  // __HTTP_HEADER_H_

