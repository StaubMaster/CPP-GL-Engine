#include "Graphics/Attribute/ColorF4.hpp"



Attribute::ColorF4::~ColorF4() { }

Attribute::ColorF4::ColorF4(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 4, 1)
{ }

Attribute::ColorF4::ColorF4(const ColorF4 & other)
	: Attribute::FloatN(other)
{ }
Attribute::ColorF4 & Attribute::ColorF4::operator=(const ColorF4 & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
