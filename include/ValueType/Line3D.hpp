#ifndef  LINE_3D_HPP
# define LINE_3D_HPP

# include "ValueType/Point3D.hpp"

struct Ray3D;

struct Line3D
{
	public:
	Point3D Origin;
	Point3D Target;

	public:
	~Line3D();

	Line3D();
	Line3D(Point3D origin, Point3D target);
	
	Line3D(const Line3D & other);
	Line3D & operator=(const Line3D & other);
	
	Line3D(const Ray3D & ray);



	Line3D Reverse() const;

	Point3D Differance() const;
	float Length() const;

	Point3D Middle() const;
};

#endif