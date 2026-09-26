#ifndef  BOX_I_2_HPP
# define BOX_I_2_HPP

# include "ValueType/Bool/2.hpp"
# include "ValueType/Vector/I2.hpp"

struct BoxI2
{
	VectorI2	Min;
	VectorI2	Max;

	VectorI2	Size() const;
	VectorI2	Center() const;

	~BoxI2() = default;
	BoxI2() = default;
	BoxI2(const BoxI2 & other) = default;
	BoxI2 & operator=(const BoxI2 & other) = default;

	BoxI2(const VectorI2 & min, const VectorI2 & max);

	static BoxI2	InverseLimit();

	void	Consider(const VectorI2 & vec);
	void	Consider(const BoxI2 & box);

	Bool2	IsNormal() const;
	BoxI2	Normalize() const;

	Bool2	ContainsEdge(const VectorI2 & vec) const;
	Bool2	ContainsInclusive(const VectorI2 & vec) const;
	Bool2	ContainsExclusive(const VectorI2 & vec) const;
	Bool2	IntersectsInclusive(const BoxI2 & box) const;
	Bool2	IntersectsExclusive(const BoxI2 & box) const;
	BoxI2	OuterBox(const BoxI2 & other) const;
	BoxI2	InnerBox(const BoxI2 & other) const;
};

#endif