#ifndef  TRANSFORMATION_3D_HPP
# define TRANSFORMATION_3D_HPP

# include "ValueType/Point3D.hpp"
# include "ValueType/EulerAngle3D.hpp"

struct Matrix4x4;

struct Transformation3D
{
	Point3D			Position;
	EulerAngle3D	Rotation;
	// Scale
	// Shear
	// Distort

	~Transformation3D();
	Transformation3D();

	Transformation3D(const Transformation3D & other);
	Transformation3D & operator=(const Transformation3D & other);

	Transformation3D(Point3D pos);
	Transformation3D(EulerAngle3D rot);
	Transformation3D(Point3D pos, EulerAngle3D rot);

	Matrix4x4 ToMatrixForward() const;
	Matrix4x4 ToMatrixReverse() const;

	Point3D Forward(Point3D p) const;
	Point3D Reverse(Point3D p) const;
};


#endif