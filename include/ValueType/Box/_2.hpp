#ifndef  BOX_2_HPP
# define BOX_2_HPP

# include "ValueType/Box/__.hpp"

struct Bool2;

template<typename ValueType, typename VectorType, typename BoxType> struct Box_2 : public Box__<ValueType, VectorType, BoxType>
{
~Box_2() = default;
Box_2() = default;
Box_2(const Box_2 & other) = default;
Box_2 & operator=(const Box_2 & other) = default;

Box_2(VectorType min, VectorType max);



bool		IsNormal() const;
BoxType		Normalize() const;

void	Consider(const VectorType & vec);



// put these in Box__ with BoolType ?

// pass parameter by Value vs Referance ?
// these ValueTypes are relatively small so Value should be fine

// Contains2
Bool2	IntersectEdge(const VectorType & vec) const;
Bool2	IntersectInclusive(const VectorType & vec) const;
Bool2	IntersectExclusive(const VectorType & vec) const;

// Intersects2
Bool2	IntersectInclusive(const BoxType & box) const;
Bool2	IntersectExclusive(const BoxType & box) const;

// Contains2
bool Intersekt(const VectorType & val) const;

// Intersects2
bool Intersekt(const BoxType & box) const;
};

#endif