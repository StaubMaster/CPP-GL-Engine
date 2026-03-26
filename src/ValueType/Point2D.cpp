#include "ValueType/Point2D.hpp"

#include <math.h>



Point2D::~Point2D() { }

Point2D::Point2D()
	: X(0.0f)
	, Y(0.0f)
{ }
Point2D::Point2D(float x, float y)
	: X(x)
	, Y(y)
{ }

Point2D::Point2D(const Point2D & other)
	: X(other.X)
	, Y(other.Y)
{ }
Point2D & Point2D::operator=(const Point2D & other)
{
	X = other.X;
	Y = other.Y;
	return *this;
}



float Point2D::length2() const
{
	return ((X * X) + (Y * Y));
}
float Point2D::length() const
{
	return sqrt(length2());
}
Point2D Point2D::normalize() const
{
	float len = length();
	return Point2D(X / len, Y / len);
}
Point2D Point2D::normalize(float & len) const
{
	len = length();
	return Point2D(X / len, Y / len);
}



Point2D Point2D::operator+() const { return Point2D(+X, +Y); }
Point2D Point2D::operator-() const { return Point2D(-X, -Y); }
Point2D Point2D::operator!() const { return normalize(); }





Point2D & Point2D::operator+=(float f) { X += f; Y += f; return *this; }
Point2D & Point2D::operator-=(float f) { X -= f; Y -= f; return *this; }
Point2D & Point2D::operator*=(float f) { X *= f; Y *= f; return *this; }
Point2D & Point2D::operator/=(float f) { X /= f; Y /= f; return *this; }



Point2D Point2D::operator+(const Point2D & other) const { return Point2D(X + other.X, Y + other.Y); }
Point2D Point2D::operator-(const Point2D & other) const { return Point2D(X - other.X, Y - other.Y); }
Point2D Point2D::operator*(const Point2D & other) const { return Point2D(X * other.X, Y * other.Y); }
Point2D Point2D::operator/(const Point2D & other) const { return Point2D(X / other.X, Y / other.Y); }

Point2D & Point2D::operator+=(const Point2D & other) { X += other.X; Y += other.Y; return *this; }
Point2D & Point2D::operator-=(const Point2D & other) { X -= other.X; Y -= other.Y; return *this; }
Point2D & Point2D::operator*=(const Point2D & other) { X *= other.X; Y *= other.Y; return *this; }
Point2D & Point2D::operator/=(const Point2D & other) { X /= other.X; Y /= other.Y; return *this; }





float Point2D::dot(const Point2D & other) const
{
	return (
		(X * other.X) +
		(Y * other.Y)
	);
}
float Point2D::dot(const Point2D & p0, const Point2D & p1)
{
	return p0.dot(p1);
}



/*
(p0.Y * p1.Z) - (p0.Z * p1.Y)
(p0.Z * p1.X) - (p0.X * p1.Z)
(p0.X * p1.Y) - (p0.Y * p1.X)
*/
float Point2D::cross(const Point2D & other) const
{
	return (
		(X * other.Y) -
		(Y * other.X)
	);
}
float Point2D::cross(const Point2D & p0, const Point2D & p1)
{
	return (
		(p0.X * p1.Y) -
		(p0.Y * p1.X)
	);
}

Point2D Point2D::cross(float f) const
{
	return Point2D(
		+(Y * f),
		-(X * f)
	);
}
Point2D Point2D::cross(float f, const Point2D & p)
{
/*
+(00 * 0000) -(f0 * p1.Y)
+(f0 * p1.X) -(00 * 0000)
+(00 * p1.Y) -(00 * p1.X)
*/
	return Point2D(
		-(f * p.Y),
		+(f * p.X)
	);
}
Point2D Point2D::cross(const Point2D & p, float f)
{
/*
+(p0.Y * f1) -(0000 * 00)
+(0000 * 00) -(p0.X * f1)
+(p0.X * 00) -(p0.Y * 00)
*/
	return Point2D(
		+(p.Y * f),
		-(p.X * f)
	);
}





Point2D operator+(Point2D p, float f) { return Point2D(p.X + f, p.Y + f); }
Point2D operator-(Point2D p, float f) { return Point2D(p.X - f, p.Y - f); }
Point2D operator*(Point2D p, float f) { return Point2D(p.X * f, p.Y * f); }
Point2D operator/(Point2D p, float f) { return Point2D(p.X / f, p.Y / f); }

Point2D operator+(float f, Point2D p) { return Point2D(f + p.X, f + p.Y); }
Point2D operator-(float f, Point2D p) { return Point2D(f - p.X, f - p.Y); }
Point2D operator*(float f, Point2D p) { return Point2D(f * p.X, f * p.Y); }
Point2D operator/(float f, Point2D p) { return Point2D(f / p.X, f / p.Y); }
