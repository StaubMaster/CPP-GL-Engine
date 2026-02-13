#include "Graphics/Attribute/Angle2D.hpp"
#include "ValueType/Angle.hpp"



Attribute::Angle2D::Angle2D()
{ }
Attribute::Angle2D::Angle2D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :	Attribute::Base(),
	Location0(2, divisor, stride, index + 0),
	Location1(2, divisor, stride, index + 1)
{ }
Attribute::Angle2D::~Angle2D()
{ }

Attribute::Angle2D::Angle2D(const Angle2D & other) :
	Attribute::Base(),
	Location0(other.Location0),
	Location1(other.Location1)
{ }
Attribute::Angle2D & Attribute::Angle2D::operator=(const Angle2D & other)
{
	Attribute::Base::operator=(other);
	Location0 = other.Location0;
	Location1 = other.Location1;
	return *this;
}



void Attribute::Angle2D::Bind(const unsigned char * & offset) const
{
	offset += sizeof(Angle) * 1;
	Location0.Bind(offset);
	Location1.Bind(offset);
}
