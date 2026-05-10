#ifndef  LINE_3D_HPP
# define LINE_3D_HPP

# include "ValueType/Vector/F3.hpp"

struct Ray3D;

struct Line3D
{
	public:
	VectorF3	Origin;
	VectorF3	Target;

	public:
	~Line3D();

	Line3D();
	Line3D(VectorF3 origin, VectorF3 target);
	
	Line3D(const Line3D & other);
	Line3D & operator=(const Line3D & other);
	
	Line3D(const Ray3D & ray);



	Line3D	Reverse() const;

	VectorF3	Differance() const;
	float		Length() const;

	VectorF3	Middle() const;
};

#endif