#include "Graphics/Attribute/Point4D.hpp"
#include "Graphics/Buffer/Attribute.hpp"



Attribute::Point4D::~Point4D() { }

Attribute::Point4D::Point4D()
	: Attribute::Float4()
{ }

Attribute::Point4D::Point4D(const Point4D & other)
	: Attribute::Float4(other)
{ }
Attribute::Point4D & Attribute::Point4D::operator=(const Point4D & other)
{
	Attribute::Float4::operator=(other);
	return *this;
}
