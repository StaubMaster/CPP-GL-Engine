#include "Graphics/Attribute/ColorF4.hpp"



Attribute::ColorF4::~ColorF4() { }

Attribute::ColorF4::ColorF4()
	: Attribute::Float4()
{ }

Attribute::ColorF4::ColorF4(const ColorF4 & other)
	: Attribute::Float4(other)
{ }
Attribute::ColorF4 & Attribute::ColorF4::operator=(const ColorF4 & other)
{
	Attribute::Float4::operator=(other);
	return *this;
}
