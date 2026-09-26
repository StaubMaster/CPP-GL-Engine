#include "ValueType/Loop/I2.hpp"



LoopI2::LoopI2(const VectorI2 & size)
	: Box(VectorI2(), size)
	, MinExclude(false)
	, MaxExclude(true)
{ }

LoopI2::LoopI2(const VectorI2 & min, const VectorI2 & max)
	: Box(min, max)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopI2::LoopI2(const VectorI2 & min, const VectorI2 & max, const Bool2 & minEx, const Bool2 & maxEx)
	: Box(min, max)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }

LoopI2::LoopI2(const BoxI2 & box)
	: Box(box)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopI2::LoopI2(const BoxI2 & box, const Bool2 & minEx, const Bool2 & maxEx)
	: Box(box)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }



VectorI2 LoopI2::Min() const
{
	VectorI2 idx(Box.Min);
	if (MinExclude.GetX()) { idx.X++; }
	if (MinExclude.GetY()) { idx.Y++; }
	return idx;
}
VectorI2 LoopI2::Max() const
{
	VectorI2 idx(Box.Max);
	if (MaxExclude.GetX()) { idx.X--; }
	if (MaxExclude.GetY()) { idx.Y--; }
	return idx;
}
VectorI2 LoopI2::Size() const
{
	return (Min() - Max());
}



Bool2 LoopI2::Check(const VectorI2 & idx) const
{
	Bool2 min;
	if (MinExclude.GetX()) { min.SetX(idx.X > Box.Min.X); } else { min.SetX(idx.X >= Box.Min.X); }
	if (MinExclude.GetY()) { min.SetY(idx.Y > Box.Min.Y); } else { min.SetY(idx.Y >= Box.Min.Y); }

	Bool2 max;
	if (MaxExclude.GetX()) { max.SetX(idx.X < Box.Max.X); } else { max.SetX(idx.X <= Box.Max.X); }
	if (MaxExclude.GetY()) { max.SetY(idx.Y < Box.Max.Y); } else { max.SetY(idx.Y <= Box.Max.Y); }

	return min & max;
}



/*	Problem
Overflow might happen
check before ++ and --
*/
void LoopI2::Next(VectorI2 & idx) const
{
	VectorI2 min = Min();
	VectorI2 max = Max();

	if (idx.X >= max.X)
	{
		idx.X = min.X;
		idx.Y++;
	}
	else
	{
		idx.X++;
	}
}
void LoopI2::Prev(VectorI2 & idx) const
{
	VectorI2 min = Min();
	VectorI2 max = Max();

	if (idx.X <= min.X)
	{
		idx.X = max.X;
		idx.Y--;
	}
	else
	{
		idx.X--;
	}
}
