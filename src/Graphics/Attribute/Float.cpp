#include "Graphics/Attribute/Float.hpp"



Attribute::Float::~Float() { }

Attribute::Float::Float(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 1, 1)
{ }

Attribute::Float::Float(const Float & other)
	: Attribute::FloatN(other)
{ }
Attribute::Float & Attribute::Float::operator=(const Float & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
