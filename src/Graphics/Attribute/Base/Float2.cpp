#include "Graphics/Attribute/Base/Float2.hpp"
#include "OpenGLEnums.hpp"



Attribute::Float2::~Float2() { }

Attribute::Float2::Float2()
	: Attribute::Base()
	, Location(2)
{ }

Attribute::Float2::Float2(const Float2 & other)
	: Attribute::Base(other)
	, Location(other.Location)
{ }
Attribute::Float2 & Attribute::Float2::operator=(const Float2 & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Float2::Change(GL::AttributeLocation index)
{
	Location.Change(index);
}



void Attribute::Float2::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
