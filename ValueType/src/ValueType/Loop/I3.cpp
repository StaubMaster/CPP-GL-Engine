#include "ValueType/Loop/I3.hpp"



LoopI3::LoopI3(const VectorI3 & size)
	: Box(VectorI3(), size)
	, MinExclude(false)
	, MaxExclude(true)
{ }

LoopI3::LoopI3(const VectorI3 & min, const VectorI3 & max)
	: Box(min, max)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopI3::LoopI3(const VectorI3 & min, const VectorI3 & max, const Bool3 & minEx, const Bool3 & maxEx)
	: Box(min, max)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }

LoopI3::LoopI3(const BoxI3 & box)
	: Box(box)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopI3::LoopI3(const BoxI3 & box, const Bool3 & minEx, const Bool3 & maxEx)
	: Box(box)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }



VectorI3 LoopI3::Min() const
{
	VectorI3 idx(Box.Min);
	if (MinExclude.GetX()) { idx.X++; }
	if (MinExclude.GetY()) { idx.Y++; }
	if (MinExclude.GetZ()) { idx.Z++; }
	return idx;
}
VectorI3 LoopI3::Max() const
{
	VectorI3 idx(Box.Max);
	if (MaxExclude.GetX()) { idx.X--; }
	if (MaxExclude.GetY()) { idx.Y--; }
	if (MaxExclude.GetZ()) { idx.Z--; }
	return idx;
}
VectorI3 LoopI3::Size() const
{
	return (Min() - Max());
}



Bool3 LoopI3::Check(const VectorI3 & idx) const
{
	Bool3 min;
	if (MinExclude.GetX()) { min.SetX(idx.X > Box.Min.X); } else { min.SetX(idx.X >= Box.Min.X); }
	if (MinExclude.GetY()) { min.SetY(idx.Y > Box.Min.Y); } else { min.SetY(idx.Y >= Box.Min.Y); }
	if (MinExclude.GetZ()) { min.SetZ(idx.Z > Box.Min.Z); } else { min.SetZ(idx.Z >= Box.Min.Z); }

	Bool3 max;
	if (MaxExclude.GetX()) { max.SetX(idx.X < Box.Max.X); } else { max.SetX(idx.X <= Box.Max.X); }
	if (MaxExclude.GetY()) { max.SetY(idx.Y < Box.Max.Y); } else { max.SetY(idx.Y <= Box.Max.Y); }
	if (MaxExclude.GetZ()) { max.SetZ(idx.Z < Box.Max.Z); } else { max.SetZ(idx.Z <= Box.Max.Z); }

	return min & max;
}



void LoopI3::Next(VectorI3 & idx) const
{
	VectorI3 min = Min();
	VectorI3 max = Max();

	if (idx.X >= max.X)
	{
		idx.X = min.X;
		if (idx.Y >= max.Y)
		{
			idx.Y = min.Y;
			idx.Z++;
		}
		else
		{
			idx.Y++;
		}
	}
	else
	{
		idx.X++;
	}
}
void LoopI3::Prev(VectorI3 & idx) const
{
	VectorI3 min = Min();
	VectorI3 max = Max();

	if (idx.X <= min.X)
	{
		idx.X = max.X;
		if (idx.Y <= min.Y)
		{
			idx.Y = max.Y;
			idx.Z--;
		}
		else
		{
			idx.Y--;
		}
	}
	else
	{
		idx.X--;
	}
}
