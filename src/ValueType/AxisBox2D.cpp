#include "ValueType/Box/F2.hpp"
#include <math.h>



BoxF2::BoxF2() :
	Min(+INFINITY, +INFINITY),
	Max(-INFINITY, -INFINITY)
{ }
BoxF2::BoxF2(VectorF2 min, VectorF2 max) :
	Min(min),
	Max(max)
{ }



BoxF2::BoxF2(const BoxF2 & other) :
	Min(other.Min),
	Max(other.Max)
{ }
BoxF2 & BoxF2::operator=(const BoxF2 & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



void BoxF2::Consider(VectorF2 val)
{
	if (val.X < Min.X) { Min.X = val.X; }
	if (val.Y < Min.Y) { Min.Y = val.Y; }

	if (val.X > Max.X) { Max.X = val.X; }
	if (val.Y > Max.Y) { Max.Y = val.Y; }
}


VectorF2 BoxF2::Size() const
{
	return (Max - Min);
}
VectorF2 BoxF2::Center() const
{
	return ((Max * 0.5f) + (Min * 0.5f));
}



bool BoxF2::Intersekt(VectorF2 val) const
{
	return (Min.X <= val.X && Max.X >= val.X)
		&& (Min.Y <= val.Y && Max.Y >= val.Y)
	;
}
bool BoxF2::Intersekt(const BoxF2 & other) const
{
	return ((Max.X > other.Min.X) && (Min.X < other.Max.X))
		&& ((Max.Y > other.Min.Y) && (Min.Y < other.Max.Y))
	;
}
