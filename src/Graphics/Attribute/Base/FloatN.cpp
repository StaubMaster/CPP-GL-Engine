#include "Graphics/Attribute/Base/FloatN.hpp"
#include "Graphics/Buffer/Attribute.hpp"
#include "OpenGL.hpp"



Attribute::FloatN::FloatN()
{ }
Attribute::FloatN::FloatN(
	Buffer::Attribute & buffer,
	GL::AttributeID index
) :
	Location(GL::AttributeType::Float, sizeof(float), 1, index)
{ (void)buffer; }
Attribute::FloatN::FloatN(
	Buffer::Attribute & buffer,
	GL::AttributeID index,
	unsigned int count
) :	Attribute::Base(),
	Location(GL::AttributeType::Float, sizeof(float) * count, count, index)
{ (void)buffer; }
Attribute::FloatN::~FloatN()
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



void Attribute::FloatN::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	GL::EnableVertexAttribArray(Location.Index);
	GL::VertexAttribDivisor(Location.Index, divisor);
	GL::VertexAttribPointer(Location.Index, Location.Count, Location.Type, GL_FALSE, stride, offset);
	offset += Location.Size;
}
