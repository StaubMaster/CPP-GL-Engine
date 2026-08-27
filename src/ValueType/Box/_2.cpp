#include "ValueType/Box/_2.hpp"
#include "ValueType/Bool/2.hpp"

/*
template<typename ValueType, typename VectorType, typename BoxType>
Box_2<ValueType, VectorType, BoxType>::
*/



template<typename ValueType, typename VectorType, typename BoxType>Box_2<ValueType, VectorType, BoxType>::Box_2(VectorType min, VectorType max)
	: Box__<ValueType, VectorType, BoxType>(min, max)
{ }



template<typename ValueType, typename VectorType, typename BoxType> bool		Box_2<ValueType, VectorType, BoxType>::IsNormal() const
{
	return ((this -> Min) <= (this -> Max)).All(true);
}
template<typename ValueType, typename VectorType, typename BoxType> BoxType		Box_2<ValueType, VectorType, BoxType>::Normalize() const
{
	return BoxType(
		(this -> Min).Min(this -> Max),
		(this -> Max).Max(this -> Min)
	);
}

template<typename ValueType, typename VectorType, typename BoxType> void	Box_2<ValueType, VectorType, BoxType>::Consider(const VectorType & vec)
{
	if (vec.X < (this -> Min.X)) { (this -> Min.X) = vec.X; }
	if (vec.Y < (this -> Min.Y)) { (this -> Min.Y) = vec.Y; }

	if (vec.X > (this -> Max.X)) { (this -> Max.X) = vec.X; }
	if (vec.Y > (this -> Max.Y)) { (this -> Max.Y) = vec.Y; }
}





template<typename ValueType, typename VectorType, typename BoxType> Bool2 Box_2<ValueType, VectorType, BoxType>::IntersectEdge(const VectorType & vec) const { return (vec == this -> Min) | (vec == this -> Max); }
template<typename ValueType, typename VectorType, typename BoxType> Bool2 Box_2<ValueType, VectorType, BoxType>::IntersectInclusive(const VectorType & vec) const { return (vec >= this -> Min) & (vec <= this -> Max); }
template<typename ValueType, typename VectorType, typename BoxType> Bool2 Box_2<ValueType, VectorType, BoxType>::IntersectExclusive(const VectorType & vec) const { return (vec >  this -> Min) & (vec <  this -> Max); }
template<typename ValueType, typename VectorType, typename BoxType> Bool2 Box_2<ValueType, VectorType, BoxType>::IntersectInclusive(const BoxType & box) const { return (this -> Max >= box.Min) & (this -> Min <= box.Max); }
template<typename ValueType, typename VectorType, typename BoxType> Bool2 Box_2<ValueType, VectorType, BoxType>::IntersectExclusive(const BoxType & box) const { return (this -> Max >  box.Min) & (this -> Min <  box.Max); }

template<typename ValueType, typename VectorType, typename BoxType> bool Box_2<ValueType, VectorType, BoxType>::Intersekt(const VectorType & vec) const
{
	return IntersectInclusive(vec).All(true);
}
template<typename ValueType, typename VectorType, typename BoxType> bool Box_2<ValueType, VectorType, BoxType>::Intersekt(const BoxType & box) const
{
	return IntersectExclusive(box).All(true);
}
