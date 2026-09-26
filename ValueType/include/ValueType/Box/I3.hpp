#ifndef  BOX_I_3_HPP
# define BOX_I_3_HPP

# include "ValueType/Bool/3.hpp"
# include "ValueType/Vector/I3.hpp"

struct BoxI3
{
	VectorI3	Min;
	VectorI3	Max;

	VectorI3	Size() const;
	VectorI3	Center() const;

	~BoxI3() = default;
	BoxI3() = default;
	BoxI3(const BoxI3 & other) = default;
	BoxI3 & operator=(const BoxI3 & other) = default;

	BoxI3(const VectorI3 & min, const VectorI3 & max);
	
	static BoxI3	InverseLimit();

	void	Consider(const VectorI3 & vec);
	void	Consider(const BoxI3 & box);

	Bool3	IsNormal() const;
	BoxI3	Normalize() const;

	Bool3	ContainsEdge(const VectorI3 & vec) const;
	Bool3	ContainsInclusive(const VectorI3 & vec) const;
	Bool3	ContainsExclusive(const VectorI3 & vec) const;
	Bool3	IntersectsInclusive(const BoxI3 & box) const;
	Bool3	IntersectsExclusive(const BoxI3 & box) const;
	BoxI3	OuterBox(const BoxI3 & other) const;
	BoxI3	InnerBox(const BoxI3 & other) const;
};

#endif