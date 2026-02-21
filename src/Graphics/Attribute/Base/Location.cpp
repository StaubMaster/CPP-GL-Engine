#include "Graphics/Attribute/Base/Location.hpp"



Attribute::Location::~Location() { }

Attribute::Location::Location(
	GL::AttributeType type,
	unsigned int count,
	unsigned int size
)
	: Type(type)
	, Count(count)
	, Size(size)
	, Index(-1)
{ }

Attribute::Location::Location(const Location & other)
	: Type(other.Type)
	, Count(other.Count)
	, Size(other.Size)
	, Index(other.Index)
{ }
Attribute::Location & Attribute::Location::operator=(const Location & other)
{
//	Type = other.Type;
//	Size = other.Size;
//	Count = other.Count;
	Index = other.Index;
	return *this;
}

void Attribute::Location::Change(GL::AttributeLocation index)
{
	Index = index;
}
