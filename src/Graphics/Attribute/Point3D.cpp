#include "Graphics/Attribute/Point3D.hpp"



Attribute::Point3D::Point3D()
{ }
Attribute::Point3D::Point3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :	Attribute::Base(),
	Location(3, divisor, stride, indexPos)
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



void Attribute::Point3D::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
