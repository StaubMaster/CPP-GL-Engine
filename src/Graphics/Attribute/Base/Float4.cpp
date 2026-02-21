#include "Graphics/Attribute/Base/Float4.hpp"
#include "OpenGLEnums.hpp"



Attribute::Float4::~Float4() { }

Attribute::Float4::Float4()
	: Attribute::Base()
	, Location(4)
{ }

Attribute::Float4::Float4(const Float4 & other)
	: Attribute::Base(other)
	, Location(other.Location)
{ }
Attribute::Float4 & Attribute::Float4::operator=(const Float4 & other)
{
	Attribute::Base::operator=(other);
	Location = other.Location;
	return *this;
}



void Attribute::Float4::Change(GL::AttributeLocation index)
{
	Location.Change(index);
}



void Attribute::Float4::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location.Bind(divisor, stride, offset);
}