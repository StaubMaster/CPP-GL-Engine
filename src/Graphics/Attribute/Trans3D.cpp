#include "Graphics/Attribute/Trans3D.hpp"



Attribute::Trans3D::Trans3D()
{ }
Attribute::Trans3D::Trans3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos,
	unsigned int indexRot
) :	Attribute::Base(),
	Pos(divisor, stride, indexPos),
	Rot(divisor, stride, indexRot)
{ }
Attribute::Trans3D::~Trans3D()
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



void Attribute::Trans3D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
	Rot.Bind(offset);
}
