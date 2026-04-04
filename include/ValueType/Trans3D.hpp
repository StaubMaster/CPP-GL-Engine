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

	// is Scaling done before or after everything else ?
	// what about the others
	// does it depend on the order of making the Matrixes ?



	~Trans3D();
	
	Trans3D();
	Trans3D(Point3D pos);
	Trans3D(EulerAngle3D rot);
	Trans3D(Point3D pos, EulerAngle3D rot);

	Trans3D(const Trans3D & other);
	Trans3D & operator=(const Trans3D & other);



	Point3D		forward(Point3D p) const;
	Point3D		reverse(Point3D p) const;
};


#endif