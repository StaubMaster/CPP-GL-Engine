#include "Graphics/Attribute/ColorF4.hpp"



Attribute::ColorF4::ColorF4()
{ }
Attribute::ColorF4::ColorF4(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexCol
) :	Attribute::Base(),
	Location(4, divisor, stride, indexCol)
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



void Attribute::ColorF4::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
