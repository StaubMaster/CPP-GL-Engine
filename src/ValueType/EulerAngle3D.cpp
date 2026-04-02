#include "ValueType/EulerAngle3D.hpp"
#include "ValueType/Point3D.hpp"
#include "ValueType/Point2D.hpp"



EulerAngle3D::~EulerAngle3D()
{ }
EulerAngle3D::EulerAngle3D()
	: Z0()
	, X1()
	, Y2()
{ }
EulerAngle3D::EulerAngle3D(const EulerAngle3D & other)
	: Z0(other.Z0)
	, X1(other.X1)
	, Y2(other.Y2)
{ }
const EulerAngle3D & EulerAngle3D::operator=(const EulerAngle3D & other)
{
	Z0 = other.Z0;
	X1 = other.X1;
	Y2 = other.Y2;
	return *this;
}



EulerAngle3D::EulerAngle3D(Angle a0, Angle a1, Angle a2)
	: Z0(a0)
	, X1(a1)
	, Y2(a2)
{ }
EulerAngle3D EulerAngle3D::Degrees(float a0, float a1, float a2)
{
	return EulerAngle3D(
		Angle::Degrees(a0),
		Angle::Degrees(a1),
		Angle::Degrees(a2)
	);
}
EulerAngle3D EulerAngle3D::Radians(float a0, float a1, float a2)
{
	return EulerAngle3D(
		Angle::Radians(a0),
		Angle::Radians(a1),
		Angle::Radians(a2)
	);
}



Point3D EulerAngle3D::Forward(Point3D p) const
{
	Point2D temp;
	Z0.Forward(p.X, p.Y);
	X1.Forward(p.Y, p.Z);
	Y2.Forward(p.Z, p.X);
	return p;
}
Point3D EulerAngle3D::Reverse(Point3D p) const
{
	Point2D temp;
	Y2.Reverse(p.Z, p.X);
	X1.Reverse(p.Y, p.Z);
	Z0.Reverse(p.X, p.Y);
	return p;
}



EulerAngle3D	EulerAngle3D::operator+(const EulerAngle3D & other) const { return EulerAngle3D(Z0 + other.Z0, X1 + other.X1, Y2 + other.Y2); }
EulerAngle3D	EulerAngle3D::operator-(const EulerAngle3D & other) const { return EulerAngle3D(Z0 - other.Z0, X1 - other.X1, Y2 - other.Y2); }
EulerAngle3D &	EulerAngle3D::operator+=(const EulerAngle3D & other) { Z0 += other.Z0; X1 += other.X1; Y2 += other.Y2; return *this; }
EulerAngle3D &	EulerAngle3D::operator-=(const EulerAngle3D & other) { Z0 += other.Z0; X1 -= other.X1; Y2 -= other.Y2; return *this; }

EulerAngle3D	EulerAngle3D::operator*(const float & flt) const { return EulerAngle3D(Z0 * flt, X1 * flt, Y2 * flt); }
EulerAngle3D	EulerAngle3D::operator/(const float & flt) const { return EulerAngle3D(Z0 / flt, X1 / flt, Y2 / flt); }
EulerAngle3D &	EulerAngle3D::operator*=(const float & flt) { Z0 *= flt; X1 *= flt; Y2 *= flt; return *this; }
EulerAngle3D &	EulerAngle3D::operator/=(const float & flt) { Z0 /= flt; X1 /= flt; Y2 /= flt; return *this; }
