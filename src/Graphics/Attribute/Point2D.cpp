#include "Graphics/Attribute/Point2D.hpp"



Attribute::Point2D::Point2D()
{ }
Attribute::Point2D::Point2D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :	Attribute::Base(),
	Location(2, divisor, stride, indexPos)
{ }
Attribute::Point2D::~Point2D()
{ }

Attribute::Point2D::Point2D(const Point2D & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::Point2D & Attribute::Point2D::operator=(const Point2D & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Point2D::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
