#include "Graphics/Attribute/Trans3D.hpp"



Attribute::Trans3D::~Trans3D() { }

Attribute::Trans3D::Trans3D()
	: Attribute::Base()
	, Pos()
	, Rot()
{ }

Attribute::Trans3D::Trans3D(const Trans3D & other) :
	Attribute::Base(),
	Pos(other.Pos),
	Rot(other.Rot)
{ }
Attribute::Trans3D & Attribute::Trans3D::operator=(const Trans3D & other)
{
	Attribute::Base::operator=(other);
	Pos = other.Pos;
	Rot = other.Rot;
	return *this;
}



void Attribute::Trans3D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Pos.Bind(divisor, stride, offset);
	Rot.Bind(divisor, stride, offset);
}
