#ifndef  BOX_1_HPP
# define BOX_1_HPP

# include "Box__.hpp"

template<typename VectorType> struct Box_1 : public Box__<VectorType>
{
~Box_1() { }

Box_1(VectorType min, VectorType max)
	: Box__<VectorType>(min, max)
{ }

Box_1(const Box_1 & other)
	: Box__<VectorType>(other)
{ }
Box_1 & operator=(const Box_1 & other)
{
	Box__<VectorType>::operator=(other);
	return *this;
}



void Consider(VectorType val)
{
	if (val < this -> Min) { this -> Min = val; }

	if (val > this -> Max) { this -> Max = val; }
}



// put these in Box__ with BoolType ?

// pass parameter by Value vs Referance ?
// these ValueTypes are relatively small so Value should be fine

bool IntersectInclusive(VectorType vec) const { return (vec >= this -> Min) & (vec <= this -> Max); }
bool IntersectExclusive(VectorType vec) const { return (vec > this -> Min) & (vec < this -> Max); }
bool IntersectEdge(VectorType vec) const { return (vec == this -> Min) | (vec == this -> Max); }

bool IntersectInclusive(Box_1 box) const { return (this -> Max >= box.Min) & (this -> Min <= box.Max); }
bool IntersectExclusive(Box_1 box) const { return (this -> Max > box.Min) & (this -> Min < box.Max); }



bool Intersekt(VectorType val) const
{
	return IntersectInclusive(val);
	/*return (this -> Min.X <= val.X && this -> Max.X >= val.X)
		&& (this -> Min.Y <= val.Y && this -> Max.Y >= val.Y)
	;*/
}
bool Intersekt(Box_1 other) const
{
	return IntersectExclusive(other);
	/*return ((this -> Max.X > other.Min.X) && (this -> Min.X < other.Max.X))
		&& ((this -> Max.Y > other.Min.Y) && (this -> Min.Y < other.Max.Y))
	;*/
}
};

#endif