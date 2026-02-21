#include "Graphics/Attribute/Base/Float3.hpp"
#include "OpenGLEnums.hpp"



Attribute::Float3::~Float3() { }

Attribute::Float3::Float3()
	: Attribute::Base()
	, Location(3)
{ }

Attribute::Float3::Float3(const Float3 & other)
	: Attribute::Base(other)
	, Location(other.Location)
{ }
Attribute::Float3 & Attribute::Float3::operator=(const Float3 & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Float3::Change(GL::AttributeLocation index)
{
	Location.Change(index);
}



void Attribute::Float3::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}
