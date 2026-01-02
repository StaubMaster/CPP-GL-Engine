#include "Graphics/Attribute/Base/AttributeLocation.hpp"



Attribute::Location::Location() :
	Type(0),
	Size(0),
	Count(0),
	Divisor(0),
	Stride(0),
	Index(0)
{ }
Attribute::Location::Location(
	unsigned int type,
	unsigned int size,
	unsigned int count,
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :
	Type(type),
	Size(size),
	Count(count),
	Divisor(divisor),
	Stride(stride),
	Index(index)
{ }
Attribute::Location::~Location()
{ }

Attribute::Location::Location(const Location & other) :
	Type(other.Type),
	Size(other.Size),
	Count(other.Count),
	Divisor(other.Divisor),
	Stride(other.Stride),
	Index(other.Index)
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
