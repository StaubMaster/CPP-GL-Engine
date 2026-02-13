#ifndef  AXISBOX_3D_HPP
# define AXISBOX_3D_HPP

#include "Point3D.hpp"

struct AxisBox3D
{
	public:
	Point3D	Min;
	Point3D	Max;

	public:
	AxisBox3D();
	AxisBox3D(Point3D min, Point3D max);

	AxisBox3D(const AxisBox3D & other);
	AxisBox3D & operator=(const AxisBox3D & other);

	public:
	void Consider(Point3D val);

	public:
	Point3D Size() const;
	Point3D Center() const;

	public:
	bool Intersekt(Point3D val) const;
	bool Intersekt(const AxisBox3D & other) const;
	static bool Intersekt(const AxisBox3D & box0, const AxisBox3D & box1);
};

#endif
