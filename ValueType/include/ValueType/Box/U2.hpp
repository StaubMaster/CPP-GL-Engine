#ifndef  BOX_U_2_HPP
# define BOX_U_2_HPP

# include "ValueType/Bool/2.hpp"
# include "ValueType/Vector/U2.hpp"

struct BoxU2
{
	VectorU2	Min;
	VectorU2	Max;

	VectorU2	Size() const;
	VectorU2	Center() const;

	~BoxU2() = default;
	BoxU2() = default;
	BoxU2(const BoxU2 & other) = default;
	BoxU2 & operator=(const BoxU2 & other) = default;

	BoxU2(const VectorU2 & min, const VectorU2 & max);
	
	static BoxU2	InverseLimit();

	void	Consider(const VectorU2 & vec);
	void	Consider(const BoxU2 & box);

	Bool2	IsNormal() const;
	BoxU2	Normalize() const;

	Bool2	ContainsEdge(const VectorU2 & vec) const;
	Bool2	ContainsInclusive(const VectorU2 & vec) const;
	Bool2	ContainsExclusive(const VectorU2 & vec) const;
	Bool2	IntersectsInclusive(const BoxU2 & box) const;
	Bool2	IntersectsExclusive(const BoxU2 & box) const;
	BoxU2	OuterBox(const BoxU2 & other) const;
	BoxU2	InnerBox(const BoxU2 & other) const;
};

#endif