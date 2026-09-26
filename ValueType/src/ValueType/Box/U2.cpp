#include "ValueType/Box/U2.hpp"



VectorU2 BoxU2::Size() const
{
	return (Max - Min);
}
VectorU2 BoxU2::Center() const
{
	return ((Min + Max) / 2.0f);
}



BoxU2::BoxU2(const VectorU2 & min, const VectorU2 & max)
	: Min(min)
	, Max(max)
{ }



BoxU2 BoxU2::InverseLimit()
{
	return BoxU2(
		VectorU2(0xFFFFFFFF),
		VectorU2(0x00000000)
	);
}

void BoxU2::Consider(const VectorU2 & vec)
{
	Min = Min.Min(vec);
	Max = Max.Max(vec);
}



Bool2 BoxU2::IsNormal() const
{
	return (Min <= Max);
}
//BoxU2 BoxU2::Normalize() const;



Bool2 BoxU2::ContainsEdge(const VectorU2 & vec) const			{ return (vec == Min) | (vec == Max); }
Bool2 BoxU2::ContainsInclusive(const VectorU2 & vec) const		{ return (vec >= Min) & (vec <= Max); }
Bool2 BoxU2::ContainsExclusive(const VectorU2 & vec) const		{ return (vec >  Min) & (vec <  Max); }

Bool2 BoxU2::IntersectsInclusive(const BoxU2 & box) const	{ return (Max >= box.Min) & (Min <= box.Max); }
Bool2 BoxU2::IntersectsExclusive(const BoxU2 & box) const	{ return (Max >  box.Min) & (Min <  box.Max); }

//BoxU2 BoxU2::OuterBox(const BoxU2 & other) const;
//BoxU2 BoxU2::InnerBox(const BoxU2 & other) const;
