#include "Graphics/Attribute/Trans2D.hpp"
#include "Graphics/Buffer/Attribute.hpp"



Attribute::Trans2D::Trans2D()
{ }
Attribute::Trans2D::Trans2D(
	Buffer::Attribute & buffer,
	GL::AttributeID indexPos,
	GL::AttributeID indexRot
) :	Attribute::Base(),
	Pos(buffer, indexPos),
	Rot(buffer, indexRot)
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



void Attribute::Trans2D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Pos.Bind(divisor, stride, offset);
	Rot.Bind(divisor, stride, offset);
}
