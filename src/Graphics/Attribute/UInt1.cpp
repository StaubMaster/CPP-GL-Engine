#include "Graphics/Attribute/UInt1.hpp"
#include "OpenGL/openGL.h"



Attribute::UInt1::UInt1()
{ }
Attribute::UInt1::UInt1(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :	Attribute::Base(),
	Location(GL_UNSIGNED_INT, sizeof(unsigned int) * 1, 1, divisor, stride, index)
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



void Attribute::UInt1::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
