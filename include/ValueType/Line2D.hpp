#ifndef  LINE_2D_HPP
# define LINE_2D_HPP

# include "ValueType/Vector/F2.hpp"

struct Ray2D;

struct Line2D
{
	public:
	VectorF2	Origin;
	VectorF2	Target;

	public:
	~Line2D();

	Line2D();
	Line2D(VectorF2 origin, VectorF2 target);
	
	Line2D(const Line2D & other);
	Line2D & operator=(const Line2D & other);
	
	Line2D(const Ray2D & ray);



	Line2D	Reverse() const;

	VectorF2	Differance() const;
	float		Length() const;

	VectorF2	Middle() const;
	VectorF2	Normal() const;
};

#endif