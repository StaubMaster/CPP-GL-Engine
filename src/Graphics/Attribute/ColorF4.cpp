#include "Graphics/Attribute/ColorF4.hpp"
#include "Graphics/Buffer/Attribute.hpp"



Attribute::ColorF4::ColorF4()
{ }
Attribute::ColorF4::ColorF4(
	Buffer::Attribute & buffer,
	GL::AttributeID indexCol
) :	Attribute::Base(),
	Location(buffer, indexCol, 4)
{ }
Attribute::ColorF4::~ColorF4()
{ }

Attribute::ColorF4::ColorF4(const ColorF4 & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::ColorF4 & Attribute::ColorF4::operator=(const ColorF4 & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::ColorF4::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
