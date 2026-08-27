#ifndef  BOX_3_HPP
# define BOX_3_HPP

# include "ValueType/Box/__.hpp"

struct Bool3;

template<typename ValueType, typename VectorType, typename BoxType> struct Box_3 : public Box__<ValueType, VectorType, BoxType>
{
~Box_3() = default;
Box_3() = default;
Box_3(const Box_3 & other) = default;
Box_3 & operator=(const Box_3 & other) = default;

Box_3(VectorType min, VectorType max);



bool		IsNormal() const;
BoxType		Normalize() const;

void	Consider(const VectorType & vec);



BoxType		operator+(const VectorType & vec) const;
BoxType		operator-(const VectorType & vec) const;
BoxType		operator*(const VectorType & vec) const;
BoxType		operator/(const VectorType & vec) const;



// put these in Box__ with BoolType ?

// pass parameter by Value vs Referance ?
// these ValueTypes are relatively small so Value should be fine

// Contains3
Bool3	IntersectVecEdge(const VectorType & vec) const;
Bool3	IntersectVecInclusive(const VectorType & vec) const;
Bool3	IntersectVecExclusive(const VectorType & vec) const;

// Intersects3
Bool3	IntersectBoxInclusive(const BoxType & box) const;
Bool3	IntersectBoxExclusive(const BoxType & box) const;

// Contains
bool	Intersekt(const VectorType & vec) const;

// Intersects
bool	Intersekt(const BoxType & box) const;
};

#endif