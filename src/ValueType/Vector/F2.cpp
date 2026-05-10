#include "ValueType/Vector/F2.hpp"

#include "ValueType/Vector/U2.hpp"
#include "ValueType/Vector/I2.hpp"

#include <math.h>



VectorF2::~VectorF2() { }

VectorF2::VectorF2() : Vector_2() { }
VectorF2::VectorF2(float value) : Vector_2(value) { }
VectorF2::VectorF2(float x, float y) : Vector_2(x, y) { }

VectorF2::VectorF2(const VectorF2 & other) : Vector_2(other) { }
VectorF2::VectorF2(const VectorU2 & other) : Vector_2(other) { }
VectorF2::VectorF2(const VectorI2 & other) : Vector_2(other) { }

VectorF2 & VectorF2::operator=(const VectorF2 & other) { Vector_2::operator=(other); return *this; }
VectorF2 & VectorF2::operator=(const VectorU2 & other) { Vector_2::operator=(other); return *this; }
VectorF2 & VectorF2::operator=(const VectorI2 & other) { Vector_2::operator=(other); return *this; }




float VectorF2::length2() const { return ((X * X) + (Y * Y)); }
float VectorF2::length() const { return sqrt(length2()); }
VectorF2 VectorF2::normalize() const
{
	float len = length();
	if (len > 0.0f)
	{
		return VectorF2(
			X / len,
			Y / len
		);
	}
	return VectorF2();
}
VectorF2 VectorF2::normalize(float & len) const
{
	len = length();
	if (len > 0.0f)
	{
		return VectorF2(
			X / len,
			Y / len
		);
	}
	len = 0.0f;
	return VectorF2();
}
VectorF2 VectorF2::operator!() const { return normalize(); }



VectorF2 VectorF2::round () const { return VectorF2(roundf(X), roundf(Y)); }
VectorF2 VectorF2::roundC() const { return VectorF2( ceilf(X),  ceilf(Y)); }
VectorF2 VectorF2::roundF() const { return VectorF2(floorf(X), floorf(Y)); }

VectorF2 VectorF2::round (float size) const { return VectorF2(roundf(X / size) * size, roundf(Y / size) * size); }
VectorF2 VectorF2::roundC(float size) const { return VectorF2( ceilf(X / size) * size,  ceilf(Y / size) * size); }
VectorF2 VectorF2::roundF(float size) const { return VectorF2(floorf(X / size) * size, floorf(Y / size) * size); }





float VectorF2::dot(const VectorF2 & v0, const VectorF2 & v1) { return v0.dot(v1); }
float VectorF2::dot(const VectorF2 & other) const { return ((X * other.X) + (Y * other.Y)); }



float VectorF2::cross(const VectorF2 & other) const
{
	return (
		(X * other.Y) -
		(Y * other.X)
	);
}
float VectorF2::cross(const VectorF2 & v0, const VectorF2 & v1)
{
	return (
		(v0.X * v1.Y) -
		(v0.Y * v1.X)
	);
}

VectorF2 VectorF2::cross(float f) const
{
	return VectorF2(
		+(Y * f),
		-(X * f)
	);
}
VectorF2 VectorF2::cross(float f, const VectorF2 & v)
{
/*
+(00 * 0000) -(f0 * p1.Y)
+(f0 * p1.X) -(00 * 0000)
+(00 * p1.Y) -(00 * p1.X)
*/
	return VectorF2(
		-(f * v.Y),
		+(f * v.X)
	);
}
VectorF2 VectorF2::cross(const VectorF2 & v, float f)
{
/*
+(p0.Y * f1) -(0000 * 00)
+(0000 * 00) -(p0.X * f1)
+(p0.X * 00) -(p0.Y * 00)
*/
	return VectorF2(
		+(v.Y * f),
		-(v.X * f)
	);
}





VectorF2 operator+(VectorF2 v, float f) { return VectorF2(v.X + f, v.Y + f); }
VectorF2 operator-(VectorF2 v, float f) { return VectorF2(v.X - f, v.Y - f); }
VectorF2 operator*(VectorF2 v, float f) { return VectorF2(v.X * f, v.Y * f); }
VectorF2 operator/(VectorF2 v, float f) { return VectorF2(v.X / f, v.Y / f); }

VectorF2 operator+(float f, VectorF2 v) { return VectorF2(f + v.X, f + v.Y); }
VectorF2 operator-(float f, VectorF2 v) { return VectorF2(f - v.X, f - v.Y); }
VectorF2 operator*(float f, VectorF2 v) { return VectorF2(f * v.X, f * v.Y); }
VectorF2 operator/(float f, VectorF2 v) { return VectorF2(f / v.X, f / v.Y); }
