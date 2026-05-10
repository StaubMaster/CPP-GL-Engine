#include "ValueType/Box/F3.hpp"
#include <math.h>



BoxF3::BoxF3() :
	Min(+INFINITY, +INFINITY, +INFINITY),
	Max(-INFINITY, -INFINITY, -INFINITY)
{ }
BoxF3::BoxF3(VectorF3 min, VectorF3 max) :
	Min(min),
	Max(max)
{ }



BoxF3::BoxF3(const BoxF3 & other) :
	Min(other.Min),
	Max(other.Max)
{ }
BoxF3 & BoxF3::operator=(const BoxF3 & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



void BoxF3::Consider(VectorF3 val)
{
	if (val.X < Min.X) { Min.X = val.X; }
	if (val.Y < Min.Y) { Min.Y = val.Y; }
	if (val.Z < Min.Z) { Min.Z = val.Z; }

	if (val.X > Max.X) { Max.X = val.X; }
	if (val.Y > Max.Y) { Max.Y = val.Y; }
	if (val.Z > Max.Z) { Max.Z = val.Z; }
}


VectorF3 BoxF3::Size() const
{
	return (Max - Min);
}
VectorF3 BoxF3::Center() const
{
	return ((Max * 0.5f) + (Min * 0.5f));
}



bool BoxF3::Intersekt(VectorF3 val) const
{
	return (Min.X <= val.X && Max.X >= val.X)
		&& (Min.Y <= val.Y && Max.Y >= val.Y)
		&& (Min.Z <= val.Z && Max.Z >= val.Z)
	;
}
bool BoxF3::Intersekt(const BoxF3 & other) const
{
	return ((Max.X > other.Min.X) && (Min.X < other.Max.X))
		&& ((Max.Y > other.Min.Y) && (Min.Y < other.Max.Y))
		&& ((Max.Z > other.Min.Z) && (Min.Z < other.Max.Z))
	;
}
