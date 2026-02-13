#include "Graphics/Attribute/Trans2D.hpp"



Attribute::Trans2D::Trans2D()
{ }
Attribute::Trans2D::Trans2D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos,
	unsigned int indexRot
) :	Attribute::Base(),
	Pos(divisor, stride, indexPos),
	Rot(divisor, stride, indexRot)
{ }
Attribute::Trans2D::~Trans2D()
{ }

Attribute::Trans2D::Trans2D(const Trans2D & other) :
	Attribute::Base(),
	Pos(other.Pos),
	Rot(other.Rot)
{ }
Attribute::Trans2D & Attribute::Trans2D::operator=(const Trans2D & other)
{
	Attribute::Base::operator=(other);
	Pos = other.Pos;
	Rot = other.Rot;
	return *this;
}



void Attribute::Trans2D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
	Rot.Bind(offset);
}
