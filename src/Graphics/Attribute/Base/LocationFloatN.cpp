#include "Graphics/Attribute/Base/LocationFloatN.hpp"
#include "Graphics/Buffer/Attribute.hpp"
#include "OpenGL.hpp"



Attribute::LocationFloatN::~LocationFloatN() { }

Attribute::LocationFloatN::LocationFloatN(unsigned int count)
	: Attribute::Location(GL::AttributeType::Float, count, sizeof(float) * count)
{ }

Attribute::LocationFloatN::LocationFloatN(const LocationFloatN & other)
	: Attribute::Location(other)
{ }
Attribute::LocationFloatN & Attribute::LocationFloatN::operator=(const LocationFloatN & other)
{
	Attribute::Location::operator=(other);
	return *this;
}



void Attribute::LocationFloatN::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	GL::EnableVertexAttribArray(Index);
	GL::VertexAttribDivisor(Index, divisor);
	GL::VertexAttribPointer(Index, Count, Type, GL_FALSE, stride, offset);
	offset += Size;
}
