#include "Graphics/Attribute/Point3D.hpp"
#include "Graphics/Buffer/Attribute.hpp"



Attribute::Point3D::~Point3D() { }

Attribute::Point3D::Point3D()
	: Attribute::Float3()
{ }

Attribute::Point3D::Point3D(const Point3D & other)
	: Attribute::Float3(other)
{ }
Attribute::Point3D & Attribute::Point3D::operator=(const Point3D & other)
{
	Attribute::Float3::operator=(other);
	return *this;
}
