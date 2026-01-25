#include "Graphics/Attribute/Base/FloatN.hpp"
#include "OpenGL.hpp"



Attribute::FloatN::FloatN()
{ }
Attribute::FloatN::FloatN(
	unsigned int n,
	GL::AttributeDivisor divisor,
	unsigned int stride,
	GL::AttributeID index
) :	Attribute::Base(),
	Location(GL::AttributeType::Float, sizeof(float) * n, n, divisor, stride, index)
{ }
Attribute::FloatN::~FloatN()
{ }

Attribute::FloatN::FloatN(
	GL::AttributeDivisor divisor,
	unsigned int stride,
	GL::AttributeID index
) :
	Location(GL::AttributeType::Float, sizeof(float), 1, divisor, stride, index)
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
	GL::EnableVertexAttribArray(Location.Index);
	GL::VertexAttribPointer(Location.Index, Location.Count, Location.Type, GL_FALSE, Location.Stride, offset);
	GL::VertexAttribDivisor(Location.Index, Location.Divisor);
	offset += Location.Size;
}
