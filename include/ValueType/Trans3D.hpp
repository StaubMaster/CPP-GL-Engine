#ifndef  TRANS_3D_HPP
# define TRANS_3D_HPP

# include "ValueType/Vector/F3.hpp"
# include "ValueType/EulerAngle3D.hpp"

struct Matrix4x4;

struct Trans3D
{
	VectorF3			Position;
	EulerAngle3D	Rotation;
	// Scale
	// Shear
	// Distort

	// is Scaling done before or after everything else ?
	// what about the others
	// does it depend on the order of making the Matrixes ?



	~Trans3D();
	
	Trans3D();
	Trans3D(VectorF3 pos);
	Trans3D(EulerAngle3D rot);
	Trans3D(VectorF3 pos, EulerAngle3D rot);

	Trans3D(const Trans3D & other);
	Trans3D & operator=(const Trans3D & other);



	VectorF3		forward(VectorF3 p) const;
	VectorF3		reverse(VectorF3 p) const;
};


#endif