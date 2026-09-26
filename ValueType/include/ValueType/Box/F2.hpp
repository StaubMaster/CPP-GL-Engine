#ifndef  BOX_F_2_HPP
# define BOX_F_2_HPP

# include "ValueType/Bool/2.hpp"
# include "ValueType/Vector/F2.hpp"

struct BoxF2
{
	VectorF2	Min;
	VectorF2	Max;

	VectorF2	Size() const;
	VectorF2	Center() const;

	~BoxF2() = default;
	BoxF2() = default;
	BoxF2(const BoxF2 & other) = default;
	BoxF2 & operator=(const BoxF2 & other) = default;

	BoxF2(const VectorF2 & min, const VectorF2 & max);

	static BoxF2	InverseLimit();

	void	Consider(const VectorF2 & vec);
	void	Consider(const BoxF2 & box);

	Bool2	IsNormal() const;
	BoxF2	Normalize() const;

	Bool2	ContainsEdge(const VectorF2 & vec) const;
	Bool2	ContainsInclusive(const VectorF2 & vec) const;
	Bool2	ContainsExclusive(const VectorF2 & vec) const;
	Bool2	IntersectsInclusive(const BoxF2 & box) const;
	Bool2	IntersectsExclusive(const BoxF2 & box) const;
	BoxF2	OuterBox(const BoxF2 & other) const;
	BoxF2	InnerBox(const BoxF2 & other) const;
};

#endif