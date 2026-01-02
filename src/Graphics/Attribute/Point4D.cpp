#include "Graphics/Attribute/Point4D.hpp"



Attribute::Point4D::Point4D()
{ }
Attribute::Point4D::Point4D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :	Attribute::Base(),
	Location(4, divisor, stride, indexPos)
{ }
Attribute::Point4D::~Point4D()
{ }

Attribute::Point4D::Point4D(const Point4D & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::Point4D & Attribute::Point4D::operator=(const Point4D & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Point4D::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
