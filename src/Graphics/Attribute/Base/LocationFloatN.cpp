#include "Graphics/Attribute/Base/LocationFloatN.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "OpenGL.hpp"



Attribute::LocationFloatN::~LocationFloatN() { }

Attribute::LocationFloatN::LocationFloatN(Buffer::Array & buffer, unsigned int size0, unsigned int size1)
	: Attribute::Location(buffer, GL::AttributeType::Float, size0, size1, size0 * sizeof(float))
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
	for (unsigned int s = 0; s < Size1; s++)
	{
		if (Index != -1)
		{
			GL::EnableVertexAttribArray(Index + s);
			GL::VertexAttribDivisor(Index + s, divisor);
			GL::VertexAttribPointer(Index + s, Size0, Type, GL_FALSE, stride, offset);
		}
		offset += Offset;
	}
}
