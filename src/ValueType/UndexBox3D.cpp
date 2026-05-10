#include "ValueType/UndexBox3D.hpp"



UndexBox3D::UndexBox3D() :
	Min(),
	Max()
{ }
UndexBox3D::UndexBox3D(VectorU3 min, VectorU3 max) :
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



Bool3 UndexBox3D::CheckIn(VectorU3 udx) const
{
	return (udx >= Min) & (udx <= Max);
}
Bool3 UndexBox3D::CheckEx(VectorU3 udx) const
{
	return (udx > Min) & (udx < Max);
}
Bool3 UndexBox3D::CheckEdge(VectorU3 udx) const
{
	return (udx == Min) | (udx == Max);
}
