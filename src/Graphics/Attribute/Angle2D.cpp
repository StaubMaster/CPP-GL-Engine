#include "Graphics/Attribute/Angle2D.hpp"
#include "ValueType/Angle.hpp"



Attribute::Angle2D::~Angle2D() { }

Attribute::Angle2D::Angle2D()
	: Attribute::Float2x2()
{ }

Attribute::Angle2D::Angle2D(const Angle2D & other)
	: Attribute::Float2x2(other)
{ }
Attribute::Angle2D & Attribute::Angle2D::operator=(const Angle2D & other)
{
	Attribute::Float2x2::operator=(other);
	return *this;
}



void Attribute::Angle2D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	offset += sizeof(Angle) * 1;
	Attribute::Float2x2::Bind(divisor, stride, offset);
}
