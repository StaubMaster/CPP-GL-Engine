#include "Graphics/Attribute/Base/Location.hpp"
#include "Graphics/Buffer/Array.hpp"



Attribute::Location::~Location() { }

Attribute::Location::Location(
	Buffer::Array & buffer,
	GL::AttributeType type,
	unsigned int size0,
	unsigned int size1,
	unsigned int offset
)
	: Type(type)
	, Size0(size0)
	, Size1(size1)
	, Offset(offset)
	, Index(-1)
{
	buffer.Attributes.Insert(this);
}

Attribute::Location::Location(const Location & other)
	: Type(other.Type)
	, Size0(other.Size0)
	, Size1(other.Size1)
	, Offset(other.Offset)
	, Index(other.Index)
{ }
Attribute::Location & Attribute::Location::operator=(const Location & other)
{
	Index = other.Index;
	return *this;
}

void Attribute::Location::Change(GL::AttributeLocation index)
{
	Index = index;
}
