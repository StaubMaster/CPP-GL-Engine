#ifndef  TRANS_2D_HPP
# define TRANS_2D_HPP

# include "ValueType/Vector/F2.hpp"
# include "Angle.hpp"

struct Ray2D;
struct Line2D;

struct Trans2D
{
	VectorF2		Pos; // Position
	Angle		Rot; // Rotation



	~Trans2D();

	Trans2D();
	Trans2D(VectorF2 pos);
	Trans2D(VectorF2 pos, Angle rot);

	Trans2D(const Trans2D & other);
	Trans2D & operator=(const Trans2D & other);



	VectorF2		forward(VectorF2 p) const;
	VectorF2		reverse(VectorF2 p) const;

	Ray2D		forward(Ray2D ray) const;
	Ray2D		reverse(Ray2D ray) const;
};

#endif
