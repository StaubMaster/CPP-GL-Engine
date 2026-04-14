#ifndef  BOX_3_HPP
# define BOX_3_HPP

# include "Box__.hpp"
# include "Bool3.hpp"

template<typename VectorType, typename BoxType> struct Box_3 : public Box__<VectorType>
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



template<typename OtherBoxType>
BoxType OuterBox(const OtherBoxType & other) const
{
	return BoxType(this -> Min.Min(other), this -> Max.Max(other));
}

/*
a-------a
|       |
|   c---c---b
|   |   |   |
a---c---c   |
    |       |
    b-------b
Normal
c.Min = (b.Min.X, b.Min.Y)
c.Max = (a.Max.X, a.Max.Y)

a-------a
|       |
|       c---c-------b
|       |   |       |
a-------c---c       |
            |       |
            b-------b
not Normal
c.Min = (a.Max.X, b.Min.Y)
c.Max = (b.Min.X, a.Max.Y)
Min and Max are what they would be if they were Normaized

a-------a
|       |
|       |
|       |
a-------c-------c
        |       |
        c-------c-------b
                |       |
                |       |
                |       |
                b-------b
not Normal
c.Min = (a.Max.X, a.Max.Y)
c.Max = (b.Min.X, b.Min.Y)
Min and Max are what they would be if they were Normaized

    a-------a
    |       |
b---c-------c---b
|   |       |   |
|   |       |   |
|   |       |   |
b---c-------c---b
    |       |
    a-------a
Normal
c.Min = (a.Min.X, b.Min.Y)
c.Max = (a.Max.X, b.Max.Y)

    b-------b
    |       |
a---c---c   |
|   |   |   |
|   c---c---b
|       |
a-------a
Normal
c.Min = (b.Min.X, a.Min.Y)
c.Max = (a.Max.X, b.Max.Y)
*/
template<typename OtherBoxType>
BoxType InnerBox(const OtherBoxType & other) const 
{
	return BoxType(this -> Min.Max(other.Min), this -> Max.Min(other.Max));
}

};

#endif