#include "ValueType/VectorU2.hpp"

#include "ValueType/VectorF2.hpp"
#include "ValueType/VectorI2.hpp"



VectorU2::~VectorU2() { }

VectorU2::VectorU2() : Vector_2() { }
VectorU2::VectorU2(unsigned int value) : Vector_2(value) { }
VectorU2::VectorU2(unsigned int x, unsigned int y) : Vector_2(x, y) { }

VectorU2::VectorU2(const VectorF2 & other) : Vector_2(other) { }
VectorU2::VectorU2(const VectorU2 & other) : Vector_2(other) { }
VectorU2::VectorU2(const VectorI2 & other) : Vector_2(other) { }

VectorU2 & VectorU2::operator=(const VectorF2 & other) { Vector_2::operator=(other); return *this; }
VectorU2 & VectorU2::operator=(const VectorU2 & other) { Vector_2::operator=(other); return *this; }
VectorU2 & VectorU2::operator=(const VectorI2 & other) { Vector_2::operator=(other); return *this; }



VectorU2 VectorU2::operator%(const VectorU2 & other) const { return VectorU2(X % other.X, Y % other.Y); }

VectorU2 VectorU2::operator~() const { return VectorU2(~X, ~Y); }
VectorU2 VectorU2::operator&(const VectorU2 & other) const { return VectorU2(X & other.X, Y & other.Y); }
VectorU2 VectorU2::operator|(const VectorU2 & other) const { return VectorU2(X | other.X, Y | other.Y); }
VectorU2 VectorU2::operator^(const VectorU2 & other) const { return VectorU2(X ^ other.X, Y ^ other.Y); }
VectorU2 VectorU2::operator<<(const VectorU2 & other) const { return VectorU2(X << other.X, Y << other.Y); }
VectorU2 VectorU2::operator>>(const VectorU2 & other) const { return VectorU2(X >> other.X, Y >> other.Y); }



unsigned int VectorU2::Product() const { return X * Y; }

unsigned int VectorU2::Convert(VectorU2 udx) const
{
	return (udx.X) + (udx.Y * X);
}
VectorU2 VectorU2::Convert(unsigned int udx) const
{
	VectorU2 vec;
	vec.X = udx % X; udx = udx / X;
//	vec.Y = udx % Y;
	vec.Y = udx;
	return vec;
}

unsigned int VectorU2::Convert(unsigned int size, VectorU2 udx)
{
	return (udx.X) + (udx.Y * size);
}
VectorU2 VectorU2::Convert(unsigned int size, unsigned int udx)
{
	VectorU2 vec;
	vec.X = udx % size; udx = udx / size;
//	vec.Y = udx % size;
	vec.Y = udx;
	return vec;
}





VectorU2 operator+(VectorU2 vec, unsigned int val) { return VectorU2(vec.X + val, vec.Y + val); }
VectorU2 operator-(VectorU2 vec, unsigned int val) { return VectorU2(vec.X - val, vec.Y - val); }
VectorU2 operator*(VectorU2 vec, unsigned int val) { return VectorU2(vec.X * val, vec.Y * val); }
VectorU2 operator/(VectorU2 vec, unsigned int val) { return VectorU2(vec.X / val, vec.Y / val); }

VectorU2 operator+(unsigned int val, VectorU2 vec) { return VectorU2(val + vec.X, val + vec.Y); }
VectorU2 operator-(unsigned int val, VectorU2 vec) { return VectorU2(val - vec.X, val - vec.Y); }
VectorU2 operator*(unsigned int val, VectorU2 vec) { return VectorU2(val * vec.X, val * vec.Y); }
VectorU2 operator/(unsigned int val, VectorU2 vec) { return VectorU2(val / vec.X, val / vec.Y); }
