#include "Graphics/Attribute/Base/FloatN.hpp"
#include "OpenGL/openGL.h"



Attribute::FloatN::FloatN()
{ }
Attribute::FloatN::FloatN(
	unsigned int n,
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :	Attribute::Base(),
	Location(GL_FLOAT, sizeof(float) * n, n, divisor, stride, index)
{ }
Attribute::FloatN::~FloatN()
{ }

Attribute::FloatN::FloatN(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :
	Location(GL_FLOAT, sizeof(float), 1, divisor, stride, index)
{ }

Attribute::FloatN::FloatN(const FloatN & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::FloatN & Attribute::FloatN::operator=(const FloatN & other)
{
	Attribute::Base::operator=(other);
	//Location = other.Location;
	return *this;
}



void Attribute::FloatN::Bind(const unsigned char * & offset) const
{
	glEnableVertexAttribArray(Location.Index);
	glVertexAttribPointer(Location.Index, Location.Count, Location.Type, GL_FALSE, Location.Stride, offset);
	glVertexAttribDivisor(Location.Index, Location.Divisor);
	offset += Location.Size;
}
