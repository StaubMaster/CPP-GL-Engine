#ifndef  TRANS_3D_HPP
# define TRANS_3D_HPP

# include "ValueType/Point3D.hpp"
# include "ValueType/EulerAngle3D.hpp"

struct Matrix4x4;

struct Trans3D
{
	Point3D			Position;
	EulerAngle3D	Rotation;
	// Scale
	// Shear
	// Distort

	~Trans3D();
	Trans3D();

	Trans3D(const Trans3D & other);
	Trans3D & operator=(const Trans3D & other);

	Trans3D(Point3D pos);
	Trans3D(EulerAngle3D rot);
	Trans3D(Point3D pos, EulerAngle3D rot);

	Point3D Forward(Point3D p) const;
	Point3D Reverse(Point3D p) const;

	Matrix4x4 ToMatrixForward() const;
	Matrix4x4 ToMatrixReverse() const;
};


#endif