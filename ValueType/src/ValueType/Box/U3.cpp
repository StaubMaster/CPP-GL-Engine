#include "ValueType/Box/U3.hpp"



VectorU3 BoxU3::Size() const
{
	return (Max - Min);
}
VectorU3 BoxU3::Center() const
{
	return ((Min + Max) / 2.0f);
}



BoxU3::BoxU3(const VectorU3 & min, const VectorU3 & max)
	: Min(min)
	, Max(max)
{ }



BoxU3 BoxU3::InverseLimit()
{
	return BoxU3(
		VectorU3(0xFFFFFFFF),
		VectorU3(0x00000000)
	);
}

void BoxU3::Consider(const VectorU3 & vec)
{
	Min = Min.Min(vec);
	Max = Max.Max(vec);
}



Bool3 BoxU3::IsNormal() const
{
	return (Min <= Max);
}
//BoxU3 BoxU3::Normalize() const;



Bool3 BoxU3::ContainsEdge(const VectorU3 & vec) const			{ return (vec == Min) | (vec == Max); }
Bool3 BoxU3::ContainsInclusive(const VectorU3 & vec) const		{ return (vec >= Min) & (vec <= Max); }
Bool3 BoxU3::ContainsExclusive(const VectorU3 & vec) const		{ return (vec >  Min) & (vec <  Max); }

Bool3 BoxU3::IntersectsInclusive(const BoxU3 & box) const	{ return (Max >= box.Min) & (Min <= box.Max); }
Bool3 BoxU3::IntersectsExclusive(const BoxU3 & box) const	{ return (Max >  box.Min) & (Min <  box.Max); }

//BoxU3 BoxU3::OuterBox(const BoxU3 & other) const;
//BoxU3 BoxU3::InnerBox(const BoxU3 & other) const;
