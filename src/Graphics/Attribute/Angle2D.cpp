#include "Graphics/Attribute/Angle2D.hpp"
#include "Graphics/Buffer/Attribute.hpp"
#include "ValueType/Angle.hpp"



Attribute::Angle2D::Angle2D()
{ }
Attribute::Angle2D::Angle2D(
	Buffer::Attribute & buffer,
	GL::AttributeID index
) :	Attribute::Base(),
	Location0(buffer, index + 0, 2),
	Location1(buffer, index + 1, 2)
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



void Attribute::Angle2D::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	offset += sizeof(Angle) * 1;
	Location0.Bind(divisor, stride, offset);
	Location1.Bind(divisor, stride, offset);
}
