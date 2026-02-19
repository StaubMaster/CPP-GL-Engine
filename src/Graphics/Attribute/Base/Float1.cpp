#include "Graphics/Attribute/Float1.hpp"
#include "OpenGL/openGL.h"



Attribute::Float1::Float1()
{ }
Attribute::Float1::Float1(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :	Attribute::Base(),
	Location(GL_FLOAT, sizeof(float) * 1, 1, divisor, stride, index)
{ }
Attribute::Float1::~Float1()
{ }

Attribute::Float1::Float1(const Float1 & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::Float1 & Attribute::Float1::operator=(const Float1 & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Float1::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
