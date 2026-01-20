#include "ValueType/AxisBox2D.hpp"
#include <math.h>



AxisBox2D::AxisBox2D() :
	Min(+INFINITY, +INFINITY),
	Max(-INFINITY, -INFINITY)
{ }
AxisBox2D::AxisBox2D(Point2D min, Point2D max) :
	Min(min),
	Max(max)
{ }



AxisBox2D::AxisBox2D(const AxisBox2D & other) :
	Min(other.Min),
	Max(other.Max)
{ }
AxisBox2D & AxisBox2D::operator=(const AxisBox2D & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



void AxisBox2D::Consider(Point2D val)
{
	if (val.X < Min.X) { Min.X = val.X; }
	if (val.Y < Min.Y) { Min.Y = val.Y; }

	if (val.X > Max.X) { Max.X = val.X; }
	if (val.Y > Max.Y) { Max.Y = val.Y; }
}


Point2D AxisBox2D::Size() const
{
	return (Max - Min);
}
Point2D AxisBox2D::Center() const
{
	return ((Max * 0.5f) + (Min * 0.5f));
}



bool AxisBox2D::Intersekt(Point2D val) const
{
	return (Min.X <= val.X && Max.X >= val.X)
		&& (Min.Y <= val.Y && Max.Y >= val.Y);
}
