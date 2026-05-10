#include "ValueType/Vector/F4.hpp"

#include <math.h>



VectorF4::VectorF4() :
	X(0), Y(0), Z(0), W(0)
{ }
VectorF4::VectorF4(float x, float y, float z, float w) :
	X(x), Y(y), Z(z), W(w)
{ }
VectorF4::~VectorF4()
{ }



VectorF4::VectorF4(const VectorF4 & other) :
	X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{ }
VectorF4 & VectorF4::operator=(const VectorF4 & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	W = other.W;
	return *this;
}



float VectorF4::length2() const
{
	return ((X * X) + (Y * Y) + (Z * Z) + (W * W));
}
float VectorF4::length() const
{
	return sqrt(length2());
}
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
	return VectorF4(0, 0, 0, 0);
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
	return VectorF4(0, 0, 0, 0);
}

VectorF4 VectorF4::round() const
{
	return VectorF4(
		roundf(X),
		roundf(Y),
		roundf(Z),
		roundf(W)
	);
}
VectorF4 VectorF4::roundC() const
{
	return VectorF4(
		ceilf(X),
		ceilf(Y),
		ceilf(Z),
		ceilf(W)
	);
}
VectorF4 VectorF4::roundF() const
{
	return VectorF4(
		floorf(X),
		floorf(Y),
		floorf(Z),
		floorf(W)
	);
}

VectorF4 VectorF4::round(float size) const
{
	return VectorF4(
		roundf(X / size) * size,
		roundf(Y / size) * size,
		roundf(Z / size) * size,
		roundf(W / size) * size
	);
}
VectorF4 VectorF4::roundC(float size) const
{
	return VectorF4(
		ceilf(X / size) * size,
		ceilf(Y / size) * size,
		ceilf(Z / size) * size,
		ceilf(W / size) * size
	);
}
VectorF4 VectorF4::roundF(float size) const
{
	return VectorF4(
		floorf(X / size) * size,
		floorf(Y / size) * size,
		floorf(Z / size) * size,
		floorf(W / size) * size
	);
}





VectorF4 VectorF4::operator+() const
{
	return VectorF4(
		+X,
		+Y,
		+Z,
		+W
	);
}
VectorF4 VectorF4::operator-() const
{
	return VectorF4(
		-X,
		-Y,
		-Z,
		-W
	);
}
VectorF4 VectorF4::operator!() const
{
	return normalize();
}





VectorF4 VectorF4::operator+(const float & flt) const
{
	return VectorF4(
		X + flt,
		Y + flt,
		Z + flt,
		W + flt
	);
}
VectorF4 VectorF4::operator-(const float & flt) const
{
	return VectorF4(
		X - flt,
		Y - flt,
		Z - flt,
		W - flt
	);
}
VectorF4 VectorF4::operator*(const float & flt) const
{
	return VectorF4(
		X * flt,
		Y * flt,
		Z * flt,
		W * flt
	);
}
VectorF4 VectorF4::operator/(const float & flt) const
{
	return VectorF4(
		X / flt,
		Y / flt,
		Z / flt,
		W / flt
	);
}



VectorF4 & VectorF4::operator+=(const float & flt)
{
	X += flt;
	Y += flt;
	Z += flt;
	W += flt;
	return *this;
}
VectorF4 & VectorF4::operator-=(const float & flt)
{
	X -= flt;
	Y -= flt;
	Z -= flt;
	W -= flt;
	return *this;
}
VectorF4 & VectorF4::operator*=(const float & flt)
{
	X *= flt;
	Y *= flt;
	Z *= flt;
	W *= flt;
	return *this;
}
VectorF4 & VectorF4::operator/=(const float & flt)
{
	X /= flt;
	Y /= flt;
	Z /= flt;
	W /= flt;
	return *this;
}





VectorF4 VectorF4::operator+(const VectorF4 & other) const
{
	return VectorF4(
		X + other.X,
		Y + other.Y,
		Z + other.Z,
		W + other.W
	);
}
VectorF4 VectorF4::operator-(const VectorF4 & other) const
{
	return VectorF4(
		X - other.X,
		Y - other.Y,
		Z - other.Z,
		W - other.W
	);
}
VectorF4 VectorF4::operator*(const VectorF4 & other) const
{
	return VectorF4(
		X * other.X,
		Y * other.Y,
		Z * other.Z,
		W * other.W
	);
}
VectorF4 VectorF4::operator/(const VectorF4 & other) const
{
	return VectorF4(
		X / other.X,
		Y / other.Y,
		Z / other.Z,
		W / other.W
	);
}



VectorF4 & VectorF4::operator+=(const VectorF4 & other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;
	W += other.W;
	return *this;
}
VectorF4 & VectorF4::operator-=(const VectorF4 & other)
{
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;
	W -= other.W;
	return *this;
}
VectorF4 & VectorF4::operator*=(const VectorF4 & other)
{
	X *= other.X;
	Y *= other.Y;
	Z *= other.Z;
	W *= other.W;
	return *this;
}
VectorF4 & VectorF4::operator/=(const VectorF4 & other)
{
	X /= other.X;
	Y /= other.Y;
	Z /= other.Z;
	W /= other.W;
	return *this;
}





float VectorF4::dot(const VectorF4 & p0, const VectorF4 & p1)
{
	return (
		(p0.X * p1.X) +
		(p0.Y * p1.Y) +
		(p0.Z * p1.Z) +
		(p0.W * p1.W)
	);
}
