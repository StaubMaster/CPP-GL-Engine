#ifndef  BOX_3_HPP
# define BOX_3_HPP

# include "Box__.hpp"
# include "Bool3.hpp"

template<typename VectorType> struct Box_3 : public Box__<VectorType>
{
~Box_3() { }

Box_3(VectorType min, VectorType max)
	: Box__<VectorType>(min, max)
{ }

Box_3(const Box_3 & other)
	: Box__<VectorType>(other)
{ }
Box_3 & operator=(const Box_3 & other)
{
	Box__<VectorType>::operator=(other);
	return *this;
}



void Consider(VectorType val)
{
	if (val.X < this -> Min.X) { this -> Min.X = val.X; }
	if (val.Y < this -> Min.Y) { this -> Min.Y = val.Y; }
	if (val.Z < this -> Min.Z) { this -> Min.Z = val.Z; }

	if (val.X > this -> Max.X) { this -> Max.X = val.X; }
	if (val.Y > this -> Max.Y) { this -> Max.Y = val.Y; }
	if (val.Z > this -> Max.Z) { this -> Max.Z = val.Z; }
}



// put these in Box__ with BoolType ?

// pass parameter by Value vs Referance ?
// these ValueTypes are relatively small so Value should be fine

Bool3 IntersectInclusive(VectorType vec) const { return (vec >= this -> Min) & (vec <= this -> Max); }
Bool3 IntersectExclusive(VectorType vec) const { return (vec > this -> Min) & (vec < this -> Max); }
Bool3 IntersectEdge(VectorType vec) const { return (vec == this -> Min) | (vec == this -> Max); }

Bool3 IntersectInclusive(Box_3 box) const { return (this -> Max >= box.Min) & (this -> Min <= box.Max); }
Bool3 IntersectExclusive(Box_3 box) const { return (this -> Max > box.Min) & (this -> Min < box.Max); }



bool Intersekt(VectorType val) const
{
	return IntersectInclusive(val).All(true);
	/*return (this -> Min.X <= val.X && this -> Max.X >= val.X)
		&& (this -> Min.Y <= val.Y && this -> Max.Y >= val.Y)
	;*/
}
bool Intersekt(Box_3 other) const
{
	return IntersectExclusive(other).All(true);
	/*return ((this -> Max.X > other.Min.X) && (this -> Min.X < other.Max.X))
		&& ((this -> Max.Y > other.Min.Y) && (this -> Min.Y < other.Max.Y))
	;*/
}
};

#endif