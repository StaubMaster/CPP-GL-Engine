#include "DataStruct/UndexRange3D.hpp"



UndexRange3D::UndexRange3D() :
	Min(),
	Max()
{ }
UndexRange3D::UndexRange3D(Undex3D min, Undex3D max) :
	Min(min),
	Max(max)
{ }
UndexRange3D::~UndexRange3D()
{ }



UndexRange3D::UndexRange3D(const UndexRange3D & other) :
	Min(other.Min),
	Max(other.Max)
{ }
UndexRange3D & UndexRange3D::operator=(const UndexRange3D & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



Bool3D UndexRange3D::CheckIn(Undex3D udx) const
{
	return (udx >= Min) & (udx <= Max);
}
Bool3D UndexRange3D::CheckEx(Undex3D udx) const
{
	return (udx > Min) & (udx < Max);
}
Bool3D UndexRange3D::CheckEdge(Undex3D udx) const
{
	return (udx == Min) | (udx == Max);
}
