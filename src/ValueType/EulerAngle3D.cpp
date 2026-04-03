#include "ValueType/EulerAngle3D.hpp"
#include "ValueType/Point3D.hpp"
#include "ValueType/Point2D.hpp"

#include <math.h>



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



EulerAngle3D::EulerAngle3D(Angle z0, Angle x1, Angle y2)
	: Z0(z0)
	, X1(x1)
	, Y2(y2)
{ }
EulerAngle3D EulerAngle3D::Degrees(float z0, float x1, float y2)
{
	return EulerAngle3D(
		Angle::Degrees(z0),
		Angle::Degrees(x1),
		Angle::Degrees(y2)
	);
}
EulerAngle3D EulerAngle3D::Radians(float z0, float x1, float y2)
{
	return EulerAngle3D(
		Angle::Radians(z0),
		Angle::Radians(x1),
		Angle::Radians(y2)
	);
}

EulerAngle3D EulerAngle3D::PointToX(Point3D dir)
{
	float len_Y = sqrt((dir.Z * dir.Z) + (dir.X * dir.X));
	return EulerAngle3D(
		+Angle::aTan2(dir.Y, len_Y),
		Angle(),
		-Angle::aTan2(dir.Z, dir.X)
	);
}
EulerAngle3D EulerAngle3D::PointToY(Point3D dir)
{
	float len_X = sqrt((dir.Y * dir.Y) + (dir.Z * dir.Z));
	return EulerAngle3D(
		-Angle::aTan2(dir.X, len_X),
		+Angle::aTan2(dir.Z, dir.Y),
		Angle()
	);
}
EulerAngle3D EulerAngle3D::PointToZ(Point3D dir)
{
	float len_Y = sqrt((dir.Z * dir.Z) + (dir.X * dir.X));
	return EulerAngle3D(
		Angle(),
		-Angle::aTan2(dir.Y, len_Y),
		+Angle::aTan2(dir.X, dir.Z)
	);
}





EulerAngle3D EulerAngle3D::round(Angle size) const { return EulerAngle3D(Z0.round(size), X1.round(size), Y2.round(size) ); }
EulerAngle3D EulerAngle3D::roundC(Angle size) const { return EulerAngle3D(Z0.roundC(size), X1.roundC(size), Y2.roundC(size) ); }
EulerAngle3D EulerAngle3D::roundF(Angle size) const { return EulerAngle3D(Z0.roundF(size), X1.roundF(size), Y2.roundF(size) ); }





Point3D EulerAngle3D::forward(Point3D p) const
{
	Point2D temp;
	Z0.forward(p.X, p.Y);
	X1.forward(p.Y, p.Z);
	Y2.forward(p.Z, p.X);
	return p;
}
Point3D EulerAngle3D::reverse(Point3D p) const
{
	Point2D temp;
	Y2.reverse(p.Z, p.X);
	X1.reverse(p.Y, p.Z);
	Z0.reverse(p.X, p.Y);
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
