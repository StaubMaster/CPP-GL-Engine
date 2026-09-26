#include "ValueType/Box/F2.hpp"



VectorF2 BoxF2::Size() const
{
	return (Max - Min);
}
VectorF2 BoxF2::Center() const
{
	return ((Min + Max) / 2.0f);
}



BoxF2::BoxF2(const VectorF2 & min, const VectorF2 & max)
	: Min(min)
	, Max(max)
{ }



BoxF2 BoxF2::InverseLimit()
{
	return BoxF2(
		VectorF2(+1/0.0f),
		VectorF2(-1/0.0f)
	);
}

void BoxF2::Consider(const VectorF2 & vec)
{
	Min = Min.Min(vec);
	Max = Max.Max(vec);
}



Bool2 BoxF2::IsNormal() const
{
	return (Min <= Max);
}
//BoxF2 BoxF2::Normalize() const;



Bool2 BoxF2::ContainsEdge(const VectorF2 & vec) const		{ return (vec == Min) | (vec == Max); }
Bool2 BoxF2::ContainsInclusive(const VectorF2 & vec) const	{ return (vec >= Min) & (vec <= Max); }
Bool2 BoxF2::ContainsExclusive(const VectorF2 & vec) const	{ return (vec >  Min) & (vec <  Max); }

Bool2 BoxF2::IntersectsInclusive(const BoxF2 & box) const	{ return (Max >= box.Min) & (Min <= box.Max); }
Bool2 BoxF2::IntersectsExclusive(const BoxF2 & box) const	{ return (Max >  box.Min) & (Min <  box.Max); }

BoxF2 BoxF2::OuterBox(const BoxF2 & other) const	{ return BoxF2(VectorF2::Min(Min, other.Min), VectorF2::Max(Max, other.Max)); }
BoxF2 BoxF2::InnerBox(const BoxF2 & other) const	{ return BoxF2(VectorF2::Max(Min, other.Min), VectorF2::Min(Max, other.Max)); }
