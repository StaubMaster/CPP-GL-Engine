#include "ValueType/Angle3D.hpp"
#include "ValueType/Point3D.hpp"

#include <math.h>



Angle3D::Angle3D() :
	X(),
	Y(),
	Z(),
	Mat(Matrix3x3::Default())
{ CalcMatrix(); }
Angle3D::Angle3D(Angle x, Angle y, Angle z) :
	X(x),
	Y(y),
	Z(z),
	Mat(Matrix3x3::Default())
{ CalcMatrix(); }
Angle3D::~Angle3D()
{ }



Angle3D::Angle3D(const Angle3D & other) :
	X(other.X),
	Y(other.Y),
	Z(other.Z),
	Mat(other.Mat)
{ }
const Angle3D & Angle3D::operator =(const Angle3D & other)
{
	this -> X = other.X;
	this -> Y = other.Y;
	this -> Z = other.Z;
	this -> Mat = other.Mat;
	return *this;
}



Angle3D Angle3D::FromPoint3D(const Point3D & dir)
{
	float len = sqrt((dir.X * dir.X) + (dir.Z * dir.Z));

	return Angle3D(
		Angle::SaTan2(dir.Z, dir.X),
		Angle::SaTan2(len, dir.Y),
		Angle()
	);
}



void Angle3D::CalcMatrix()
{
	float sinX = X.Sin();
	float cosX = X.Cos();
	Matrix3x3 matX(
		 +cosX , 0 , -sinX ,
		   0   , 1 ,   0   ,
		 +sinX , 0 , +cosX
	);

	float sinY = Y.Sin();
	float cosY = Y.Cos();
	Matrix3x3 matY(
		 1 ,   0   ,   0   ,
		 0 , +cosY , -sinY ,
		 0 , +sinY , +cosY
	);

	float sinZ = Z.Sin();
	float cosZ = Z.Cos();
	Matrix3x3 matZ(
		 +cosZ , +sinZ , 0 ,
		 -sinZ , +cosZ , 0 ,
		   0   ,   0   , 1
	);

	Mat = Matrix3x3::Default();
	Mat = Mat * matZ;
	Mat = Mat * matY;
	Mat = Mat * matX;
}



Point3D	Angle3D::rotateFore(Point3D p) const
{
	return Mat.Multiply0(p);
}
Point3D	Angle3D::rotateBack(Point3D p) const
{
	return Mat.Multiply1(p);
}

Angle3D	Angle3D::rotateFore(Angle3D a) const
{
	Point3D pX, pY, pZ;
	pX = a.rotateFore(rotateFore(Point3D(1, 0, 0)));
	pY = a.rotateFore(rotateFore(Point3D(0, 1, 0)));
	pZ = a.rotateFore(rotateFore(Point3D(0, 0, 1)));

	return Angle3D(
		Angle::SaTan2(pZ.Z, pX.Z),
		Angle::SaSin(pY.Z),
		Angle::SaTan2(pY.Y, pY.X)
	);
	/*return Angle3D(
		atan2f(pX.Z, pZ.Z),
		asinf(pY.Z),
		atan2(pY.X, pY.Y)
	);*/
}
Angle3D	Angle3D::rotateBack(Angle3D a) const
{
	Point3D pX, pY, pZ;
	pX = a.rotateBack(rotateBack(Point3D(1, 0, 0)));
	pY = a.rotateBack(rotateBack(Point3D(0, 1, 0)));
	pZ = a.rotateBack(rotateBack(Point3D(0, 0, 1)));

	return Angle3D(
		Angle::SaTan2(pZ.Z, pX.Z),
		Angle::SaSin(pY.Z),
		Angle::SaTan2(pY.Y, pY.X)
	);
	/*return Angle3D(
		atan2f(pX.Z, pZ.Z),
		asinf(pY.Z),
		atan2(pY.X, pY.Y)
	);*/
}



Angle3D Angle3D::operator+(const Angle3D & other) const
{
	return Angle3D(
		X + other.X,
		Y + other.Y,
		Z + other.Z
	);
}
Angle3D Angle3D::operator-(const Angle3D & other) const
{
	return Angle3D(
		X - other.X,
		Y - other.Y,
		Z - other.Z
	);
}

Angle3D & Angle3D::operator+=(const Angle3D & other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;
	CalcMatrix();
	return *this;
}
Angle3D & Angle3D::operator-=(const Angle3D & other)
{
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;
	CalcMatrix();
	return *this;
}
