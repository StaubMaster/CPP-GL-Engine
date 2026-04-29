#include "Graphics/Attribute/VectorF3.hpp"



Attribute::VectorF3::~VectorF3() { }

Attribute::VectorF3::VectorF3(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 3, 1)
{ }

Attribute::VectorF3::VectorF3(const VectorF3 & other)
	: Attribute::FloatN(other)
{ }
Attribute::VectorF3 & Attribute::VectorF3::operator=(const VectorF3 & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
