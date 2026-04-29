#include "Graphics/Attribute/Matrix2x2.hpp"



Attribute::Matrix2x2::~Matrix2x2() { }

Attribute::Matrix2x2::Matrix2x2(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 2, 2)
{ }

Attribute::Matrix2x2::Matrix2x2(const Matrix2x2 & other)
	: Attribute::FloatN(other)
{ }
Attribute::Matrix2x2 & Attribute::Matrix2x2::operator=(const Matrix2x2 & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
