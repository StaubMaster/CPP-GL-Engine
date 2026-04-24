#include "Graphics/Attribute/AxisBox2D.hpp"



Attribute::AxisBox2D::~AxisBox2D() { }

Attribute::AxisBox2D::AxisBox2D()
	: Attribute::Base()
	, Min(2)
	, Max(2)
{ }

Attribute::AxisBox2D::AxisBox2D(const AxisBox2D & other)
	: Attribute::Base(other)
	, Min(other.Min)
	, Max(other.Max)
{ }
Attribute::AxisBox2D & Attribute::AxisBox2D::operator=(const AxisBox2D & other)
{
	Attribute::Base::operator=(other);
	Min = other.Min;
	Max = other.Max;
	return *this;
}



void Attribute::AxisBox2D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Min.Bind(divisor, stride, offset);
	Max.Bind(divisor, stride, offset);
}
