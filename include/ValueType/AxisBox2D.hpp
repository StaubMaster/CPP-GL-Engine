#ifndef  AXISBOX_2D_HPP
# define AXISBOX_2D_HPP

#include "Point2D.hpp"

struct AxisBox2D
{
	public:
	Point2D	Min;
	Point2D	Max;

	public:
	AxisBox2D();
	AxisBox2D(Point2D min, Point2D max);

	AxisBox2D(const AxisBox2D & other);
	AxisBox2D & operator=(const AxisBox2D & other);

	public:
	void Consider(Point2D val);

	public:
	Point2D Size() const;
	Point2D Center() const;

	public:
	bool Intersekt(Point2D val) const;
	bool Intersekt(const AxisBox2D & other) const;
};

#endif
