#include "ValueType/Box/I3.hpp"



VectorI3 BoxI3::Size() const
{
	return (Max - Min);
}
VectorI3 BoxI3::Center() const
{
	return ((Min + Max) / 2.0f);
}



BoxI3::BoxI3(const VectorI3 & min, const VectorI3 & max)
	: Min(min)
	, Max(max)
{ }



BoxI3 BoxI3::InverseLimit()
{
	return BoxI3(
		VectorI3(0x7FFFFFFF),
		VectorI3(0x80000000)
	);
}

void BoxI3::Consider(const VectorI3 & vec)
{
	Min = Min.Min(vec);
	Max = Max.Max(vec);
}



Bool3 BoxI3::IsNormal() const
{
	return (Min <= Max);
}
//BoxI3 BoxI3::Normalize() const;



Bool3 BoxI3::ContainsEdge(const VectorI3 & vec) const			{ return (vec == Min) | (vec == Max); }
Bool3 BoxI3::ContainsInclusive(const VectorI3 & vec) const		{ return (vec >= Min) & (vec <= Max); }
Bool3 BoxI3::ContainsExclusive(const VectorI3 & vec) const		{ return (vec >  Min) & (vec <  Max); }

Bool3 BoxI3::IntersectsInclusive(const BoxI3 & box) const	{ return (Max >= box.Min) & (Min <= box.Max); }
Bool3 BoxI3::IntersectsExclusive(const BoxI3 & box) const	{ return (Max >  box.Min) & (Min <  box.Max); }

//BoxI3 BoxI3::OuterBox(const BoxI3 & other) const;
//BoxI3 BoxI3::InnerBox(const BoxI3 & other) const;
