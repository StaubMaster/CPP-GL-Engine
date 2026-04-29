#include "Graphics/Attribute/Matrix4x4.hpp"



Attribute::Matrix4x4::~Matrix4x4() { }

Attribute::Matrix4x4::Matrix4x4(Buffer::Array & buffer)
	: Attribute::FloatN(buffer, 4, 4)
{ }

Attribute::Matrix4x4::Matrix4x4(const Matrix4x4 & other)
	: Attribute::FloatN(other)
{ }
Attribute::Matrix4x4 & Attribute::Matrix4x4::operator=(const Matrix4x4 & other)
{
	Attribute::FloatN::operator=(other);
	return *this;
}
