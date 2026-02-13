#include "ValueType/UndexLoop3D.hpp"



UndexLoop3D::UndexLoop3D() :
	Range()
{ }
UndexLoop3D::UndexLoop3D(Undex3D min, Undex3D max) :
	Range(min, max),
	MinExclude(false),
	MaxExclude(true)
{ }
UndexLoop3D::UndexLoop3D(Undex3D min, Bool3D minEx, Undex3D max, Bool3D maxEx) :
	Range(min, max),
	MinExclude(minEx),
	MaxExclude(maxEx)
{ }
UndexLoop3D::~UndexLoop3D()
{ }

UndexLoop3D::UndexLoop3D(const UndexLoop3D & other) :
	Range(other.Range)
{ }
UndexLoop3D & UndexLoop3D::operator=(const UndexLoop3D & other)
{
	Range = other.Range;
	return *this;
}



Undex3D UndexLoop3D::Min() const
{
	Undex3D udx(Range.Min);
	if (MinExclude.GetX()) { udx.X++; }
	if (MinExclude.GetY()) { udx.Y++; }
	if (MinExclude.GetZ()) { udx.Z++; }
	return udx;
}
Undex3D UndexLoop3D::Max() const
{
	Undex3D udx(Range.Max);
	if (MaxExclude.GetX()) { udx.X--; }
	if (MaxExclude.GetY()) { udx.Y--; }
	if (MaxExclude.GetZ()) { udx.Z--; }
	return udx;
}



Bool3D UndexLoop3D::Check(Undex3D udx) const
{
	Bool3D min;
	if (MinExclude.GetX()) { min.SetX(udx.X > Range.Min.X); } else { min.SetX(udx.X >= Range.Min.X); }
	if (MinExclude.GetY()) { min.SetY(udx.Y > Range.Min.Y); } else { min.SetY(udx.Y >= Range.Min.Y); }
	if (MinExclude.GetZ()) { min.SetZ(udx.Z > Range.Min.Z); } else { min.SetZ(udx.Z >= Range.Min.Z); }

	Bool3D max;
	if (MaxExclude.GetX()) { max.SetX(udx.X < Range.Max.X); } else { max.SetX(udx.X <= Range.Max.X); }
	if (MaxExclude.GetY()) { max.SetY(udx.Y < Range.Max.Y); } else { max.SetY(udx.Y <= Range.Max.Y); }
	if (MaxExclude.GetZ()) { max.SetZ(udx.Z < Range.Max.Z); } else { max.SetZ(udx.Z <= Range.Max.Z); }

	return min & max;
}



/*	Problem
Overflow might happen
check before ++ and --
*/
void UndexLoop3D::Next(Undex3D & udx) const
{
	Undex3D	min = Min();
	Undex3D	max = Max();

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
void UndexLoop3D::Prev(Undex3D & udx) const
{
	udx.X--;
	if (udx.X < Range.Min.X)
	{
		udx.X = Range.Max.X;
		udx.Y--;
		if (udx.Y < Range.Min.Y)
		{
			udx.Y = Range.Max.Y;
			udx.Z--;
		}
	}
}
