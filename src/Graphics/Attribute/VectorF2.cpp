#include "Graphics/Attribute/VectorF2.hpp"



Attribute::VectorF2::~VectorF2() { }

Attribute::VectorF2::VectorF2(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 2, 1)
{ }

Attribute::VectorF2::VectorF2(const VectorF2 & other)
	: Attribute::FloatN(other)
{ }
Attribute::VectorF2 & Attribute::VectorF2::operator=(const VectorF2 & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
