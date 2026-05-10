#include "ValueType/UndexBox2D.hpp"



UndexBox2D::UndexBox2D() :
	Min(),
	Max()
{ }
UndexBox2D::UndexBox2D(VectorU2 min, VectorU2 max) :
	Min(min),
	Max(max)
{ }
UndexBox2D::~UndexBox2D()
{ }



UndexBox2D::UndexBox2D(const UndexBox2D & other) :
	Min(other.Min),
	Max(other.Max)
{ }
UndexBox2D & UndexBox2D::operator=(const UndexBox2D & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



Bool2 UndexBox2D::CheckIn(VectorU2 udx) const
{
	return (udx >= Min) & (udx <= Max);
}
Bool2 UndexBox2D::CheckEx(VectorU2 udx) const
{
	return (udx > Min) & (udx < Max);
}
Bool2 UndexBox2D::CheckEdge(VectorU2 udx) const
{
	return (udx == Min) | (udx == Max);
}
