#include "ValueType/LoopI2.hpp"



LoopI2::~LoopI2()
{ }

LoopI2::LoopI2() :
	Range()
{ }
LoopI2::LoopI2(VectorI2 min, VectorI2 max) :
	Range(min, max),
	MinExclude(false),
	MaxExclude(true)
{ }
LoopI2::LoopI2(VectorI2 min, Bool2D minEx, VectorI2 max, Bool2D maxEx) :
	Range(min, max),
	MinExclude(minEx),
	MaxExclude(maxEx)
{ }

LoopI2::LoopI2(const LoopI2 & other) :
	Range(other.Range)
{ }
LoopI2 & LoopI2::operator=(const LoopI2 & other)
{
	Range = other.Range;
	return *this;
}



VectorI2 LoopI2::Min() const
{
	VectorI2 udx(Range.Min);
	if (MinExclude.GetX()) { udx.X++; }
	if (MinExclude.GetY()) { udx.Y++; }
	return udx;
}
VectorI2 LoopI2::Max() const
{
	VectorI2 udx(Range.Max);
	if (MaxExclude.GetX()) { udx.X--; }
	if (MaxExclude.GetY()) { udx.Y--; }
	return udx;
}



Bool2D LoopI2::Check(VectorI2 udx) const
{
	Bool2D min;
	if (MinExclude.GetX()) { min.SetX(udx.X > Range.Min.X); } else { min.SetX(udx.X >= Range.Min.X); }
	if (MinExclude.GetY()) { min.SetY(udx.Y > Range.Min.Y); } else { min.SetY(udx.Y >= Range.Min.Y); }

	Bool2D max;
	if (MaxExclude.GetX()) { max.SetX(udx.X < Range.Max.X); } else { max.SetX(udx.X <= Range.Max.X); }
	if (MaxExclude.GetY()) { max.SetY(udx.Y < Range.Max.Y); } else { max.SetY(udx.Y <= Range.Max.Y); }

	return min & max;
}



/*	Problem
Overflow might happen
check before ++ and --
*/
void LoopI2::Next(VectorI2 & udx) const
{
	VectorI2	min = Min();
	VectorI2	max = Max();

	if (udx.X >= max.X)
	{
		udx.X = min.X;
		udx.Y++;
	}
	else
	{
		udx.X++;
	}
}
void LoopI2::Prev(VectorI2 & udx) const
{
	udx.X--;
	if (udx.X < Range.Min.X)
	{
		udx.X = Range.Max.X;
		udx.Y--;
	}
}
