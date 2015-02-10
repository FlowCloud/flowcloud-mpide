//************************************************************************
//*	XMLNode.h
//*		Author: Simon Pinfold
//************************************************************************

#ifndef XMLNode_h
#define XMLNode_h

#include <console.h>
extern "C" {
	#include <flow/app/string_builder.h>
	#include <flow/flowcore.h>
	#include <flow/core/xmltree.h>
}

#define NAME_SIZE (64)
#define CONTENT_SIZE (256)

/**
 * \class XMLNode
 *
 * \brief Represents a single basic node in an XML document
 *
 * This class represents a basic XML node. It may have attributes added, 
 * child nodes added and it's content may be set. It can be serialized
 * by appending it's XML string representation to a StringBuilder.
 *
 */
class XMLNode;

/**
 * \class XMLNodeAttribute
 *
 * \brief Represents a single attribute within an \ref XMLNode
 *
 * This class represents a single mapping between a name and a value for 
 * purposes of holding an attribute for a \ref XMLNode.
 *
 */
class XMLNodeAttribute
{
friend class XMLNode;

public:
	XMLNodeAttribute(const char *_name, const char *_value);
	XMLNodeAttribute(const char *_name, int _value);
	XMLNodeAttribute(const char *_name, double _value, int places);

	~XMLNodeAttribute(){};
protected:

	/** Append the string representation of this attribute to the 
	  * specified StringBuilder */
	StringBuilder appendTo(StringBuilder builder);
private:
	char name[NAME_SIZE+1];
	char value[NAME_SIZE+1];
};

class XMLNode
{
public:
	/// Create a new XML node with the specified name
	XMLNode(const char *_name);
	~XMLNode();
	
	/// Create and add a new XMLNode as a child
	XMLNode &addChild(const char *childName);

	
	/// Add an attribute with the specified name and value
	void addAttribute(const char *name, const char *value);

	/// Add an attribute with the specified name and integer value
	void addAttribute(const char *name, int value);

	/// Add an attribute with the specified name and decimal value, truncated to the specified number of decimal places
	void addAttribute(const char *name, double value, int places);


	/// Set the content to the specified content
	void setContent(const char *content);

	/// Set the content to the specified content
	void setContent(int content);

	/// Set the content to the specified content
	void setContent(double content, int places);

	/// Append the string representation of this XML node with all attributes, contents and children to the specified StringBuilder
	StringBuilder appendTo(StringBuilder builder);

private:
	void checkArraySizes();

	char name[NAME_SIZE+1];
	char content[CONTENT_SIZE+1];

	int childCount;
	int childrenSize;
	XMLNode **children;

	int attributeCount;
	int attributesSize;
	XMLNodeAttribute **attributes;


};

class ReadableXMLNode
{
public:
	ReadableXMLNode(TreeNode _wrap);
	ReadableXMLNode(const char *_name);

	ReadableXMLNode getChild(char *path);

	const char *getName();

	const char *getValue();
	int getIntegerValue();
	double getFloatValue();

private:
	TreeNode wrap;
	const char *name;
};

#endif