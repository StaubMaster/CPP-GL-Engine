#include "Graphics/Attribute/Angle3D.hpp"
#include "ValueType/Angle.hpp"



Attribute::Angle3D::~Angle3D() { }

Attribute::Angle3D::Angle3D()
	: Attribute::Float3x3()
{ }

Attribute::Angle3D::Angle3D(const Angle3D & other)
	: Attribute::Float3x3(other)
{ }
Attribute::Angle3D & Attribute::Angle3D::operator=(const Angle3D & other)
{
	Attribute::Float3x3::operator=(other);
	return *this;
}



void Attribute::Angle3D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	offset += sizeof(Angle) * 3;
	Attribute::Float3x3::Bind(divisor, stride, offset);
}
