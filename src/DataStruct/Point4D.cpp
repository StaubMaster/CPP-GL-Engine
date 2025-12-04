#include "DataStruct/Point4D.hpp"

#include <math.h>



Point4D::Point4D() :
	X(0), Y(0), Z(0), W(0)
{ }
Point4D::Point4D(float x, float y, float z, float w) :
	X(x), Y(y), Z(z), W(w)
{ }
Point4D::~Point4D()
{ }



Point4D::Point4D(const Point4D & other) :
	X(other.X), Y(other.Y), Z(other.Z), W(other.W)
{ }
Point4D & Point4D::operator =(const Point4D & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	W = other.W;
	return *this;
}



float Point4D::length2() const
{
	return ((X * X) + (Y * Y) + (Z * Z) + (W * W));
}
float Point4D::length() const
{
	return sqrt(length2());
}
Point4D Point4D::normalize() const
{
	float len = length();
	return Point4D(
		X / len,
		Y / len,
		Z / len,
		W / len
	);
}





Point4D Point4D::operator +() const
{
	return Point4D(
		+X,
		+Y,
		+Z,
		+W
	);
}
Point4D Point4D::operator -() const
{
	return Point4D(
		-X,
		-Y,
		-Z,
		-W
	);
}
Point4D Point4D::operator !() const
{
	return normalize();
}





Point4D Point4D::operator +(const float & flt) const
{
	return Point4D(
		X + flt,
		Y + flt,
		Z + flt,
		W + flt
	);
}
Point4D Point4D::operator -(const float & flt) const
{
	return Point4D(
		X - flt,
		Y - flt,
		Z - flt,
		W - flt
	);
}
Point4D Point4D::operator *(const float & flt) const
{
	return Point4D(
		X * flt,
		Y * flt,
		Z * flt,
		W * flt
	);
}
Point4D Point4D::operator /(const float & flt) const
{
	return Point4D(
		X / flt,
		Y / flt,
		Z / flt,
		W / flt
	);
}



Point4D & Point4D::operator +=(const float & flt)
{
	X += flt;
	Y += flt;
	Z += flt;
	W += flt;
	return *this;
}
Point4D & Point4D::operator -=(const float & flt)
{
	X -= flt;
	Y -= flt;
	Z -= flt;
	W -= flt;
	return *this;
}
Point4D & Point4D::operator *=(const float & flt)
{
	X *= flt;
	Y *= flt;
	Z *= flt;
	W *= flt;
	return *this;
}
Point4D & Point4D::operator /=(const float & flt)
{
	X /= flt;
	Y /= flt;
	Z /= flt;
	W /= flt;
	return *this;
}





Point4D Point4D::operator +(const Point4D & other) const
{
	return Point4D(
		X + other.X,
		Y + other.Y,
		Z + other.Z,
		W + other.W
	);
}
Point4D Point4D::operator -(const Point4D & other) const
{
	return Point4D(
		X - other.X,
		Y - other.Y,
		Z - other.Z,
		W - other.W
	);
}
Point4D Point4D::operator *(const Point4D & other) const
{
	return Point4D(
		X * other.X,
		Y * other.Y,
		Z * other.Z,
		W * other.W
	);
}
Point4D Point4D::operator /(const Point4D & other) const
{
	return Point4D(
		X / other.X,
		Y / other.Y,
		Z / other.Z,
		W / other.W
	);
}



Point4D & Point4D::operator +=(const Point4D & other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;
	W += other.W;
	return *this;
}
Point4D & Point4D::operator -=(const Point4D & other)
{
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;
	W -= other.W;
	return *this;
}
Point4D & Point4D::operator *=(const Point4D & other)
{
	X *= other.X;
	Y *= other.Y;
	Z *= other.Z;
	W *= other.W;
	return *this;
}
Point4D & Point4D::operator /=(const Point4D & other)
{
	X /= other.X;
	Y /= other.Y;
	Z /= other.Z;
	W /= other.W;
	return *this;
}





float Point4D::dot(const Point4D & p0, const Point4D & p1)
{
	return (
		(p0.X * p1.X) +
		(p0.Y * p1.Y) +
		(p0.Z * p1.Z) +
		(p0.W * p1.W)
	);
}
float Point4D::operator %(const Point4D & other) const
{
	return dot(*this, other);
}
