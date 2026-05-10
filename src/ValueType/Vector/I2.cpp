#include "ValueType/Vector/I2.hpp"

#include "ValueType/Vector/F2.hpp"
#include "ValueType/Vector/U2.hpp"



VectorI2::~VectorI2() { }

VectorI2::VectorI2() : Vector_2() { }
VectorI2::VectorI2(int value) : Vector_2(value) { }
VectorI2::VectorI2(int x, int y) : Vector_2(x, y) { }

VectorI2::VectorI2(const VectorF2 & other) : Vector_2(other) { }
VectorI2::VectorI2(const VectorU2 & other) : Vector_2(other) { }
VectorI2::VectorI2(const VectorI2 & other) : Vector_2(other) { }

VectorI2 & VectorI2::operator=(const VectorF2 & other) { Vector_2::operator=(other); return *this; }
VectorI2 & VectorI2::operator=(const VectorU2 & other) { Vector_2::operator=(other); return *this; }
VectorI2 & VectorI2::operator=(const VectorI2 & other) { Vector_2::operator=(other); return *this; }



VectorI2 VectorI2::operator%(const VectorI2 & other) const { return VectorI2(X % other.X, Y % other.Y); }

VectorI2 VectorI2::operator~() const { return VectorI2(~X, ~Y); }
VectorI2 VectorI2::operator&(const VectorI2 & other) const { return VectorI2(X & other.X, Y & other.Y); }
VectorI2 VectorI2::operator|(const VectorI2 & other) const { return VectorI2(X | other.X, Y | other.Y); }
VectorI2 VectorI2::operator^(const VectorI2 & other) const { return VectorI2(X ^ other.X, Y ^ other.Y); }
VectorI2 VectorI2::operator<<(const VectorI2 & other) const { return VectorI2(X << other.X, Y << other.Y); }
VectorI2 VectorI2::operator>>(const VectorI2 & other) const { return VectorI2(X >> other.X, Y >> other.Y); }



int VectorI2::Product() const { return X * Y; }

int VectorI2::Convert(VectorI2 idx) const
{
	return (idx.X) + (idx.Y * X);
}
VectorI2 VectorI2::Convert(int idx) const
{
	VectorI2 vec;
	vec.X = idx % X; idx = idx / X;
//	vec.Y = idx % Y;
	vec.Y = idx;
	return vec;
}

int VectorI2::Convert(int size, VectorI2 idx)
{
	return (idx.X) + (idx.Y * size);
}
VectorI2 VectorI2::Convert(int size, int idx)
{
	VectorI2 vec;
	vec.X = idx % size; idx = idx / size;
//	vec.Y = idx % size;
	vec.Y = idx;
	return vec;
}





VectorI2 operator+(VectorI2 vec, int val) { return VectorI2(vec.X + val, vec.Y + val); }
VectorI2 operator-(VectorI2 vec, int val) { return VectorI2(vec.X - val, vec.Y - val); }
VectorI2 operator*(VectorI2 vec, int val) { return VectorI2(vec.X * val, vec.Y * val); }
VectorI2 operator/(VectorI2 vec, int val) { return VectorI2(vec.X / val, vec.Y / val); }

VectorI2 operator+(int val, VectorI2 vec) { return VectorI2(val + vec.X, val + vec.Y); }
VectorI2 operator-(int val, VectorI2 vec) { return VectorI2(val - vec.X, val - vec.Y); }
VectorI2 operator*(int val, VectorI2 vec) { return VectorI2(val * vec.X, val * vec.Y); }
VectorI2 operator/(int val, VectorI2 vec) { return VectorI2(val / vec.X, val / vec.Y); }
