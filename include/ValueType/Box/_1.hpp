#ifndef  BOX_1_HPP
# define BOX_1_HPP

# include "ValueType/Box/__.hpp"

template<typename ValueType, typename VectorType, typename BoxType> struct Box_1 : public Box__<ValueType, VectorType, BoxType>
{
~Box_1() = default;
Box_1() = default;
Box_1(const Box_1 & other) = default;
Box_1 & operator=(const Box_1 & other) = default;

Box_1(VectorType min, VectorType max);



bool		IsNormal() const;
BoxType		Normalize() const;

void	Consider(const VectorType & vec);



// put these in Box__ with BoolType ?

// pass parameter by Value vs Referance ?
// these ValueTypes are relatively small so Value should be fine

// Contains1
bool	IntersectEdge(const VectorType & vec) const;
bool	IntersectInclusive(const VectorType & vec) const;
bool	IntersectExclusive(const VectorType & vec) const;

// Intersects1
bool	IntersectInclusive(const BoxType & box) const;
bool	IntersectExclusive(const BoxType & box) const;

// Contains
bool	Intersekt(const VectorType & vec) const;

// Intersects
bool	Intersekt(const BoxType & box) const;
};

#endif