#include "Graphics/Attribute/Angle3D.hpp"
#include "ValueType/Angle.hpp"



Attribute::Angle3D::Angle3D()
{ }
Attribute::Angle3D::Angle3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :	Attribute::Base(),
	Location0(3, divisor, stride, index + 0),
	Location1(3, divisor, stride, index + 1),
	Location2(3, divisor, stride, index + 2)
{ }
Attribute::Angle3D::~Angle3D()
{ }

Attribute::Angle3D::Angle3D(const Angle3D & other) :
	Attribute::Base(),
	Location0(other.Location0),
	Location1(other.Location1),
	Location2(other.Location2)
{ }
Attribute::Angle3D & Attribute::Angle3D::operator=(const Angle3D & other)
{
	Attribute::Base::operator=(other);
	Location0 = other.Location0;
	Location1 = other.Location1;
	Location2 = other.Location2;
	return *this;
}



void Attribute::Angle3D::Bind(const unsigned char * & offset) const
{
	offset += sizeof(Angle) * 3;
	Location0.Bind(offset);
	Location1.Bind(offset);
	Location2.Bind(offset);
}
