#include "ValueType/Box/I2.hpp"



VectorI2 BoxI2::Size() const
{
	return (Max - Min);
}
VectorI2 BoxI2::Center() const
{
	return ((Min + Max) / 2.0f);
}



BoxI2::BoxI2(const VectorI2 & min, const VectorI2 & max)
	: Min(min)
	, Max(max)
{ }



BoxI2 BoxI2::InverseLimit()
{
	return BoxI2(
		VectorI2(0x7FFFFFFF),
		VectorI2(0x80000000)
	);
}

void BoxI2::Consider(const VectorI2 & vec)
{
	Min = Min.Min(vec);
	Max = Max.Max(vec);
}



Bool2 BoxI2::IsNormal() const
{
	return (Min <= Max);
}
//BoxI2 BoxI2::Normalize() const;



Bool2 BoxI2::ContainsEdge(const VectorI2 & vec) const			{ return (vec == Min) | (vec == Max); }
Bool2 BoxI2::ContainsInclusive(const VectorI2 & vec) const		{ return (vec >= Min) & (vec <= Max); }
Bool2 BoxI2::ContainsExclusive(const VectorI2 & vec) const		{ return (vec >  Min) & (vec <  Max); }

Bool2 BoxI2::IntersectsInclusive(const BoxI2 & box) const	{ return (Max >= box.Min) & (Min <= box.Max); }
Bool2 BoxI2::IntersectsExclusive(const BoxI2 & box) const	{ return (Max >  box.Min) & (Min <  box.Max); }

//BoxI2 BoxI2::OuterBox(const BoxI2 & other) const;
//BoxI2 BoxI2::InnerBox(const BoxI2 & other) const;
