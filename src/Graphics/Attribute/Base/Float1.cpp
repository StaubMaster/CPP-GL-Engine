#include "Graphics/Attribute/Base/Float1.hpp"
#include "OpenGLEnums.hpp"



Attribute::Float1::~Float1() { }

Attribute::Float1::Float1()
	: Attribute::Base()
	, Location(1)
{ }

Attribute::Float1::Float1(const Float1 & other)
	: Attribute::Base(other)
	, Location(other.Location)
{ }
Attribute::Float1 & Attribute::Float1::operator=(const Float1 & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Float1::Change(GL::AttributeLocation index)
{
	Location.Change(index);
}



void Attribute::Float1::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
