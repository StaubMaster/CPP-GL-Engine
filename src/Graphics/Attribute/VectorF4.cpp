#include "Graphics/Attribute/VectorF4.hpp"



Attribute::VectorF4::~VectorF4() { }

Attribute::VectorF4::VectorF4(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 4, 1)
{ }

Attribute::VectorF4::VectorF4(const VectorF4 & other)
	: Attribute::FloatN(other)
{ }
Attribute::VectorF4 & Attribute::VectorF4::operator=(const VectorF4 & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
