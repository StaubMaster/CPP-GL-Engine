#include "Graphics/Attribute/Point2D.hpp"



Attribute::Point2D::~Point2D() { }

Attribute::Point2D::Point2D()
	: Attribute::Float2()
{ }

Attribute::Point2D::Point2D(const Point2D & other)
	: Attribute::Float2(other)
{ }
Attribute::Point2D & Attribute::Point2D::operator=(const Point2D & other)
{
	Attribute::Float2::operator=(other);
	return *this;
}
