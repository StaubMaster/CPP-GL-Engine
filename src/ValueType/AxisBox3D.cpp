#include "ValueType/AxisBox3D.hpp"
#include <math.h>



AxisBox3D::AxisBox3D() :
	Min(+INFINITY, +INFINITY, +INFINITY),
	Max(-INFINITY, -INFINITY, -INFINITY)
{ }
AxisBox3D::AxisBox3D(Point3D min, Point3D max) :
	Min(min),
	Max(max)
{ }



AxisBox3D::AxisBox3D(const AxisBox3D & other) :
	Min(other.Min),
	Max(other.Max)
{ }
AxisBox3D & AxisBox3D::operator=(const AxisBox3D & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



void AxisBox3D::Consider(Point3D val)
{
	if (val.X < Min.X) { Min.X = val.X; }
	if (val.Y < Min.Y) { Min.Y = val.Y; }
	if (val.Z < Min.Z) { Min.Z = val.Z; }

	if (val.X > Max.X) { Max.X = val.X; }
	if (val.Y > Max.Y) { Max.Y = val.Y; }
	if (val.Z > Max.Z) { Max.Z = val.Z; }
}


Point3D AxisBox3D::Size() const
{
	return (Max - Min);
}
Point3D AxisBox3D::Center() const
{
	return ((Max * 0.5f) + (Min * 0.5f));
}



bool AxisBox3D::Intersekt(Point3D val) const
{
	return (Min.X <= val.X && Max.X >= val.X)
		&& (Min.Y <= val.Y && Max.Y >= val.Y)
		&& (Min.Z <= val.Z && Max.Z >= val.Z);
}
bool AxisBox3D::Intersekt(const AxisBox3D & other) const
{
	return (
		((Max.X > other.Min.X) & (Min.X < other.Max.X)) &
		((Max.Y > other.Min.Y) & (Min.Y < other.Max.Y)) &
		((Max.Z > other.Min.Z) & (Min.Z < other.Max.Z))
	);
}
