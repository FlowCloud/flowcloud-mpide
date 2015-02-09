//************************************************************************
//*	XMLNode.cpp
//*		Author: Simon Pinfold
//************************************************************************

//TODO: license

#include <XMLNode.h>
#include <string.h>

#define abs(x) ((x)<0 ? -(x) : (x))


void doubleToStr(char *str, size_t len, double value, int places)
{
	int intValue = int(value);
	if (places > 0)
	{
		int decimalPart = abs(int((value - intValue)*pow(10, places)));
		snprintf(str, len, "%d.%d", intValue, decimalPart);
	} else 
	{
		snprintf(str, len, "%d", intValue);
	}
}

XMLNodeAttribute::XMLNodeAttribute(const char *_name, const char *_value)
{
	strncpy(name, _name, NAME_SIZE);
	strncpy(value, _value, NAME_SIZE);
}

XMLNodeAttribute::XMLNodeAttribute(const char *_name, int _value)
{
	strncpy(name, _name, NAME_SIZE);
	snprintf(value, NAME_SIZE, "%d", _value);
}

XMLNodeAttribute::XMLNodeAttribute(const char *_name, double _value, int places)
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

XMLNode::XMLNode(const char *_name) : childrenSize(0), childCount(0), 
								attributesSize(0), attributeCount(0),
								children(NULL), attributes(NULL)
{
	strncpy(name, _name, NAME_SIZE);
	content[0] = '\0';
}

XMLNode::~XMLNode()
{

	for (int i = 0; i < attributeCount; ++i)
	{
		delete attributes[i];
	}
	if (attributes)
	{
		Flow_MemFree((void**)&attributes);
	}

	for (int i = 0; i < childCount; ++i)
	{
		delete children[i];
	}
	if (children)
	{
		Flow_MemFree((void**)&children);
	}
}

void XMLNode::checkArraySizes()
{
	if (childCount == childrenSize)
	{
		// if the array is 0 then allocate space for a child else double the size
		childrenSize = childrenSize ? childrenSize*2 : 1;
		children = (XMLNode**)Flow_MemRealloc(children, childrenSize * sizeof(XMLNode*));
	}
	if (attributeCount == attributesSize)
	{
		attributesSize = attributesSize ? attributesSize*2 : 1;
		attributes = (XMLNodeAttribute**)Flow_MemRealloc(attributes, attributesSize * sizeof(XMLNodeAttribute*));
	}
}

XMLNode &XMLNode::addChild(const char *childName)
{
	checkArraySizes();
	XMLNode *child = new XMLNode(childName);
	children[childCount++] = child;
	return *child;
}


void XMLNode::addAttribute(const char *_name, const char *_value)
{
	checkArraySizes();
	XMLNodeAttribute *attribute = new XMLNodeAttribute(_name, _value);
	attributes[attributeCount++] = attribute;
}

void XMLNode::addAttribute(const char *_name, int _value)
{
	checkArraySizes();
	XMLNodeAttribute *attribute = new XMLNodeAttribute(_name, _value);
	attributes[attributeCount++] = attribute;
}

void XMLNode::addAttribute(const char *_name, double _value, int places)
{
	checkArraySizes();
	XMLNodeAttribute *attribute = new XMLNodeAttribute(_name, _value, places);
	attributes[attributeCount++] = attribute;
}


void XMLNode::setContent(const char *_content)
{
	strncpy(content, _content, CONTENT_SIZE);
}

void XMLNode::setContent(int _content)
{
	snprintf(content, CONTENT_SIZE, "%d", _content);
}

void XMLNode::setContent(double _content, int places)
{
	doubleToStr(content, CONTENT_SIZE, _content, places);
}


StringBuilder XMLNode::appendTo(StringBuilder builder)
{
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





ReadableXMLNode::ReadableXMLNode(TreeNode _wrap) :
								wrap(_wrap), name(NULL)
{
}

ReadableXMLNode::ReadableXMLNode(const char *_name) :
								wrap(NULL), name(_name)
{
}

ReadableXMLNode ReadableXMLNode::getChild(char *path)
{
	return ReadableXMLNode(TreeNode_Navigate(wrap, path));
}

const char *ReadableXMLNode::getName()
{
	if (name)
	{
		return name;
	} 
	else
	{
		return TreeNode_GetName(wrap);
	}
}

const char *ReadableXMLNode::getValue()
{
	if (name)
	{
		return "";
	} 
	else
	{
		return (const char*)TreeNode_GetValue(wrap);
	}
}
int ReadableXMLNode::getIntegerValue()
{
	int r;
	sscanf(getValue(), "%d", &r);
	return r;
}
double ReadableXMLNode::getFloatValue()
{
	double r;
	sscanf(getValue(), "%lf", &r);
	return r;
}