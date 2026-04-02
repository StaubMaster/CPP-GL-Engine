#include "Graphics/Attribute/Base/Float4x4.hpp"
#include "OpenGLEnums.hpp"



Attribute::Float4x4::~Float4x4() { }

Attribute::Float4x4::Float4x4()
	: Attribute::Base()
	, Location0(4)
	, Location1(4)
	, Location2(4)
	, Location3(4)
{ }

Attribute::Float4x4::Float4x4(const Float4x4 & other)
	: Attribute::Base(other)
	, Location0(other.Location0)
	, Location1(other.Location1)
	, Location2(other.Location2)
	, Location3(other.Location3)
{ }
Attribute::Float4x4 & Attribute::Float4x4::operator=(const Float4x4 & other)
{
	Attribute::Base::operator=(other);
	Location0 = other.Location0;
	Location1 = other.Location1;
	Location2 = other.Location2;
	Location3 = other.Location3;
	return *this;
}



void Attribute::Float4x4::Change(GL::AttributeLocation index0, GL::AttributeLocation index1, GL::AttributeLocation index2, GL::AttributeLocation index3)
{
	Location0.Change(index0);
	Location1.Change(index1);
	Location2.Change(index2);
	Location3.Change(index3);
}



void Attribute::Float4x4::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Location0.Bind(divisor, stride, offset);
	Location1.Bind(divisor, stride, offset);
	Location2.Bind(divisor, stride, offset);
	Location3.Bind(divisor, stride, offset);
}