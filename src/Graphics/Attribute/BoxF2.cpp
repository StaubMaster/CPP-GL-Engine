#include "Graphics/Attribute/BoxF2.hpp"



Attribute::BoxF2::~BoxF2() { }

Attribute::BoxF2::BoxF2(Buffer::Array & buffer)
	: Attribute::Base()
	, Min(buffer)
	, Max(buffer)
{ }


void Attribute::BoxF2::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	Min.Bind(divisor, stride, offset);
	Max.Bind(divisor, stride, offset);
}
