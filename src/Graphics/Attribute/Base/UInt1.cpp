#include "Graphics/Attribute/UInt1.hpp"
#include "Graphics/Buffer/Attribute.hpp"
#include "OpenGL/openGL.h"



Attribute::UInt1::UInt1()
{ }
Attribute::UInt1::UInt1(
	Buffer::Attribute & buffer,
	GL::AttributeID index
) :	Attribute::Base(),
	Location(GL_UNSIGNED_INT, sizeof(unsigned int), 1, index)
{ }
Attribute::UInt1::UInt1(
	Buffer::Attribute & buffer,
	GL::AttributeID index,
	unsigned int count
) :	Attribute::Base(),
	Location(GL_UNSIGNED_INT, sizeof(unsigned int) * count, count, index)
{ }
Attribute::UInt1::~UInt1()
{ }

Attribute::UInt1::UInt1(const UInt1 & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::UInt1 & Attribute::UInt1::operator=(const UInt1 & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::UInt1::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(offset);
}
