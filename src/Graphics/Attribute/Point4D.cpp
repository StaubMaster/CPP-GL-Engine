#include "Graphics/Attribute/Point4D.hpp"
#include "Graphics/Buffer/Attribute.hpp"



Attribute::Point4D::Point4D()
{ }
Attribute::Point4D::Point4D(
	Buffer::Attribute & buffer,
	GL::AttributeID indexPos
) :	Attribute::Base(),
	Location(buffer, indexPos, 4)
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



void Attribute::Point4D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
