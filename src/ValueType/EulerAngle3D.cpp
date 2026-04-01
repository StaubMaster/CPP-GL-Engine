#include "ValueType/EulerAngle3D.hpp"



EulerAngle3D::~EulerAngle3D()
{ }
EulerAngle3D::EulerAngle3D()
	: X()
	, Y()
	, Z()
{ }
EulerAngle3D::EulerAngle3D(const EulerAngle3D & other)
	: X(other.X)
	, Y(other.Y)
	, Z(other.Z)
{ }
const EulerAngle3D & EulerAngle3D::operator=(const EulerAngle3D & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return *this;
}



EulerAngle3D::EulerAngle3D(Angle x, Angle y, Angle z)
	: X(x)
	, Y(y)
	, Z(z)
{ }
EulerAngle3D EulerAngle3D::Degrees(float x, float y, float z)
{
	return EulerAngle3D(
		Angle::Degrees(x),
		Angle::Degrees(y),
		Angle::Degrees(z)
	);
}
EulerAngle3D EulerAngle3D::Radians(float x, float y, float z)
{
	return EulerAngle3D(
		Angle::Radians(x),
		Angle::Radians(y),
		Angle::Radians(z)
	);
}



EulerAngle3D	EulerAngle3D::operator+(const EulerAngle3D & other) const { return EulerAngle3D(X + other.X, Y + other.Y, Z + other.Z); }
EulerAngle3D	EulerAngle3D::operator-(const EulerAngle3D & other) const { return EulerAngle3D(X - other.X, Y - other.Y, Z - other.Z); }
EulerAngle3D &	EulerAngle3D::operator+=(const EulerAngle3D & other) { X += other.X; Y += other.Y; Z += other.Z; return *this; }
EulerAngle3D &	EulerAngle3D::operator-=(const EulerAngle3D & other) { X += other.X; Y -= other.Y; Z -= other.Z; return *this; }

EulerAngle3D	EulerAngle3D::operator*(const float & flt) const { return EulerAngle3D(X * flt, Y * flt, Z * flt); }
EulerAngle3D	EulerAngle3D::operator/(const float & flt) const { return EulerAngle3D(X / flt, Y / flt, Z / flt); }
EulerAngle3D &	EulerAngle3D::operator*=(const float & flt) { X *= flt; Y *= flt; Z *= flt; return *this; }
EulerAngle3D &	EulerAngle3D::operator/=(const float & flt) { X /= flt; Y /= flt; Z /= flt; return *this; }
