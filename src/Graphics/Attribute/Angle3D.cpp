#include "Graphics/Attribute/Angle3D.hpp"
#include "Graphics/Buffer/Attribute.hpp"
#include "ValueType/Angle.hpp"



Attribute::Angle3D::Angle3D()
{ }
Attribute::Angle3D::Angle3D(
	Buffer::Attribute & buffer,
	GL::AttributeID index
) :	Attribute::Base(),
	Location0(buffer, index + 0, 3),
	Location1(buffer, index + 1, 3),
	Location2(buffer, index + 2, 3)
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



void Attribute::Angle3D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	offset += sizeof(Angle) * 3;
	Location0.Bind(divisor, stride, offset);
	Location1.Bind(divisor, stride, offset);
	Location2.Bind(divisor, stride, offset);
}
