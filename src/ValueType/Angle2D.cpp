#include "ValueType/Angle2D.hpp"
#include "ValueType/Point2D.hpp"

#include <math.h>



Angle2D::Angle2D() :
	Ang(),
	Mat(Matrix2x2::Default())
{ CalcMatrix(); }
Angle2D::Angle2D(Angle ang) :
	Ang(ang),
	Mat(Matrix2x2::Default())
{ CalcMatrix(); }
Angle2D::~Angle2D()
{ }



Angle2D::Angle2D(const Angle2D & other) :
	Ang(other.Ang),
	Mat(other.Mat)
{ }
const Angle2D & Angle2D::operator =(const Angle2D & other)
{
	this -> Ang = other.Ang;
	this -> Mat = other.Mat;
	return *this;
}



Angle2D Angle2D::FromPoint2D(const Point2D & dir)
{
	return Angle2D(
		Angle::SaTan2(dir.Y, dir.X)
	);
}



void Angle2D::CalcMatrix()
{
	float sin_ = Ang.Sin();
	float cos_ = Ang.Cos();
	Mat = Matrix2x2(
		 +cos_ , -sin_ ,
		 +sin_ , +cos_
	);
}



Point2D	Angle2D::rotateFore(Point2D p) const
{
	return Mat.Multiply0(p);
}
Point2D	Angle2D::rotateBack(Point2D p) const
{
	return Mat.Multiply1(p);
}

/*Angle2D	Angle2D::rotateFore(Angle2D a) const
{
	Point2D pX, pY, pZ;
	pX = a.rotateFore(rotateFore(Point2D(1, 0, 0)));
	pY = a.rotateFore(rotateFore(Point2D(0, 1, 0)));
	pZ = a.rotateFore(rotateFore(Point2D(0, 0, 1)));

	return Angle2D(
		Angle::SaTan2(pZ.Z, pX.Z),
		Angle::SaSin(pY.Z),
		Angle::SaTan2(pY.Y, pY.X)
	);
}*/
/*Angle2D	Angle2D::rotateBack(Angle2D a) const
{
	Point2D pX, pY, pZ;
	pX = a.rotateBack(rotateBack(Point2D(1, 0, 0)));
	pY = a.rotateBack(rotateBack(Point2D(0, 1, 0)));
	pZ = a.rotateBack(rotateBack(Point2D(0, 0, 1)));

	return Angle2D(
		Angle::SaTan2(pZ.Z, pX.Z),
		Angle::SaSin(pY.Z),
		Angle::SaTan2(pY.Y, pY.X)
	);
}*/



Angle2D Angle2D::operator+(const Angle2D & other) const
{
	return Angle2D(
		Ang + other.Ang
	);
}
Angle2D Angle2D::operator-(const Angle2D & other) const
{
	return Angle2D(
		Ang - other.Ang
	);
}

Angle2D & Angle2D::operator+=(const Angle2D & other)
{
	Ang += other.Ang;
	CalcMatrix();
	return *this;
}
Angle2D & Angle2D::operator-=(const Angle2D & other)
{
	Ang -= other.Ang;
	CalcMatrix();
	return *this;
}



Angle2D Angle2D::operator*(const float & flt) const
{
	return Angle2D(
		Ang * flt
	);
}
Angle2D Angle2D::operator/(const float & flt) const
{
	return Angle2D(
		Ang * flt
	);
}
Angle2D & Angle2D::operator*=(const float & flt)
{
	Ang *= flt;
	CalcMatrix();
	return *this;
}
Angle2D & Angle2D::operator/=(const float & flt)
{
	Ang /= flt;
	return *this;
}
