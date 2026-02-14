#include "ValueType/AxisBox1D.hpp"
#include <math.h>



AxisBox1D::AxisBox1D() :
	Min(+INFINITY),
	Max(-INFINITY)
{ }
AxisBox1D::AxisBox1D(float min, float max) :
	Min(min),
	Max(max)
{ }



AxisBox1D::AxisBox1D(const AxisBox1D & other) :
	Min(other.Min),
	Max(other.Max)
{ }
AxisBox1D & AxisBox1D::operator=(const AxisBox1D & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



void AxisBox1D::Consider(float val)
{
	if (val < Min) { Min = val; }

	if (val > Max) { Max = val; }
}


float AxisBox1D::Size() const
{
	return (Max - Min);
}
float AxisBox1D::Center() const
{
	return ((Max * 0.5f) + (Min * 0.5f));
}



bool AxisBox1D::Intersekt(float val) const
{
	return (Min <= val && Max >= val);
}
bool AxisBox1D::Intersekt(const AxisBox1D & other) const
{
/*
: A : B : C :
: D : E : F :

:	#-0-#			:	#---0---#		:	#-----0-----#	:
:			#-1-#	:		#---1---#	:		#-1-#		:

:			#-0-#	:		#---0---#	:		#-0-#		:
:	#-1-#			:	#---1---#		:	#-----1-----#	:

				: A : B : C : D : E : F :
Min0 <=> Min1	: < : < : < : > : > : > :
Max0 <=> Min1	: < : > : > : > : > : > :
Min0 <=> Max1	: < : < : < : > : < : < :
Max0 <=> Max1	: < : < : < : > : > : > :
				: A : B : C : D : E : F :
Max0  >  Min1 | Min0  <  Max1
*/
	return ((Max > other.Min) && (Min < other.Max));
}
