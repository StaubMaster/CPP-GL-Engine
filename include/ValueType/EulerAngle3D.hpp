#ifndef  EULER_ANGLE_3D_HPP
# define EULER_ANGLE_3D_HPP

# include "Angle.hpp"

struct Point3D;
struct Matrix3x3;

struct EulerAngle3D
{
	public:
	Angle	Z0;
	Angle	X1;
	Angle	Y2;

	public:
	~EulerAngle3D();
	EulerAngle3D();
	EulerAngle3D(const EulerAngle3D & other);
	const EulerAngle3D & operator=(const EulerAngle3D & other);

	public:
	EulerAngle3D(Angle z0, Angle x1, Angle y2);
	static EulerAngle3D Degrees(float z0, float x1, float y2);
	static EulerAngle3D Radians(float z0, float x1, float y2);

	static EulerAngle3D PointToX(Point3D dir);
	static EulerAngle3D PointToY(Point3D dir);
	static EulerAngle3D PointToZ(Point3D dir);

	public:
	Point3D	Forward(Point3D p) const;
	Point3D	Reverse(Point3D p) const;

	public:
	EulerAngle3D	operator+(const EulerAngle3D & other) const;
	EulerAngle3D	operator-(const EulerAngle3D & other) const;
	EulerAngle3D &	operator+=(const EulerAngle3D & other);
	EulerAngle3D &	operator-=(const EulerAngle3D & other);

	EulerAngle3D	operator*(const float & flt) const;
	EulerAngle3D	operator/(const float & flt) const;
	EulerAngle3D &	operator*=(const float & flt);
	EulerAngle3D &	operator/=(const float & flt);
};

#endif
