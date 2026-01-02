#include "Graphics/Attribute/Color.hpp"



Attribute::Color::Color()
{ }
Attribute::Color::Color(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexCol
) :	Attribute::Base(),
	Location(3, divisor, stride, indexCol)
{ }
Attribute::Color::~Color()
{ }

Attribute::Color::Color(const Color & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::Color & Attribute::Color::operator=(const Color & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Color::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
