#include "Graphics/Attribute/General/Layout.hpp"
#include "Graphics/Attribute/General/Base.hpp"



Attribute::Layout::~Layout()
{ }
Attribute::Layout::Layout(GL::AttributeDivisor divisor, GL::AttributeStride stride)
	: Attributes()
	, Divisor(divisor)
	, Stride(stride)
{ }

Attribute::Layout::Layout(const Layout & other)
	: Attributes(other.Attributes)
	, Divisor(other.Divisor)
	, Stride(other.Stride)
{ }
/*Attribute::Layout & Attribute::Layout::operator=(const Layout & other)
{
	Attributes = other.Attributes;
}*/



void Attribute::Layout::Bind() const
{
	GL::AttributeOffset offset = nullptr;
	for (unsigned int i = 0; i < Attributes.Count(); i++)
	{
		Attributes[i] -> Bind(Divisor, Stride, offset);
	}
}
