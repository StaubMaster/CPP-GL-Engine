#include "ValueType/Vector/F3.hpp"

#include <math.h>



VectorF3::~VectorF3() { }

VectorF3::VectorF3() :
	X(0), Y(0), Z(0)
{ }
VectorF3::VectorF3(float x, float y, float z) :
	X(x), Y(y), Z(z)
{ }

VectorF3::VectorF3(const VectorF3 & other) :
	X(other.X), Y(other.Y), Z(other.Z)
{ }
VectorF3 & VectorF3::operator=(const VectorF3 & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return *this;
}





float VectorF3::length2() const
{
	return ((X * X) + (Y * Y) + (Z * Z));
}
float VectorF3::length() const
{
	return sqrt(length2());
}
VectorF3 VectorF3::normalize() const
{
	float len = length();
	if (len > 0.0f)
	{
		return VectorF3(
			X / len,
			Y / len,
			Z / len
		);
	}
	return VectorF3(0, 0, 0);
}
VectorF3 VectorF3::normalize(float & len) const
{
	len = length();
	if (len > 0.0f)
	{
		return VectorF3(
			X / len,
			Y / len,
			Z / len
		);
	}
	len = 0.0f;
	return VectorF3(0, 0, 0);
}

VectorF3 VectorF3::round() const
{
	return VectorF3(
		roundf(X),
		roundf(Y),
		roundf(Z)
	);
}
VectorF3 VectorF3::roundC() const
{
	return VectorF3(
		ceilf(X),
		ceilf(Y),
		ceilf(Z)
	);
}
VectorF3 VectorF3::roundF() const
{
	return VectorF3(
		floorf(X),
		floorf(Y),
		floorf(Z)
	);
}

VectorF3 VectorF3::round(float size) const
{
	return VectorF3(
		roundf(X / size) * size,
		roundf(Y / size) * size,
		roundf(Z / size) * size
	);
}
VectorF3 VectorF3::roundC(float size) const
{
	return VectorF3(
		ceilf(X / size) * size,
		ceilf(Y / size) * size,
		ceilf(Z / size) * size
	);
}
VectorF3 VectorF3::roundF(float size) const
{
	return VectorF3(
		floorf(X / size) * size,
		floorf(Y / size) * size,
		floorf(Z / size) * size
	);
}





VectorF3 VectorF3::operator+() const
{
	return VectorF3(
		+X,
		+Y,
		+Z
	);
}
VectorF3 VectorF3::operator-() const
{
	return VectorF3(
		-X,
		-Y,
		-Z
	);
}
VectorF3 VectorF3::operator!() const
{
	return normalize();
}

VectorF3 VectorF3::operator+(const VectorF3 & other) const { return VectorF3(X + other.X, Y + other.Y, Z + other.Z); }
VectorF3 VectorF3::operator-(const VectorF3 & other) const { return VectorF3(X - other.X, Y - other.Y, Z - other.Z); }
VectorF3 VectorF3::operator*(const VectorF3 & other) const { return VectorF3(X * other.X, Y * other.Y, Z * other.Z); }
VectorF3 VectorF3::operator/(const VectorF3 & other) const { return VectorF3(X / other.X, Y / other.Y, Z / other.Z); }

VectorF3 & VectorF3::operator+=(const VectorF3 & other) { X += other.X; Y += other.Y; Z += other.Z; return *this; }
VectorF3 & VectorF3::operator-=(const VectorF3 & other) { X -= other.X; Y -= other.Y; Z -= other.Z; return *this; }
VectorF3 & VectorF3::operator*=(const VectorF3 & other) { X *= other.X; Y *= other.Y; Z *= other.Z; return *this; }
VectorF3 & VectorF3::operator/=(const VectorF3 & other) { X /= other.X; Y /= other.Y; Z /= other.Z; return *this; }





float VectorF3::dot(const VectorF3 & p0, const VectorF3 & p1)
{
	return (
		(p0.X * p1.X) +
		(p0.Y * p1.Y) +
		(p0.Z * p1.Z)
	);
}
float VectorF3::dot(const VectorF3 & other) const
{
	return dot(*this, other);
}

VectorF3 VectorF3::cross(const VectorF3 & p0, const VectorF3 & p1)
{
	return VectorF3(
		(p0.Y * p1.Z) - (p0.Z * p1.Y),
		(p0.Z * p1.X) - (p0.X * p1.Z),
		(p0.X * p1.Y) - (p0.Y * p1.X)
	);
}
VectorF3 VectorF3::cross(const VectorF3 & other) const
{
	return cross(*this, other);
}





VectorF3 & VectorF3::operator+=(float f) { X += f; Y += f; Z += f; return *this; }
VectorF3 & VectorF3::operator-=(float f) { X -= f; Y -= f; Z -= f; return *this; }
VectorF3 & VectorF3::operator*=(float f) { X *= f; Y *= f; Z *= f; return *this; }
VectorF3 & VectorF3::operator/=(float f) { X /= f; Y /= f; Z /= f; return *this; }

VectorF3 operator+(VectorF3 p, float f) { return VectorF3(p.X + f, p.Y + f, p.Z + f); }
VectorF3 operator-(VectorF3 p, float f) { return VectorF3(p.X - f, p.Y - f, p.Z - f); }
VectorF3 operator*(VectorF3 p, float f) { return VectorF3(p.X * f, p.Y * f, p.Z * f); }
VectorF3 operator/(VectorF3 p, float f) { return VectorF3(p.X / f, p.Y / f, p.Z / f); }

VectorF3 operator+(float f, VectorF3 p) { return VectorF3(f + p.X, f + p.Y, f + p.Z); }
VectorF3 operator-(float f, VectorF3 p) { return VectorF3(f - p.X, f - p.Y, f - p.Z); }
VectorF3 operator*(float f, VectorF3 p) { return VectorF3(f * p.X, f * p.Y, f * p.Z); }
VectorF3 operator/(float f, VectorF3 p) { return VectorF3(f / p.X, f / p.Y, f / p.Z); }
