#include "DataStruct/UndexLoop3D.hpp"


UndexLoop3D::UndexLoop3D() :
	Range()
{ }
UndexLoop3D::UndexLoop3D(Undex3D min, Undex3D max) :
	Range(min, max)
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



Undex3D UndexLoop3D::Min() const { return Range.Min; }
Undex3D UndexLoop3D::Max() const { return Range.Max; }



Bool3D UndexLoop3D::CheckIn(Undex3D udx) const { return Range.CheckIn(udx); }
Bool3D UndexLoop3D::CheckEx(Undex3D udx) const { return Range.CheckEx(udx); }



void UndexLoop3D::Next(Undex3D & udx) const
{
	udx.X++;
	if (udx.X > Range.Max.X)
	{
		udx.X = Range.Min.X;
		udx.Y++;
		if (udx.Y > Range.Max.Y)
		{
			udx.Y = Range.Min.Y;
			udx.Z++;
		}
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
