#include "Graphics/Attribute/Point3D.hpp"
#include "Graphics/Buffer/Attribute.hpp"



Attribute::Point3D::Point3D()
{ }
Attribute::Point3D::Point3D(
	Buffer::Attribute & buffer,
	GL::AttributeID indexPos
) :	Attribute::Base(),
	Location(buffer, indexPos, 3)
{ }
Attribute::Point3D::~Point3D()
{ }

Attribute::Point3D::Point3D(const Point3D & other) :
	Attribute::Base(),
	Location(other.Location)
{ }
Attribute::Point3D & Attribute::Point3D::operator=(const Point3D & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Point3D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
