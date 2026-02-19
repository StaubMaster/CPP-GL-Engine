#include "Graphics/Attribute/Point2D.hpp"
#include "Graphics/Buffer/Attribute.hpp"



Attribute::Point2D::Point2D()
{ }
Attribute::Point2D::Point2D(
	Buffer::Attribute & buffer,
	GL::AttributeID indexPos
) :	Attribute::Base(),
	Location(buffer, indexPos, 2)
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



void Attribute::Point2D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
