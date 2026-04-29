#include "Graphics/Attribute/Matrix3x3.hpp"



Attribute::Matrix3x3::~Matrix3x3() { }

Attribute::Matrix3x3::Matrix3x3(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 3, 3)
{ }

Attribute::Matrix3x3::Matrix3x3(const Matrix3x3 & other)
	: Attribute::FloatN(other)
{ }
Attribute::Matrix3x3 & Attribute::Matrix3x3::operator=(const Matrix3x3 & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
