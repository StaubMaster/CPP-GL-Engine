#ifndef  EULER_ANGLE_3D_HPP
# define EULER_ANGLE_3D_HPP

# include "Angle.hpp"

struct Point3D;
struct Matrix3x3;

struct EulerAngle3D
{
	public:
	Angle	X;
	Angle	Y;
	Angle	Z;

	public:
	~EulerAngle3D();
	EulerAngle3D();
	EulerAngle3D(const EulerAngle3D & other);
	const EulerAngle3D & operator=(const EulerAngle3D & other);

	public:
	EulerAngle3D(Angle x, Angle y, Angle z);
	static EulerAngle3D Degrees(float x, float y, float z);
	static EulerAngle3D Radians(float x, float y, float z);

	public:
	Matrix3x3	ToMatrix() const;

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
