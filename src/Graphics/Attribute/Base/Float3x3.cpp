#include "Graphics/Attribute/Base/Float3x3.hpp"
#include "OpenGLEnums.hpp"



Attribute::Float3x3::~Float3x3() { }

Attribute::Float3x3::Float3x3()
	: Attribute::Base()
	, Location0(3)
	, Location1(3)
	, Location2(3)
{ }

Attribute::Float3x3::Float3x3(const Float3x3 & other)
	: Attribute::Base(other)
	, Location0(other.Location0)
	, Location1(other.Location1)
	, Location2(other.Location2)
{ }
Attribute::Float3x3 & Attribute::Float3x3::operator=(const Float3x3 & other)
{
	Attribute::Base::operator=(other);
	Location0 = other.Location0;
	Location1 = other.Location1;
	Location2 = other.Location2;
	return *this;
}



void Attribute::Float3x3::Change(GL::AttributeLocation index0, GL::AttributeLocation index1, GL::AttributeLocation index2)
{
	Location0.Change(index0);
	Location1.Change(index1);
	Location2.Change(index2);
}



void Attribute::Float3x3::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location0.Bind(divisor, stride, offset);
	Location1.Bind(divisor, stride, offset);
	Location2.Bind(divisor, stride, offset);
}