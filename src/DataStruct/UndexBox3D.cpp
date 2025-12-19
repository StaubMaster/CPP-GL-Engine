#include "DataStruct/UndexBox3D.hpp"



UndexBox3D::UndexBox3D() :
	Min(),
	Max()
{ }
UndexBox3D::UndexBox3D(Undex3D min, Undex3D max) :
	Min(min),
	Max(max)
{ }
UndexBox3D::~UndexBox3D()
{ }



UndexBox3D::UndexBox3D(const UndexBox3D & other) :
	Min(other.Min),
	Max(other.Max)
{ }
UndexBox3D & UndexBox3D::operator=(const UndexBox3D & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



Bool3D UndexBox3D::CheckIn(Undex3D udx) const
{
	return (udx >= Min) & (udx <= Max);
}
Bool3D UndexBox3D::CheckEx(Undex3D udx) const
{
	return (udx > Min) & (udx < Max);
}
Bool3D UndexBox3D::CheckEdge(Undex3D udx) const
{
	return (udx == Min) | (udx == Max);
}
