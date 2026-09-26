#include "ValueType/Box/F1.hpp"

//#include "ValueType/Box/I1.hpp"
//#include "ValueType/Box/U1.hpp"

//#include "ValueType/Bool/1.hpp"



float BoxF1::Size() const
{
	return (Max - Min);
}
float BoxF1::Center() const
{
	return ((Min + Max) / 2.0f);
}



BoxF1::BoxF1(const float & min, const float & max)
	: Min(min)
	, Max(max)
{ }

//BoxI1 BoxF1::ToI() const { return BoxI1(Min.ToI(), Max.ToI()); }
//BoxU1 BoxF1::ToU() const { return BoxU1(Min.ToU(), Max.ToU()); }



BoxF1 BoxF1::InverseLimit()
{
	return BoxF1(
		+1/0.0f,
		-1/0.0f
	);
}

void BoxF1::Consider(const float & vec)
{
	if (vec < Min) { Min = vec; }

	if (vec > Max) { Max = vec; }
}



bool BoxF1::IsNormal() const
{
	return (Min <= Max);
}
//BoxF1 BoxF1::Normalize() const;



bool BoxF1::ContainsEdge(const float & vec) const			{ return (vec == Min) | (vec == Max); }
bool BoxF1::ContainsInclusive(const float & vec) const		{ return (vec >= Min) & (vec <= Max); }
bool BoxF1::ContainsExclusive(const float & vec) const		{ return (vec >  Min) & (vec <  Max); }

bool BoxF1::IntersectsInclusive(const BoxF1 & box) const	{ return (Max >= box.Min) & (Min <= box.Max); }
bool BoxF1::IntersectsExclusive(const BoxF1 & box) const	{ return (Max >  box.Min) & (Min <  box.Max); }

//BoxF1 BoxF1::OuterBox(const BoxF1 & other) const;
//BoxF1 BoxF1::InnerBox(const BoxF1 & other) const;
