#ifndef  BOX_2_HPP
# define BOX_2_HPP

# include "Box__.hpp"
# include "Bool2.hpp"

template<typename VectorType> struct Box_2 : public Box__<VectorType>
{
~Box_2() { }

Box_2(VectorType min, VectorType max)
	: Box__<VectorType>(min, max)
{ }

Box_2(const Box_2 & other)
	: Box__<VectorType>(other)
{ }
Box_2 & operator=(const Box_2 & other)
{
	Box__<VectorType>::operator=(other);
	return *this;
}



void Consider(VectorType val)
{
	if (val.X < this -> Min.X) { this -> Min.X = val.X; }
	if (val.Y < this -> Min.Y) { this -> Min.Y = val.Y; }

	if (val.X > this -> Max.X) { this -> Max.X = val.X; }
	if (val.Y > this -> Max.Y) { this -> Max.Y = val.Y; }
}



// put these in Box__ with BoolType ?

// pass parameter by Value vs Referance ?
// these ValueTypes are relatively small so Value should be fine

Bool2 IntersectInclusive(VectorType vec) const { return (vec >= this -> Min) & (vec <= this -> Max); }
Bool2 IntersectExclusive(VectorType vec) const { return (vec > this -> Min) & (vec < this -> Max); }
Bool2 IntersectEdge(VectorType vec) const { return (vec == this -> Min) | (vec == this -> Max); }

Bool2 IntersectInclusive(Box_2 box) const { return (this -> Max >= box.Min) & (this -> Min <= box.Max); }
Bool2 IntersectExclusive(Box_2 box) const { return (this -> Max > box.Min) & (this -> Min < box.Max); }



bool Intersekt(VectorType val) const
{
	return IntersectInclusive(val).All(true);
	/*return (this -> Min.X <= val.X && this -> Max.X >= val.X)
		&& (this -> Min.Y <= val.Y && this -> Max.Y >= val.Y)
	;*/
}
bool Intersekt(Box_2 other) const
{
	return IntersectExclusive(other).All(true);
	/*return ((this -> Max.X > other.Min.X) && (this -> Min.X < other.Max.X))
		&& ((this -> Max.Y > other.Min.Y) && (this -> Min.Y < other.Max.Y))
	;*/
}
};

#endif