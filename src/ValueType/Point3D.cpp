#include "ValueType/Point3D.hpp"

#include <math.h>



Point3D::~Point3D() { }

Point3D::Point3D() :
	X(0), Y(0), Z(0)
{ }
Point3D::Point3D(float x, float y, float z) :
	X(x), Y(y), Z(z)
{ }

Point3D::Point3D(const Point3D & other) :
	X(other.X), Y(other.Y), Z(other.Z)
{ }
Point3D & Point3D::operator=(const Point3D & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return *this;
}





float Point3D::length2() const
{
	return ((X * X) + (Y * Y) + (Z * Z));
}
float Point3D::length() const
{
	return sqrt(length2());
}
Point3D Point3D::normalize() const
{
	float len = length();
	if (len > 0.0f)
	{
		return Point3D(
			X / len,
			Y / len,
			Z / len
		);
	}
	return Point3D(0, 0, 0);
}
Point3D Point3D::normalize(float & len) const
{
	len = length();
	if (len > 0.0f)
	{
		return Point3D(
			X / len,
			Y / len,
			Z / len
		);
	}
	len = 0.0f;
	return Point3D(0, 0, 0);
}

Point3D Point3D::round() const
{
	return Point3D(
		roundf(X),
		roundf(Y),
		roundf(Z)
	);
}
Point3D Point3D::roundC() const
{
	return Point3D(
		ceilf(X),
		ceilf(Y),
		ceilf(Z)
	);
}
Point3D Point3D::roundF() const
{
	return Point3D(
		floorf(X),
		floorf(Y),
		floorf(Z)
	);
}

Point3D Point3D::round(float size) const
{
	return Point3D(
		roundf(X / size) * size,
		roundf(Y / size) * size,
		roundf(Z / size) * size
	);
}
Point3D Point3D::roundC(float size) const
{
	return Point3D(
		ceilf(X / size) * size,
		ceilf(Y / size) * size,
		ceilf(Z / size) * size
	);
}
Point3D Point3D::roundF(float size) const
{
	return Point3D(
		floorf(X / size) * size,
		floorf(Y / size) * size,
		floorf(Z / size) * size
	);
}





Point3D Point3D::operator+() const
{
	return Point3D(
		+X,
		+Y,
		+Z
	);
}
Point3D Point3D::operator-() const
{
	return Point3D(
		-X,
		-Y,
		-Z
	);
}
Point3D Point3D::operator!() const
{
	return normalize();
}

Point3D Point3D::operator+(const Point3D & other) const { return Point3D(X + other.X, Y + other.Y, Z + other.Z); }
Point3D Point3D::operator-(const Point3D & other) const { return Point3D(X - other.X, Y - other.Y, Z - other.Z); }
Point3D Point3D::operator*(const Point3D & other) const { return Point3D(X * other.X, Y * other.Y, Z * other.Z); }
Point3D Point3D::operator/(const Point3D & other) const { return Point3D(X / other.X, Y / other.Y, Z / other.Z); }

Point3D & Point3D::operator+=(const Point3D & other) { X += other.X; Y += other.Y; Z += other.Z; return *this; }
Point3D & Point3D::operator-=(const Point3D & other) { X -= other.X; Y -= other.Y; Z -= other.Z; return *this; }
Point3D & Point3D::operator*=(const Point3D & other) { X *= other.X; Y *= other.Y; Z *= other.Z; return *this; }
Point3D & Point3D::operator/=(const Point3D & other) { X /= other.X; Y /= other.Y; Z /= other.Z; return *this; }





float Point3D::dot(const Point3D & p0, const Point3D & p1)
{
	return (
		(p0.X * p1.X) +
		(p0.Y * p1.Y) +
		(p0.Z * p1.Z)
	);
}
float Point3D::dot(const Point3D & other) const
{
	return dot(*this, other);
}

Point3D Point3D::cross(const Point3D & p0, const Point3D & p1)
{
	return Point3D(
		(p0.Y * p1.Z) - (p0.Z * p1.Y),
		(p0.Z * p1.X) - (p0.X * p1.Z),
		(p0.X * p1.Y) - (p0.Y * p1.X)
	);
}
Point3D Point3D::cross(const Point3D & other) const
{
	return cross(*this, other);
}





Point3D & Point3D::operator+=(float f) { X += f; Y += f; Z += f; return *this; }
Point3D & Point3D::operator-=(float f) { X -= f; Y -= f; Z -= f; return *this; }
Point3D & Point3D::operator*=(float f) { X *= f; Y *= f; Z *= f; return *this; }
Point3D & Point3D::operator/=(float f) { X /= f; Y /= f; Z /= f; return *this; }

Point3D operator+(Point3D p, float f) { return Point3D(p.X + f, p.Y + f, p.Z + f); }
Point3D operator-(Point3D p, float f) { return Point3D(p.X - f, p.Y - f, p.Z - f); }
Point3D operator*(Point3D p, float f) { return Point3D(p.X * f, p.Y * f, p.Z * f); }
Point3D operator/(Point3D p, float f) { return Point3D(p.X / f, p.Y / f, p.Z / f); }

Point3D operator+(float f, Point3D p) { return Point3D(f + p.X, f + p.Y, f + p.Z); }
Point3D operator-(float f, Point3D p) { return Point3D(f - p.X, f - p.Y, f - p.Z); }
Point3D operator*(float f, Point3D p) { return Point3D(f * p.X, f * p.Y, f * p.Z); }
Point3D operator/(float f, Point3D p) { return Point3D(f / p.X, f / p.Y, f / p.Z); }
