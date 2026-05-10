#ifndef  BOX_3_HPP
# define BOX_3_HPP

# include "ValueType/Box/__.hpp"
# include "ValueType/Bool3.hpp"

template<typename VectorType, typename BoxType> struct Box_3 : public Box__<VectorType, BoxType>
{
~Box_3() { }

Box_3(VectorType min, VectorType max)
	: Box__<VectorType, BoxType>(min, max)
{ }

Box_3(const Box_3 & other)
	: Box__<VectorType, BoxType>(other)
{ }
Box_3 & operator=(const BoxType & other)
{
	Box__<VectorType, BoxType>::operator=(other);
	return *this;
}



Bool3 IsNormal() const { return (this -> Min) <= (this -> Max); }



void Consider(VectorType val)
{
	if (val.X < this -> Min.X) { this -> Min.X = val.X; }
	if (val.Y < this -> Min.Y) { this -> Min.Y = val.Y; }
	if (val.Z < this -> Min.Z) { this -> Min.Z = val.Z; }

	if (val.X > this -> Max.X) { this -> Max.X = val.X; }
	if (val.Y > this -> Max.Y) { this -> Max.Y = val.Y; }
	if (val.Z > this -> Max.Z) { this -> Max.Z = val.Z; }
}



BoxType operator+(VectorType vec) const { return BoxType(this -> Min + vec, this -> Max + vec); }
BoxType operator-(VectorType vec) const { return BoxType(this -> Min - vec, this -> Max - vec); }
BoxType operator*(VectorType vec) const { return BoxType(this -> Min * vec, this -> Max * vec); }
BoxType operator/(VectorType vec) const { return BoxType(this -> Min / vec, this -> Max / vec); }



// put these in Box__ with BoolType ?

// pass parameter by Value vs Referance ?
// these ValueTypes are relatively small so Value should be fine

template<typename OtherVectorType>
Bool3 IntersectVecInclusive(OtherVectorType vec) const { return (vec >= this -> Min) & (vec <= this -> Max); }
template<typename OtherVectorType>
Bool3 IntersectVecExclusive(OtherVectorType vec) const { return (vec > this -> Min) & (vec < this -> Max); }
template<typename OtherVectorType>
Bool3 IntersectVecEdge(OtherVectorType vec) const { return (vec == this -> Min) | (vec == this -> Max); }

template<typename OtherBoxType>
Bool3 IntersectBoxInclusive(const OtherBoxType & other) const { return (this -> Max >= other.Min) & (this -> Min <= other.Max); }
template<typename OtherBoxType>
Bool3 IntersectBoxExclusive(const OtherBoxType & other) const { return (this -> Max > other.Min) & (this -> Min < other.Max); }



bool Intersekt(VectorType val) const
{
	return IntersectVecInclusive(val).All(true);
	/*return (this -> Min.X <= val.X && this -> Max.X >= val.X)
		&& (this -> Min.Y <= val.Y && this -> Max.Y >= val.Y)
	;*/
}
bool Intersekt(Box_3 other) const
{
	return IntersectVecExclusive(other).All(true);
	/*return ((this -> Max.X > other.Min.X) && (this -> Min.X < other.Max.X))
		&& ((this -> Max.Y > other.Min.Y) && (this -> Min.Y < other.Max.Y))
	;*/
}
};

#endif