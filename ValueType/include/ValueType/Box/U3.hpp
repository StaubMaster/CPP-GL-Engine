#ifndef  BOX_U_3_HPP
# define BOX_U_3_HPP

# include "ValueType/Vector/U3.hpp"

struct Bool3;

struct BoxI3;
struct BoxF3;

struct BoxU3
{
	VectorU3	Min;
	VectorU3	Max;

	VectorU3	Size() const;
	VectorU3	Center() const;

	~BoxU3() = default;
	BoxU3() = default;
	BoxU3(const BoxU3 & other) = default;
	BoxU3 & operator=(const BoxU3 & other) = default;
	
	BoxU3(const VectorU3 & min, const VectorU3 & max);

	BoxI3	ToI() const;
	BoxF3	ToF() const;

	static BoxU3	InverseLimit();

	void	Consider(const VectorU3 & vec);
	void	Consider(const BoxU3 & box);

	Bool3	IsNormal() const;
	BoxU3	Normalize() const;

	Bool3	ContainsEdge(const VectorU3 & vec) const;
	Bool3	ContainsInclusive(const VectorU3 & vec) const;
	Bool3	ContainsExclusive(const VectorU3 & vec) const;
	Bool3	IntersectsInclusive(const BoxU3 & box) const;
	Bool3	IntersectsExclusive(const BoxU3 & box) const;
	BoxU3	OuterBox(const BoxU3 & other) const;
	BoxU3	InnerBox(const BoxU3 & other) const;
};

#endif