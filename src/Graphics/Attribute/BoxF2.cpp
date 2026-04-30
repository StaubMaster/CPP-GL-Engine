#include "Graphics/Attribute/BoxF2.hpp"



Attribute::BoxF2::~BoxF2() { }

Attribute::BoxF2::BoxF2(Buffer::Array & buffer)
	: Attribute::Base(buffer)
	, Min(buffer)
	, Max(buffer)
{ }
Attribute::BoxF2::BoxF2(Buffer::Array & buffer, const BoxF2 & other)
	: Attribute::Base(buffer, other)
	, Min(buffer, other.Min)
	, Max(buffer, other.Max)
{ }



void Attribute::BoxF2::Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const
{
	(void)divisor;
	(void)stride;
	(void)offset;
	//Min.Bind(divisor, stride, offset);
	//Max.Bind(divisor, stride, offset);
}
