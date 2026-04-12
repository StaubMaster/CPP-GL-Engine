#include "ValueType/VectorF4.hpp"

#include <math.h>



VectorF4::~VectorF4() { }

VectorF4::VectorF4()
	: Vector_4()
{ }
VectorF4::VectorF4(float value)
	: Vector_4(value)
{ }
VectorF4::VectorF4(float x, float y, float z, float w)
	: Vector_4(x, y, z, w)
{ }

VectorF4::VectorF4(const VectorF4 & other)
	: Vector_4(other)
{ }
VectorF4 & VectorF4::operator=(const VectorF4 & other)
{
	Vector_4::operator=(other);
	return *this;
}





float VectorF4::length2() const { return ((X * X) + (Y * Y) + (Z * Z) + (W * W)); }
float VectorF4::length() const { return sqrt(length2()); }
VectorF4 VectorF4::normalize() const
{
	float len = length();
	if (len > 0.0f)
	{
		return VectorF4(
			X / len,
			Y / len,
			Z / len,
			W / len
		);
	}
	return VectorF4();
}
VectorF4 VectorF4::normalize(float & len) const
{
	len = length();
	if (len > 0.0f)
	{
		return VectorF4(
			X / len,
			Y / len,
			Z / len,
			W / len
		);
	}
	len = 0.0f;
	return VectorF4();
}
VectorF4 VectorF4::operator!() const { return normalize(); }



VectorF4 VectorF4::round () const { return VectorF4(roundf(X), roundf(Y), roundf(Z), roundf(W)); }
VectorF4 VectorF4::roundC() const { return VectorF4( ceilf(X),  ceilf(Y),  ceilf(Z),  ceilf(W)); }
VectorF4 VectorF4::roundF() const { return VectorF4(floorf(X), floorf(Y), floorf(Z), floorf(W)); }

VectorF4 VectorF4::round (float size) const { return VectorF4(roundf(X / size) * size, roundf(Y / size) * size, roundf(Z / size) * size, roundf(W / size) * size); }
VectorF4 VectorF4::roundC(float size) const { return VectorF4( ceilf(X / size) * size,  ceilf(Y / size) * size,  ceilf(Z / size) * size,  ceilf(W / size) * size); }
VectorF4 VectorF4::roundF(float size) const { return VectorF4(floorf(X / size) * size, floorf(Y / size) * size, floorf(Z / size) * size, floorf(W / size) * size); }





float VectorF4::dot(const VectorF4 & other) const
{
	return (
		(X * other.X) +
		(Y * other.Y)
	);
}
float VectorF4::dot(const VectorF4 & p0, const VectorF4 & p1)
{
	return p0.dot(p1);
}





VectorF4 operator+(VectorF4 p, float f) { return VectorF4(p.X + f, p.Y + f, p.Z + f, p.W + f); }
VectorF4 operator-(VectorF4 p, float f) { return VectorF4(p.X - f, p.Y - f, p.Z - f, p.W - f); }
VectorF4 operator*(VectorF4 p, float f) { return VectorF4(p.X * f, p.Y * f, p.Z * f, p.W * f); }
VectorF4 operator/(VectorF4 p, float f) { return VectorF4(p.X / f, p.Y / f, p.Z / f, p.W / f); }

VectorF4 operator+(float f, VectorF4 p) { return VectorF4(f + p.X, f + p.Y, f + p.Z, f + p.W); }
VectorF4 operator-(float f, VectorF4 p) { return VectorF4(f - p.X, f - p.Y, f - p.Z, f - p.W); }
VectorF4 operator*(float f, VectorF4 p) { return VectorF4(f * p.X, f * p.Y, f * p.Z, f * p.W); }
VectorF4 operator/(float f, VectorF4 p) { return VectorF4(f / p.X, f / p.Y, f / p.Z, f / p.W); }
