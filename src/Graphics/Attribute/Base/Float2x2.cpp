#include "Graphics/Attribute/Base/Float2x2.hpp"
#include "OpenGLEnums.hpp"



Attribute::Float2x2::~Float2x2() { }

Attribute::Float2x2::Float2x2()
	: Attribute::Base()
	, Location0(2)
	, Location1(2)
{ }

Attribute::Float2x2::Float2x2(const Float2x2 & other)
	: Attribute::Base(other)
	, Location0(other.Location0)
	, Location1(other.Location1)
{ }
Attribute::Float2x2 & Attribute::Float2x2::operator=(const Float2x2 & other)
{
	Attribute::Base::operator=(other);
	Location0 = other.Location0;
	Location1 = other.Location1;
	return *this;
}



void Attribute::Float2x2::Change(GL::AttributeLocation index0, GL::AttributeLocation index1)
{
	Location0.Change(index0);
	Location1.Change(index1);
}



void Attribute::Float2x2::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location0.Bind(divisor, stride, offset);
	Location1.Bind(divisor, stride, offset);
}
