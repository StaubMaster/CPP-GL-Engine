#include "Graphics/Attribute/Base/Location.hpp"



Attribute::Location::Location()
	: Type((GL::AttributeType)0)
	, Size(0)
	, Count(0)
	, Index((GL::AttributeID)0)
{ }
Attribute::Location::Location(
	GL::AttributeType type,
	unsigned int size,
	unsigned int count,
	GL::AttributeID index
)
	: Type(type)
	, Size(size)
	, Count(count)
	, Index(index)
{ }
Attribute::Location::~Location()
{ }

Attribute::Location::Location(const Location & other)
	: Type(other.Type)
	, Size(other.Size)
	, Count(other.Count)
	, Index(other.Index)
{ }
/*Attribute::Location & Attribute::Location::operator=(const Location & other)
{
	Type = other.Type;
	Size = other.Size;
	Count = other.Count;
	Divisor = other.Divisor;
	Stride = other.Stride;
	Index = other.Index;
	return *this;
}*/
