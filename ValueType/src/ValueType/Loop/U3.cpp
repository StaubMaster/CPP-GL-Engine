#include "ValueType/Loop/U3.hpp"



LoopU3::LoopU3(const VectorU3 & size)
	: Box(VectorU3(), size)
	, MinExclude(false)
	, MaxExclude(true)
{ }

LoopU3::LoopU3(const VectorU3 & min, const VectorU3 & max)
	: Box(min, max)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopU3::LoopU3(const VectorU3 & min, const VectorU3 & max, const Bool3 & minEx, const Bool3 & maxEx)
	: Box(min, max)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }

LoopU3::LoopU3(const BoxU3 & box)
	: Box(box)
	, MinExclude(false)
	, MaxExclude(true)
{ }
LoopU3::LoopU3(const BoxU3 & box, const Bool3 & minEx, const Bool3 & maxEx)
	: Box(box)
	, MinExclude(minEx)
	, MaxExclude(maxEx)
{ }



VectorU3 LoopU3::Min() const
{
	VectorU3 udx(Box.Min);
	if (MinExclude.GetX()) { udx.X++; }
	if (MinExclude.GetY()) { udx.Y++; }
	if (MinExclude.GetZ()) { udx.Z++; }
	return udx;
}
VectorU3 LoopU3::Max() const
{
	VectorU3 udx(Box.Max);
	if (MaxExclude.GetX()) { udx.X--; }
	if (MaxExclude.GetY()) { udx.Y--; }
	if (MaxExclude.GetZ()) { udx.Z--; }
	return udx;
}



Bool3 LoopU3::Check(const VectorU3 & udx) const
{
	Bool3 min;
	if (MinExclude.GetX()) { min.SetX(udx.X > Box.Min.X); } else { min.SetX(udx.X >= Box.Min.X); }
	if (MinExclude.GetY()) { min.SetY(udx.Y > Box.Min.Y); } else { min.SetY(udx.Y >= Box.Min.Y); }
	if (MinExclude.GetZ()) { min.SetZ(udx.Z > Box.Min.Z); } else { min.SetZ(udx.Z >= Box.Min.Z); }

	Bool3 max;
	if (MaxExclude.GetX()) { max.SetX(udx.X < Box.Max.X); } else { max.SetX(udx.X <= Box.Max.X); }
	if (MaxExclude.GetY()) { max.SetY(udx.Y < Box.Max.Y); } else { max.SetY(udx.Y <= Box.Max.Y); }
	if (MaxExclude.GetZ()) { max.SetZ(udx.Z < Box.Max.Z); } else { max.SetZ(udx.Z <= Box.Max.Z); }

	return min & max;
}



void LoopU3::Next(VectorU3 & udx) const
{
	VectorU3 min = Min();
	VectorU3 max = Max();

	if (udx.X >= max.X)
	{
		udx.X = min.X;
		if (udx.Y >= max.Y)
		{
			udx.Y = min.Y;
			udx.Z++;
		}
		else
		{
			udx.Y++;
		}
	}
	else
	{
		udx.X++;
	}
}
void LoopU3::Prev(VectorU3 & udx) const
{
	VectorU3 min = Min();
	VectorU3 max = Max();

	if (udx.X <= min.X)
	{
		udx.X = max.X;
		if (udx.Y <= min.Y)
		{
			udx.Y = max.Y;
			udx.Z--;
		}
		else
		{
			udx.Y--;
		}
	}
	else
	{
		udx.X--;
	}
}
