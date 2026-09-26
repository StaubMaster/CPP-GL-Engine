#include "ValueType/Box/F3.hpp"



VectorF3 BoxF3::Size() const
{
	return (Max - Min);
}
VectorF3 BoxF3::Center() const
{
	return ((Min + Max) / 2.0f);
}



BoxF3::BoxF3(const VectorF3 & min, const VectorF3 & max)
	: Min(min)
	, Max(max)
{ }



BoxF3 BoxF3::InverseLimit()
{
	return BoxF3(
		VectorF3(+1/0.0f),
		VectorF3(-1/0.0f)
	);
}

void BoxF3::Consider(const VectorF3 & vec)
{
	Min = Min.Min(vec);
	Max = Max.Max(vec);
}



Bool3 BoxF3::IsNormal() const
{
	return (Min <= Max);
}
//BoxF3 BoxF3::Normalize() const;



Bool3 BoxF3::ContainsEdge(const VectorF3 & vec) const			{ return (vec == Min) | (vec == Max); }
Bool3 BoxF3::ContainsInclusive(const VectorF3 & vec) const		{ return (vec >= Min) & (vec <= Max); }
Bool3 BoxF3::ContainsExclusive(const VectorF3 & vec) const		{ return (vec >  Min) & (vec <  Max); }

Bool3 BoxF3::IntersectsInclusive(const BoxF3 & box) const	{ return (Max >= box.Min) & (Min <= box.Max); }
Bool3 BoxF3::IntersectsExclusive(const BoxF3 & box) const	{ return (Max >  box.Min) & (Min <  box.Max); }

//BoxF3 BoxF3::OuterBox(const BoxF3 & other) const;
//BoxF3 BoxF3::InnerBox(const BoxF3 & other) const;



BoxF3 BoxF3::operator+(const VectorF3 & vec) const { return BoxF3(Min + vec, Max + vec); }
BoxF3 BoxF3::operator-(const VectorF3 & vec) const { return BoxF3(Min - vec, Max - vec); }
BoxF3 BoxF3::operator*(const VectorF3 & vec) const { return BoxF3(Min * vec, Max * vec); }
BoxF3 BoxF3::operator/(const VectorF3 & vec) const { return BoxF3(Min / vec, Max / vec); }
