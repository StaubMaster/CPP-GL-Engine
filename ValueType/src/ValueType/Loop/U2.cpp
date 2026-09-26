#include "ValueType/Loop/U2.hpp"



LoopU2::LoopU2(const VectorU2 & size)
	: Box(VectorU2(), size)
	, MinExclude(false)
	, MaxExclude(true)
{ }

LoopU2::LoopU2(const VectorU2 & min, const VectorU2 & max)
	: Box(min, max)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopU2::LoopU2(const VectorU2 & min, const VectorU2 & max, const Bool2 & minEx, const Bool2 & maxEx)
	: Box(min, max)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }

LoopU2::LoopU2(const BoxU2 & box)
	: Box(box)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopU2::LoopU2(const BoxU2 & box, const Bool2 & minEx, const Bool2 & maxEx)
	: Box(box)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }



VectorU2 LoopU2::Min() const
{
	VectorU2 udx(Box.Min);
	if (MinExclude.GetX()) { udx.X++; }
	if (MinExclude.GetY()) { udx.Y++; }
	return udx;
}
VectorU2 LoopU2::Max() const
{
	VectorU2 udx(Box.Max);
	if (MaxExclude.GetX()) { udx.X--; }
	if (MaxExclude.GetY()) { udx.Y--; }
	return udx;
}



Bool2 LoopU2::Check(const VectorU2 & udx) const
{
	Bool2 min;
	if (MinExclude.GetX()) { min.SetX(udx.X > Box.Min.X); } else { min.SetX(udx.X >= Box.Min.X); }
	if (MinExclude.GetY()) { min.SetY(udx.Y > Box.Min.Y); } else { min.SetY(udx.Y >= Box.Min.Y); }

	Bool2 max;
	if (MaxExclude.GetX()) { max.SetX(udx.X < Box.Max.X); } else { max.SetX(udx.X <= Box.Max.X); }
	if (MaxExclude.GetY()) { max.SetY(udx.Y < Box.Max.Y); } else { max.SetY(udx.Y <= Box.Max.Y); }

	return min & max;
}



void LoopU2::Next(VectorU2 & udx) const
{
	VectorU2 min = Min();
	VectorU2 max = Max();

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
void LoopU2::Prev(VectorU2 & udx) const
{
	VectorU2 min = Min();
	VectorU2 max = Max();

	if (udx.X <= min.X)
	{
		udx.X = max.X;
		udx.Y--;
	}
	else
	{
		udx.X--;
	}
}
