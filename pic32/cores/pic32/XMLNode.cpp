//************************************************************************
//*	XMLNode.cpp
//*		Author: Simon Pinfold
//************************************************************************

//TODO: license

#include <XMLNode.h>
#include <string.h>

#define abs(x) ((x)<0 ? -(x) : (x))

extern "C" void _SYS_CONSOLE_PRINT(const char* format, ...);

void doubleToStr(char *str, size_t len, double value, int places)
{
	int intValue = int(value);
	if (places > 0)
	{
		int decimalPart = abs(int((value - intValue)*places));
		snprintf(str, len, "%d.%d", intValue, decimalPart);
	} else 
	{
		snprintf(str, len, "%d", intValue);
	}
}

XMLNodeAttribute::XMLNodeAttribute(char *_name, char *_value)
{
	strncpy(name, _name, NAME_SIZE);
	strncpy(value, _value, NAME_SIZE);
}

XMLNodeAttribute::XMLNodeAttribute(char *_name, int _value)
{
	strncpy(name, _name, NAME_SIZE);
	snprintf(value, NAME_SIZE, "%d", _value);
}

XMLNodeAttribute::XMLNodeAttribute(char *_name, double _value, int places)
{
	strncpy(name, _name, NAME_SIZE);
	doubleToStr(value, NAME_SIZE, _value, places);
}



StringBuilder XMLNodeAttribute::appendTo(StringBuilder builder)
{
	builder = StringBuilder_Append(builder, " ");
	builder = StringBuilder_Append(builder, name);
	builder = StringBuilder_Append(builder, "=\"");
	builder = StringBuilder_Append(builder, value);
	builder = StringBuilder_Append(builder, "\"");
	return builder;
}

XMLNode::XMLNode(char *_name) : childrenSize(0), childCount(0), 
								attributesSize(0), attributeCount(0),
								children(NULL), attributes(NULL)
{
	_SYS_CONSOLE_PRINT("* XMLNode::XMLNode(%s)\r\n", _name);
	strncpy(name, _name, NAME_SIZE);
	content[0] = '\0';
}


XMLNode::~XMLNode()
{
	_SYS_CONSOLE_PRINT("* XMLNode(\"%s\")::~XMLNode()\r\n", name);

	_SYS_CONSOLE_PRINT("<%s>\tDeleting %d attributes\r\n", name, attributeCount);
	for (int i = 0; i < attributeCount; ++i)
	{
		_SYS_CONSOLE_PRINT("<%s>\tDeleting attribute %d\r\n", name, i);
		delete attributes[i];
	}
	if (attributes)
	{
		_SYS_CONSOLE_PRINT("<%s>\tFreeing attribute list\r\n", name);
		Flow_MemFree((void**)&attributes);
		_SYS_CONSOLE_PRINT("<%s>\tattribute list %s\r\n", name, attributes ? "NOT NULL" : "NULL");
	}

	_SYS_CONSOLE_PRINT("<%s>\tDeleting %d children\r\n", name, childCount);
	for (int i = 0; i < childCount; ++i)
	{
		_SYS_CONSOLE_PRINT("<%s>\tDeleting child %d\r\n", name, i);
		delete children[i];
	}
	if (children)
	{
		_SYS_CONSOLE_PRINT("<%s>\tFreeing child list\r\n", name);
		Flow_MemFree((void**)&children);
		_SYS_CONSOLE_PRINT("<%s>\tchild list %s\r\n", name, children ? "NOT NULL" : "NULL");
	}
}

void XMLNode::checkArraySizes()
{
	_SYS_CONSOLE_PRINT("* XMLNode(\"%s\")::checkArraySizes()\r\n", name);
	if (childCount == childrenSize)
	{
		// if the array is 0 then allocate space for a child else double the size
		childrenSize = childrenSize ? childrenSize*2 : 1;
		_SYS_CONSOLE_PRINT("<%s>\tResizing child list to %d (%d bytes)\r\n", name, childrenSize, childrenSize * sizeof(XMLNode*));
		children = (XMLNode**)Flow_MemRealloc(children, childrenSize * sizeof(XMLNode*));
	}
	if (attributeCount == attributesSize)
	{
		attributesSize = attributesSize ? attributesSize*2 : 1;
		_SYS_CONSOLE_PRINT("<%s>\tResizing attribute list to %d (%d bytes)\r\n", name, attributesSize, attributesSize * sizeof(XMLNodeAttribute*));
		attributes = (XMLNodeAttribute**)Flow_MemRealloc(attributes, attributesSize * sizeof(XMLNodeAttribute*));
	}
}

XMLNode &XMLNode::addChild(char *childName)
{
	_SYS_CONSOLE_PRINT("* XMLNode(\"%s\")::addChild(\"%s\")\r\n", name, childName);
	checkArraySizes();
	XMLNode *child = new XMLNode(childName);
	children[childCount++] = child;
	return *child;
}


XMLNodeAttribute XMLNode::addAttribute(char *_name, char *_value)
{
	checkArraySizes();
	XMLNodeAttribute *attribute = new XMLNodeAttribute(_name, _value);
	attributes[attributeCount++] = attribute;
	return *attribute;
}

XMLNodeAttribute XMLNode::addAttribute(char *_name, int _value)
{
	checkArraySizes();
	XMLNodeAttribute *attribute = new XMLNodeAttribute(_name, _value);
	attributes[attributeCount++] = attribute;
	return *attribute;
}

XMLNodeAttribute XMLNode::addAttribute(char *_name, double _value, int places)
{
	checkArraySizes();
	XMLNodeAttribute *attribute = new XMLNodeAttribute(_name, _value, places);
	attributes[attributeCount++] = attribute;
	return *attribute;
}


void XMLNode::setContent(char *_content)
{
	strncpy(content, _content, CONTENT_SIZE);
	_SYS_CONSOLE_PRINT("* XMLNode(%s)::setContent(%s)\r\n", name, content);
}

void XMLNode::setContent(int _content)
{
	snprintf(content, CONTENT_SIZE, "%d", _content);
	_SYS_CONSOLE_PRINT("* XMLNode(%s)::setContent(%s)\r\n", name, content);
}

void XMLNode::setContent(double _content, int places)
{
	doubleToStr(content, CONTENT_SIZE, _content, places);
	_SYS_CONSOLE_PRINT("* XMLNode(%s)::setContent(%s)\r\n", name, content);
}


StringBuilder XMLNode::appendTo(StringBuilder builder)
{
	_SYS_CONSOLE_PRINT("* appendTo\r\n");
	builder = StringBuilder_Append(builder, "<");
	builder = StringBuilder_Append(builder, name);
	for (int i = 0; i < attributeCount; ++i)
	{
		builder = attributes[i]->appendTo(builder);
	}
	builder = StringBuilder_Append(builder, ">");

	builder = StringBuilder_Append(builder, content);

	for (int i = 0; i < childCount; ++i)
	{
		builder = children[i]->appendTo(builder);
	}

	builder = StringBuilder_Append(builder, "</");
	builder = StringBuilder_Append(builder, name);
	builder = StringBuilder_Append(builder, ">");

	return builder;
}



