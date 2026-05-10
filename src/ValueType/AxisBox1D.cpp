#include "ValueType/Box/F1.hpp"
#include <math.h>



BoxF1::BoxF1() :
	Min(+INFINITY),
	Max(-INFINITY)
{ }
BoxF1::BoxF1(float min, float max) :
	Min(min),
	Max(max)
{ }



BoxF1::BoxF1(const BoxF1 & other) :
	Min(other.Min),
	Max(other.Max)
{ }
BoxF1 & BoxF1::operator=(const BoxF1 & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



void BoxF1::Consider(float val)
{
	if (val < Min) { Min = val; }

	if (val > Max) { Max = val; }
}


float BoxF1::Size() const
{
	return (Max - Min);
}
float BoxF1::Center() const
{
	return ((Max * 0.5f) + (Min * 0.5f));
}



bool BoxF1::Intersekt(float val) const
{
	return (Min <= val && Max >= val);
}
bool BoxF1::Intersekt(const BoxF1 & other) const
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
