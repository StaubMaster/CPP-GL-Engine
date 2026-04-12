#include "ValueType/VectorU3.hpp"



VectorU3::~VectorU3() { }

VectorU3::VectorU3()
	: Vector_3()
{ }
VectorU3::VectorU3(unsigned int value)
	: Vector_3(value)
{ }
VectorU3::VectorU3(unsigned int x, unsigned int y, unsigned int z)
	: Vector_3(x, y, z)
{ }

VectorU3::VectorU3(const VectorU3 & other)
	: Vector_3(other)
{ }
VectorU3 & VectorU3::operator=(const VectorU3 & other)
{
	Vector_3::operator=(other);
	return *this;
}



VectorU3 VectorU3::operator%(const VectorU3 & other) const { return VectorU3(X % other.X, Y % other.Y, Z % other.Z); }

VectorU3 VectorU3::operator~() const { return VectorU3(~X, ~Y, ~Z); }
VectorU3 VectorU3::operator&(const VectorU3 & other) const { return VectorU3(X & other.X, Y & other.Y, Z & other.Z); }
VectorU3 VectorU3::operator|(const VectorU3 & other) const { return VectorU3(X | other.X, Y | other.Y, Z | other.Z); }
VectorU3 VectorU3::operator^(const VectorU3 & other) const { return VectorU3(X ^ other.X, Y ^ other.Y, Z ^ other.Z); }
VectorU3 VectorU3::operator<<(const VectorU3 & other) const { return VectorU3(X << other.X, Y << other.Y, Z << other.Z); }
VectorU3 VectorU3::operator>>(const VectorU3 & other) const { return VectorU3(X >> other.X, Y >> other.Y, Z >> other.Z); }



unsigned int VectorU3::Product() const { return X * Y * Z; }
